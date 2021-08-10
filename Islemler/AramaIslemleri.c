// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.1

#include "AramaIslemleri.h"

// >=  0 : ise Aranan 'nin Kaynak icindeki konumu
// == -1 : ise girdiler hatali
// == -2 : ise bulunamadi
Tip_i32 AI_Bul_Bayt(Tip_Isaretci Kaynak, Tip_u32 KaynaktakiBilgiMiktari, Tip_u8 ArananBilgi)
{
	if (Kaynak == Tip_null || KaynaktakiBilgiMiktari == 0) return -1;

	for (Tip_u32 i = 0; i < KaynaktakiBilgiMiktari; i++)
	{
		if (Isaretci_Icerigi(Kaynak, i, Tip_u8) == ArananBilgi) return i;
	}

	return -2;
}
Tip_i32 AI_Bul_Bayt_Sondan(Tip_Isaretci Kaynak, Tip_u32 KaynaktakiBilgiMiktari, Tip_u8 ArananBilgi)
{
	if (Kaynak == Tip_null || KaynaktakiBilgiMiktari == 0) return -1;

	for (Tip_i32 i = KaynaktakiBilgiMiktari - 1 ; i >= 0; i--)
	{
		if (Isaretci_Icerigi(Kaynak, i, Tip_u8) == ArananBilgi) return i;
	}

	return -2;
}

// >=  0 : ise Aranan 'nin Kaynak icindeki konumu
// == -1 : ise girdiler hatali
// == -2 : ise bulunamadi
Tip_i32 AI_Bul_Blok(Tip_Isaretci Kaynak, Tip_u32 KaynaktakiBilgiMiktari, Tip_Isaretci ArananBilgi, Tip_u32 ArananBilgiMiktari)
{
	if (Kaynak == Tip_null || ArananBilgi == Tip_null) return -1;

	Tip_i32 Konum_Yedek = 0, Konum_IlkKarakter;

	TekrarAra:
	Konum_IlkKarakter = AI_Bul_Bayt(Isaretci_Konumlandir(Kaynak, Konum_Yedek, Tip_u8), KaynaktakiBilgiMiktari - Konum_Yedek, Isaretci_Icerigi(ArananBilgi, 0, Tip_u8));
	if (Konum_IlkKarakter < 0) return -2;
	Konum_IlkKarakter += Konum_Yedek + 1; //bir sonraki karakter
	Konum_Yedek = Konum_IlkKarakter;

	Tip_i32 Sayac_Konum_Aranan = 1;
	for (; Konum_IlkKarakter < KaynaktakiBilgiMiktari && Sayac_Konum_Aranan < ArananBilgiMiktari; Konum_IlkKarakter++)
	{
		if (Isaretci_Icerigi(Kaynak, Konum_IlkKarakter, Tip_u8) !=
			Isaretci_Icerigi(ArananBilgi, Sayac_Konum_Aranan, Tip_u8)) goto TekrarAra;

		 Sayac_Konum_Aranan++;
	}
	if (Sayac_Konum_Aranan != ArananBilgiMiktari) return -2;

	return Konum_Yedek - 1;
}
Tip_i32 AI_Bul_Blok_Sondan(Tip_Isaretci Kaynak, Tip_u32 KaynaktakiBilgiMiktari, Tip_Isaretci ArananBilgi, Tip_u32 ArananBilgiMiktari)
{
	if (Kaynak == Tip_null || ArananBilgi == Tip_null) return -1;

	Tip_i32 Konum_Yedek = KaynaktakiBilgiMiktari, Konum_IlkKarakter;

	TekrarAra:
	Konum_IlkKarakter = AI_Bul_Bayt_Sondan(Kaynak, Konum_Yedek, Isaretci_Icerigi(ArananBilgi, 0, Tip_u8));
	if (Konum_IlkKarakter < 0) return -2;
	Konum_Yedek = Konum_IlkKarakter;

	Konum_IlkKarakter++; //bir sonraki karakter
	Tip_i32 Sayac_Konum_Aranan = 1;
	for (; Konum_IlkKarakter < KaynaktakiBilgiMiktari && Sayac_Konum_Aranan < ArananBilgiMiktari; Konum_IlkKarakter++)
	{
		if (Isaretci_Icerigi(Kaynak, Konum_IlkKarakter, Tip_u8) !=
			Isaretci_Icerigi(ArananBilgi, Sayac_Konum_Aranan, Tip_u8)) goto TekrarAra;

		 Sayac_Konum_Aranan++;
	}
	if (Sayac_Konum_Aranan != ArananBilgiMiktari) return -2;

	return Konum_Yedek;
}

// >=  0 : ise belirtilen adet kadar karakter Hedef icine aktarildi
// == -1 : ise girdiler hatali
// == -2 : ise bulunamadi
// == -3 : ise Hedef kapasitesi yeterli olmadýðý için yarým kaldý
Tip_i32 AI_Degistir(Tip_Isaretci Kaynak, Tip_u32 KaynaktakiBilgiMiktari,
					Tip_Isaretci ArananBilgi, Tip_u32 ArananBilgiMiktari,
					Tip_Isaretci YeniBilgi, Tip_u32 YeniBilgiMiktari,
					Tip_Isaretci Hedef, Tip_u32 HedefKapasitesi,
					Tip_bool SadeceIlkBuldugunuDegistir)
{
	if (Kaynak == Tip_null || ArananBilgi == Tip_null || YeniBilgi == Tip_null  || Hedef == Tip_null) return -1;

	Tip_i32 Konum_Kaynak = 0, Sayac_Bulundu = 0, Sayac_HedefKullanildi = 0;
	while (Konum_Kaynak < KaynaktakiBilgiMiktari)
	{
		Tip_i32 Konum_Aranan = AI_Bul_Blok(Isaretci_Konumlandir(Kaynak, Konum_Kaynak, Tip_u8), KaynaktakiBilgiMiktari - Konum_Kaynak, ArananBilgi, ArananBilgiMiktari);
		if (Konum_Aranan < 0) break;

		//Aranan bilginin solundaki kismin kopyalanmasi
		if ((Sayac_HedefKullanildi + Konum_Aranan) > HedefKapasitesi) return -3;
		_Islem_memcpy_(Isaretci_Konumlandir(Hedef, Sayac_HedefKullanildi, Tip_u8), Isaretci_Konumlandir(Kaynak, Konum_Kaynak, Tip_u8), Konum_Aranan);
		Sayac_HedefKullanildi += Konum_Aranan;

		//YeniBilginin kopyalanmasi
		if ((Sayac_HedefKullanildi + YeniBilgiMiktari) > HedefKapasitesi) return -3;
		_Islem_memcpy_(Isaretci_Konumlandir(Hedef, Sayac_HedefKullanildi, Tip_u8), YeniBilgi, YeniBilgiMiktari);
		Sayac_HedefKullanildi += YeniBilgiMiktari;

		Sayac_Bulundu++;
		Konum_Kaynak += Konum_Aranan + ArananBilgiMiktari;

		if (SadeceIlkBuldugunuDegistir) break;
	}

	if (Sayac_Bulundu == 0) return -2;

	if (Konum_Kaynak < KaynaktakiBilgiMiktari)
	{
		Sayac_Bulundu = KaynaktakiBilgiMiktari - Konum_Kaynak;
		_Islem_memcpy_(Isaretci_Konumlandir(Hedef, Sayac_HedefKullanildi, Tip_u8), Isaretci_Konumlandir(Kaynak, Konum_Kaynak, Tip_u8), Sayac_Bulundu);
		Sayac_HedefKullanildi += Sayac_Bulundu;
	}

	return Sayac_HedefKullanildi;
}
