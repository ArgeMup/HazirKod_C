// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.3

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

	Tip_bool Gorev_Islem_Ekle(Tip_Isaretci_Gorev Gorev, Tip_Islem_Gorev Islem, Tip_Isaretci KullaniciNesnesi)
	{
		if (Gorev == Tip_null || Islem == Tip_null) return false;

		_Tip_s_Gorev * Yeni = Liste_Eleman_Ekle_VeYerTahsisEt(Gorev, sizeof(_Tip_s_Gorev), true);
		if (Yeni == Tip_null) return false;

		Yeni->Islem = Islem;
		Yeni->Detaylar.KullaniciNesnesi = KullaniciNesnesi;

		return true;
	}
	Tip_bool Gorev_Islem_MevcutMu(Tip_Isaretci_Gorev Gorev, Tip_Islem_Gorev Islem)
	{
		if (Gorev == Tip_null || Islem == Tip_null) return false;

		Liste_Kuyruk_DegiskeniniOlustur(Gorev, KuyrukDegiskeni);
		while(KuyrukDegiskeni != NULL)
		{
			_Tip_s_Gorev * Eleman = Liste_Kuyruk_SonrakiEleman(Gorev, KuyrukDegiskeni);
			if (Eleman->Islem == Islem) return true;
		}

		return false;
	}
	Tip_void Gorev_Islem_HemenCalistir(Tip_Isaretci_Gorev Gorev, Tip_Islem_Gorev Islem, Tip_u32 Gecikme_msn)
	{
		if (Gorev == Tip_null || Islem == Tip_null) return;

		Liste_Kuyruk_DegiskeniniOlustur(Gorev, KuyrukDegiskeni);
		while(KuyrukDegiskeni != NULL)
		{
			_Tip_s_Gorev * Eleman = Liste_Kuyruk_SonrakiEleman(Gorev, KuyrukDegiskeni);
			if (Eleman->Islem == Islem)
			{
				Eleman->ZamanlamayaMudahaleEt.Gecikme_msn = Gecikme_msn;
				Eleman->ZamanlamayaMudahaleEt.HemenCalistir = true;
				return;
			}
		}
	}

	//Gorev_Calistir islemini cok sik cagirmak islemci yuku olusturur
	//Buradan dondurulen deger kadar milisaniye bekleyip, tekrar cagirmak daha uygundur
	//Eger Gorev_Islem_HemenCalistir islemi kullaniliyorsa, buradan dondurulen deger anlamsizlasir,
	//Mekanizma tahmin disinda uzun bir bekleme suresi ureteceginden HemenCalistirma mumkun olamaz.
	//Bu islemden dondurulen deger sadece liste icerisindeki islemler degerlendirilerek olusturulur
	Tip_u32 Gorev_Calistir(Tip_Isaretci_Gorev Gorev)
	{
		Tip_u32 EnKisaBekleme = (Tip_u32)0 - 1; //azami deger
		
		if (Gorev == Tip_null) return EnKisaBekleme;

		Liste_Kuyruk_DegiskeniniOlustur(Gorev, KuyrukDegiskeni);
		while(KuyrukDegiskeni != NULL)
		{
			_Tip_s_Gorev * Eleman = Liste_Kuyruk_SonrakiEleman(Gorev, KuyrukDegiskeni);

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

				if (ZamanAsimi_msn < 0) Liste_Eleman_Sil(Gorev, Eleman, true);	//Sil
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
