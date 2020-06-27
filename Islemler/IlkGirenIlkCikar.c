// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.0

#include "IlkGirenIlkCikar.h"

Tip_Isaretci_IGIC IGIC_Yeni(Tip_u32 Kapasite, enum e_IGIC_YerKalmazsa_ YerKalmazsa, Tip_Islem_IGIC_Siliniyor Islem_Siliniyor)
{
	if (Kapasite == 0 ||
		YerKalmazsa > e_IGIC_YerKalmazsa_TalebiReddet) return Tip_null;

	struct _s_IGIC_ * Yeni = YT_Yeni(sizeof(struct _s_IGIC_) + Kapasite);
	if (Yeni == Tip_null) return Tip_null;

	_Islem_memset_(Yeni, 0, sizeof(struct _s_IGIC_));

	Yeni->Kapasite = Kapasite;
	Yeni->Tampon = Yeni + sizeof(struct _s_IGIC_);
	Yeni->YerKalmazsa = YerKalmazsa;
	Yeni->Islem_Siliniyor = Islem_Siliniyor;

	return Yeni;
}

Tip_u32 IGIC_Bilgi_Oku(Tip_Isaretci_IGIC IGIC, Tip_Isaretci YazilacakTampon, Tip_u32 TamponKapasitesi, Tip_bool VeBosYerAc)
{
	if (IGIC == Tip_null) return 0;

	if (TamponKapasitesi > IGIC_DoluAlan(IGIC)) TamponKapasitesi = IGIC_DoluAlan(IGIC);

	Tip_i32 Cark = (_IGIC_(IGIC)->Konum_Okuma + TamponKapasitesi) - IGIC_Kapasite(IGIC);
	if (Cark > 0)
	{
		//cark etti, dongu hesabini yap
		if (YazilacakTampon)
		{
			Tip_u32 Fark = TamponKapasitesi - Cark;
			_Islem_memcpy_(YazilacakTampon, Isaretci_Konumlandir(_IGIC_(IGIC)->Tampon, _IGIC_(IGIC)->Konum_Okuma, Tip_u8), Fark);
			_Islem_memcpy_(Isaretci_Konumlandir(YazilacakTampon, Fark, Tip_u8), _IGIC_(IGIC)->Tampon, Cark);
		}
		if (VeBosYerAc) _IGIC_(IGIC)->Konum_Okuma = Cark;
	}
	else
	{
		if (YazilacakTampon) _Islem_memcpy_(YazilacakTampon, Isaretci_Konumlandir(_IGIC_(IGIC)->Tampon, _IGIC_(IGIC)->Konum_Okuma, Tip_u8), TamponKapasitesi);
		if (VeBosYerAc) _IGIC_(IGIC)->Konum_Okuma += TamponKapasitesi;
	}

	if (VeBosYerAc) IGIC_DoluAlan(IGIC) -= TamponKapasitesi;

	return TamponKapasitesi;
}
Tip_bool IGIC_Bilgi_Ekle(Tip_Isaretci_IGIC IGIC, Tip_Isaretci OkunacakTampon, Tip_u32 Adet)
{
	if (IGIC == Tip_null ||
		OkunacakTampon == Tip_null ||
		Adet == 0 ||
		Adet > IGIC_Kapasite(IGIC)) return false; //Parametre hatali

	Tip_i32 Fark = Adet - IGIC_BosAlan(IGIC);
	if (Fark > 0)
	{
		//dolu, once bosalt
		if (_IGIC_(IGIC)->YerKalmazsa == e_IGIC_YerKalmazsa_TalebiReddet) return false; //Bos yer yok

		if (_IGIC_(IGIC)->Islem_Siliniyor)
		{
			if (!_IGIC_(IGIC)->Islem_Siliniyor(IGIC, Fark)) return false; //Silme islemi iptal edildi
			else
			{
				//Kullanici yer acmis mi
				Fark = Adet - IGIC_BosAlan(IGIC);
			}
		}

		if (Fark > 0)
		{
			if (IGIC_Bilgi_Oku(IGIC, NULL, Fark, true) != Fark) goto BeklenmeyenDurum;
		}
	}

	Tip_i32 Cark = (_IGIC_(IGIC)->Konum_Ekleme + Adet) - IGIC_Kapasite(IGIC);
	if (Cark > 0)
	{
		//cark etti, dongu hesabini yap
		Fark = Adet - Cark;
		_Islem_memcpy_(Isaretci_Konumlandir(_IGIC_(IGIC)->Tampon, _IGIC_(IGIC)->Konum_Ekleme, Tip_u8), OkunacakTampon, Fark);
		_Islem_memcpy_(_IGIC_(IGIC)->Tampon, Isaretci_Konumlandir(OkunacakTampon, Fark, Tip_u8), Cark);
		_IGIC_(IGIC)->Konum_Ekleme = Cark;
	}
	else
	{
		_Islem_memcpy_(Isaretci_Konumlandir(_IGIC_(IGIC)->Tampon, _IGIC_(IGIC)->Konum_Ekleme, Tip_u8), OkunacakTampon, Adet);
		_IGIC_(IGIC)->Konum_Ekleme += Adet;
	}

	IGIC_DoluAlan(IGIC) += Adet;

	return true;

	BeklenmeyenDurum:
	HataKontrol_Hatali(e_HataKontrol_Hata_IlkGirenIlkCikar);
	return false;
}
