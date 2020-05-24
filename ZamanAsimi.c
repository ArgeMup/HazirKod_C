// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.1

#include "ZamanAsimi.h"

#if ZamanAsimi_AcKapat_CokluZamanlayici == 0
struct s_ZamanAsimi_ _ZamanAsimi_IcKullanim_;
struct s_ZamanAsimi_ * ZamanAsimi = &_ZamanAsimi_IcKullanim_;
#endif

void ZamanAsimi_Baslat(ZamanAsimi_Parametre_1)
{
	ZamanAsimi->_IcKullanim_.An.MiliSaniye_Dusuk = 0;
	
	#if ZamanAsimi_AcKapat_8Bayt	
	ZamanAsimi->_IcKullanim_.An.MiliSaniye_Yuksek = 0;
	#endif	
	
	#if ZamanAsimi_AcKapat_Gorev_Adet	
	for (_Ortak_Tip_uint16_t_ i = 0; i < ZamanAsimi_AcKapat_Gorev_Adet; i++)
	{
		ZamanAsimi->_IcKullanim_.Gorevler[i].Islem = _Ortak_Tip_null_;
	}
	#endif	
}
void ZamanAsimi_Baslat_An(ZamanAsimi_Parametre_2 struct s_ZamanAsimi_An_ * An)
{
  	An->ZamanAsimi = ZamanAsimi;
}

#if ZamanAsimi_AcKapat_Gorev_Adet
_Ortak_Tip_Isaretci_ ZamanAsimi_Gorev_Ekle(ZamanAsimi_Parametre_2 struct s_Gorev_ Gorev)
{
  	if (Gorev.Islem == _Ortak_Tip_null_) return _Ortak_Tip_null_;   
	
	for (_Ortak_Tip_uint16_t_ i = 0; i < ZamanAsimi_AcKapat_Gorev_Adet; i++)
	{
	  	if (ZamanAsimi->_IcKullanim_.Gorevler[i].Islem == _Ortak_Tip_null_)
		{
			ZamanAsimi_Gorev_Duzenle(&ZamanAsimi->_IcKullanim_.Gorevler[i], Gorev);
			ZamanAsimi->_IcKullanim_.Gorevler[i].Islem = Gorev.Islem;
			ZamanAsimi->_IcKullanim_.Gorevler[i]._IcKullanim_.An.ZamanAsimi = ZamanAsimi;
			return &ZamanAsimi->_IcKullanim_.Gorevler[i];
		}
	}
	
	return _Ortak_Tip_null_;
}
void ZamanAsimi_Gorev_Sil(_Ortak_Tip_Isaretci_ Tutacak)
{
  	((struct s_Gorev_ *)Tutacak)->Islem = _Ortak_Tip_null_;
}
void ZamanAsimi_Gorev_Duzenle(_Ortak_Tip_Isaretci_ Tutacak, struct s_Gorev_ Gorev)
{
	((struct s_Gorev_ *)Tutacak)->Durum = Gorev.Durum;
	((struct s_Gorev_ *)Tutacak)->Hatirlatici = Gorev.Hatirlatici;
	((struct s_Gorev_ *)Tutacak)->CalismaAdedi = Gorev.CalismaAdedi;
	((struct s_Gorev_ *)Tutacak)->Aralik_MiliSaniye = Gorev.Aralik_MiliSaniye; 
	
	ZamanAsimi_Kur_MiliSaniye(&(((struct s_Gorev_ *)Tutacak)->_IcKullanim_.An), Gorev.Aralik_MiliSaniye, false);
}
void ZamanAsimi_Gorevler_Calistir(ZamanAsimi_Parametre_1)
{
	for (_Ortak_Tip_uint16_t_ i = 0; i < ZamanAsimi_AcKapat_Gorev_Adet; i++)
	{
	  	if (ZamanAsimi->_IcKullanim_.Gorevler[i].Islem == _Ortak_Tip_null_) continue;
		if (ZamanAsimi->_IcKullanim_.Gorevler[i].Durum == e_Gorev_Durum_Durdur) continue;
		if (ZamanAsimi->_IcKullanim_.Gorevler[i].Durum == e_Gorev_Durum_AdetliCalistir && ZamanAsimi->_IcKullanim_.Gorevler[i].CalismaAdedi == 0) continue;
		if (!ZamanAsimi_OlduMu(&ZamanAsimi->_IcKullanim_.Gorevler[i]._IcKullanim_.An)) continue; 
		
		_Ortak_Tip_uint32_t_ Gecikme = ZamanAsimi->_IcKullanim_.Gorevler[i].Islem(&ZamanAsimi->_IcKullanim_.Gorevler[i]);
		
		switch(ZamanAsimi->_IcKullanim_.Gorevler[i].Durum)
		{
		case e_Gorev_Durum_AdetliCalistir:
		  	if (ZamanAsimi->_IcKullanim_.Gorevler[i].CalismaAdedi > 0) ZamanAsimi->_IcKullanim_.Gorevler[i].CalismaAdedi--;
		case e_Gorev_Durum_SurekliCalistir:	
			break;
			
		case e_Gorev_Durum_Sil:
		  	ZamanAsimi->_IcKullanim_.Gorevler[i].Islem = _Ortak_Tip_null_;
		case e_Gorev_Durum_Durdur:	
			continue;
		}
		
		//Gecikme=0:Gecerli sureyi, Gecikme>0:Bu seferlik yeni sureyi kullan
		if (Gecikme == 0) Gecikme = ZamanAsimi->_IcKullanim_.Gorevler[i].Aralik_MiliSaniye;
		ZamanAsimi_Kur_MiliSaniye(&ZamanAsimi->_IcKullanim_.Gorevler[i]._IcKullanim_.An, Gecikme, false);
	}
}
#endif

////////////////////////////////////////////////////////////////////
// Zaman asimini ayarla, hemen geri d�n
////////////////////////////////////////////////////////////////////

void ZamanAsimi_Kur_MiliSaniye(struct s_ZamanAsimi_An_ * An, _Ortak_Tip_uint32_t_ Sure, _Ortak_Tip_bool_ UstuneEkle)
{
  	if (!UstuneEkle)
	{
		An->MiliSaniye_Dusuk = 0;

		#if ZamanAsimi_AcKapat_8Bayt
		An->MiliSaniye_Yuksek = 0;
		#endif
	}
  
	An->MiliSaniye_Dusuk += Sure;
	
	#if ZamanAsimi_AcKapat_8Bayt
	if (Sure > An->MiliSaniye_Dusuk) An->MiliSaniye_Yuksek += 1;
	#endif
	
	if (!UstuneEkle)
	{
		An->MiliSaniye_Dusuk += An->ZamanAsimi->_IcKullanim_.An.MiliSaniye_Dusuk;
		
		#if ZamanAsimi_AcKapat_8Bayt
		if (An->ZamanAsimi->_IcKullanim_.An.MiliSaniye_Dusuk > An->MiliSaniye_Dusuk) An->MiliSaniye_Yuksek += 1;
		#endif
	}
}

#if ZamanAsimi_AcKapat_Kur_Saniye
void ZamanAsimi_Kur_Saniye(struct s_ZamanAsimi_An_ * An, _Ortak_Tip_uint32_t_ Sure, _Ortak_Tip_bool_ UstuneEkle)
{
  	if (!UstuneEkle)
	{
		An->MiliSaniye_Dusuk = 0;
		
		#if ZamanAsimi_AcKapat_8Bayt
		An->MiliSaniye_Yuksek = 0;
		#endif
	}

  	const _Ortak_Tip_uint32_t_ Katsayi = 1000 /*mili saniye*/;
	const _Ortak_Tip_uint32_t_ UstDeger = 0xFFFFFFFF / Katsayi ;
	
	while (Sure > 0)
	{
		_Ortak_Tip_uint32_t_ gecici = Sure;
		if (gecici > UstDeger) gecici = UstDeger;
		
		ZamanAsimi_Kur_MiliSaniye(An, gecici * Katsayi, true);
		Sure -= gecici;
	}
	
	if (!UstuneEkle)
	{
		An->MiliSaniye_Dusuk += An->ZamanAsimi->_IcKullanim_.An.MiliSaniye_Dusuk;
		
		#if ZamanAsimi_AcKapat_8Bayt
		if (An->ZamanAsimi->_IcKullanim_.An.MiliSaniye_Dusuk > An->MiliSaniye_Dusuk) An->MiliSaniye_Yuksek += 1;
		#endif
	}
}
#if ZamanAsimi_AcKapat_Kur_Dakika
void ZamanAsimi_Kur_Dakika(struct s_ZamanAsimi_An_ * An, _Ortak_Tip_uint32_t_ Sure, _Ortak_Tip_bool_ UstuneEkle)
{
  	if (!UstuneEkle)
	{
		An->MiliSaniye_Dusuk = 0;
		
		#if ZamanAsimi_AcKapat_8Bayt
		An->MiliSaniye_Yuksek = 0;
		#endif
	}

	const _Ortak_Tip_uint32_t_ Katsayi = 60 /*saniye*/;
	const _Ortak_Tip_uint32_t_ UstDeger = 0xFFFFFFFF / Katsayi ;
	
	while (Sure > 0)
	{
		_Ortak_Tip_uint32_t_ gecici = Sure;
		if (gecici > UstDeger) gecici = UstDeger;
		
		ZamanAsimi_Kur_Saniye(An, gecici * Katsayi, true);
		Sure -= gecici;
	}
	
	if (!UstuneEkle)
	{
		An->MiliSaniye_Dusuk += An->ZamanAsimi->_IcKullanim_.An.MiliSaniye_Dusuk;
		
		#if ZamanAsimi_AcKapat_8Bayt
		if (An->ZamanAsimi->_IcKullanim_.An.MiliSaniye_Dusuk > An->MiliSaniye_Dusuk) An->MiliSaniye_Yuksek += 1;
		#endif
	}
}
#if ZamanAsimi_AcKapat_Kur_Saat
void ZamanAsimi_Kur_Saat(struct s_ZamanAsimi_An_ * An, _Ortak_Tip_uint32_t_ Sure, _Ortak_Tip_bool_ UstuneEkle)
{
  	if (!UstuneEkle)
	{
		An->MiliSaniye_Dusuk = 0;
		
		#if ZamanAsimi_AcKapat_8Bayt
		An->MiliSaniye_Yuksek = 0;
		#endif
	}

	const _Ortak_Tip_uint32_t_ Katsayi = 60 /*dakika*/;
	const _Ortak_Tip_uint32_t_ UstDeger = 0xFFFFFFFF / Katsayi ;
	
	while (Sure > 0)
	{
		_Ortak_Tip_uint32_t_ gecici = Sure;
		if (gecici > UstDeger) gecici = UstDeger;
		
		ZamanAsimi_Kur_Dakika(An, gecici * Katsayi, true);
		Sure -= gecici;
	}
	
	if (!UstuneEkle)
	{
		An->MiliSaniye_Dusuk += An->ZamanAsimi->_IcKullanim_.An.MiliSaniye_Dusuk;
		
		#if ZamanAsimi_AcKapat_8Bayt
		if (An->ZamanAsimi->_IcKullanim_.An.MiliSaniye_Dusuk > An->MiliSaniye_Dusuk) An->MiliSaniye_Yuksek += 1;
		#endif
	}
}
#if ZamanAsimi_AcKapat_Kur_Gun
void ZamanAsimi_Kur_Gun(struct s_ZamanAsimi_An_ * An, _Ortak_Tip_uint32_t_ Sure, _Ortak_Tip_bool_ UstuneEkle)
{
  	if (!UstuneEkle)
	{
		An->MiliSaniye_Dusuk = 0;
		
		#if ZamanAsimi_AcKapat_8Bayt
		An->MiliSaniye_Yuksek = 0;
		#endif
	}

	const _Ortak_Tip_uint32_t_ Katsayi = 24 /*saat*/;
	const _Ortak_Tip_uint32_t_ UstDeger = 0xFFFFFFFF / Katsayi ;
	
	while (Sure > 0)
	{
		_Ortak_Tip_uint32_t_ gecici = Sure;
		if (gecici > UstDeger) gecici = UstDeger;
		
		ZamanAsimi_Kur_Saat(An, gecici * Katsayi, true);
		Sure -= gecici;
	}
	
	if (!UstuneEkle)
	{
		An->MiliSaniye_Dusuk += An->ZamanAsimi->_IcKullanim_.An.MiliSaniye_Dusuk;
		
		#if ZamanAsimi_AcKapat_8Bayt
		if (An->ZamanAsimi->_IcKullanim_.An.MiliSaniye_Dusuk > An->MiliSaniye_Dusuk) An->MiliSaniye_Yuksek += 1;
		#endif
	}
}
#if ZamanAsimi_AcKapat_Kur_Hafta
void ZamanAsimi_Kur_Hafta(struct s_ZamanAsimi_An_ * An, _Ortak_Tip_uint32_t_ Sure, _Ortak_Tip_bool_ UstuneEkle)
{
  	if (!UstuneEkle)
	{
		An->MiliSaniye_Dusuk = 0;
		
		#if ZamanAsimi_AcKapat_8Bayt
		An->MiliSaniye_Yuksek = 0;
		#endif
	}

	const _Ortak_Tip_uint32_t_ Katsayi = 7 /*gun*/;
	const _Ortak_Tip_uint32_t_ UstDeger = 0xFFFFFFFF / Katsayi ;
	
	while (Sure > 0)
	{
		_Ortak_Tip_uint32_t_ gecici = Sure;
		if (gecici > UstDeger) gecici = UstDeger;
		
		ZamanAsimi_Kur_Gun(An, gecici * Katsayi, true);
		Sure -= gecici;
	}
	
	if (!UstuneEkle)
	{
		An->MiliSaniye_Dusuk += An->ZamanAsimi->_IcKullanim_.An.MiliSaniye_Dusuk;
		
		#if ZamanAsimi_AcKapat_8Bayt
		if (An->ZamanAsimi->_IcKullanim_.An.MiliSaniye_Dusuk > An->MiliSaniye_Dusuk) An->MiliSaniye_Yuksek += 1;
		#endif
	}
}
#if ZamanAsimi_AcKapat_Kur_Yil
void ZamanAsimi_Kur_Yil(struct s_ZamanAsimi_An_ * An, _Ortak_Tip_uint32_t_ Sure, _Ortak_Tip_bool_ UstuneEkle)
{
  	if (!UstuneEkle)
	{
		An->MiliSaniye_Dusuk = 0;
		
		#if ZamanAsimi_AcKapat_8Bayt
		An->MiliSaniye_Yuksek = 0;
		#endif
	}

	const _Ortak_Tip_uint32_t_ Katsayi = 365 /*gun*/;
	const _Ortak_Tip_uint32_t_ UstDeger = 0xFFFFFFFF / Katsayi ;
	
	while (Sure > 0)
	{
		_Ortak_Tip_uint32_t_ gecici = Sure;
		if (gecici > UstDeger) gecici = UstDeger;
		
		ZamanAsimi_Kur_Gun(An, gecici * Katsayi, true);
		Sure -= gecici;
	}
	
	if (!UstuneEkle)
	{
		An->MiliSaniye_Dusuk += An->ZamanAsimi->_IcKullanim_.An.MiliSaniye_Dusuk;
		
		#if ZamanAsimi_AcKapat_8Bayt
		if (An->ZamanAsimi->_IcKullanim_.An.MiliSaniye_Dusuk > An->MiliSaniye_Dusuk) An->MiliSaniye_Yuksek += 1;
		#endif
	}
}
#endif
#endif
#endif
#endif
#endif
#endif

_Ortak_Tip_bool_ ZamanAsimi_OlduMu(struct s_ZamanAsimi_An_ * An)
{
	if (An->ZamanAsimi->SayaciGuncelle) An->ZamanAsimi->SayaciGuncelle(&An->ZamanAsimi->_IcKullanim_.An, An->ZamanAsimi->Hatirlatici);
	
	#if ZamanAsimi_AcKapat_8Bayt
	if (An->MiliSaniye_Yuksek <= An->ZamanAsimi->_IcKullanim_.An.MiliSaniye_Yuksek)
	{
	#endif
	  
		if (An->MiliSaniye_Dusuk <= An->ZamanAsimi->_IcKullanim_.An.MiliSaniye_Dusuk) return true;
		
	#if ZamanAsimi_AcKapat_8Bayt
	}
	#endif
	
	return false;
}
void ZamanAsimi_SayaciIlerlet(ZamanAsimi_Parametre_2 _Ortak_Tip_uint32_t_ MiliSaniye)
{
	ZamanAsimi->_IcKullanim_.An.MiliSaniye_Dusuk += MiliSaniye;
	
	#if ZamanAsimi_AcKapat_8Bayt
	if (MiliSaniye > ZamanAsimi->_IcKullanim_.An.MiliSaniye_Dusuk) ZamanAsimi->_IcKullanim_.An.MiliSaniye_Yuksek++;
	#endif
}

////////////////////////////////////////////////////////////////////
// Zaman asimini ayarla, surenin dolmas�n� bekle
////////////////////////////////////////////////////////////////////

void ZamanAsimi_Bekle_MiliSaniye(ZamanAsimi_Parametre_2 _Ortak_Tip_uint32_t_ Sure)
{
  	struct s_ZamanAsimi_An_ An;
	ZamanAsimi_Baslat_An(ZamanAsimi_Parametre_3 &An);
	
	ZamanAsimi_Kur_MiliSaniye(&An, Sure, false);
	
	while (!ZamanAsimi_OlduMu(&An));
}
#if ZamanAsimi_AcKapat_Kur_Saniye
void ZamanAsimi_Bekle_Saniye(ZamanAsimi_Parametre_2 _Ortak_Tip_uint32_t_ Sure)
{
  	struct s_ZamanAsimi_An_ An;
	ZamanAsimi_Baslat_An(ZamanAsimi_Parametre_3 &An);
	
	ZamanAsimi_Kur_Saniye(&An, Sure, false);
	
	while (!ZamanAsimi_OlduMu(&An));
}
#endif