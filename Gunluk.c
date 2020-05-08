// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.1

#define YAZDIR_BASLIK "Gunluk.c"
#include "Gunluk.h"
/////////////////////////////////////////////////////////////////////////////
//#define YAZDIR_BASLIK "Deneme.c" her dosyada ayri ayri tanimlanmali
/////////////////////////////////////////////////////////////////////////////

_An_Tip_ Gunluk_An;

_Ortak_Tip_weak_ void Gunluk_Disari_Aktarma_Islemi(_Ortak_Tip_Isaretci_ Tampon, _Ortak_Tip_uint16_t_ Adet)
{
	(void)Tampon;
	(void)Adet;
}

void Gunluk_Baslat()
{
  	Sure_Hemen(Gunluk_An);
  		
  	Gunluk_Ekle(YAZDIR_BASLIK, "%s", "\r\n\r\n\r\n");
  	Gunluk_Ekle(YAZDIR_BASLIK, "%s", "*********************************************************\r\n");
}
void Gunluk_Ekle(const _Ortak_Tip_char_ * Baslik, const _Ortak_Tip_char_ * Metin, ...)
{
	if (!Sure_DolduMu(Gunluk_An)) return;

	va_list valist;
	va_start(valist, Metin);

	char Yazi[256];
	_Ortak_Tip_uint16_t_ Konum = 0;
	Konum += snprintf(&Yazi[Konum],  (sizeof(Yazi) - 2) - Konum, "%lu ", An_Simdi());
	Konum += snprintf(&Yazi[Konum],  (sizeof(Yazi) - 2) - Konum, "%s ", Baslik);
	Konum += vsnprintf(&Yazi[Konum], (sizeof(Yazi) - 2) - Konum, Metin, valist);
	Konum += snprintf(&Yazi[Konum],  (sizeof(Yazi) - 0) - Konum, "\r\n");
	
	va_end(valist);

	Gunluk_Disari_Aktarma_Islemi(Yazi, Konum);
}
void Gunluk_Ekle_Hex(const _Ortak_Tip_char_ * Baslik, _Ortak_Tip_Isaretci_ Tampon, _Ortak_Tip_uint16_t_ Adet)
{
	if (!Sure_DolduMu(Gunluk_An)) return;

	char Yazi[256];
	_Ortak_Tip_uint16_t_ YazdirilanAdet = 0;
	_Ortak_Tip_uint16_t_ Konum = 0;
	
	Konum += snprintf(&Yazi[Konum],  (sizeof(Yazi) - 2) - Konum, "%lu ", An_Simdi());
	Konum += snprintf(&Yazi[Konum],  (sizeof(Yazi) - 2) - Konum, "%s Adet:%.5d | Hex | Konum | Ascii\r\n", Baslik, Adet);
	Gunluk_Disari_Aktarma_Islemi(Yazi, Konum);
	
	while (YazdirilanAdet < Adet)
	{
	  	_Ortak_Tip_uint16_t_ AnlikAdet = Adet - YazdirilanAdet;
	  	if (AnlikAdet > 16) AnlikAdet = 16; 
		
		Konum = 0;

		Konum += snprintf(&Yazi[Konum],  (sizeof(Yazi) - 2) - Konum, "%lu %s ", An_Simdi(), Baslik);

		for (_Ortak_Tip_uint16_t_ i = 0; i < AnlikAdet; i++)
		{
			Konum += snprintf(&Yazi[Konum], sizeof(Yazi) - Konum, "%.2X ", *((_Ortak_Tip_uint8_t_ *)((_Ortak_Tip_uint32_t_)Tampon + YazdirilanAdet + i)));
		}
		Konum += snprintf(&Yazi[Konum], sizeof(Yazi) - Konum, "| %.4X - %.4X | ", YazdirilanAdet, YazdirilanAdet + AnlikAdet - 1);
		for (_Ortak_Tip_uint16_t_ i = 0; i < AnlikAdet; i++)
		{
			char siradaki = (_Ortak_Tip_char_)(*((_Ortak_Tip_uint8_t_ *)((_Ortak_Tip_uint32_t_)Tampon + YazdirilanAdet + i)));
			if (!isprint(siradaki)) siradaki = ' ';
			Konum += snprintf(&Yazi[Konum], sizeof(Yazi) - Konum, "%c", siradaki);
		}
		Konum += snprintf(&Yazi[Konum], sizeof(Yazi) - Konum, "\r\n");
		
		Gunluk_Disari_Aktarma_Islemi(Yazi, Konum);
		
		YazdirilanAdet += AnlikAdet;
	}
}
void Gunluk_SureliDurdur(_Ortak_Tip_uint32_t_ Saniye)
{	
	Gunluk_Ekle(YAZDIR_BASLIK, "%d sn boyunca durduruldu", Saniye);
  	Sure_Saniye(Gunluk_An, Saniye);	
}
