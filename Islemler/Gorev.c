// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.7

#include "Gorev.h"

#ifdef HazirKod_C_Kullan_Gorev

	//ZamanAsimi_msn  < 0 Gorevi sil
	//ZamanAsimi_msn == 0 Gorevi hemen calisacak sekilde kur
	//ZamanAsimi_msn  > 0 Gorevi msn sonra calistir

	typedef struct
	{
		_Tip_s_Gorev_Detaylar Detaylar;
		Tip_Islem_Gorev Islem;
		struct
		{
			Tip_bool HemenCalistir;
			Tip_u32 Gecikme_msn;
		} ZamanlamayaMudahaleEt;
	} _Tip_s_Gorev;

	Tip_bool Gorev_Islem_Ekle(Tip_Isaretci_Gorev Gorev, Tip_Islem_Gorev Islem _Gorev_Sablon_KullaniciNesnesi_Islem)
	{
		if (Gorev == Tip_null || Islem == Tip_null) return false;

		_Tip_s_Gorev * Yeni = Dizi_Eleman_Ekle_VeYerTahsisEt(Gorev, sizeof(_Tip_s_Gorev), true);
		if (Yeni == Tip_null) return false;

		Yeni->Islem = Islem;

		#ifdef _Gorev_Sablon_KullaniciNesnesi
			Yeni->Detaylar.KullaniciNesnesi = KullaniciNesnesi;
		#endif

		return true;
	}
	Tip_bool Gorev_Islem_MevcutMu(Tip_Isaretci_Gorev Gorev, Tip_Islem_Gorev Islem _Gorev_Sablon_KullaniciNesnesi_Islem)
	{
		if (Gorev == Tip_null || Islem == Tip_null) return false;

		for (Tip_u32 i = 0; i < Dizi_Eleman_Sayisi(Gorev); i++)
		{
			_Tip_s_Gorev * Eleman = Dizi_Elemani(Gorev, i);
			if (Eleman->Islem == Islem)
			{
				#ifdef _Gorev_Sablon_KullaniciNesnesi
					if (KullaniciNesnesi == NULL) return true;
					else if (KullaniciNesnesi == Eleman->Detaylar.KullaniciNesnesi) return true;
				#else
					return true;
				#endif
			}
		}

		return false;
	}
	Tip_void Gorev_Islem_HemenCalistir(Tip_Isaretci_Gorev Gorev, Tip_Islem_Gorev Islem _Gorev_Sablon_KullaniciNesnesi_Islem, Tip_u32 Gecikme_msn)
	{
		if (Gorev == Tip_null || Islem == Tip_null) return;

		for (Tip_u32 i = 0; i < Dizi_Eleman_Sayisi(Gorev); i++)
		{
			_Tip_s_Gorev * Eleman = Dizi_Elemani(Gorev, i);
			if (Eleman->Islem == Islem)
			{
				#ifdef _Gorev_Sablon_KullaniciNesnesi
					bool UzerindeCalistir = false;
					if (KullaniciNesnesi == NULL) UzerindeCalistir = true;
					else if (KullaniciNesnesi == Eleman->Detaylar.KullaniciNesnesi) UzerindeCalistir = true;

					if (UzerindeCalistir)
					{
				#endif
						Eleman->ZamanlamayaMudahaleEt.Gecikme_msn = Gecikme_msn;
						Eleman->ZamanlamayaMudahaleEt.HemenCalistir = true;
				#ifdef _Gorev_Sablon_KullaniciNesnesi
					}
				#endif
			}
		}
	}

	//Gorev_Calistir islemini cok sik cagirmak islemci yuku olusturur
	//Buradan dondurulen deger kadar milisaniye bekleyip, tekrar cagirmak daha uygundur
	//Eger Gorev_Islem_HemenCalistir islemi kullaniliyorsa, buradan dondurulen deger anlamsizlasir,
	//Mekanizma tahmin disinda uzun bir bekleme suresi ureteceginden HemenCalistirma mumkun olamaz.
	//Bu islemden dondurulen deger sadece dizi icerisindeki islemler degerlendirilerek olusturulur
	Tip_u32 Gorev_Calistir(Tip_Isaretci_Gorev Gorev)
	{
		Tip_u32 EnKisaBekleme = (Tip_u32)0 - 1; //azami deger
		
		if (Gorev == Tip_null) return EnKisaBekleme;

		for (Tip_u32 i = 0; i < Dizi_Eleman_Sayisi(Gorev); i++)
		{
			_Tip_s_Gorev * Eleman = Dizi_Elemani(Gorev, i);

			Tip_bool Calistir = false;

			if (Eleman->ZamanlamayaMudahaleEt.HemenCalistir)
			{
				Eleman->ZamanlamayaMudahaleEt.HemenCalistir = false;

				if (Eleman->ZamanlamayaMudahaleEt.Gecikme_msn > 0)
				{
					Sure_MiliSaniye(Eleman->Detaylar.An, Eleman->ZamanlamayaMudahaleEt.Gecikme_msn);

					if (Eleman->ZamanlamayaMudahaleEt.Gecikme_msn < EnKisaBekleme) EnKisaBekleme = Eleman->ZamanlamayaMudahaleEt.Gecikme_msn;
				}
				else Calistir = true;
			}
			else
			{
				Tip_u32 KalanSure = Sure_KalanSure_MiliSaniye(Eleman->Detaylar.An);

				if (KalanSure > 0)
				{
					if (KalanSure < EnKisaBekleme) EnKisaBekleme = KalanSure;
				}
				else Calistir = true;
			}

			if (Calistir)
			{
				Tip_i32 ZamanAsimi_msn = Eleman->Islem(&Eleman->Detaylar);

				if (ZamanAsimi_msn < 0) Dizi_Eleman_Sil(Gorev, i, true);		//Sil
				else
				{
					Sure_MiliSaniye(Eleman->Detaylar.An, ZamanAsimi_msn);		//Kur

					if (ZamanAsimi_msn < EnKisaBekleme) EnKisaBekleme = ZamanAsimi_msn;
				}
			}
		}

		return EnKisaBekleme;
	}

#endif
