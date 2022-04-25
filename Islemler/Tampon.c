// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.6

#include "Tampon.h"

#ifdef HazirKod_C_Kullan_Tampon

	Tip_Isaretci_Tampon Tampon_Yeni(Tip_u32 Kapasite, Tip_bool Sifirla)
	{
		Tip_Isaretci_Tampon Yeni = YT_Yeni(sizeof(_Tip_s_Tampon) + Kapasite, false);
		if (Yeni == Tip_null) return Tip_null;

		Yeni->Sayac = 0;
		Yeni->Kapasite = Kapasite;
		Yeni->Isaretci = Isaretci_Konumlandir(Yeni, sizeof(_Tip_s_Tampon), Tip_u8, Tip_void);

		if (Sifirla)
		{
			_Islem_memset_(Yeni->Isaretci, 0, Kapasite);

			#ifdef _Tampon_Sablon_KullaniciNesnesi
				_Islem_memset_(&Yeni->KullaniciNesnesi, 0, sizeof(_Tampon_Sablon_KullaniciNesnesi));
			#endif
		}

		return Yeni;
	}
	Tip_void Tampon_Paketle(Tip_Isaretci_Tampon Tampon)
	{
		if (Tampon == Tip_null) return;

		Tampon->Kapasite = Tampon->Sayac;
		Tampon->Sayac = 0;
	}
	Tip_bool Tampon_Kirp(Tip_Isaretci_Tampon Tampon, Tip_u32 Bastan, Tip_u32 Sondan)
	{
		if (Tampon == Tip_null) return false;

		Tip_u32 toplam = Bastan + Sondan;
		if (toplam > Tampon->Kapasite) return false;

		if (Bastan > 0) Tampon->Isaretci = Isaretci_Konumlandir(Tampon->Isaretci, Bastan, Tip_u8, Tip_void);
		Tampon->Kapasite -= toplam;

		Tampon->Sayac = 0;

		return true;
	}
	Tip_void Tampon_Sil(Tip_Isaretci_Tampon Tampon)
	{
		YT_Sil(Tampon);
	}

	Tip_u32 Tampon_Bilgi_Oku_Konum(Tip_Isaretci_Tampon Tampon, Tip_u32 BaslangicKonumu, Tip_Isaretci Hedef, Tip_u32 HedefKapasitesi)
	{
		if (Tampon == Tip_null) return 0;
		if ( (Tampon->Kapasite - BaslangicKonumu) < HedefKapasitesi) HedefKapasitesi = Tampon->Kapasite - BaslangicKonumu;

		_Islem_memcpy_(Hedef, Isaretci_Konumlandir(Tampon->Isaretci, BaslangicKonumu, Tip_u8, Tip_void), HedefKapasitesi);
		return HedefKapasitesi;
	}
	Tip_bool Tampon_Bilgi_Ekle_Konum(Tip_Isaretci_Tampon Tampon, Tip_u32 BaslangicKonumu, Tip_Isaretci Kaynak, Tip_u32 Adet)
	{
		if (Tampon == Tip_null) return false;
		if ( (Tampon->Kapasite - BaslangicKonumu) < Adet) return false;

		_Islem_memcpy_(Isaretci_Konumlandir(Tampon->Isaretci, BaslangicKonumu, Tip_u8, Tip_void), Kaynak, Adet);
		return true;
	}

	Tip_u32 Tampon_Bilgi_Oku_BaslangictanGecerliKonumaKadar(Tip_Isaretci_Tampon Tampon, Tip_Isaretci Hedef, Tip_u32 HedefKapasitesi)
	{
		Tip_u32 adet = Tampon_Bilgi_Oku_Konum(Tampon, 0, Hedef, HedefKapasitesi);

		if (adet > 0)
		{
			Tampon->Sayac -= adet;
			if (Tampon->Sayac > 0) _Islem_memcpy_(Tampon->Isaretci, Isaretci_Konumlandir(Tampon->Isaretci, adet, Tip_u8, Tip_void), Tampon->Sayac);
		}

		return adet;
	}
	Tip_bool Tampon_Bilgi_Ekle_GecerliKonumdanItibaren(Tip_Isaretci_Tampon Tampon, Tip_Isaretci Kaynak, Tip_u32 Adet)
	{
		Tip_bool sonuc = Tampon_Bilgi_Ekle_Konum(Tampon, Tampon->Sayac, Kaynak, Adet);

		if (sonuc) Tampon->Sayac += Adet;

		return sonuc;
	}

	#ifdef _YT_Tanimli_HEAP_Kutuphanesini_kullanMA

		#ifdef HazirKod_C_Kullan_DeneyselEklentiler

		Tip_void Tampon_Yenile(Tip_Isaretci_Tampon Tampon)
		{
			if (Tampon == Tip_null) return;

			Tampon->Sayac = 0;
				Tampon->Kapasite = YT_Kapasite(Tampon) - sizeof(_Tip_s_Tampon);
				Tampon->Isaretci = Isaretci_Konumlandir(Tampon, sizeof(_Tip_s_Tampon), Tip_u8, Tip_void);
		}

		#endif

	#endif

#endif
