// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.1

#include "Depo.h"

Tip_Isaretci_Depo Depo_Yeni(Tip_u8 AyirmaBirimi_KapladigiAlan_Bayt, Tip_u32 Kapasite, enum e_IGIC_YerKalmazsa_ YerKalmazsa, Tip_Islem_IGIC_Siliniyor Islem_Siliniyor)
{
	if (Kapasite == 0 ||
		AyirmaBirimi_KapladigiAlan_Bayt == 0 ||
		AyirmaBirimi_KapladigiAlan_Bayt > sizeof(Tip_u32) ||
		YerKalmazsa > e_IGIC_YerKalmazsa_TalebiReddet) return Tip_null; //HataliParametre

	struct _s_Depo_ * Yeni = YT_Yeni(sizeof(struct _s_Depo_));
	if (Yeni == Tip_null) return Tip_null;

	Yeni->IGIC = IGIC_Yeni(Kapasite, YerKalmazsa, Islem_Siliniyor);
	if (Yeni->IGIC == Tip_null)
	{
		YT_Sil(Yeni);
		return Tip_null;
	}

	Yeni->AyirmaBirimi_KapladigiAlan_Bayt = AyirmaBirimi_KapladigiAlan_Bayt;
	Yeni->AyirmaBirimi_TamKapasitesi = (1 << (Yeni->AyirmaBirimi_KapladigiAlan_Bayt * 8)) - 1;

	Tip_u32 EnFazla = Kapasite - Yeni->AyirmaBirimi_KapladigiAlan_Bayt;
	if (EnFazla < Yeni->AyirmaBirimi_TamKapasitesi) Yeni->AyirmaBirimi_TamKapasitesi = EnFazla;

	return Yeni;
}
Tip_void Depo_Sil(Tip_Isaretci_Depo Depo)
{
	if (Depo == Tip_null) return;

	IGIC_Sil(_Depo_IGIC_(Depo));
	YT_Sil(Depo);
}

Tip_bool Depo_Bilgi_Ekle(Tip_Isaretci_Depo Depo, Tip_Isaretci OkunacakTampon, Tip_u32 Adet)
{
	if (Depo == Tip_null ||
		OkunacakTampon == Tip_null ||
		Adet == 0 ||
		Adet > _Depo_(Depo)->AyirmaBirimi_TamKapasitesi ) return false; //HataliParametre;
	
	Tip_u32 toplam = Adet + _Depo_(Depo)->AyirmaBirimi_KapladigiAlan_Bayt;
	while (Depo_BosAlan(Depo) < toplam)
	{
		if (_Depo_IGIC_(Depo)->YerKalmazsa == e_IGIC_YerKalmazsa_TalebiReddet) return false; //Bos Yer Yok

		Tip_u32 AnlikAdet = 0;
		Tip_u32 igic_okunan = IGIC_Bilgi_Oku(_Depo_(Depo)->IGIC, &AnlikAdet, _Depo_(Depo)->AyirmaBirimi_KapladigiAlan_Bayt, false);
		if (igic_okunan != _Depo_(Depo)->AyirmaBirimi_KapladigiAlan_Bayt) goto BeklenmeyenDurum;
		AnlikAdet += _Depo_(Depo)->AyirmaBirimi_KapladigiAlan_Bayt;

		if (_Depo_IGIC_(Depo)->Islem_Siliniyor)
		{
			if (!_Depo_IGIC_(Depo)->Islem_Siliniyor(_Depo_IGIC_(Depo), AnlikAdet)) return false; //SilmeIslemiIptalEdildi;
		}

		if (Depo_BosAlan(Depo) < toplam)
		{
			if (IGIC_Bilgi_Oku(_Depo_(Depo)->IGIC, Tip_null, AnlikAdet, true) != AnlikAdet) goto BeklenmeyenDurum;
		}
	} 
	
	if (!IGIC_Bilgi_Ekle(_Depo_(Depo)->IGIC, &Adet, _Depo_(Depo)->AyirmaBirimi_KapladigiAlan_Bayt)) goto BeklenmeyenDurum;
	if (!IGIC_Bilgi_Ekle(_Depo_(Depo)->IGIC, OkunacakTampon, Adet)) goto BeklenmeyenDurum;

	return true;

	BeklenmeyenDurum:
	HataKontrol_Hatali(e_HataKontrol_Hata_Depo);
	return false;
}
Tip_u32 Depo_Bilgi_Oku(Tip_Isaretci_Depo Depo, Tip_Isaretci YazilacakTampon, Tip_u32 TamponKapasitesi)
{
	if (Depo == Tip_null) return 0;
	
	Tip_u32 OkunanAdet = 0;
	while (OkunanAdet < TamponKapasitesi && Depo_DoluAlan(Depo) > 0)
	{
		Tip_u32 AnlikAdet = 0;
		Tip_u32 igic_okunan = IGIC_Bilgi_Oku(_Depo_(Depo)->IGIC, &AnlikAdet, _Depo_(Depo)->AyirmaBirimi_KapladigiAlan_Bayt, false);
		if (igic_okunan != _Depo_(Depo)->AyirmaBirimi_KapladigiAlan_Bayt) goto BeklenmeyenDurum;

		if (OkunanAdet + AnlikAdet > TamponKapasitesi) break;
		
		igic_okunan = IGIC_Bilgi_Oku(_Depo_(Depo)->IGIC, Tip_null, _Depo_(Depo)->AyirmaBirimi_KapladigiAlan_Bayt, true);
		if (igic_okunan != _Depo_(Depo)->AyirmaBirimi_KapladigiAlan_Bayt) goto BeklenmeyenDurum;

		igic_okunan = IGIC_Bilgi_Oku(_Depo_(Depo)->IGIC, (YazilacakTampon ? (Tip_u8 *)YazilacakTampon + OkunanAdet : Tip_null), AnlikAdet, true);
		if (igic_okunan != AnlikAdet) goto BeklenmeyenDurum;

		OkunanAdet += AnlikAdet;
	}
	
	return OkunanAdet;

	BeklenmeyenDurum:
	HataKontrol_Hatali(e_HataKontrol_Hata_Depo);
	return 0;
}
Tip_u32 Depo_Bilgi_SiradakiAdet(Tip_Isaretci_Depo Depo)
{
	if (Depo == Tip_null) return 0;

	Tip_u32 AnlikAdet = 0;
	Tip_u32 igic_okunan = IGIC_Bilgi_Oku(_Depo_(Depo)->IGIC, &AnlikAdet, _Depo_(Depo)->AyirmaBirimi_KapladigiAlan_Bayt, false);
	if (igic_okunan != _Depo_(Depo)->AyirmaBirimi_KapladigiAlan_Bayt) goto BeklenmeyenDurum;

	return AnlikAdet;
	
	BeklenmeyenDurum:
	HataKontrol_Hatali(e_HataKontrol_Hata_Depo);
	return 0;
}

