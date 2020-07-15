// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.0

#include "AramaIslemleri.h"

//== 0 : ise yok
// > 0 : ise Aranan 'nin Kaynak icindeki konumu + 1
Tip_u32 AI_Bul_Bayt(Tip_Isaretci Kaynak, Tip_u32 KaynakBoyut, Tip_u8 Aranan)
{
	if (Kaynak == Tip_null) return 0;

	for (Tip_u32 i = 0; i < KaynakBoyut; i++)
	{
		if (Isaretci_Icerigi(Kaynak, i, Tip_u8) == Aranan) return i+1;
	}

	return 0;
}

//== 0 : ise yok
// > 0 : ise Aranan 'in ilk elemanýnýn Kaynak icindeki konumu + 1
Tip_u32 AI_Bul_Blok(Tip_Isaretci Kaynak, Tip_u32 KaynakBoyut, Tip_Isaretci Aranan, Tip_u32 ArananBoyut)
{
	if (Kaynak == Tip_null || Aranan == Tip_null) return 0;

	Tip_u32 Konum_Yedek = 0, Konum_IlkKarakter;

	TekrarAra:
	Konum_IlkKarakter = AI_Bul_Bayt(Isaretci_Konumlandir(Kaynak, Konum_Yedek, Tip_u8), KaynakBoyut - Konum_Yedek, Isaretci_Icerigi(Aranan, 0, Tip_u8));
	if (Konum_IlkKarakter == 0) return 0;
	Konum_IlkKarakter += Konum_Yedek;

	Konum_Yedek = Konum_IlkKarakter;
	Tip_u32 Sayac_Konum_Aranan = 1;
	for (; Konum_IlkKarakter < KaynakBoyut && Sayac_Konum_Aranan < ArananBoyut; Konum_IlkKarakter++, Sayac_Konum_Aranan++)
	{
		if (Isaretci_Icerigi(Kaynak, Konum_IlkKarakter, Tip_u8) !=
			Isaretci_Icerigi(Aranan, Sayac_Konum_Aranan, Tip_u8)) goto TekrarAra;
	}
	if (Sayac_Konum_Aranan != ArananBoyut) return 0;

	return Konum_Yedek;
}


