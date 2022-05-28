// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.11
#define _Gunluk_Baslik "Gunluk"
#include "Gunluk.h"

#ifdef HazirKod_C_Kullan_Gunluk

	Tip_Sure _Gunluk_An;

	Tip_void Gunluk_Baslat()
	{
		Sure_Hemen(_Gunluk_An);

		_Gunluk_Disari_Aktarma_Islemi(_Yazdirma_Sablon_SatirSonu _Yazdirma_Sablon_SatirSonu _Yazdirma_Sablon_SatirSonu, (sizeof(_Yazdirma_Sablon_SatirSonu) - 1) * 3);
		_Gunluk_Disari_Aktarma_Islemi("*****************************************************" _Yazdirma_Sablon_SatirSonu, 55);
	}
	Tip_void _Gunluk_Ekle(enum e_Gunluk_Gorunum_ Gorunum, const Tip_char * Baslik _Gunluk_Satir_Numarasinida_Yazdirsin_Islem , const Tip_char * Sekil, ...)
	{
		if ( Baslik == NULL || !Sure_DolduMu(_Gunluk_An) ) return;

		va_list valist;
		if (Sekil) va_start(valist, Sekil);
		Tip_bool Kirpildi = false;

		#ifdef _Gunluk_Tampon_Kapasitesi_Sabit
			Tip_char Yazi[_Gunluk_Tampon_Kapasitesi_Sabit];
			Tip_u32 Kapasite = _Gunluk_Tampon_Kapasitesi_Sabit - (sizeof(_Yazdirma_Sablon_SatirSonu) - 1);
		#else
			Tip_u32 Kapasite = 0;
			if (Sekil) Kapasite = vsnprintf(NULL, 0, Sekil, valist);
			Kapasite += Gorunum == e_Gunluk_Gorunum_Duzyazi ? 0 : 32;
			Kapasite += 12 /*Zaman Damgasi*/ + 32 /*Tahmini Baslik*/ + 2 /*son*/;
			if (Kapasite > _Gunluk_Tampon_Azami_Kapasitesi)
			{
				Kirpildi = true;
				Kapasite = _Gunluk_Tampon_Azami_Kapasitesi;
			}
			Tip_char Yazi[Kapasite];
		#endif

		Tip_u16 Konum = 0;

		if (Gorunum != e_Gunluk_Gorunum_Duzyazi)
		{
			Konum += snprintf(&Yazi[Konum], Kapasite - Konum, "\033[1");
			if (Gorunum & 0x0F) Konum += snprintf(&Yazi[Konum], Kapasite - Konum, ";" _Yazdirma_Sablon_Tip_u8, (Gorunum & 0x0F) + 29);
			if (Gorunum & 0xF0) Konum += snprintf(&Yazi[Konum], Kapasite - Konum, ";" _Yazdirma_Sablon_Tip_u8, (Gorunum >> 4) + 39);
			Konum += snprintf(&Yazi[Konum], Kapasite - Konum, "m");
		}
	
		Tip_char ZamanDamgasiYazisi[24];
		Sure_DegiskeniniOlustur(Zaman_Damgasi);
		Sure_Simdi(Zaman_Damgasi);
		Sure_Yazdir(Zaman_Damgasi, ZamanDamgasiYazisi, sizeof(ZamanDamgasiYazisi));

		Konum += snprintf(&Yazi[Konum],  Kapasite - Konum, _Yazdirma_Sablon_Yazi " ", ZamanDamgasiYazisi);
		Konum += snprintf(&Yazi[Konum],  Kapasite - Konum, _Yazdirma_Sablon_Yazi _Gunluk_Sablon_Satir_Numarasi " " _Yazdirma_Sablon_Yazi, Baslik _Gunluk_Satir_Numarasinida_Yazdirsin_Degisken, ( Kirpildi ? "KIRPILDI " : "" ) );
		if (Sekil) Konum += vsnprintf(&Yazi[Konum], Kapasite - Konum, Sekil, valist);

		if (Gorunum != e_Gunluk_Gorunum_Duzyazi) Konum += snprintf(&Yazi[Konum], Kapasite - Konum, "\033[0m");
	
		Konum += snprintf(&Yazi[Konum],  sizeof(Yazi) - Konum, _Yazdirma_Sablon_SatirSonu);

		if (Sekil) va_end(valist);
	
		_Gunluk_Disari_Aktarma_Islemi(Yazi, Konum);
	}
	Tip_void _Gunluk_Ekle_Hex(const Tip_char * Baslik _Gunluk_Satir_Numarasinida_Yazdirsin_Islem, Tip_Isaretci Tampon, Tip_u16 Adet)
	{
		if ( Baslik == NULL || !Sure_DolduMu(_Gunluk_An) ) return;

		Tip_char Yazi[256];
		Tip_u16 Kapasite = sizeof(Yazi) - (sizeof(_Yazdirma_Sablon_SatirSonu) - 1);
		Tip_u16 YazdirilanAdet = 0;
		Tip_u16 Konum = 0;

		char ZamanDamgasiYazisi[24];
		Sure_DegiskeniniOlustur(Zaman_Damgasi);
		Sure_Simdi(Zaman_Damgasi);
		Sure_Yazdir(Zaman_Damgasi, ZamanDamgasiYazisi, sizeof(ZamanDamgasiYazisi));

		Konum += snprintf(&Yazi[Konum],  Kapasite - Konum, _Yazdirma_Sablon_Yazi " ", ZamanDamgasiYazisi);
		Konum += snprintf(&Yazi[Konum],  Kapasite - Konum, _Yazdirma_Sablon_Yazi _Gunluk_Sablon_Satir_Numarasi " Adet:" _Yazdirma_Sablon_Tip_u16 " | Hex | Konum | Ascii" _Yazdirma_Sablon_SatirSonu, Baslik _Gunluk_Satir_Numarasinida_Yazdirsin_Degisken, Adet);
		_Gunluk_Disari_Aktarma_Islemi(Yazi, Konum);
		
		while (YazdirilanAdet < Adet)
		{
			Tip_u16 AnlikAdet = Adet - YazdirilanAdet;
			if (AnlikAdet > 16) AnlikAdet = 16;

			Konum = 0;

			Konum += snprintf(&Yazi[Konum],  Kapasite - Konum, _Yazdirma_Sablon_Yazi " " _Yazdirma_Sablon_Yazi _Gunluk_Sablon_Satir_Numarasi " ", ZamanDamgasiYazisi, Baslik _Gunluk_Satir_Numarasinida_Yazdirsin_Degisken);

			for (Tip_u16 i = 0; i < AnlikAdet; i++)
			{
				Konum += snprintf(&Yazi[Konum], Kapasite - Konum, _Yazdirma_Sablon_Hex " ", Isaretci_Icerigi(Tampon, YazdirilanAdet + i, Tip_u8, Tip_u8));
			}

			Konum += snprintf(&Yazi[Konum], Kapasite - Konum, "| " _Yazdirma_Sablon_Hex_Tip_16 " - " _Yazdirma_Sablon_Hex_Tip_16 " | ", YazdirilanAdet, YazdirilanAdet + AnlikAdet - 1);

			for (Tip_u16 i = 0; i < AnlikAdet; i++)
			{
				Tip_char siradaki = Isaretci_Icerigi(Tampon, YazdirilanAdet + i, Tip_u8, Tip_char);
				if (!isprint(siradaki)) siradaki = ' ';

				Konum += snprintf(&Yazi[Konum], Kapasite - Konum, _Yazdirma_Sablon_Tip_char, siradaki);
			}

			Konum += snprintf(&Yazi[Konum], sizeof(Yazi) - Konum, _Yazdirma_Sablon_SatirSonu);

			_Gunluk_Disari_Aktarma_Islemi(Yazi, Konum);

			YazdirilanAdet += AnlikAdet;
		}
	}
	Tip_void Gunluk_SureliDurdur(Tip_u32 Saniye)
	{
		HazirKod_C_Gunluk(_Yazdirma_Sablon_Tip_u32 " sn boyunca durduruldu", Saniye);
		
		if (Saniye == 0) Sure_Hemen(_Gunluk_An);
		else Sure_Saniye(_Gunluk_An, Saniye);
	}

#endif
