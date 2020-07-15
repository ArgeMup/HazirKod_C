// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.3

#define YAZDIR_BASLIK "Gunluk.c"
#include "Gunluk.h"
/////////////////////////////////////////////////////////////////////////////
//#define YAZDIR_BASLIK "Deneme.c" her dosyada ayri ayri tanimlanmali
/////////////////////////////////////////////////////////////////////////////

Tip_Sure _Gunluk_An;

Tip_void Gunluk_Baslat()
{
  	Sure_Hemen(_Gunluk_An);
  		
  	Gunluk_Ekle(YAZDIR_BASLIK, "%s", "\r\n\r\n\r\n");
  	Gunluk_Ekle(YAZDIR_BASLIK, "%s", "*********************************************************\r\n");
}
Tip_void Gunluk_Ekle(const Tip_char * Baslik, const Tip_char * Sekil, ...)
{
	if (!Sure_DolduMu(_Gunluk_An)) return;

	va_list valist;
	va_start(valist, Sekil);

	Tip_char Yazi[256];
	Tip_u16 Konum = 0;
	Konum += snprintf(&Yazi[Konum],  (sizeof(Yazi) - 2) - Konum, "%lu ", An_Simdi());
	Konum += snprintf(&Yazi[Konum],  (sizeof(Yazi) - 2) - Konum, "%s ", Baslik);
	Konum += vsnprintf(&Yazi[Konum], (sizeof(Yazi) - 2) - Konum, Sekil, valist);
	Konum += snprintf(&Yazi[Konum],  (sizeof(Yazi) - 0) - Konum, "\r\n");
	
	va_end(valist);

	_Gunluk_Disari_Aktarma_Islemi(Yazi, Konum);
}
Tip_void Gunluk_Ekle_Hex(const Tip_char * Baslik, Tip_Isaretci Tampon, Tip_u16 Adet)
{
	if (!Sure_DolduMu(_Gunluk_An)) return;

	Tip_char Yazi[256];
	Tip_u16 YazdirilanAdet = 0;
	Tip_u16 Konum = 0;
	
	Konum += snprintf(&Yazi[Konum],  (sizeof(Yazi) - 2) - Konum, "%lu ", An_Simdi());
	Konum += snprintf(&Yazi[Konum],  (sizeof(Yazi) - 2) - Konum, "%s Adet:%.5d | Hex | Konum | Ascii\r\n", Baslik, Adet);
	_Gunluk_Disari_Aktarma_Islemi(Yazi, Konum);
	
	while (YazdirilanAdet < Adet)
	{
	  	Tip_u16 AnlikAdet = Adet - YazdirilanAdet;
	  	if (AnlikAdet > 16) AnlikAdet = 16; 
		
		Konum = 0;

		Konum += snprintf(&Yazi[Konum],  (sizeof(Yazi) - 2) - Konum, "%lu %s ", An_Simdi(), Baslik);

		for (Tip_u16 i = 0; i < AnlikAdet; i++)
		{
			Konum += snprintf(&Yazi[Konum], sizeof(Yazi) - Konum, "%.2X ", Isaretci_Icerigi(Tampon, YazdirilanAdet + i, Tip_u8));
		}
		Konum += snprintf(&Yazi[Konum], sizeof(Yazi) - Konum, "| %.4X - %.4X | ", YazdirilanAdet, YazdirilanAdet + AnlikAdet - 1);
		for (Tip_u16 i = 0; i < AnlikAdet; i++)
		{
			Tip_char siradaki = Isaretci_Icerigi(Tampon, YazdirilanAdet + i, Tip_u8);
			if (!isprint(siradaki)) siradaki = ' ';
			Konum += snprintf(&Yazi[Konum], sizeof(Yazi) - Konum, "%c", siradaki);
		}
		Konum += snprintf(&Yazi[Konum], sizeof(Yazi) - Konum, "\r\n");
		
		_Gunluk_Disari_Aktarma_Islemi(Yazi, Konum);
		
		YazdirilanAdet += AnlikAdet;
	}
}
Tip_void Gunluk_SureliDurdur(Tip_u32 Saniye)
{	
	//Gunluk_Ekle(YAZDIR_BASLIK, "%d sn boyunca durduruldu", Saniye);
	if (Saniye == 0) Sure_Hemen(_Gunluk_An);
	else Sure_Saniye(_Gunluk_An, Saniye);
}
