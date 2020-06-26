// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.0

#include "YaziIslemleri.h"

//0 : yok
//!=0 Aranan 'in son karakterinin Tampon icindeki adresi
Tip_char * YI_Ara(Tip_char * Kaynak, Tip_u32 KaynakBoyut, Tip_char * Aranan)
{
	Tip_u32 bulunan, TamponNoAranan, TamponNoKaynak, TamponNoKaynak_Yedek = 0, Aranan_KarakterSayisi = strlen(Aranan);

Goto_Ara_0:
	TamponNoAranan = 0;
	bulunan = 0;
	TamponNoKaynak = TamponNoKaynak_Yedek;
	
	for (; TamponNoKaynak < KaynakBoyut; TamponNoKaynak++)
	{
		if (Kaynak[TamponNoKaynak] == Aranan[0]) goto Goto_Ara_1;
	}
	return Tip_null;
	
Goto_Ara_1:
  	TamponNoKaynak_Yedek = TamponNoKaynak + 1; 
	for (; TamponNoKaynak < KaynakBoyut && TamponNoAranan < Aranan_KarakterSayisi; TamponNoKaynak++, TamponNoAranan++)
	{
		if (Kaynak[TamponNoKaynak] != Aranan[TamponNoAranan]) goto Goto_Ara_0;
		bulunan++;
	}
	if (bulunan != Aranan_KarakterSayisi) return Tip_null;

	return (Tip_char *)(Kaynak + TamponNoKaynak - 1 /*Son karakteri gosterir*/);
}
Tip_u32 YI_BulAyiklaKopyala(Tip_char * Kaynak, Tip_u32 KaynakBoyut, Tip_char * ArananBaslangic, Tip_char * ArananBitis, Tip_char * Hedef, Tip_u32 HedefBoyut)
{	
	Tip_char * IsrtBaslangic;
	Tip_char * IsrtBitis;

	//ABCDEFGH
	//Baslangic 	C 			Bitis 	F 			Hedef 	DE			true	2
	//Baslangic 	C 			Bitis 	Tip_null  	Hedef 	DEFGH		true	5
	//Baslangic   	Tip_null	Bitis	G 			Hedef 	ABCDEF		true	6
	//Baslangic   	Tip_null	Bitis   Tip_null	Hedef 	Tip_null	false	0
	//Baslangic   	Q			Bitis   W			Hedef 	Tip_null	false	0

	if (ArananBaslangic == Tip_null && ArananBitis == Tip_null) return 0;
	else if (ArananBaslangic != Tip_null && ArananBitis != Tip_null)
	{
		IsrtBaslangic = YI_Ara(Kaynak, KaynakBoyut, ArananBaslangic);
		if (!IsrtBaslangic) return 0;
		IsrtBitis = YI_Ara(IsrtBaslangic, KaynakBoyut - ((IsrtBaslangic+1) - Kaynak), ArananBitis);
		if (!IsrtBitis) return 0;
		if ( ((Tip_u32)IsrtBitis - (Tip_u32)IsrtBaslangic) < HedefBoyut) HedefBoyut = (Tip_u32)IsrtBitis - (Tip_u32)IsrtBaslangic;
		Kaynak = IsrtBaslangic;
	}
	else if (ArananBaslangic == Tip_null)
	{
		IsrtBitis = YI_Ara(Kaynak, KaynakBoyut, ArananBitis);
		if (!IsrtBitis) return 0;
		if ( ( (Tip_u32)IsrtBitis - (Tip_u32)Kaynak ) < HedefBoyut) HedefBoyut = ((Tip_u32)IsrtBitis - (Tip_u32)Kaynak);
	}
	else
	{
		IsrtBaslangic = YI_Ara(Kaynak, KaynakBoyut, ArananBaslangic);
		if (!IsrtBaslangic) return 0;
		Kaynak = IsrtBaslangic;
	}

	*Hedef = 0;
	_Islem_memcpy_(Hedef, Kaynak, HedefBoyut);
	if (*Hedef == 0) return 0;
	*(Hedef + HedefBoyut - 1) = '\0';
	return HedefBoyut;
}

Tip_char * YI_Yazdir(Tip_char * Tampon, Tip_u32 TamponKapasitesi, Tip_char * Sekil, ...)
{
	va_list args;
	va_start(args, Sekil);
	vsnprintf(Tampon, TamponKapasitesi, Sekil, args);
	va_end(args);

	return Tampon;
}
Tip_char * YI_Yazdir_TarihSaat(Tip_time An, Tip_char * Tampon, Tip_u32 TamponKapasitesi)
{
	struct tm ZamanBilgisi = { 0 };
	//localtime_r(&An, &ZamanBilgisi); // mingw win de tanimli de�il
	strftime(Tampon, TamponKapasitesi, _YI_Yazdir_Sablon_TarihSaat, &ZamanBilgisi);
	return Tampon;
}
Tip_char * YI_Yazdir_NoktaliSayi(Tip_float NoktaliSayi, Tip_char * Tampon, Tip_u32 TamponKapasitesi)
{
	snprintf(Tampon, TamponKapasitesi, _YI_Yazdir_Sablon_NoktaliSayi, NoktaliSayi);

	return Tampon;
}
Tip_char * YI_Yazdir_TamSayi_Hex(Tip_u32 TamSayi, Tip_char * Tampon, Tip_u32 TamponKapasitesi)
{
	snprintf(Tampon, TamponKapasitesi, _YI_Yazdir_Sablon_TamSayi_Hex, TamSayi);

	return Tampon;
}
Tip_char * YI_Yazdir_TamSayi(Tip_u32 TamSayi, Tip_char * Tampon, Tip_u32 TamponKapasitesi)
{
	snprintf(Tampon, TamponKapasitesi, _YI_Yazdir_Sablon_TamSayi, TamSayi);

	return Tampon;
}
Tip_char * YI_Yazdir_Hex_Tampon(Tip_Isaretci Girdi, Tip_u32 GirdiAdet, Tip_char * Tampon, Tip_u32 TamponKapasitesi)
{
	Tip_u32 AdetKullanilan = 0;
	for (Tip_u32 i = 0; i < GirdiAdet && AdetKullanilan < TamponKapasitesi; i++)
	{
		AdetKullanilan += snprintf(Isaretci_Konumlandir(Tampon, AdetKullanilan, Tip_char), TamponKapasitesi - AdetKullanilan, _YI_Yazdir_Sablon_Tampon_Hex, Isaretci_Icerigi(Girdi, i, Tip_u8));
	}

	if (AdetKullanilan >= TamponKapasitesi) AdetKullanilan = TamponKapasitesi - 1;
	Tampon[AdetKullanilan] = '\0';

	return Tampon;
}
