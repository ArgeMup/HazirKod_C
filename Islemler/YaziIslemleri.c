// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.0

#include "YaziIslemleri.h"

//== 0 : ise yok
// > 0 : ise Kopyalanan karakter adedi
Tip_u32 YI_BulAyiklaKopyala(Tip_char * Kaynak, Tip_char * ArananBaslangic, Tip_char * ArananBitis, Tip_char * Hedef, Tip_u32 HedefKapasite)
{	
	//ABCDEFGH
	//Baslangic 	C 			Bitis 	F 			Hedef 	DE			true	2
	//Baslangic 	C 			Bitis 	Tip_null  	Hedef 	DEFGH		true	5
	//Baslangic   	Tip_null	Bitis	G 			Hedef 	ABCDEF		true	6
	//Baslangic   	Tip_null	Bitis   Tip_null	Hedef 				false	0
	//Baslangic   	Q			Bitis   W			Hedef 				false	0

	Tip_u32 KonumBaslangic, KonumBitis;

	if (Kaynak == Tip_null || Hedef == Tip_null) return 0;

	if (ArananBaslangic != Tip_null && ArananBitis != Tip_null)
	{
		KonumBaslangic = YI_Ara(Kaynak, ArananBaslangic);
		if (KonumBaslangic == 0) return 0;

		KonumBaslangic = KonumBaslangic + strlen(ArananBaslangic) - 1 /*Ilk karaktere gitmek icin*/;

		KonumBitis = YI_Ara(Isaretci_Konumlandir(Kaynak, KonumBaslangic, Tip_char), ArananBitis);
		if (KonumBitis == 0) return 0;

		KonumBitis = KonumBitis + KonumBaslangic - 1 /*Ilk karaktere gitmek icin*/;
	}
	else if (ArananBaslangic == Tip_null)
	{
		KonumBaslangic = 0;
		KonumBitis = YI_Ara(Isaretci_Konumlandir(Kaynak, KonumBaslangic, Tip_char), ArananBitis);
		if (KonumBitis == 0) return 0;

		KonumBitis = KonumBitis - 1 /*Ilk karaktere gitmek icin*/;
	}
	else
	{
		KonumBaslangic = YI_Ara(Kaynak, ArananBaslangic);
		if (KonumBaslangic == 0) return 0;

		KonumBaslangic = KonumBaslangic + strlen(ArananBaslangic) - 1 /*Ilk karaktere gitmek icin*/;

		KonumBitis = strlen(Kaynak);
	}

	Tip_u32 Adet = KonumBitis - KonumBaslangic;
	if ( (Adet + 1 /*\0*/) > HedefKapasite) Adet = HedefKapasite - 1;

	_Islem_memcpy_(Hedef, Isaretci_Konumlandir(Kaynak, KonumBaslangic, Tip_u8), Adet);
	Isaretci_Icerigi(Hedef, Adet, Tip_char) = '\0';

	return Adet;
}

Tip_char * YI_Yazdir(Tip_char * Hedef, Tip_u32 HedefKapasite, Tip_char * Sekil, ...)
{
	va_list args;
	va_start(args, Sekil);
	vsnprintf(Hedef, HedefKapasite, Sekil, args);
	va_end(args);

	return Hedef;
}
Tip_char * YI_Yazdir_TarihSaat(Tip_char * Hedef, Tip_u32 HedefKapasite, Tip_time An)
{
	struct tm ZamanBilgisi = { 0 };
	localtime_r(&An, &ZamanBilgisi); // mingw win de tanimli degil
	strftime(Hedef, HedefKapasite, _YI_Yazdir_Sablon_TarihSaat, &ZamanBilgisi);
	return Hedef;
}
Tip_char * YI_Yazdir_NoktaliSayi(Tip_char * Hedef, Tip_u32 HedefKapasite, Tip_float NoktaliSayi)
{
	snprintf(Hedef, HedefKapasite, _YI_Yazdir_Sablon_NoktaliSayi, NoktaliSayi);

	return Hedef;
}
Tip_char * YI_Yazdir_TamSayi_Hex(Tip_char * Hedef, Tip_u32 HedefKapasite, Tip_u32 TamSayi)
{
	snprintf(Hedef, HedefKapasite, _YI_Yazdir_Sablon_TamSayi_Hex, TamSayi);

	return Hedef;
}
Tip_char * YI_Yazdir_TamSayi(Tip_char * Hedef, Tip_u32 HedefKapasite, Tip_u32 TamSayi)
{
	snprintf(Hedef, HedefKapasite, _YI_Yazdir_Sablon_TamSayi, TamSayi);

	return Hedef;
}
Tip_char * YI_Yazdir_Hex_Tampon(Tip_char * Hedef, Tip_u32 HedefKapasite, Tip_Isaretci Kaynak, Tip_u32 Adet)
{
	Tip_u32 AdetKullanilan = snprintf(Isaretci_Konumlandir(Hedef, 0, Tip_char), HedefKapasite, "0x");

	for (Tip_u32 i = 0; i < Adet && AdetKullanilan < HedefKapasite; i++)
	{
		AdetKullanilan += snprintf(Isaretci_Konumlandir(Hedef, AdetKullanilan, Tip_char), HedefKapasite - AdetKullanilan, _YI_Yazdir_Sablon_Tampon_Hex, Isaretci_Icerigi(Kaynak, i, Tip_u8));
	}

	if (AdetKullanilan >= HedefKapasite) AdetKullanilan = HedefKapasite - 1;
	Hedef[AdetKullanilan] = '\0';

	return Hedef;
}
