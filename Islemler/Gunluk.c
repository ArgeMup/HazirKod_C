// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.6
#define _Gunluk_Baslik "Gunluk"
#include "Gunluk.h"

Tip_Sure _Gunluk_An;

Tip_void Gunluk_Baslat()
{
  	Sure_Hemen(_Gunluk_An);
  		
  	Gunluk("\r\n\r\n\r\n");
  	Gunluk("*********************************************************\r\n");
}
Tip_void _Gunluk_Ekle(enum e_Gunluk_Gorunum_ Gorunum, const Tip_char * Baslik, const Tip_char * Sekil, ...)
{
	if ( Baslik == NULL || !Sure_DolduMu(_Gunluk_An) ) return;

	va_list valist;
	va_start(valist, Sekil);

	#ifdef _Gunluk_Tampon_Kapasitesi_Sabit
		Tip_char Yazi[_Gunluk_Tampon_Kapasitesi_Sabit];
		Tip_u32 Kapasite = _Gunluk_Tampon_Kapasitesi_Sabit - 2 /*\r\n*/;
	#else
		Tip_u32 Kapasite = vsnprintf(NULL, 0, Sekil, valist);
		Kapasite += Gorunum == e_Gunluk_Gorunum_Duzyazi ? 0 : 32;
		Kapasite += 12 /*Zaman Damgasi*/ + 32 /*Tahmini Baslik*/ + 2 /*son*/;
		if (Kapasite > _Gunluk_Tampon_Azami_Kapasitesi) Kapasite = _Gunluk_Tampon_Azami_Kapasitesi;
		Tip_char Yazi[Kapasite];
	#endif

	Tip_u16 Konum = 0;

	if (Gorunum != e_Gunluk_Gorunum_Duzyazi)
	{
		Konum += snprintf(&Yazi[Konum], Kapasite - Konum, "\033[1");
		if (Gorunum & 0x0F) Konum += snprintf(&Yazi[Konum], Kapasite - Konum, ";%d", (Gorunum & 0x0F) + 29);
		if (Gorunum & 0xF0) Konum += snprintf(&Yazi[Konum], Kapasite - Konum, ";%d", (Gorunum >> 4) + 39);
		Konum += snprintf(&Yazi[Konum], Kapasite - Konum, "m");
	}

	Konum += snprintf(&Yazi[Konum],  Kapasite - Konum, _Gunluk_Tip_Sure_Sablon " ", An_Simdi());
	Konum += snprintf(&Yazi[Konum],  Kapasite - Konum, "%s ", Baslik);
	Konum += vsnprintf(&Yazi[Konum], Kapasite - Konum, Sekil, valist);

	if (Gorunum != e_Gunluk_Gorunum_Duzyazi) Konum += snprintf(&Yazi[Konum], Kapasite - Konum, "\033[0m");

	Konum += snprintf(&Yazi[Konum],  sizeof(Yazi) - Konum, "\r\n");
	
	va_end(valist);

	_Gunluk_Disari_Aktarma_Islemi(Yazi, Konum);
}
Tip_void _Gunluk_Ekle_Hex(const Tip_char * Baslik, Tip_Isaretci Tampon, Tip_u16 Adet)
{
	if ( Baslik == NULL || !Sure_DolduMu(_Gunluk_An) ) return;

	Tip_char Yazi[256];
	Tip_u16 Kapasite = sizeof(Yazi) - 2 /*\r\n*/;
	Tip_u16 YazdirilanAdet = 0;
	Tip_u16 Konum = 0;
	
	Konum += snprintf(&Yazi[Konum],  Kapasite - Konum, _Gunluk_Tip_Sure_Sablon " ", An_Simdi());
	Konum += snprintf(&Yazi[Konum],  Kapasite - Konum, "%s Adet:%.5d | Hex | Konum | Ascii\r\n", Baslik, Adet);
	_Gunluk_Disari_Aktarma_Islemi(Yazi, Konum);
	
	while (YazdirilanAdet < Adet)
	{
	  	Tip_u16 AnlikAdet = Adet - YazdirilanAdet;
	  	if (AnlikAdet > 16) AnlikAdet = 16; 
		
		Konum = 0;

		Konum += snprintf(&Yazi[Konum],  Kapasite - Konum, _Gunluk_Tip_Sure_Sablon " %s ", An_Simdi(), Baslik);

		for (Tip_u16 i = 0; i < AnlikAdet; i++)
		{
			Konum += snprintf(&Yazi[Konum], Kapasite - Konum, "%.2X ", Isaretci_Icerigi(Tampon, YazdirilanAdet + i, Tip_u8));
		}

		Konum += snprintf(&Yazi[Konum], Kapasite - Konum, "| %.4X - %.4X | ", YazdirilanAdet, YazdirilanAdet + AnlikAdet - 1);

		for (Tip_u16 i = 0; i < AnlikAdet; i++)
		{
			Tip_char siradaki = Isaretci_Icerigi(Tampon, YazdirilanAdet + i, Tip_u8);
			if (!isprint(siradaki)) siradaki = ' ';

			Konum += snprintf(&Yazi[Konum], Kapasite - Konum, "%c", siradaki);
		}

		Konum += snprintf(&Yazi[Konum], sizeof(Yazi) - Konum, "\r\n");
		
		_Gunluk_Disari_Aktarma_Islemi(Yazi, Konum);
		
		YazdirilanAdet += AnlikAdet;
	}
}
Tip_void Gunluk_SureliDurdur(Tip_u32 Saniye)
{	
	HazirKod_C_Gunluk("%d sn boyunca durduruldu", Saniye);
	
	if (Saniye == 0) Sure_Hemen(_Gunluk_An);
	else Sure_Saniye(_Gunluk_An, Saniye);
}
