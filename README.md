# HazirKod_C
Genel Amacli C Kutuphanesi ArgeMup@yandex.com

	#include "AramaIslemleri.h"
	#include "Depo.h"
	#include "Dizi.h"
	#include "Gorev.h"
	#include "IlkGirenIlkCikar.h"
	#include "KomutSatiri.h"
	#include "LedKontrol.h"
	#include "Liste.h"
	#include "Tampon.h"
	#include "YaziIslemleri.h"
	#include "YerTahsisati.h"
	#include "Zamanlama.h"
	
	//////////////////////////////////////////////////////////////////////////////
	#define _Gunluk_Baslik "KaynakKod.c"	//Gunluk ciktilarini tum dosyada kapatmak için NULL olmali
	#include "Gunluk.h"						//Kaynak kod içinde tanimlanmali
	//////////////////////////////////////////////////////////////////////////////
	
	void Ornek_AramaIslemleri();
	void Ornek_Depo();
	void Ornek_Dizi();
	void Ornek_Gorev();
	void Ornek_Gunluk();
	void Ornek_IlkGirenIlkCikar();
	void Ornek_KomutSatiri();
	void Ornek_Liste();
	void Ornek_Tampon();
	void Ornek_YaziIslemleri();
	void Ornek_YerTahsisati();
	void Ornek_Zamanlama();
	void Ornek_HazirKod_C_Ayarlar_h();
	void Kiyaslama_Dizi_Liste();
	
	int main(void)
	{
		Ornek_Gunluk();
		Ornek_AramaIslemleri();
		Ornek_Depo();
		Ornek_Dizi();
		Ornek_Gorev();
		Ornek_IlkGirenIlkCikar();
		Ornek_KomutSatiri();
		Ornek_Liste();
		Ornek_Tampon();
		Ornek_YaziIslemleri();
		Ornek_YerTahsisati();
		Ornek_Zamanlama();
		Ornek_HazirKod_C_Ayarlar_h();
		//Kiyaslama_Dizi_Liste();
	
		return EXIT_SUCCESS;
	}
	
	void Ornek_Gunluk()
	{
		//Sure Sayacini baslatmak için gerekli
		Gunluk_Baslat();
	
		Gunluk("Gelisiguzel bir bilgi verir - siyah yazi");
		Gunluk_Bilgi("Asamalar arasi gecise dair bilgi verir - siyah ustune yesil yazi");
		Gunluk_Uyari("Bilinen bir duruma dair bilgi verir - siyah ustune sari yazi");
		Gunluk_Hata("Bilinen bir hataya dair bilgi verir - siyah ustune kirmizi yazi");
		Gunluk_BeklenmeyenDurum("Hesapta olmayan bir duruma dair bilgi verir - kirmizi ustune beyaz yazi");
	
		uint8_t Dizi[] = { 'a', 'b', 'Y', 'Z', 1, 5, 35 };
		Gunluk_Hex(Dizi, sizeof(Dizi));
	
		Gunluk_SureliDurdur(1);
		Gunluk("Bunu yazdirmayacak");
		Bekle_MiliSaniye(1500);
		Gunluk("Bunu yazdiracak");
	
	//	0-19698453 KaynakKod.c Gelisiguzel bir bilgi verir - siyah yazi
	//	[1;32;40m0-19698453 KaynakKod.c Asamalar arasi gecise dair bilgi verir - siyah ustune yesil yazi[0m
	//	[1;33;40m0-19698453 KaynakKod.c Bilinen bir duruma dair bilgi verir - siyah ustune sari yazi[0m
	//	[1;31;40m0-19698453 KaynakKod.c Bilinen bir hataya dair bilgi verir - siyah ustune kirmizi yazi[0m
	//	[1;37;41m0-19698453 KaynakKod.c Hesapta olmayan bir duruma dair bilgi verir - kirmizi ustune beyaz yazi[0m
	//	0-19698453 KaynakKod.c Adet:00007 | Hex | Konum | Ascii
	//	0-19698453 KaynakKod.c 61 62 59 5A 01 05 23 | 0000 - 0006 | abYZ  #
	//	0-19699968 KaynakKod.c Bunu yazdiracak
	}
	
	void Ornek_AramaIslemleri()
	{
		Gunluk("-----Ornek_AramaIslemleri-----");
	
		Tip_u8 T1[] = { 4, 4, 4, 4 };
		Gunluk("T1");
		Gunluk_Hex(T1, sizeof(T1));
	
		Tip_u8 T2[] = { 3, 4, 5 };
		Gunluk("T2");
		Gunluk_Hex(T2, sizeof(T2));
	
		Tip_u8 T3[] = { 35, 45, 55 };
		Gunluk("T3");
		Gunluk_Hex(T3, sizeof(T3));
	
		Tip_u8 T10[] = { 1,2,3,     4,4,4,     'M','U','P',     5,6,     3,4,5,     'M','U','P',     7,8,     4,4,4,4,     'M','U','P',     9,10,   35,45, 3,4,5 };
		Gunluk("T10");
		Gunluk_Hex(T10, sizeof(T10));
	
		Tip_u8 T4[] = { 'M', 'U', 'P' };
		Gunluk("T4");
		Gunluk_Hex(T4, sizeof(T4));
	
		Tip_u8 T20[] = { "ArgeMup" };
		Gunluk("T20");
		Gunluk_Hex(T20, sizeof(T20));
	
		Gunluk("");
	
		Tip_i32 BulunduguKonum = AI_Bul_Blok(T10, sizeof(T10), T1, sizeof(T1));
		Gunluk("AI_Bul_Blok(T10, sizeof(T10), T1, sizeof(T1)); -> %d", BulunduguKonum);
	
		BulunduguKonum = AI_Bul_Blok(T10, sizeof(T10), T2, sizeof(T2));
		Gunluk("AI_Bul_Blok(T10, sizeof(T10), T2, sizeof(T2)); -> %d", BulunduguKonum);
	
		BulunduguKonum = AI_Bul_Blok(T10, sizeof(T10), T3, sizeof(T3));
		Gunluk("AI_Bul_Blok(T10, sizeof(T10), T3, sizeof(T3)); -> %d", BulunduguKonum);
	
		BulunduguKonum = AI_Bul_Bayt(T10, sizeof(T10), 1);
		Gunluk("AI_Bul_Bayt(T10, sizeof(T10), 1); -> %d", BulunduguKonum);
	
		BulunduguKonum = AI_Bul_Bayt(T10, sizeof(T10), 4);
		Gunluk("AI_Bul_Bayt(T10, sizeof(T10), 4); -> %d", BulunduguKonum);
	
		BulunduguKonum = AI_Bul_Bayt(T10, sizeof(T10), 8);
		Gunluk("AI_Bul_Bayt(T10, sizeof(T10), 8); -> %d", BulunduguKonum);
	
		BulunduguKonum = AI_Bul_Bayt(T10, sizeof(T10), 10);
		Gunluk("AI_Bul_Bayt(T10, sizeof(T10), 10); -> %d", BulunduguKonum);
	
		BulunduguKonum = AI_Bul_Bayt(T10, sizeof(T10), 55);
		Gunluk("AI_Bul_Bayt(T10, sizeof(T10), 55); -> %d", BulunduguKonum);
	
		Gunluk("");
	
		BulunduguKonum = AI_Bul_Blok_Sondan(T10, sizeof(T10), T2, sizeof(T2));
		Gunluk("AI_Bul_Blok(T10, sizeof(T10), T2, sizeof(T2)); -> %d", BulunduguKonum);
	
		BulunduguKonum = AI_Bul_Bayt_Sondan(T10, sizeof(T10), 4);
		Gunluk("AI_Bul_Bayt(T10, sizeof(T10), 4); -> %d", BulunduguKonum);
	
		BulunduguKonum = AI_Bul_Blok_Sondan(T10, sizeof(T10), T3, sizeof(T3));
		Gunluk("AI_Bul_Blok(T10, sizeof(T10), T3, sizeof(T3)); -> %d", BulunduguKonum);
	
		BulunduguKonum = AI_Bul_Bayt_Sondan(T10, sizeof(T10), 99);
		Gunluk("AI_Bul_Bayt(T10, sizeof(T10), 99); -> %d", BulunduguKonum);
	
		Gunluk("");
	
		Gunluk("T10");
		Gunluk_Hex(T10, sizeof(T10));
	
		Tip_u8 Tampon[64] = { 0 };
		BulunduguKonum = AI_Degistir(T10, sizeof(T10), T4, sizeof(T4), T20, sizeof(T20), Tampon, sizeof(Tampon), true);
		Gunluk("AI_Degistir(T10, sizeof(T10), T4, sizeof(T4), T20, sizeof(T20), Tampon, sizeof(Tampon), true); -> %d", BulunduguKonum);
		Gunluk_Hex(Tampon, sizeof(Tampon));
	
		memset(Tampon, 0, sizeof(Tampon));
		BulunduguKonum = AI_Degistir(T10, sizeof(T10), T4, sizeof(T4), T20, sizeof(T20), Tampon, sizeof(Tampon), false);
		Gunluk("AI_Degistir(T10, sizeof(T10), T4, sizeof(T4), T20, sizeof(T20), Tampon, sizeof(Tampon), false); -> %d", BulunduguKonum);
		Gunluk_Hex(Tampon, sizeof(Tampon));
	
	//	0-28180812 KaynakKod.c -----Ornek_AramaIslemleri-----
	//	0-28180812 KaynakKod.c T1
	//	0-28180812 KaynakKod.c Adet:00004 | Hex | Konum | Ascii
	//	0-28180812 KaynakKod.c 04 04 04 04 | 0000 - 0003 |
	//	0-28180812 KaynakKod.c T2
	//	0-28180812 KaynakKod.c Adet:00003 | Hex | Konum | Ascii
	//	0-28180812 KaynakKod.c 03 04 05 | 0000 - 0002 |
	//	0-28180812 KaynakKod.c T3
	//	0-28180812 KaynakKod.c Adet:00003 | Hex | Konum | Ascii
	//	0-28180812 KaynakKod.c 23 2D 37 | 0000 - 0002 | #-7
	//	0-28180812 KaynakKod.c T10
	//	0-28180812 KaynakKod.c Adet:00033 | Hex | Konum | Ascii
	//	0-28180812 KaynakKod.c 01 02 03 04 04 04 4D 55 50 05 06 03 04 05 4D 55 | 0000 - 000F |       MUP     MU
	//	0-28180812 KaynakKod.c 50 07 08 04 04 04 04 4D 55 50 09 0A 23 2D 03 04 | 0010 - 001F | P      MUP  #-
	//	0-28180812 KaynakKod.c 05 | 0020 - 0020 |
	//	0-28180812 KaynakKod.c T4
	//	0-28180812 KaynakKod.c Adet:00003 | Hex | Konum | Ascii
	//	0-28180812 KaynakKod.c 4D 55 50 | 0000 - 0002 | MUP
	//	0-28180812 KaynakKod.c T20
	//	0-28180812 KaynakKod.c Adet:00008 | Hex | Konum | Ascii
	//	0-28180812 KaynakKod.c 41 72 67 65 4D 75 70 00 | 0000 - 0007 | ArgeMup
	//	0-28180812 KaynakKod.c
	//	0-28180812 KaynakKod.c AI_Bul_Blok(T10, sizeof(T10), T1, sizeof(T1)); -> 19
	//	0-28180812 KaynakKod.c AI_Bul_Blok(T10, sizeof(T10), T2, sizeof(T2)); -> 11
	//	0-28180812 KaynakKod.c AI_Bul_Blok(T10, sizeof(T10), T3, sizeof(T3)); -> -2
	//	0-28180812 KaynakKod.c AI_Bul_Bayt(T10, sizeof(T10), 1); -> 0
	//	0-28180812 KaynakKod.c AI_Bul_Bayt(T10, sizeof(T10), 4); -> 3
	//	0-28180812 KaynakKod.c AI_Bul_Bayt(T10, sizeof(T10), 8); -> 18
	//	0-28180812 KaynakKod.c AI_Bul_Bayt(T10, sizeof(T10), 10); -> 27
	//	0-28180812 KaynakKod.c AI_Bul_Bayt(T10, sizeof(T10), 55); -> -2
	//	0-28180812 KaynakKod.c
	//	0-28180812 KaynakKod.c AI_Bul_Blok(T10, sizeof(T10), T2, sizeof(T2)); -> 30
	//	0-28180812 KaynakKod.c AI_Bul_Bayt(T10, sizeof(T10), 4); -> 31
	//	0-28180812 KaynakKod.c AI_Bul_Blok(T10, sizeof(T10), T3, sizeof(T3)); -> -2
	//	0-28180812 KaynakKod.c AI_Bul_Bayt(T10, sizeof(T10), 99); -> -2
	//	0-28180812 KaynakKod.c
	//	0-28180812 KaynakKod.c T10
	//	0-28180812 KaynakKod.c Adet:00033 | Hex | Konum | Ascii
	//	0-28180812 KaynakKod.c 01 02 03 04 04 04 4D 55 50 05 06 03 04 05 4D 55 | 0000 - 000F |       MUP     MU
	//	0-28180812 KaynakKod.c 50 07 08 04 04 04 04 4D 55 50 09 0A 23 2D 03 04 | 0010 - 001F | P      MUP  #-
	//	0-28180812 KaynakKod.c 05 | 0020 - 0020 |
	//	0-28180812 KaynakKod.c AI_Degistir(T10, sizeof(T10), T4, sizeof(T4), T20, sizeof(T20), Tampon, sizeof(Tampon), true); -> 38
	//	0-28180812 KaynakKod.c Adet:00064 | Hex | Konum | Ascii
	//	0-28180812 KaynakKod.c 01 02 03 04 04 04 41 72 67 65 4D 75 70 00 05 06 | 0000 - 000F |       ArgeMup
	//	0-28180812 KaynakKod.c 03 04 05 4D 55 50 07 08 04 04 04 04 4D 55 50 09 | 0010 - 001F |    MUP      MUP
	//	0-28180812 KaynakKod.c 0A 23 2D 03 04 05 00 00 00 00 00 00 00 00 00 00 | 0020 - 002F |  #-
	//	0-28180812 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0030 - 003F |
	//	0-28180812 KaynakKod.c AI_Degistir(T10, sizeof(T10), T4, sizeof(T4), T20, sizeof(T20), Tampon, sizeof(Tampon), false); -> 48
	//	0-28180812 KaynakKod.c Adet:00064 | Hex | Konum | Ascii
	//	0-28180812 KaynakKod.c 01 02 03 04 04 04 41 72 67 65 4D 75 70 00 05 06 | 0000 - 000F |       ArgeMup
	//	0-28180812 KaynakKod.c 03 04 05 41 72 67 65 4D 75 70 00 07 08 04 04 04 | 0010 - 001F |    ArgeMup
	//	0-28180812 KaynakKod.c 04 41 72 67 65 4D 75 70 00 09 0A 23 2D 03 04 05 | 0020 - 002F |  ArgeMup   #-
	//	0-28180812 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0030 - 003F |
	}
	
	Tip_bool Ornek_Depo_Islem_Siliniyor_IkinciSefer = false;
	Tip_bool Ornek_Depo_Islem_Siliniyor(Tip_Isaretci_IGIC IGIC, Tip_u32 Adet)
	{
		if (!Ornek_Depo_Islem_Siliniyor_IkinciSefer)
		{
			Ornek_Depo_Islem_Siliniyor_IkinciSefer = true;
			Gunluk("Ornek_Depo_Islem_Siliniyor, %d adet", Adet);
			return true;
		}
		else
		{
			Gunluk("Ornek_Depo_Islem_Siliniyor, %d adet", Adet);
			return false;
		}
	}
	void Ornek_Depo()
	{
		Gunluk("-----Ornek_Depo-----");
	
		Tip_Isaretci_Depo Depo =  Depo_Yeni(sizeof(Tip_u8), 100, e_IGIC_YerKalmazsa_EnEskiyiSil, Ornek_Depo_Islem_Siliniyor);
	
		Tip_char * Bilgi = "1234567890ABCDEF";
		Gunluk_Hex(Bilgi, sizeof(Bilgi));
	
		Tip_bool sonuc = Depo_Bilgi_Ekle(Depo, Bilgi, strlen(Bilgi));
		Gunluk("Tip_bool sonuc = Depo_Bilgi_Ekle(Depo, Bilgi, strlen(Bilgi)); -> %d", sonuc);
	
		Tip_u32 Adet = Depo_Bilgi_SiradakiAdet(Depo);
		Gunluk("Tip_u32 Adet = Depo_Bilgi_SiradakiAdet(Depo); -> %d", Adet);
	
		sonuc = Depo_Bilgi_Ekle(Depo, Bilgi, strlen(Bilgi)/2);
		Gunluk("sonuc = Depo_Bilgi_Ekle(Depo, Bilgi, strlen(Bilgi)/2); -> %d", sonuc);
	
		Adet = Depo_Bilgi_SiradakiAdet(Depo);
		Gunluk("Adet = Depo_Bilgi_SiradakiAdet(Depo); -> %d", Adet);
	
		Tip_char Okunan[50];
		Adet = Depo_Bilgi_Oku(Depo, Okunan, strlen(Bilgi));
		Gunluk("Adet = Depo_Bilgi_Oku(Depo, Okunan, strlen(Bilgi)); -> %d", Adet);
		Gunluk_Hex(Okunan, Adet);
	
		Adet = Depo_Bilgi_Oku(Depo, Okunan, strlen(Bilgi));
		Gunluk("Adet = Depo_Bilgi_Oku(Depo, Okunan, strlen(Bilgi)); -> %d", Adet);
		Gunluk_Hex(Okunan, Adet);
	
		Adet = Depo_Bilgi_Oku(Depo, Okunan, strlen(Bilgi));
		Gunluk("Adet = Depo_Bilgi_Oku(Depo, Okunan, strlen(Bilgi)); -> %d", Adet);
		Gunluk_Hex(Okunan, Adet);
	
		sonuc = Depo_Bilgi_Ekle(Depo, Okunan, sizeof(Okunan));
		Gunluk("sonuc = Depo_Bilgi_Ekle(Depo, Okunan, sizeof(Okunan)); -> %d", sonuc);
	
		sonuc = Depo_Bilgi_Ekle(Depo, Okunan, sizeof(Okunan)); //Tasma, islem siliniyor
		Gunluk("sonuc = Depo_Bilgi_Ekle(Depo, Okunan, sizeof(Okunan)); -> %d", sonuc);
	
		sonuc = Depo_Bilgi_Ekle(Depo, Okunan, sizeof(Okunan)); //Tasma, islem siliniyor
		Gunluk("sonuc = Depo_Bilgi_Ekle(Depo, Okunan, sizeof(Okunan)); -> %d", sonuc);
	
		Adet = Depo_BosAlan(Depo);
		Gunluk("Adet = Depo_BosAlan(Depo); -> %d", Adet);
	
		Adet = Depo_DoluAlan(Depo);
		Gunluk("Adet = Depo_DoluAlan(Depo); -> %d", Adet);
	
		Adet = Depo_Kapasite(Depo);
		Gunluk("Adet = Depo_Kapasite(Depo); -> %d", Adet);
	
		Depo_Sil(Depo);
	
	//	0-28515734 KaynakKod.c -----Ornek_Depo-----
	//	0-28515734 KaynakKod.c Adet:00008 | Hex | Konum | Ascii
	//	0-28515734 KaynakKod.c 31 32 33 34 35 36 37 38 | 0000 - 0007 | 12345678
	//	0-28515734 KaynakKod.c Tip_bool sonuc = Depo_Bilgi_Ekle(Depo, Bilgi, strlen(Bilgi)); -> 1
	//	0-28515734 KaynakKod.c Tip_u32 Adet = Depo_Bilgi_SiradakiAdet(Depo); -> 16
	//	0-28515734 KaynakKod.c sonuc = Depo_Bilgi_Ekle(Depo, Bilgi, strlen(Bilgi)/2); -> 1
	//	0-28515734 KaynakKod.c Adet = Depo_Bilgi_SiradakiAdet(Depo); -> 16
	//	0-28515734 KaynakKod.c Adet = Depo_Bilgi_Oku(Depo, Okunan, strlen(Bilgi)); -> 16
	//	0-28515734 KaynakKod.c Adet:00016 | Hex | Konum | Ascii
	//	0-28515734 KaynakKod.c 31 32 33 34 35 36 37 38 39 30 41 42 43 44 45 46 | 0000 - 000F | 1234567890ABCDEF
	//	0-28515734 KaynakKod.c Adet = Depo_Bilgi_Oku(Depo, Okunan, strlen(Bilgi)); -> 8
	//	0-28515734 KaynakKod.c Adet:00008 | Hex | Konum | Ascii
	//	0-28515734 KaynakKod.c 31 32 33 34 35 36 37 38 | 0000 - 0007 | 12345678
	//	0-28515734 KaynakKod.c Adet = Depo_Bilgi_Oku(Depo, Okunan, strlen(Bilgi)); -> 0
	//	0-28515734 KaynakKod.c Adet:00000 | Hex | Konum | Ascii
	//	0-28515734 KaynakKod.c sonuc = Depo_Bilgi_Ekle(Depo, Okunan, sizeof(Okunan)); -> 1
	//	0-28515734 KaynakKod.c Ornek_Depo_Islem_Siliniyor, 51 adet
	//	0-28515734 KaynakKod.c sonuc = Depo_Bilgi_Ekle(Depo, Okunan, sizeof(Okunan)); -> 1
	//	0-28515734 KaynakKod.c Ornek_Depo_Islem_Siliniyor, 51 adet
	//	0-28515734 KaynakKod.c sonuc = Depo_Bilgi_Ekle(Depo, Okunan, sizeof(Okunan)); -> 0
	//	0-28515734 KaynakKod.c Adet = Depo_BosAlan(Depo); -> 49
	//	0-28515734 KaynakKod.c Adet = Depo_DoluAlan(Depo); -> 51
	//	0-28515734 KaynakKod.c Adet = Depo_Kapasite(Depo); -> 100
	}
	
	void Ornek_Dizi()
	{
		Gunluk("-----Ornek_Dizi-----");
	
		Tip_u8 * 	a1 = YT_Yeni(sizeof(Tip_u8), false);
		Tip_float *	a2 = YT_Yeni(sizeof(Tip_float), false);
		Tip_u16     a3 = 555;
	
		Tip_Isaretci_Dizi Dizi = Dizi_Yeni();
		if (Dizi == Tip_null) return;
		Gunluk("Dizi_Eleman_Sayisi(Dizi) : %d", Dizi_Eleman_Sayisi(Dizi));
	
		Gunluk("Dizi_Eleman_Ekle(Dizi, a1); -> %d", Dizi_Eleman_Ekle(Dizi, a1));
		Gunluk("TDizi_Eleman_Ekle(Dizi, a2); -> %d", Dizi_Eleman_Ekle(Dizi, a2));
		Gunluk("TDizi_Eleman_Ekle(Dizi, &a3); -> %d", Dizi_Eleman_Ekle(Dizi, &a3));
	
		Gunluk("Dizi_Eleman_Sayisi(Dizi) : %d", Dizi_Eleman_Sayisi(Dizi));
	
		Tip_u8 * 	b1 = Dizi_Elemani(Dizi, 0);
		Tip_float *	b2 = Dizi_Elemani(Dizi, 1);
		Gunluk("Tip_u8 * 	b1 = Dizi_Elemani(Dizi, Konum_a1); -> %d", *b1);
		Gunluk("Tip_float *	b2 = Dizi_Elemani(Dizi, Konum_a2); -> %d", *b2);
	
		*a1 = 95;
		*a2 = 987.654;
	
		Gunluk("*a1 = 95; -> %d", *b1);
		Gunluk("*a2 = 987.654; -> %f", *b2);
	
		Gunluk_Hex(_Dizi_(Dizi)->Isaretci, Dizi_Eleman_Sayisi(Dizi) * Isaretci_KapladigiAlan_Bayt);
	
		Gunluk("Dizi_Eleman_Sayisi(Dizi) : %d", Dizi_Eleman_Sayisi(Dizi));
		Gunluk("Dizi_Eleman_Sil(Dizi, 1, true); -> %d", Dizi_Eleman_Sil(Dizi, 1, true));
	
		Gunluk_Hex(_Dizi_(Dizi)->Isaretci, Dizi_Eleman_Sayisi(Dizi) * Isaretci_KapladigiAlan_Bayt);
	
		Gunluk("Dizi_Eleman_Sayisi(Dizi) : %d", Dizi_Eleman_Sayisi(Dizi));
	
		Gunluk("Dizi_Eleman_Sil(Dizi, 0, true); -> %d", Dizi_Eleman_Sil(Dizi, 0, true));
		Gunluk("Dizi_Eleman_Sayisi(Dizi) : %d", Dizi_Eleman_Sayisi(Dizi));
	
		Gunluk_Hex(_Dizi_(Dizi)->Isaretci, Dizi_Eleman_Sayisi(Dizi) * Isaretci_KapladigiAlan_Bayt);
	
		Dizi_Sil(Dizi, false);
	
	//	0-12872515 KaynakKod.c -----Ornek_Dizi-----
	//	0-12872515 KaynakKod.c Dizi->ElemanSayisi : 0
	//	0-12872515 KaynakKod.c Dizi_Eleman_Ekle(Dizi, a1); -> 1
	//	0-12872515 KaynakKod.c TDizi_Eleman_Ekle(Dizi, a2); -> 1
	//	0-12872515 KaynakKod.c TDizi_Eleman_Ekle(Dizi, &a3); -> 1
	//	0-12872515 KaynakKod.c Dizi->ElemanSayisi : 3
	//	0-12872515 KaynakKod.c Tip_u8 * 	b1 = Dizi_Elemani(Dizi, Konum_a1); -> 0
	//	0-12872515 KaynakKod.c Tip_float *	b2 = Dizi_Elemani(Dizi, Konum_a2); -> 0
	//	0-12872515 KaynakKod.c *a1 = 95; -> 95
	//	0-12872515 KaynakKod.c *a2 = 987.654; -> 987.653992
	//	0-12872515 KaynakKod.c Adet:00024 | Hex | Konum | Ascii
	//	0-12872515 KaynakKod.c 90 60 49 91 F6 7F 00 00 A8 60 49 91 F6 7F 00 00 | 0000 - 000F |  `I      `I
	//	0-12872515 KaynakKod.c A6 F8 7F F5 CD 00 00 00 | 0010 - 0017 |
	//	0-12872515 KaynakKod.c Dizi->ElemanSayisi : 3
	//	0-12872515 KaynakKod.c Dizi_Eleman_Sil(Dizi, 1, true); -> 1
	//	0-12872515 KaynakKod.c Adet:00016 | Hex | Konum | Ascii
	//	0-12872515 KaynakKod.c 90 60 49 91 F6 7F 00 00 A6 F8 7F F5 CD 00 00 00 | 0000 - 000F |  `I
	//	0-12872515 KaynakKod.c Dizi->ElemanSayisi : 2
	//	0-12872515 KaynakKod.c Dizi_Eleman_Sil(Dizi, 0, true); -> 1
	//	0-12872515 KaynakKod.c Dizi->ElemanSayisi : 1
	//	0-12872515 KaynakKod.c Adet:00008 | Hex | Konum | Ascii
	//	0-12872515 KaynakKod.c A6 F8 7F F5 CD 00 00 00 | 0000 - 0007 |
	}
	
	Tip_bool Ornek_Gorev_Islem_BirKez_HemenCalistirildi = false;
	Tip_i32 Ornek_Gorev_Islem(Tip_Isaretci_Gorev_Detaylar Detaylar)
	{
		Gunluk("Ornek_Gorev_Islem, Kullanici Nesnesi : %u\r\n", Detaylar->KullaniciNesnesi->Sayac);
		if (++Detaylar->KullaniciNesnesi->Sayac > 5)
		{
			Gorev_Islem_CikVeSil();
		}
	
		Gorev_Islem_CikVeTekrarCalistir(1000);
	}
	void Ornek_Gorev()
	{
		Gunluk("-----Ornek_Gorev-----");
	
		Tip_s_Gorev_KullaniciNesnesi KullaniciNesnesi = { 0 };
	
		Tip_Isaretci_Gorev Gorev =  Gorev_Yeni();
		if (Gorev == NULL) return;
	
		bool sonuc = Gorev_Islem_Ekle(Gorev, Ornek_Gorev_Islem, &KullaniciNesnesi);
	
		Gunluk("bool sonuc = Gorev_Islem_Ekle(Gorev, Ornek_Gorev_Islem, &KullaniciNesnesi); -> %d", sonuc);
	
	////Led kontrol islemi GOREV kutuphanesine uygun, donanýmsal hatalar vb. olaylar
	////LedKontrol kutuphanesi ile dis dunyaya aktarilabilir
	//	sonuc = Gorev_Islem_Ekle(Gorev, LedKontrol_Gorev, NULL);
	//	Gunluk("sonuc = Gorev_Islem_Ekle(Gorev, LedKontrol_Gorev, NULL); -> %d", sonuc);
	
		while (Gorev_Islem_MevcutMu(Gorev, Ornek_Gorev_Islem))
		{
			if (!Ornek_Gorev_Islem_BirKez_HemenCalistirildi && KullaniciNesnesi.Sayac == 3)
			{
				Gorev_Islem_HemenCalistir(Gorev, Ornek_Gorev_Islem, 5);
				Gunluk("Gorev_Islem_HemenCalistir(Gorev, Ornek_Gorev_Islem, 5);");
				Ornek_Gorev_Islem_BirKez_HemenCalistirildi = true;
			}
	
			Tip_u32 TavsiyeEdilenBeklemeMiktari = Gorev_Calistir(Gorev);
			Gunluk("Tip_u32 TavsiyeEdilenBeklemeMiktari = Gorev_Calistir(Gorev); -> %u", TavsiyeEdilenBeklemeMiktari);
	
			Bekle_MiliSaniye(TavsiyeEdilenBeklemeMiktari + 1);
		}
	
		Gorev_Sil(Gorev);
		Gunluk("Bitti, Kullanici Nesnesi : %d\r\n", KullaniciNesnesi);
	
	//	0-20744594 KaynakKod.c:412 -----Ornek_Gorev-----
	//	0-20744594 KaynakKod.c:421 bool sonuc = Gorev_Islem_Ekle(Gorev, Ornek_Gorev_Islem, &KullaniciNesnesi); -> 1
	//	0-20744594 KaynakKod.c:402 Ornek_Gorev_Islem, Kullanici Nesnesi : 0
	//	0-20744594 KaynakKod.c:438 Tip_u32 TavsiyeEdilenBeklemeMiktari = Gorev_Calistir(Gorev); -> 1000
	//	0-20745594 KaynakKod.c:438 Tip_u32 TavsiyeEdilenBeklemeMiktari = Gorev_Calistir(Gorev); -> 1
	//	0-20745610 KaynakKod.c:402 Ornek_Gorev_Islem, Kullanici Nesnesi : 1
	//	0-20745610 KaynakKod.c:438 Tip_u32 TavsiyeEdilenBeklemeMiktari = Gorev_Calistir(Gorev); -> 1000
	//	0-20746626 KaynakKod.c:402 Ornek_Gorev_Islem, Kullanici Nesnesi : 2
	//	0-20746626 KaynakKod.c:438 Tip_u32 TavsiyeEdilenBeklemeMiktari = Gorev_Calistir(Gorev); -> 1000
	//	0-20747626 KaynakKod.c:433 Gorev_Islem_HemenCalistir(Gorev, Ornek_Gorev_Islem, 5);
	//	0-20747626 KaynakKod.c:438 Tip_u32 TavsiyeEdilenBeklemeMiktari = Gorev_Calistir(Gorev); -> 5
	//	0-20747641 KaynakKod.c:402 Ornek_Gorev_Islem, Kullanici Nesnesi : 3
	//	0-20747641 KaynakKod.c:438 Tip_u32 TavsiyeEdilenBeklemeMiktari = Gorev_Calistir(Gorev); -> 1000
	//	0-20748657 KaynakKod.c:402 Ornek_Gorev_Islem, Kullanici Nesnesi : 4
	//	0-20748657 KaynakKod.c:438 Tip_u32 TavsiyeEdilenBeklemeMiktari = Gorev_Calistir(Gorev); -> 1000
	//	0-20749657 KaynakKod.c:438 Tip_u32 TavsiyeEdilenBeklemeMiktari = Gorev_Calistir(Gorev); -> 1
	//	0-20749672 KaynakKod.c:402 Ornek_Gorev_Islem, Kullanici Nesnesi : 5
	//	0-20749672 KaynakKod.c:438 Tip_u32 TavsiyeEdilenBeklemeMiktari = Gorev_Calistir(Gorev); -> 4294967295
	//	0-20749672 KaynakKod.c:444 Bitti, Kullanici Nesnesi : -1968869232
	}
	
	Tip_bool Ornek_IlkGirenIlkCikar_Islem_Siliniyor(Tip_Isaretci_IGIC IGIC, Tip_u32 Adet)
	{
		Gunluk("Ornek_IlkGirenIlkCikar_Islem_Siliniyor, %d adet", Adet);
		return true;
	}
	void Ornek_IlkGirenIlkCikar()
	{
		Gunluk("-----Ornek_IlkGirenIlkCikar-----");
	
		Tip_Isaretci_IGIC IGIC =  IGIC_Yeni(50, e_IGIC_YerKalmazsa_EnEskiyiSil, Ornek_IlkGirenIlkCikar_Islem_Siliniyor);
		if (IGIC == NULL) return;
	
		char * Bilgi = "1234567890ABCDEF";
		Gunluk("char * Bilgi = \"1234567890ABCDEF\";");
		Gunluk_Hex(Bilgi, strlen(Bilgi));
	
		bool sonuc = IGIC_Bilgi_Ekle(IGIC, Bilgi, strlen(Bilgi));
		Gunluk("bool sonuc = IGIC_Bilgi_Ekle(IGIC, Bilgi, strlen(Bilgi)); -> %d", sonuc);
	
		sonuc = IGIC_Bilgi_Ekle(IGIC, Bilgi, strlen(Bilgi) / 2);
		Gunluk("sonuc = IGIC_Bilgi_Ekle(IGIC, Bilgi, strlen(Bilgi) / 2); -> %d", sonuc);
	
		Tip_u32 miktar = IGIC_Kapasite(IGIC);
		Gunluk("Tip_u32 miktar = IGIC_Kapasite(IGIC); -> %d", miktar);
	
		miktar = IGIC_DoluAlan(IGIC);
		Gunluk("miktar = IGIC_DoluAlan(IGIC); -> %d", miktar);
	
		miktar = IGIC_BosAlan(IGIC);
		Gunluk("miktar = IGIC_BosAlan(IGIC); -> %d", miktar);
	
		char Okunan[100];
		miktar = IGIC_Bilgi_Oku(IGIC, Okunan, 100, true);
		Gunluk("miktar = IGIC_Bilgi_Oku(IGIC, Okunan, 100, true); -> %d", miktar);
	
		sonuc = IGIC_Bilgi_Ekle(IGIC, Bilgi, strlen(Bilgi));
		Gunluk("sonuc = IGIC_Bilgi_Ekle(IGIC, Bilgi, strlen(Bilgi)); -> %d", sonuc);
	
		sonuc = IGIC_Bilgi_Ekle(IGIC, Bilgi, strlen(Bilgi));
		Gunluk("sonuc = IGIC_Bilgi_Ekle(IGIC, Bilgi, strlen(Bilgi)); -> %d", sonuc);
	
		sonuc = IGIC_Bilgi_Ekle(IGIC, Bilgi, strlen(Bilgi));
		Gunluk("sonuc = IGIC_Bilgi_Ekle(IGIC, Bilgi, strlen(Bilgi)); -> %d", sonuc);
	
		sonuc = IGIC_Bilgi_Ekle(IGIC, Bilgi, strlen(Bilgi));
		Gunluk("sonuc = IGIC_Bilgi_Ekle(IGIC, Bilgi, strlen(Bilgi)); -> %d", sonuc);
	
		IGIC_Sil(IGIC);
	
	//	0-21856437 KaynakKod.c -----Ornek_IlkGirenIlkCikar-----
	//	0-21856437 KaynakKod.c char * Bilgi = "1234567890ABCDEF";
	//	0-21856437 KaynakKod.c Adet:00016 | Hex | Konum | Ascii
	//	0-21856437 KaynakKod.c 31 32 33 34 35 36 37 38 39 30 41 42 43 44 45 46 | 0000 - 000F | 1234567890ABCDEF
	//	0-21856437 KaynakKod.c bool sonuc = IGIC_Bilgi_Ekle(IGIC, Bilgi, strlen(Bilgi)); -> 1
	//	0-21856437 KaynakKod.c sonuc = IGIC_Bilgi_Ekle(IGIC, Bilgi, strlen(Bilgi) / 2); -> 1
	//	0-21856437 KaynakKod.c Tip_u32 miktar = IGIC_Kapasite(IGIC); -> 50
	//	0-21856437 KaynakKod.c miktar = IGIC_DoluAlan(IGIC); -> 24
	//	0-21856437 KaynakKod.c miktar = IGIC_BosAlan(IGIC); -> 26
	//	0-21856437 KaynakKod.c miktar = IGIC_Bilgi_Oku(IGIC, Okunan, 100, true); -> 24
	//	0-21856437 KaynakKod.c sonuc = IGIC_Bilgi_Ekle(IGIC, Bilgi, strlen(Bilgi)); -> 1
	//	0-21856437 KaynakKod.c sonuc = IGIC_Bilgi_Ekle(IGIC, Bilgi, strlen(Bilgi)); -> 1
	//	0-21856437 KaynakKod.c sonuc = IGIC_Bilgi_Ekle(IGIC, Bilgi, strlen(Bilgi)); -> 1
	//	0-21856437 KaynakKod.c Ornek_IlkGirenIlkCikar_Islem_Siliniyor, 14 adet
	//	0-21856437 KaynakKod.c sonuc = IGIC_Bilgi_Ekle(IGIC, Bilgi, strlen(Bilgi)); -> 1
	}
	
	Tip_u32 KomutSatiri_DonanimAdresi = 1;
	void Ornek_KomutSatiri()
	{
		Gunluk("-----Ornek_KomutSatiri-----");
	
		const char * dizi[] =
		{
		    "Komut1",
		    "Komut2",
		    "Komut3",
		    "Komut4",
		    "Komut5",
		};
	
		#define UzunKomutuKullan
	
		#ifdef UzunKomutuKullan
			bool UzunKomut = true;
			#define KomutMetni "GuRuLtu Kart 1 Komut1 -987654 Komut2 \"Alisildik yazi ornegi\" 0x112233445566778899AABBCCDDEEFF AyiracsizTekParcaYaziOrnegi OzelKarakterli_AyiracsizTekParcaYaziOrnegi|51| \"Alisildik ozel karakterli yazi ornegi|52|\" Komut3\r\n GuRuLtu"
		#else
			bool UzunKomut = false;
			#define KomutMetni "Komut1 -987654 Komut2 \"Alisildik yazi ornegi\" 0x112233445566778899AABBCCDDEEFF AyiracsizTekParcaYaziOrnegi OzelKarakterli_AyiracsizTekParcaYaziOrnegi|51| \"Alisildik ozel karakterli yazi ornegi|52|\" Komut3\r\n GuRuLtu"
		#endif
		Gunluk("#define KomutMetni \"GuRuLtu Kart 1 ... ");
		Gunluk("%s", KomutMetni);
	
	    Tip_Isaretci_Tampon Komut = Tampon_Yeni(256, false), Cevap = Tampon_Yeni(256, false), Hex, OrnekYazi1 = NULL, OrnekYazi2 = NULL, OrnekYazi3 = NULL, OrnekYazi4 = NULL;
	    Tampon_Bilgi_Ekle_GecerliKonumdanItibaren(Komut, KomutMetni, strlen(KomutMetni));
	    Tip_i32 DizidekiKonum;
	
	    Gunluk("Komut --- Tampon_Bilgi_Ekle_GecerliKonumdanItibaren(Komut, KomutMetni, strlen(KomutMetni));");
	    Gunluk_Hex(Komut->Isaretci, Komut->Kapasite);
	    Tip_s_KomutSatiri_Tampon_Detaylar Detaylar;
	
	    if (KomutSatiri_Baslat(Komut, UzunKomut, &Detaylar))
	    {
			Gunluk("Komut --- if (KomutSatiri_Baslat(Komut, UzunKomut, &Detaylar))");
			Gunluk("Komut_Baslangici %p, Komut_Bitisi %p, YeterliSayidaKarakterVarMi %d, DonanimAdresi %d", Detaylar.Komut_Baslangici, Detaylar.Komut_Bitisi, Detaylar.YeterliSayidaKarakterVarMi, Detaylar.DonanimAdresi);
			Gunluk_Hex(Komut->Isaretci, Komut->Kapasite);
	
			if (KomutSatiri_KontrolEt_Siradaki_BuMu(Komut, "Komut1"))
			{
				Gunluk("Komut --- if (KomutSatiri_KontrolEt_Siradaki_BuMu(Komut, _KomutSatiri_Komut_Komut1))");
				Gunluk_Hex(Komut->Isaretci, Komut->Kapasite);
	
				Tip_i32 Tamsayi;
				if (KomutSatiri_Oku_TamSayi(Komut, &Tamsayi))
				{
					Gunluk("Komut --- if (KomutSatiri_Oku_TamSayi(Komut, &Tamsayi))");
					Gunluk_Hex(Komut->Isaretci, Komut->Kapasite);
	
					if (KomutSatiri_KontrolEt_Siradaki_BuMu(Komut, "Komut2"))
					{
						Gunluk("Komut --- if (KomutSatiri_KontrolEt_Siradaki_BuMu(Komut, _KomutSatiri_Komut_Komut2))");
						Gunluk_Hex(Komut->Isaretci, Komut->Kapasite);
	
						OrnekYazi1 = KomutSatiri_Oku_Yazi(Komut);
						Gunluk("OrnekYazi1 --- OrnekYazi1 = KomutSatiri_Oku_Yazi(Komut);");
						Gunluk_Hex(OrnekYazi1->Isaretci, OrnekYazi1->Kapasite);
	
						Gunluk("Komut --- Komut");
						Gunluk_Hex(Komut->Isaretci, Komut->Kapasite);
	
						if (OrnekYazi1)
						{
							Hex = KomutSatiri_Oku_Hex(Komut);
							Gunluk("Hex --- Hex = KomutSatiri_Oku_Hex(Komut);");
							Gunluk_Hex(Hex->Isaretci, Hex->Kapasite);
	
							Gunluk("Komut --- Komut");
							Gunluk_Hex(Komut->Isaretci, Komut->Kapasite);
	
							OrnekYazi2 = KomutSatiri_Oku_Yazi(Komut);
							Gunluk("OrnekYazi2 --- OrnekYazi2 = KomutSatiri_Oku_Yazi(Komut);");
							Gunluk_Hex(OrnekYazi2->Isaretci, OrnekYazi2->Kapasite);
	
							Gunluk("Komut --- Komut");
							Gunluk_Hex(Komut->Isaretci, Komut->Kapasite);
	
							if (OrnekYazi2)
							{
								OrnekYazi3 = KomutSatiri_Oku_Yazi(Komut);
								Gunluk("OrnekYazi3 --- OrnekYazi3 = KomutSatiri_Oku_Yazi(Komut);");
								Gunluk_Hex(OrnekYazi3->Isaretci, OrnekYazi3->Kapasite);
	
								Gunluk("Komut --- Komut");
								Gunluk_Hex(Komut->Isaretci, Komut->Kapasite);
	
								if (OrnekYazi3)
								{
									OrnekYazi4 = KomutSatiri_Oku_Yazi(Komut);
									Gunluk("OrnekYazi4 --- OrnekYazi4 = KomutSatiri_Oku_Yazi(Komut);");
									Gunluk_Hex(OrnekYazi4->Isaretci, OrnekYazi4->Kapasite);
	
									Gunluk("Komut --- Komut");
									Gunluk_Hex(Komut->Isaretci, Komut->Kapasite);
	
									if (OrnekYazi4)
									{
										Gunluk("OrnekYazi1 %s", OrnekYazi1->Isaretci);
										Gunluk("OrnekYazi2 %s", OrnekYazi2->Isaretci);
										Gunluk("OrnekYazi3 %s", OrnekYazi3->Isaretci);
										Gunluk("OrnekYazi4 %s", OrnekYazi4->Isaretci);
	
										DizidekiKonum = KomutSatiri_KontrolEt_Siradaki_DizidekiElemanlardanBiriMi(Komut, dizi, 5);
										Gunluk("DizidekiKonum = KomutSatiri_KontrolEt_Siradaki_DizidekiElemanlardanBiriMi(Komut, dizi, 5); -> %d", DizidekiKonum);
	
										if (Hex)
										{
											KomutSatiri_Cevapla_Onay(Cevap);
											Gunluk("Cevap --- KomutSatiri_Cevapla_Onay(Cevap);");
											Gunluk_Hex(Cevap->Isaretci, Cevap->Kapasite);
										}
									}
								}
							}
						}
					}
				}
			}
	    }
	    else Gunluk("Komut_Baslangici %p, Komut_Bitisi %p, YeterliSayidaKarakterVarMi %d, DonanimAdresi %d", Detaylar.Komut_Baslangici, Detaylar.Komut_Bitisi, Detaylar.YeterliSayidaKarakterVarMi, Detaylar.DonanimAdresi);
	
	    char * _Cevap_ = Isaretci_Konumlandir(Cevap->Isaretci, 0, char, char); (void)_Cevap_;
	
	    if (Tampon_DoluAlan(Cevap) == 0)
		{
	    	Gunluk("Tampon_DoluAlan(Cevap) -> %d", DizidekiKonum);
	
	    	KomutSatiri_Cevapla_Ret(Cevap, "Parametrelerden biri hatali");
	    	Gunluk("KomutSatiri_Cevapla_Ret(Cevap, \"Parametrelerden biri hatali\");");
	    	Gunluk_Hex(Cevap->Isaretci, Cevap->Kapasite);
		}
	    else
	    {
	        Tampon_DoluAlan(Cevap) = 0;
	        KomutSatiri_Cevap_Ekle(Cevap, "Serbest Cevap %d", 35);
	        Gunluk("KomutSatiri_Cevap_Ekle(Cevap, \"Serbest Cevap %d\", 35);");
	        Gunluk_Hex(Cevap->Isaretci, Cevap->Kapasite);
	
	        Tampon_DoluAlan(Cevap) = 0;
	        KomutSatiri_Cevapla_Hex(Cevap, Hex);
	        Gunluk("KomutSatiri_Cevapla_Hex(Cevap, Hex);");
	        Gunluk_Hex(Cevap->Isaretci, Cevap->Kapasite);
	
	        Tampon_DoluAlan(Cevap) = 0;
	        KomutSatiri_Cevapla_Onay(Cevap);
	        Gunluk("KomutSatiri_Cevapla_Onay(Cevap);");
	        Gunluk_Hex(Cevap->Isaretci, Cevap->Kapasite);
	
	        Tampon_DoluAlan(Cevap) = 0;
	        KomutSatiri_Cevapla_TamSayi(Cevap, 35);
	        Gunluk("KomutSatiri_Cevapla_TamSayi(Cevap, 35);");
	        Gunluk_Hex(Cevap->Isaretci, Cevap->Kapasite);
	
	        Tampon_DoluAlan(Cevap) = 0;
	        KomutSatiri_Cevapla_Yazi(Cevap, "Serbest Yazi");
	        Gunluk("KomutSatiri_Cevapla_Yazi(Cevap, \"Serbest Yazi\");");
	        Gunluk_Hex(Cevap->Isaretci, Cevap->Kapasite);
	    }
	
	    Tampon_Sil(Hex);
	    Tampon_Sil(Komut);
	    Tampon_Sil(Cevap);
	    Tampon_Sil(OrnekYazi1);
	    Tampon_Sil(OrnekYazi2);
	    Tampon_Sil(OrnekYazi3);
	    Tampon_Sil(OrnekYazi4);
	
	//    0-9697797 KaynakKod.c -----Ornek_KomutSatiri-----
	//    0-9697797 KaynakKod.c #define KomutMetni "GuRuLtu Kart 1 ...
	//    0-9697797 KaynakKod.c GuRuLtu Kart 1 Komut1 -987654 Komut2 "Alisildik yazi ornegi" 0x112233445566778899AABBCCDDEEFF AyiracsizTekParcaYaziOrnegi OzelKarakterli_AyiracsizTekParcaYaziOrnegi|51| "Alisildik ozel karakterli yazi ornegi|52|" Komut3
	//     GuRuLtu
	//    0-9697797 KaynakKod.c Komut --- Tampon_Bilgi_Ekle_GecerliKonumdanItibaren(Komut, KomutMetni, strlen(KomutMetni));
	//    0-9697797 KaynakKod.c Adet:00256 | Hex | Konum | Ascii
	//    0-9697797 KaynakKod.c 47 75 52 75 4C 74 75 20 4B 61 72 74 20 31 20 4B | 0000 - 000F | GuRuLtu Kart 1 K
	//    0-9697797 KaynakKod.c 6F 6D 75 74 31 20 2D 39 38 37 36 35 34 20 4B 6F | 0010 - 001F | omut1 -987654 Ko
	//    0-9697797 KaynakKod.c 6D 75 74 32 20 22 41 6C 69 73 69 6C 64 69 6B 20 | 0020 - 002F | mut2 "Alisildik
	//    0-9697797 KaynakKod.c 79 61 7A 69 20 6F 72 6E 65 67 69 22 20 30 78 31 | 0030 - 003F | yazi ornegi" 0x1
	//    0-9697797 KaynakKod.c 31 32 32 33 33 34 34 35 35 36 36 37 37 38 38 39 | 0040 - 004F | 1223344556677889
	//    0-9697797 KaynakKod.c 39 41 41 42 42 43 43 44 44 45 45 46 46 20 41 79 | 0050 - 005F | 9AABBCCDDEEFF Ay
	//    0-9697797 KaynakKod.c 69 72 61 63 73 69 7A 54 65 6B 50 61 72 63 61 59 | 0060 - 006F | iracsizTekParcaY
	//    0-9697797 KaynakKod.c 61 7A 69 4F 72 6E 65 67 69 20 4F 7A 65 6C 4B 61 | 0070 - 007F | aziOrnegi OzelKa
	//    0-9697797 KaynakKod.c 72 61 6B 74 65 72 6C 69 5F 41 79 69 72 61 63 73 | 0080 - 008F | rakterli_Ayiracs
	//    0-9697797 KaynakKod.c 69 7A 54 65 6B 50 61 72 63 61 59 61 7A 69 4F 72 | 0090 - 009F | izTekParcaYaziOr
	//    0-9697797 KaynakKod.c 6E 65 67 69 7C 35 31 7C 20 22 41 6C 69 73 69 6C | 00A0 - 00AF | negi|51| "Alisil
	//    0-9697797 KaynakKod.c 64 69 6B 20 6F 7A 65 6C 20 6B 61 72 61 6B 74 65 | 00B0 - 00BF | dik ozel karakte
	//    0-9697797 KaynakKod.c 72 6C 69 20 79 61 7A 69 20 6F 72 6E 65 67 69 7C | 00C0 - 00CF | rli yazi ornegi|
	//    0-9697797 KaynakKod.c 35 32 7C 22 20 4B 6F 6D 75 74 33 0D 0A 20 47 75 | 00D0 - 00DF | 52|" Komut3   Gu
	//    0-9697797 KaynakKod.c 52 75 4C 74 75 00 00 00 00 00 00 00 00 00 00 00 | 00E0 - 00EF | RuLtu
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00F0 - 00FF |
	//    0-9697797 KaynakKod.c Komut --- if (KomutSatiri_Baslat(Komut, UzunKomut, &Detaylar))
	//    0-9697797 KaynakKod.c Komut_Baslangici 00007ff6152c60a8, Komut_Bitisi 00007ff6152c617b, YeterliSayidaKarakterVarMi 1, DonanimAdresi 1
	//    0-9697797 KaynakKod.c Adet:00204 | Hex | Konum | Ascii
	//    0-9697797 KaynakKod.c 4B 6F 6D 75 74 31 20 2D 39 38 37 36 35 34 20 4B | 0000 - 000F | Komut1 -987654 K
	//    0-9697797 KaynakKod.c 6F 6D 75 74 32 20 22 41 6C 69 73 69 6C 64 69 6B | 0010 - 001F | omut2 "Alisildik
	//    0-9697797 KaynakKod.c 20 79 61 7A 69 20 6F 72 6E 65 67 69 22 20 30 78 | 0020 - 002F |  yazi ornegi" 0x
	//    0-9697797 KaynakKod.c 31 31 32 32 33 33 34 34 35 35 36 36 37 37 38 38 | 0030 - 003F | 1122334455667788
	//    0-9697797 KaynakKod.c 39 39 41 41 42 42 43 43 44 44 45 45 46 46 20 41 | 0040 - 004F | 99AABBCCDDEEFF A
	//    0-9697797 KaynakKod.c 79 69 72 61 63 73 69 7A 54 65 6B 50 61 72 63 61 | 0050 - 005F | yiracsizTekParca
	//    0-9697797 KaynakKod.c 59 61 7A 69 4F 72 6E 65 67 69 20 4F 7A 65 6C 4B | 0060 - 006F | YaziOrnegi OzelK
	//    0-9697797 KaynakKod.c 61 72 61 6B 74 65 72 6C 69 5F 41 79 69 72 61 63 | 0070 - 007F | arakterli_Ayirac
	//    0-9697797 KaynakKod.c 73 69 7A 54 65 6B 50 61 72 63 61 59 61 7A 69 4F | 0080 - 008F | sizTekParcaYaziO
	//    0-9697797 KaynakKod.c 72 6E 65 67 69 7C 35 31 7C 20 22 41 6C 69 73 69 | 0090 - 009F | rnegi|51| "Alisi
	//    0-9697797 KaynakKod.c 6C 64 69 6B 20 6F 7A 65 6C 20 6B 61 72 61 6B 74 | 00A0 - 00AF | ldik ozel karakt
	//    0-9697797 KaynakKod.c 65 72 6C 69 20 79 61 7A 69 20 6F 72 6E 65 67 69 | 00B0 - 00BF | erli yazi ornegi
	//    0-9697797 KaynakKod.c 7C 35 32 7C 22 20 4B 6F 6D 75 74 33 | 00C0 - 00CB | |52|" Komut3
	//    0-9697797 KaynakKod.c Komut --- if (KomutSatiri_KontrolEt_Siradaki_BuMu(Komut, _KomutSatiri_Komut_Komut1))
	//    0-9697797 KaynakKod.c Adet:00197 | Hex | Konum | Ascii
	//    0-9697797 KaynakKod.c 2D 39 38 37 36 35 34 20 4B 6F 6D 75 74 32 20 22 | 0000 - 000F | -987654 Komut2 "
	//    0-9697797 KaynakKod.c 41 6C 69 73 69 6C 64 69 6B 20 79 61 7A 69 20 6F | 0010 - 001F | Alisildik yazi o
	//    0-9697797 KaynakKod.c 72 6E 65 67 69 22 20 30 78 31 31 32 32 33 33 34 | 0020 - 002F | rnegi" 0x1122334
	//    0-9697797 KaynakKod.c 34 35 35 36 36 37 37 38 38 39 39 41 41 42 42 43 | 0030 - 003F | 45566778899AABBC
	//    0-9697797 KaynakKod.c 43 44 44 45 45 46 46 20 41 79 69 72 61 63 73 69 | 0040 - 004F | CDDEEFF Ayiracsi
	//    0-9697797 KaynakKod.c 7A 54 65 6B 50 61 72 63 61 59 61 7A 69 4F 72 6E | 0050 - 005F | zTekParcaYaziOrn
	//    0-9697797 KaynakKod.c 65 67 69 20 4F 7A 65 6C 4B 61 72 61 6B 74 65 72 | 0060 - 006F | egi OzelKarakter
	//    0-9697797 KaynakKod.c 6C 69 5F 41 79 69 72 61 63 73 69 7A 54 65 6B 50 | 0070 - 007F | li_AyiracsizTekP
	//    0-9697797 KaynakKod.c 61 72 63 61 59 61 7A 69 4F 72 6E 65 67 69 7C 35 | 0080 - 008F | arcaYaziOrnegi|5
	//    0-9697797 KaynakKod.c 31 7C 20 22 41 6C 69 73 69 6C 64 69 6B 20 6F 7A | 0090 - 009F | 1| "Alisildik oz
	//    0-9697797 KaynakKod.c 65 6C 20 6B 61 72 61 6B 74 65 72 6C 69 20 79 61 | 00A0 - 00AF | el karakterli ya
	//    0-9697797 KaynakKod.c 7A 69 20 6F 72 6E 65 67 69 7C 35 32 7C 22 20 4B | 00B0 - 00BF | zi ornegi|52|" K
	//    0-9697797 KaynakKod.c 6F 6D 75 74 33 | 00C0 - 00C4 | omut3
	//    0-9697797 KaynakKod.c Komut --- if (KomutSatiri_Oku_TamSayi(Komut, &Tamsayi))
	//    0-9697797 KaynakKod.c Adet:00189 | Hex | Konum | Ascii
	//    0-9697797 KaynakKod.c 4B 6F 6D 75 74 32 20 22 41 6C 69 73 69 6C 64 69 | 0000 - 000F | Komut2 "Alisildi
	//    0-9697797 KaynakKod.c 6B 20 79 61 7A 69 20 6F 72 6E 65 67 69 22 20 30 | 0010 - 001F | k yazi ornegi" 0
	//    0-9697797 KaynakKod.c 78 31 31 32 32 33 33 34 34 35 35 36 36 37 37 38 | 0020 - 002F | x112233445566778
	//    0-9697797 KaynakKod.c 38 39 39 41 41 42 42 43 43 44 44 45 45 46 46 20 | 0030 - 003F | 899AABBCCDDEEFF
	//    0-9697797 KaynakKod.c 41 79 69 72 61 63 73 69 7A 54 65 6B 50 61 72 63 | 0040 - 004F | AyiracsizTekParc
	//    0-9697797 KaynakKod.c 61 59 61 7A 69 4F 72 6E 65 67 69 20 4F 7A 65 6C | 0050 - 005F | aYaziOrnegi Ozel
	//    0-9697797 KaynakKod.c 4B 61 72 61 6B 74 65 72 6C 69 5F 41 79 69 72 61 | 0060 - 006F | Karakterli_Ayira
	//    0-9697797 KaynakKod.c 63 73 69 7A 54 65 6B 50 61 72 63 61 59 61 7A 69 | 0070 - 007F | csizTekParcaYazi
	//    0-9697797 KaynakKod.c 4F 72 6E 65 67 69 7C 35 31 7C 20 22 41 6C 69 73 | 0080 - 008F | Ornegi|51| "Alis
	//    0-9697797 KaynakKod.c 69 6C 64 69 6B 20 6F 7A 65 6C 20 6B 61 72 61 6B | 0090 - 009F | ildik ozel karak
	//    0-9697797 KaynakKod.c 74 65 72 6C 69 20 79 61 7A 69 20 6F 72 6E 65 67 | 00A0 - 00AF | terli yazi orneg
	//    0-9697797 KaynakKod.c 69 7C 35 32 7C 22 20 4B 6F 6D 75 74 33 | 00B0 - 00BC | i|52|" Komut3
	//    0-9697797 KaynakKod.c Komut --- if (KomutSatiri_KontrolEt_Siradaki_BuMu(Komut, _KomutSatiri_Komut_Komut2))
	//    0-9697797 KaynakKod.c Adet:00182 | Hex | Konum | Ascii
	//    0-9697797 KaynakKod.c 22 41 6C 69 73 69 6C 64 69 6B 20 79 61 7A 69 20 | 0000 - 000F | "Alisildik yazi
	//    0-9697797 KaynakKod.c 6F 72 6E 65 67 69 22 20 30 78 31 31 32 32 33 33 | 0010 - 001F | ornegi" 0x112233
	//    0-9697797 KaynakKod.c 34 34 35 35 36 36 37 37 38 38 39 39 41 41 42 42 | 0020 - 002F | 445566778899AABB
	//    0-9697797 KaynakKod.c 43 43 44 44 45 45 46 46 20 41 79 69 72 61 63 73 | 0030 - 003F | CCDDEEFF Ayiracs
	//    0-9697797 KaynakKod.c 69 7A 54 65 6B 50 61 72 63 61 59 61 7A 69 4F 72 | 0040 - 004F | izTekParcaYaziOr
	//    0-9697797 KaynakKod.c 6E 65 67 69 20 4F 7A 65 6C 4B 61 72 61 6B 74 65 | 0050 - 005F | negi OzelKarakte
	//    0-9697797 KaynakKod.c 72 6C 69 5F 41 79 69 72 61 63 73 69 7A 54 65 6B | 0060 - 006F | rli_AyiracsizTek
	//    0-9697797 KaynakKod.c 50 61 72 63 61 59 61 7A 69 4F 72 6E 65 67 69 7C | 0070 - 007F | ParcaYaziOrnegi|
	//    0-9697797 KaynakKod.c 35 31 7C 20 22 41 6C 69 73 69 6C 64 69 6B 20 6F | 0080 - 008F | 51| "Alisildik o
	//    0-9697797 KaynakKod.c 7A 65 6C 20 6B 61 72 61 6B 74 65 72 6C 69 20 79 | 0090 - 009F | zel karakterli y
	//    0-9697797 KaynakKod.c 61 7A 69 20 6F 72 6E 65 67 69 7C 35 32 7C 22 20 | 00A0 - 00AF | azi ornegi|52|"
	//    0-9697797 KaynakKod.c 4B 6F 6D 75 74 33 | 00B0 - 00B5 | Komut3
	//    0-9697797 KaynakKod.c OrnekYazi1 --- OrnekYazi1 = KomutSatiri_Oku_Yazi(Komut);
	//    0-9697797 KaynakKod.c Adet:00022 | Hex | Konum | Ascii
	//    0-9697797 KaynakKod.c 41 6C 69 73 69 6C 64 69 6B 20 79 61 7A 69 20 6F | 0000 - 000F | Alisildik yazi o
	//    0-9697797 KaynakKod.c 72 6E 65 67 69 00 | 0010 - 0015 | rnegi
	//    0-9697797 KaynakKod.c Komut --- Komut
	//    0-9697797 KaynakKod.c Adet:00158 | Hex | Konum | Ascii
	//    0-9697797 KaynakKod.c 30 78 31 31 32 32 33 33 34 34 35 35 36 36 37 37 | 0000 - 000F | 0x11223344556677
	//    0-9697797 KaynakKod.c 38 38 39 39 41 41 42 42 43 43 44 44 45 45 46 46 | 0010 - 001F | 8899AABBCCDDEEFF
	//    0-9697797 KaynakKod.c 20 41 79 69 72 61 63 73 69 7A 54 65 6B 50 61 72 | 0020 - 002F |  AyiracsizTekPar
	//    0-9697797 KaynakKod.c 63 61 59 61 7A 69 4F 72 6E 65 67 69 20 4F 7A 65 | 0030 - 003F | caYaziOrnegi Oze
	//    0-9697797 KaynakKod.c 6C 4B 61 72 61 6B 74 65 72 6C 69 5F 41 79 69 72 | 0040 - 004F | lKarakterli_Ayir
	//    0-9697797 KaynakKod.c 61 63 73 69 7A 54 65 6B 50 61 72 63 61 59 61 7A | 0050 - 005F | acsizTekParcaYaz
	//    0-9697797 KaynakKod.c 69 4F 72 6E 65 67 69 7C 35 31 7C 20 22 41 6C 69 | 0060 - 006F | iOrnegi|51| "Ali
	//    0-9697797 KaynakKod.c 73 69 6C 64 69 6B 20 6F 7A 65 6C 20 6B 61 72 61 | 0070 - 007F | sildik ozel kara
	//    0-9697797 KaynakKod.c 6B 74 65 72 6C 69 20 79 61 7A 69 20 6F 72 6E 65 | 0080 - 008F | kterli yazi orne
	//    0-9697797 KaynakKod.c 67 69 7C 35 32 7C 22 20 4B 6F 6D 75 74 33 | 0090 - 009D | gi|52|" Komut3
	//    0-9697797 KaynakKod.c Hex --- Hex = KomutSatiri_Oku_Hex(Komut);
	//    0-9697797 KaynakKod.c Adet:00015 | Hex | Konum | Ascii
	//    0-9697797 KaynakKod.c 11 22 33 44 55 66 77 88 99 AA BB CC DD EE FF | 0000 - 000E |  "3DUfw
	//    0-9697797 KaynakKod.c Komut --- Komut
	//    0-9697797 KaynakKod.c Adet:00125 | Hex | Konum | Ascii
	//    0-9697797 KaynakKod.c 41 79 69 72 61 63 73 69 7A 54 65 6B 50 61 72 63 | 0000 - 000F | AyiracsizTekParc
	//    0-9697797 KaynakKod.c 61 59 61 7A 69 4F 72 6E 65 67 69 20 4F 7A 65 6C | 0010 - 001F | aYaziOrnegi Ozel
	//    0-9697797 KaynakKod.c 4B 61 72 61 6B 74 65 72 6C 69 5F 41 79 69 72 61 | 0020 - 002F | Karakterli_Ayira
	//    0-9697797 KaynakKod.c 63 73 69 7A 54 65 6B 50 61 72 63 61 59 61 7A 69 | 0030 - 003F | csizTekParcaYazi
	//    0-9697797 KaynakKod.c 4F 72 6E 65 67 69 7C 35 31 7C 20 22 41 6C 69 73 | 0040 - 004F | Ornegi|51| "Alis
	//    0-9697797 KaynakKod.c 69 6C 64 69 6B 20 6F 7A 65 6C 20 6B 61 72 61 6B | 0050 - 005F | ildik ozel karak
	//    0-9697797 KaynakKod.c 74 65 72 6C 69 20 79 61 7A 69 20 6F 72 6E 65 67 | 0060 - 006F | terli yazi orneg
	//    0-9697797 KaynakKod.c 69 7C 35 32 7C 22 20 4B 6F 6D 75 74 33 | 0070 - 007C | i|52|" Komut3
	//    0-9697797 KaynakKod.c OrnekYazi2 --- OrnekYazi2 = KomutSatiri_Oku_Yazi(Komut);
	//    0-9697797 KaynakKod.c Adet:00028 | Hex | Konum | Ascii
	//    0-9697797 KaynakKod.c 41 79 69 72 61 63 73 69 7A 54 65 6B 50 61 72 63 | 0000 - 000F | AyiracsizTekParc
	//    0-9697797 KaynakKod.c 61 59 61 7A 69 4F 72 6E 65 67 69 00 | 0010 - 001B | aYaziOrnegi
	//    0-9697797 KaynakKod.c Komut --- Komut
	//    0-9697797 KaynakKod.c Adet:00097 | Hex | Konum | Ascii
	//    0-9697797 KaynakKod.c 4F 7A 65 6C 4B 61 72 61 6B 74 65 72 6C 69 5F 41 | 0000 - 000F | OzelKarakterli_A
	//    0-9697797 KaynakKod.c 79 69 72 61 63 73 69 7A 54 65 6B 50 61 72 63 61 | 0010 - 001F | yiracsizTekParca
	//    0-9697797 KaynakKod.c 59 61 7A 69 4F 72 6E 65 67 69 7C 35 31 7C 20 22 | 0020 - 002F | YaziOrnegi|51| "
	//    0-9697797 KaynakKod.c 41 6C 69 73 69 6C 64 69 6B 20 6F 7A 65 6C 20 6B | 0030 - 003F | Alisildik ozel k
	//    0-9697797 KaynakKod.c 61 72 61 6B 74 65 72 6C 69 20 79 61 7A 69 20 6F | 0040 - 004F | arakterli yazi o
	//    0-9697797 KaynakKod.c 72 6E 65 67 69 7C 35 32 7C 22 20 4B 6F 6D 75 74 | 0050 - 005F | rnegi|52|" Komut
	//    0-9697797 KaynakKod.c 33 | 0060 - 0060 | 3
	//    0-9697797 KaynakKod.c OrnekYazi3 --- OrnekYazi3 = KomutSatiri_Oku_Yazi(Komut);
	//    0-9697797 KaynakKod.c Adet:00044 | Hex | Konum | Ascii
	//    0-9697797 KaynakKod.c 4F 7A 65 6C 4B 61 72 61 6B 74 65 72 6C 69 5F 41 | 0000 - 000F | OzelKarakterli_A
	//    0-9697797 KaynakKod.c 79 69 72 61 63 73 69 7A 54 65 6B 50 61 72 63 61 | 0010 - 001F | yiracsizTekParca
	//    0-9697797 KaynakKod.c 59 61 7A 69 4F 72 6E 65 67 69 33 00 | 0020 - 002B | YaziOrnegi3
	//    0-9697797 KaynakKod.c Komut --- Komut
	//    0-9697797 KaynakKod.c Adet:00050 | Hex | Konum | Ascii
	//    0-9697797 KaynakKod.c 22 41 6C 69 73 69 6C 64 69 6B 20 6F 7A 65 6C 20 | 0000 - 000F | "Alisildik ozel
	//    0-9697797 KaynakKod.c 6B 61 72 61 6B 74 65 72 6C 69 20 79 61 7A 69 20 | 0010 - 001F | karakterli yazi
	//    0-9697797 KaynakKod.c 6F 72 6E 65 67 69 7C 35 32 7C 22 20 4B 6F 6D 75 | 0020 - 002F | ornegi|52|" Komu
	//    0-9697797 KaynakKod.c 74 33 | 0030 - 0031 | t3
	//    0-9697797 KaynakKod.c OrnekYazi4 --- OrnekYazi4 = KomutSatiri_Oku_Yazi(Komut);
	//    0-9697797 KaynakKod.c Adet:00039 | Hex | Konum | Ascii
	//    0-9697797 KaynakKod.c 41 6C 69 73 69 6C 64 69 6B 20 6F 7A 65 6C 20 6B | 0000 - 000F | Alisildik ozel k
	//    0-9697797 KaynakKod.c 61 72 61 6B 74 65 72 6C 69 20 79 61 7A 69 20 6F | 0010 - 001F | arakterli yazi o
	//    0-9697797 KaynakKod.c 72 6E 65 67 69 34 00 | 0020 - 0026 | rnegi4
	//    0-9697797 KaynakKod.c Komut --- Komut
	//    0-9697797 KaynakKod.c Adet:00006 | Hex | Konum | Ascii
	//    0-9697797 KaynakKod.c 4B 6F 6D 75 74 33 | 0000 - 0005 | Komut3
	//    0-9697797 KaynakKod.c OrnekYazi1 Alisildik yazi ornegi
	//    0-9697797 KaynakKod.c OrnekYazi2 AyiracsizTekParcaYaziOrnegi
	//    0-9697797 KaynakKod.c OrnekYazi3 OzelKarakterli_AyiracsizTekParcaYaziOrnegi3
	//    0-9697797 KaynakKod.c OrnekYazi4 Alisildik ozel karakterli yazi ornegi4
	//    0-9697797 KaynakKod.c DizidekiKonum = KomutSatiri_KontrolEt_Siradaki_DizidekiElemanlardanBiriMi(Komut, dizi, 5); -> 2
	//    0-9697797 KaynakKod.c Cevap --- KomutSatiri_Cevapla_Onay(Cevap);
	//    0-9697797 KaynakKod.c Adet:00256 | Hex | Konum | Ascii
	//    0-9697797 KaynakKod.c 3E 3E 54 61 6D 61 6D 0D 0A 00 00 00 00 00 00 00 | 0000 - 000F | >>Tamam
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0010 - 001F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0020 - 002F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0030 - 003F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0040 - 004F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0050 - 005F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0060 - 006F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0070 - 007F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0080 - 008F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0090 - 009F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00A0 - 00AF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00B0 - 00BF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00C0 - 00CF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00D0 - 00DF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00E0 - 00EF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00F0 - 00FF |
	//    0-9697797 KaynakKod.c KomutSatiri_Cevap_Ekle(Cevap, "Serbest Cevap -858993459", 35);
	//    0-9697797 KaynakKod.c Adet:00256 | Hex | Konum | Ascii
	//    0-9697797 KaynakKod.c 53 65 72 62 65 73 74 20 43 65 76 61 70 20 33 35 | 0000 - 000F | Serbest Cevap 35
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0010 - 001F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0020 - 002F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0030 - 003F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0040 - 004F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0050 - 005F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0060 - 006F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0070 - 007F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0080 - 008F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0090 - 009F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00A0 - 00AF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00B0 - 00BF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00C0 - 00CF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00D0 - 00DF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00E0 - 00EF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00F0 - 00FF |
	//    0-9697797 KaynakKod.c KomutSatiri_Cevapla_Hex(Cevap, Hex);
	//    0-9697797 KaynakKod.c Adet:00256 | Hex | Konum | Ascii
	//    0-9697797 KaynakKod.c 3E 3E 30 78 31 31 32 32 33 33 34 34 35 35 36 36 | 0000 - 000F | >>0x112233445566
	//    0-9697797 KaynakKod.c 37 37 38 38 39 39 41 41 42 42 43 43 44 44 45 45 | 0010 - 001F | 778899AABBCCDDEE
	//    0-9697797 KaynakKod.c 46 46 0D 0A 00 00 00 00 00 00 00 00 00 00 00 00 | 0020 - 002F | FF
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0030 - 003F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0040 - 004F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0050 - 005F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0060 - 006F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0070 - 007F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0080 - 008F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0090 - 009F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00A0 - 00AF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00B0 - 00BF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00C0 - 00CF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00D0 - 00DF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00E0 - 00EF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00F0 - 00FF |
	//    0-9697797 KaynakKod.c KomutSatiri_Cevapla_Onay(Cevap);
	//    0-9697797 KaynakKod.c Adet:00256 | Hex | Konum | Ascii
	//    0-9697797 KaynakKod.c 3E 3E 54 61 6D 61 6D 0D 0A 00 34 34 35 35 36 36 | 0000 - 000F | >>Tamam   445566
	//    0-9697797 KaynakKod.c 37 37 38 38 39 39 41 41 42 42 43 43 44 44 45 45 | 0010 - 001F | 778899AABBCCDDEE
	//    0-9697797 KaynakKod.c 46 46 0D 0A 00 00 00 00 00 00 00 00 00 00 00 00 | 0020 - 002F | FF
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0030 - 003F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0040 - 004F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0050 - 005F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0060 - 006F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0070 - 007F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0080 - 008F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0090 - 009F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00A0 - 00AF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00B0 - 00BF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00C0 - 00CF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00D0 - 00DF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00E0 - 00EF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00F0 - 00FF |
	//    0-9697797 KaynakKod.c KomutSatiri_Cevapla_TamSayi(Cevap, 35);
	//    0-9697797 KaynakKod.c Adet:00256 | Hex | Konum | Ascii
	//    0-9697797 KaynakKod.c 3E 3E 33 35 0D 0A 00 0D 0A 00 34 34 35 35 36 36 | 0000 - 000F | >>35      445566
	//    0-9697797 KaynakKod.c 37 37 38 38 39 39 41 41 42 42 43 43 44 44 45 45 | 0010 - 001F | 778899AABBCCDDEE
	//    0-9697797 KaynakKod.c 46 46 0D 0A 00 00 00 00 00 00 00 00 00 00 00 00 | 0020 - 002F | FF
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0030 - 003F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0040 - 004F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0050 - 005F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0060 - 006F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0070 - 007F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0080 - 008F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0090 - 009F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00A0 - 00AF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00B0 - 00BF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00C0 - 00CF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00D0 - 00DF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00E0 - 00EF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00F0 - 00FF |
	//    0-9697797 KaynakKod.c KomutSatiri_Cevapla_Yazi(Cevap, "Serbest Yazi");
	//    0-9697797 KaynakKod.c Adet:00256 | Hex | Konum | Ascii
	//    0-9697797 KaynakKod.c 3E 3E 22 53 65 72 62 65 73 74 20 59 61 7A 69 22 | 0000 - 000F | >>"Serbest Yazi"
	//    0-9697797 KaynakKod.c 0D 0A 00 38 39 39 41 41 42 42 43 43 44 44 45 45 | 0010 - 001F |    899AABBCCDDEE
	//    0-9697797 KaynakKod.c 46 46 0D 0A 00 00 00 00 00 00 00 00 00 00 00 00 | 0020 - 002F | FF
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0030 - 003F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0040 - 004F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0050 - 005F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0060 - 006F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0070 - 007F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0080 - 008F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 0090 - 009F |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00A0 - 00AF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00B0 - 00BF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00C0 - 00CF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00D0 - 00DF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00E0 - 00EF |
	//    0-9697797 KaynakKod.c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | 00F0 - 00FF |
	}
	
	void Ornek_Liste()
	{
		Gunluk("-----Ornek_Liste-----");
	
		Tip_Isaretci_Liste Liste =  Liste_Yeni();
		if (Liste == NULL) return;
	
		Tip_u8 Eleman1 = 1;
		Tip_u16 Eleman2 = 2;
	
		Tip_bool sonuc = Liste_Eleman_Ekle(Liste, &Eleman1);
		Gunluk("Tip_bool sonuc = Liste_Eleman_Ekle(Liste, &Eleman1); -> %d", sonuc);
	
		sonuc = Liste_Eleman_Ekle(Liste, &Eleman2);
		Gunluk("sonuc = Liste_Eleman_Ekle(Liste, &Eleman2); -> %d", sonuc);
	
		Tip_u32 * Eleman3 = Liste_Eleman_Ekle_VeYerTahsisEt(Liste, sizeof(Tip_u32), true);
		*Eleman3 = 3;
		Gunluk("Tip_u32 * Eleman3 = Liste_Eleman_Ekle_VeYerTahsisEt(Liste, sizeof(Tip_u32), true); -> 0x%X", (Tip_Isaretci_SayiKarsiligi)Eleman3);
	
		Tip_u8 Eleman1Okunan;
		memcpy(&Eleman1Okunan, Liste_Eleman_Ilk(Liste), sizeof(Tip_u8));
		Gunluk("memcpy(&Eleman1Okunan, Liste_Eleman_Ilk(Liste), sizeof(Tip_u8)); -> %d", Eleman1Okunan);
	
		Tip_u32 Eleman3Okunan;
		memcpy(&Eleman3Okunan, Liste_Eleman_Son(Liste), sizeof(Tip_u32));
		Gunluk("memcpy(&Eleman3Okunan, Liste_Eleman_Son(Liste), sizeof(Tip_u32)); -> %d", Eleman3Okunan);
	
		Gunluk("Liste_Eleman_Sayisi(Liste) -> %d", Liste_Eleman_Sayisi(Liste));
	
		Tip_u32 Sayac = 0;
		Liste_Kuyruk_DegiskeniniOlustur(Liste, KuyrukDegiskeni);
		while (KuyrukDegiskeni)
		{
			Tip_Isaretci Isrt = Liste_Kuyruk_SonrakiEleman(Liste, KuyrukDegiskeni);
			Gunluk("Sayac : %d --- Tip_Isaretci Isrt = Liste_Kuyruk_SonrakiEleman(Liste, KuyrukDegiskeni); -> 0x%X", ++Sayac, (Tip_Isaretci_SayiKarsiligi)Isrt);
	
			Isrt++;
			//Sirayla
		}
	
		Gunluk("Liste_Eleman_Sil(Liste, &Eleman1, false); -> %d", Liste_Eleman_Sil(Liste, &Eleman1, false));
		Gunluk("Liste_Eleman_Sil(Liste, Eleman3, true); -> %d", Liste_Eleman_Sil(Liste, Eleman3, true));
	
		Liste_Sil(Liste, false);
	
	//	0-10844376 KaynakKod.c -----Ornek_Liste-----
	//	0-10844376 KaynakKod.c Tip_bool sonuc = Liste_Eleman_Ekle(Liste, &Eleman1); -> 1
	//	0-10844376 KaynakKod.c sonuc = Liste_Eleman_Ekle(Liste, &Eleman2); -> 1
	//	0-10844376 KaynakKod.c Tip_u32 * Eleman3 = Liste_Eleman_Ekle_VeYerTahsisEt(Liste, sizeof(Tip_u32), true); -> 0xFE7C60F8
	//	0-10844376 KaynakKod.c memcpy(&Eleman1Okunan, Liste_Eleman_Ilk(Liste), sizeof(Tip_u8)); -> 1
	//	0-10844376 KaynakKod.c memcpy(&Eleman3Okunan, Liste_Eleman_Son(Liste), sizeof(Tip_u32)); -> 3
	//	0-10844376 KaynakKod.c Liste_Eleman_Sayisi(Liste) -> 3
	//	0-10844376 KaynakKod.c Sayac : 1 --- Tip_Isaretci Isrt = Liste_Kuyruk_SonrakiEleman(Liste, KuyrukDegiskeni); -> 0x8B7FF717
	//	0-10844376 KaynakKod.c Sayac : 2 --- Tip_Isaretci Isrt = Liste_Kuyruk_SonrakiEleman(Liste, KuyrukDegiskeni); -> 0x8B7FF714
	//	0-10844376 KaynakKod.c Sayac : 3 --- Tip_Isaretci Isrt = Liste_Kuyruk_SonrakiEleman(Liste, KuyrukDegiskeni); -> 0xFE7C60F8
	//	0-10844376 KaynakKod.c Liste_Eleman_Sil(Liste, &Eleman1, false); -> 1
	//	0-10844376 KaynakKod.c Liste_Eleman_Sil(Liste, Eleman3, true); -> 1
	}
	
	void Ornek_Tampon()
	{
		Gunluk("-----Ornek_Tampon-----");
	
		Tip_Isaretci_Tampon Tampon =  Tampon_Yeni(10, false);
		if (Tampon == NULL) return;
		Gunluk("Tip_Isaretci_Tampon Tampon = Tampon_Yeni(10); - isaretci 0x%X, Sayac %d, Kapasite %d", (Tip_Isaretci_SayiKarsiligi)Tampon->Isaretci, Tampon->Sayac, Tampon->Kapasite);
	
		Tip_char Kaynak[] = "ArGeMuP";
		Tip_bool sonuc = Tampon_Bilgi_Ekle_GecerliKonumdanItibaren(Tampon, Kaynak, strlen(Kaynak));
		Gunluk("Tip_bool sonuc = Tampon_Bilgi_Ekle_GecerliKonumdanItibaren(Tampon, Kaynak, strlen(Kaynak)); -> %d", sonuc);
		Gunluk("Tampon_Bilgi_Ekle_GecerliKonumdanItibaren - isaretci 0x%X, Sayac %d, Kapasite %d", (Tip_Isaretci_SayiKarsiligi)Tampon->Isaretci, Tampon->Sayac, Tampon->Kapasite);
		Gunluk_Hex( Tampon->Isaretci, Tampon->Kapasite );
	
		Tip_u32 Adet = Tampon_Kapasite(Tampon);
		Gunluk("Tip_u32 Adet = Tampon_Kapasite(Tampon); -> %d", Adet);
	
		Adet = Tampon_DoluAlan(Tampon);
		Gunluk("Adet = Tampon_DoluAlan(Tampon); -> %d", Adet);
	
		Adet = Tampon_BosAlan(Tampon);
		Gunluk("Adet = Tampon_BosAlan(Tampon); -> %d", Adet);
	
		Tip_char okunan_blok[strlen(Kaynak)];
		Adet = Tampon_Bilgi_Oku_Konum(Tampon, 0, okunan_blok, sizeof(okunan_blok));
		Gunluk("Adet = Tampon_Bilgi_Oku_Konum(Tampon, 0, okunan_blok, sizeof(okunan_blok)); -> %d", Adet);
		Gunluk_Hex(Tampon->Isaretci, Adet);
	
		Tip_char okunan_blok2[2];
		Adet = Tampon_Bilgi_Oku_Konum(Tampon, 0, okunan_blok2, sizeof(okunan_blok2));
		Gunluk("Adet = Tampon_Bilgi_Oku_Konum(Tampon, 0, okunan_blok2, sizeof(okunan_blok2)); -> %d", Adet);
		Gunluk_Hex(okunan_blok2, Adet);
	
		Adet = Tampon_Bilgi_Oku_Konum(Tampon, 2, okunan_blok2, sizeof(okunan_blok2));
		Gunluk("Adet = Tampon_Bilgi_Oku_Konum(Tampon, 2, okunan_blok2, sizeof(okunan_blok2)); -> %d", Adet);
		Gunluk_Hex(okunan_blok2, Adet);
	
		Adet = Tampon_Bilgi_Oku_BaslangictanGecerliKonumaKadar(Tampon, okunan_blok2, sizeof(okunan_blok2));
		Gunluk("Adet = Tampon_Bilgi_Oku_BaslangictanGecerliKonumaKadar(Tampon, okunan_blok2, sizeof(okunan_blok2)); -> %d", Adet);
		Gunluk_Hex(okunan_blok2, Adet);
	
		Adet = Tampon_DoluAlan(Tampon);
		Gunluk("Adet = Tampon_DoluAlan(Tampon); -> %d", Adet);
	
		Tampon_Sil(Tampon);
		Tampon = Tampon_Yeni(10, false);
		Gunluk("Tampon_Yeni(10); - isaretci 0x%X, Sayac %d, Kapasite %d", (Tip_Isaretci_SayiKarsiligi)Tampon->Isaretci, Tampon->Sayac, Tampon->Kapasite);
	
		Tampon_DoluAlan(Tampon) = 5;
		Gunluk("Tampon_DoluAlan(Tampon) = 5; - isaretci 0x%X, Sayac %d, Kapasite %d", (Tip_Isaretci_SayiKarsiligi)Tampon->Isaretci, Tampon->Sayac, Tampon->Kapasite);
	
		Tampon_Paketle(Tampon);
		Gunluk("Tampon_Paketle(Tampon); - isaretci 0x%X, Sayac %d, Kapasite %d", (Tip_Isaretci_SayiKarsiligi)Tampon->Isaretci, Tampon->Sayac, Tampon->Kapasite);
	
		Tampon_Kirp(Tampon, 2, 1);
		Gunluk("Tampon_Kirp(Tampon, 2, 1); - isaretci 0x%X, Sayac %d, Kapasite %d", (Tip_Isaretci_SayiKarsiligi)Tampon->Isaretci, Tampon->Sayac, Tampon->Kapasite);
	
		Gunluk("IsiBitinceSil %d, Nesne %p", Tampon->KullaniciNesnesi.IsiBitinceSil, Tampon->KullaniciNesnesi.Nesne);
	
		Tampon_Sil(Tampon);
	
	//	0-10636282 KaynakKod.c -----Ornek_Tampon-----
	//	0-10636282 KaynakKod.c Tip_Isaretci_Tampon Tampon = Tampon_Yeni(10); - isaretci 0xF78560A0, Sayac 0, Kapasite 10
	//	0-10636282 KaynakKod.c Tip_bool sonuc = Tampon_Bilgi_Ekle_GecerliKonumdanItibaren(Tampon, Kaynak, strlen(Kaynak)); -> 1
	//	0-10636282 KaynakKod.c Tampon_Bilgi_Ekle_GecerliKonumdanItibaren - isaretci 0xF78560A0, Sayac 7, Kapasite 10
	//	0-10636282 KaynakKod.c Adet:00010 | Hex | Konum | Ascii
	//	0-10636282 KaynakKod.c 41 72 47 65 4D 75 50 00 00 00 | 0000 - 0009 | ArGeMuP
	//	0-10636282 KaynakKod.c Tip_u32 Adet = Tampon_Kapasite(Tampon); -> 10
	//	0-10636282 KaynakKod.c Adet = Tampon_DoluAlan(Tampon); -> 7
	//	0-10636282 KaynakKod.c Adet = Tampon_BosAlan(Tampon); -> 3
	//	0-10636282 KaynakKod.c Adet = Tampon_Bilgi_Oku_Konum(Tampon, 0, okunan_blok, sizeof(okunan_blok)); -> 7
	//	0-10636282 KaynakKod.c Adet:00007 | Hex | Konum | Ascii
	//	0-10636282 KaynakKod.c 41 72 47 65 4D 75 50 | 0000 - 0006 | ArGeMuP
	//	0-10636282 KaynakKod.c Adet = Tampon_Bilgi_Oku_Konum(Tampon, 0, okunan_blok2, sizeof(okunan_blok2)); -> 2
	//	0-10636282 KaynakKod.c Adet:00002 | Hex | Konum | Ascii
	//	0-10636282 KaynakKod.c 41 72 | 0000 - 0001 | Ar
	//	0-10636282 KaynakKod.c Adet = Tampon_Bilgi_Oku_Konum(Tampon, 2, okunan_blok2, sizeof(okunan_blok2)); -> 2
	//	0-10636282 KaynakKod.c Adet:00002 | Hex | Konum | Ascii
	//	0-10636282 KaynakKod.c 47 65 | 0000 - 0001 | Ge
	//	0-10636282 KaynakKod.c Adet = Tampon_Bilgi_Oku_BaslangictanGecerliKonumaKadar(Tampon, okunan_blok2, sizeof(okunan_blok2)); -> 2
	//	0-10636282 KaynakKod.c Adet:00002 | Hex | Konum | Ascii
	//	0-10636282 KaynakKod.c 41 72 | 0000 - 0001 | Ar
	//	0-10636282 KaynakKod.c Adet = Tampon_DoluAlan(Tampon); -> 5
	//	0-10636282 KaynakKod.c Tampon_Yeni(10); - isaretci 0xF78560A0, Sayac 0, Kapasite 10
	//	0-10636282 KaynakKod.c Tampon_DoluAlan(Tampon) = 5; - isaretci 0xF78560A0, Sayac 5, Kapasite 10
	//	0-10636282 KaynakKod.c Tampon_Paketle(Tampon); - isaretci 0xF78560A0, Sayac 0, Kapasite 5
	//	0-10636282 KaynakKod.c Tampon_Kirp(Tampon, 2, 1); - isaretci 0xF78560A2, Sayac 0, Kapasite 2
	//  0-10636282 KaynakKod.c IsiBitinceSil 0, Nesne 0000000000000000
	}
	
	void Ornek_YaziIslemleri()
	{
		Gunluk("-----Ornek_YaziIslemleri-----");
	
	    Tip_u32 konum = YI_Bul("123456789", "456");
	    Gunluk("Tip_u32 konum = YI_Bul(\"123456789\", \"456\"); -> %d", konum);
	
	    #define Kaynak2 "Adres : 192.168.0.1;Yol : 80;Kapasite : 8192"
	    Gunluk("#define Kaynak2 \"Adres : 192.168.0.1;Yol : 80;Kapasite : 8192\"");
	    #define ArananBaslangic "Yol :"
	    Gunluk("#define ArananBaslangic \"Yol :\"");
	    #define ArananBitis ";"
	    Gunluk("#define ArananBitis \";\"");
	
	    Tip_char Bulunan[256];
	
	    memset(Bulunan, 0x00, sizeof(Bulunan));
	    Tip_u32 adet = YI_Degistir(Kaynak2, "80", "ArGeMuP", Bulunan, sizeof(Bulunan), false);
	    Gunluk("Tip_u32 adet = YI_Degistir(Kaynak2, \"80\", \"ArGeMuP\", Bulunan, sizeof(Bulunan), false); -> Adet : %d ->%s<-", adet, Bulunan);
	
	    memset(Bulunan, 0xFF, sizeof(Bulunan));
	    adet = YI_BulAyiklaKopyala(Kaynak2, ArananBaslangic, ArananBitis, Bulunan, sizeof(Bulunan));
	    Gunluk("adet = YI_BulAyiklaKopyala(Kaynak2, ArananBaslangic, ArananBitis, Bulunan, sizeof(Bulunan)); -> Adet : %d ->%s<-", adet, Bulunan);
	
	    memset(Bulunan, 0xFF, sizeof(Bulunan));
	    adet = YI_BulAyiklaKopyala(Kaynak2, NULL, ArananBitis, Bulunan, sizeof(Bulunan));
	    Gunluk("adet = YI_BulAyiklaKopyala(Kaynak2, NULL, ArananBitis, Bulunan, sizeof(Bulunan)); -> Adet : %d ->%s<-", adet, Bulunan);
	
	    memset(Bulunan, 0xFF, sizeof(Bulunan));
	    adet = YI_BulAyiklaKopyala(Kaynak2, ArananBaslangic, NULL, Bulunan, sizeof(Bulunan));
	    Gunluk("adet = YI_BulAyiklaKopyala(Kaynak2, ArananBaslangic, NULL, Bulunan, sizeof(Bulunan)); -> Adet : %d ->%s<-", adet, Bulunan);
	
	    Gunluk("YI_Yazdir ->%s<-", YI_Yazdir(Bulunan, sizeof(Bulunan), "Deneme %d", 5));
	    Gunluk("YI_Yazdir_TarihSaat ->%s<-", YI_Yazdir_TarihSaat(Bulunan, sizeof(Bulunan), 0));
	    Gunluk("YI_Yazdir_NoktaliSayi ->%s<-", YI_Yazdir_NoktaliSayi(Bulunan, sizeof(Bulunan), 1.35));
	    Gunluk("YI_Yazdir_TamSayi_Hex ->%s<-", YI_Yazdir_TamSayi_Hex(Bulunan, sizeof(Bulunan), 65535));
	    Gunluk("YI_Yazdir_TamSayi ->%s<-", YI_Yazdir_TamSayi(Bulunan, sizeof(Bulunan), 65535));
	    Gunluk("YI_Yazdir_Hex_Tampon ->%s<-", YI_Yazdir_Hex_Tampon(Bulunan, sizeof(Bulunan), "123456789", strlen("123456789")));
	
	//    0-6775953 KaynakKod.c -----Ornek_YaziIslemleri-----
	//    0-6775953 KaynakKod.c Tip_u32 konum = YI_Bul("123456789", "456"); -> 3
	//    0-6775953 KaynakKod.c #define Kaynak2 "Adres : 192.168.0.1;Yol : 80;Kapasite : 8192"
	//    0-6775953 KaynakKod.c #define ArananBaslangic "Yol :"
	//    0-6775953 KaynakKod.c #define ArananBitis ";"
	//    0-6775953 KaynakKod.c Tip_u32 adet = YI_Degistir(Kaynak2, "80", "ArGeMuP", Bulunan, sizeof(Bulunan), false); -> Adet : 49 ->Adres : 192.168.0.1;Yol : ArGeMuP;Kapasite : 8192<-
	//    0-6775953 KaynakKod.c adet = YI_BulAyiklaKopyala(Kaynak2, ArananBaslangic, ArananBitis, Bulunan, sizeof(Bulunan)); -> Adet : 3 -> 80<-
	//    0-6775953 KaynakKod.c adet = YI_BulAyiklaKopyala(Kaynak2, NULL, ArananBitis, Bulunan, sizeof(Bulunan)); -> Adet : 19 ->Adres : 192.168.0.1<-
	//    0-6775953 KaynakKod.c adet = YI_BulAyiklaKopyala(Kaynak2, ArananBaslangic, NULL, Bulunan, sizeof(Bulunan)); -> Adet : 19 -> 80;Kapasite : 8192<-
	//    0-6775953 KaynakKod.c YI_Yazdir ->Deneme 5<-
	//    0-6775953 KaynakKod.c YI_Yazdir_TarihSaat -><-
	//    0-6775953 KaynakKod.c YI_Yazdir_NoktaliSayi ->1.35<-
	//    0-6775953 KaynakKod.c YI_Yazdir_TamSayi_Hex ->0x0000FFFF<-
	//    0-6775953 KaynakKod.c YI_Yazdir_TamSayi ->65535<-
	//    0-6775953 KaynakKod.c YI_Yazdir_Hex_Tampon ->0x313233343536373839<-
	}
	
	void Ornek_YerTahsisati()
	{
		Gunluk("-----Ornek_YerTahsisati-----");
	
		Tip_Isaretci Isrtc =  YT_Yeni(10, false);
		if (Isrtc == NULL) return;
	
		Gunluk("Tip_Isaretci Isrtc =  YT_Yeni(10, false); -> 0x%X", (Tip_Isaretci_SayiKarsiligi)Isrtc);
		YT_Sil(Isrtc);
	
	//	0-10606422 KaynakKod.c -----Ornek_YerTahsisati-----
	//	0-10606422 KaynakKod.c Tip_Isaretci Isrtc =  YT_Yeni(10, false); -> 0xAB2B6090
	}
	
	void Ornek_Zamanlama()
	{
		Gunluk("-----Ornek_Zamanlama-----");
		char Tampon[128];
	
		Sure_DegiskeniniOlustur(Sure);
		Gunluk("Sure_DegiskeniniOlustur(Sure); -> %s", Sure_Yazdir(Sure, Tampon, sizeof(Tampon)));
	
		Sure_MiliSaniye(Sure, 3500);
		Gunluk("Sure_MiliSaniye(Sure, 3500); -> %s", Sure_Yazdir(Sure, Tampon, sizeof(Tampon)));
	
		while(!Sure_DolduMu(Sure))
		{
			Gunluk("Kalan sure : %d msn", Sure_KalanSure_MiliSaniye(Sure));
			Sleep(500);
		}
	
	//	0-9703640 KaynakKod.c -----Ornek_Zamanlama-----
	//	0-9703640 KaynakKod.c Sure_DegiskeniniOlustur(Sure); -> 0-0
	//	0-9703640 KaynakKod.c Sure_MiliSaniye(Sure, 3500); -> 0-9707141
	//	0-9703640 KaynakKod.c Kalan sure : 3501 msn
	//	0-9704140 KaynakKod.c Kalan sure : 3001 msn
	//	0-9704656 KaynakKod.c Kalan sure : 2485 msn
	//	0-9705156 KaynakKod.c Kalan sure : 1985 msn
	//	0-9705671 KaynakKod.c Kalan sure : 1470 msn
	//	0-9706187 KaynakKod.c Kalan sure : 954 msn
	//	0-9706703 KaynakKod.c Kalan sure : 438 msn
	}
	
	void Ornek_HazirKod_C_Ayarlar_h()
	{
		Gunluk("-----Ornek_HazirKod_C_Ayarlar_h-----");
	
		Tip_u32 Degisken = 0x80000007;
		Tip_u32 Ters = BitDizisi_Uret_Ters(Degisken);
	
		Gunluk("Bit_Uret_Ters(false) -> 0x%X", Bit_Uret_Ters(false));
		Gunluk("BitDizisi_Uret_Ters(Degisken) -> 0x%X", BitDizisi_Uret_Ters(Degisken));
		Gunluk("Bit_SolaKaydir_1(5) -> 0x%X", Bit_SolaKaydir_1(5));
		Gunluk("Bit_SolaKaydir_0(5) -> 0x%X", Bit_SolaKaydir_0(5));
		Gunluk("Bit_Oku(Degisken, 31) -> 0x%X", Bit_Oku(Degisken, 31));
		Gunluk("BitDizisi_Uret_Bit_1(Degisken, 8) -> 0x%X", BitDizisi_Uret_Bit_1(Degisken, 8));
		Gunluk("itDizisi_Uret_Bit_0(Ters, 8) -> 0x%X", BitDizisi_Uret_Bit_0(Ters, 8));
		Gunluk("BitDizisi_Uret_Bit_Ters(Degisken, 8) -> 0x%X", BitDizisi_Uret_Bit_Ters(Degisken, 8));
	
		Bit_Yaz_1(Degisken, 16);
		Gunluk("Bit_Yaz_1(Degisken, 16); -> 0x%X", Bit_Yaz_1(Degisken, 16));
		Bit_Yaz_0(Ters, 16);
		Gunluk("Bit_Yaz_0(Ters, 16); -> 0x%X", Bit_Yaz_0(Ters, 16));
		Bit_Yaz_Ters(Degisken, 16);
		Gunluk("Bit_Yaz_Ters(Degisken, 16); -> 0x%X", Bit_Yaz_Ters(Degisken, 16));
	
		uint8_t Tampon[6] = { 0 };
		Isaretci_Icerigi_u16(Tampon, 0) = 0x0005;
		Isaretci_Icerigi_u16(Tampon, 4) = 0x5004;
		Gunluk("Isaretci_Icerigi_u16(Tampon, 0) = 5;");
		Gunluk_Hex(Tampon, sizeof(Tampon));
	
		Gunluk("Hesapla_Yuzde(15, 1000) -> %d", Hesapla_Yuzde(15, 1000));
		Gunluk("Hesapla_Dolgu(35, 8) -> %d", Hesapla_Dolgu(35, 8));
		Gunluk("Hesapla_EnKucuk(15, 1000) -> %d", Hesapla_EnKucuk(15, 1000));
		Gunluk("Hesapla_EnBuyuk(35, 8) -> %d", Hesapla_EnBuyuk(35, 8));
	
		Tip_u32 Tutucu;
		HataDurumu_Baslat(Tutucu);
		Gunluk("HataDurumu_Baslat(Tutucu); -> %d", Tutucu);
		Gunluk("HataDurumu_HataDevamEdiyorMu(Tutucu, e_HataDurumu_Hata_Hata1) -> %d", HataDurumu_HataDevamEdiyorMu(Tutucu, e_HataDurumu_Hata_Hata1));
	
		HataDurumu_Hatasiz(Tutucu, e_HataDurumu_Hata_Hata1);
		Gunluk("HataDurumu_Hatasiz(Tutucu, e_HataDurumu_Hata_Hata1); -> %d", Tutucu);
		Gunluk("HataDurumu_HataDevamEdiyorMu(Tutucu, e_HataDurumu_Hata_Hata1) -> %d", HataDurumu_HataDevamEdiyorMu(Tutucu, e_HataDurumu_Hata_Hata1));
	
		HataDurumu_Hatali(Tutucu, e_HataDurumu_Hata_Hata1);
		Gunluk("HataDurumu_Hatali(Tutucu, e_HataDurumu_Hata_Hata1); -> %d", Tutucu);
		Gunluk("HataDurumu_HataDevamEdiyorMu(Tutucu, e_HataDurumu_Hata_Hata1) -> %d", HataDurumu_HataDevamEdiyorMu(Tutucu, e_HataDurumu_Hata_Hata1));
	
	//	0-12772500 KaynakKod.c -----Ornek_HazirKod_C_Ayarlar_h-----
	//	0-12772500 KaynakKod.c Bit_Uret_Ters(false) -> 0x1
	//	0-12772500 KaynakKod.c BitDizisi_Uret_Ters(Degisken) -> 0x7FFFFFF8
	//	0-12772500 KaynakKod.c Bit_SolaKaydir_1(5) -> 0x20
	//	0-12772500 KaynakKod.c Bit_SolaKaydir_0(5) -> 0xFFFFFFDF
	//	0-12772500 KaynakKod.c Bit_Oku(Degisken, 31) -> 0x1
	//	0-12772500 KaynakKod.c BitDizisi_Uret_Bit_1(Degisken, 8) -> 0x80000107
	//	0-12772500 KaynakKod.c itDizisi_Uret_Bit_0(Ters, 8) -> 0x7FFFFEF8
	//	0-12772500 KaynakKod.c BitDizisi_Uret_Bit_Ters(Degisken, 8) -> 0x80000107
	//	0-12772500 KaynakKod.c Bit_Yaz_1(Degisken, 16); -> 0x80010007
	//	0-12772500 KaynakKod.c Bit_Yaz_0(Ters, 16); -> 0x7FFEFFF8
	//	0-12772500 KaynakKod.c Bit_Yaz_Ters(Degisken, 16); -> 0x80010007
	//	0-12772500 KaynakKod.c Isaretci_Icerigi_u16(Tampon, 0) = 5;
	//	0-12772500 KaynakKod.c Adet:00006 | Hex | Konum | Ascii
	//	0-12772500 KaynakKod.c 05 00 00 00 04 50 | 0000 - 0005 |      P
	//	0-12772500 KaynakKod.c Hesapla_Yuzde(15, 1000) -> 1
	//	0-12772500 KaynakKod.c Hesapla_Dolgu(35, 8) -> 5
	//	0-12772500 KaynakKod.c Hesapla_EnKucuk(15, 1000) -> 15
	//	0-12772500 KaynakKod.c Hesapla_EnBuyuk(35, 8) -> 35
	//	0-12772500 KaynakKod.c HataDurumu_Baslat(Tutucu); -> 0
	//	0-12772500 KaynakKod.c HataDurumu_HataDevamEdiyorMu(Tutucu, e_HataDurumu_Hata_Hata1) -> 1
	//	0-12772500 KaynakKod.c HataDurumu_Hatasiz(Tutucu, e_HataDurumu_Hata_Hata1); -> 1
	//	0-12772500 KaynakKod.c HataDurumu_HataDevamEdiyorMu(Tutucu, e_HataDurumu_Hata_Hata1) -> 0
	//	0-12772500 KaynakKod.c HataDurumu_Hatali(Tutucu, e_HataDurumu_Hata_Hata1); -> 0
	//	0-12772500 KaynakKod.c HataDurumu_HataDevamEdiyorMu(Tutucu, e_HataDurumu_Hata_Hata1) -> 1
	}
	
	void Kiyaslama_Dizi_Liste()
	{
		#define _Kiyaslama_Eleman_Sayisi 500
		#define _Kiyaslama_Denenme_Sayisi 10
	
		int SureOlcumleri_Dizi[_Kiyaslama_Denenme_Sayisi];
		int SureOlcumleri_Liste[_Kiyaslama_Denenme_Sayisi];
	
		YT_Sil(YT_Yeni(1, false));
		Gunluk("Bostaki ram miktari %d bayt", YT_BosAlan());
		Tip_u8 BosDegisken = 0;
		int Tik = 0;
		int ToplamSure = 0;
		Tip_u8 * okunan = Tip_null;
	
		////////////////////////////////////////////////////////////////////
	
		Tik = GetTickCount() + 1000;
		Tip_Isaretci_Liste Liste = Liste_Yeni();
		for(Tip_u32 a = 0; a < _Kiyaslama_Eleman_Sayisi; a++)
		{
			if (!Liste_Eleman_Ekle(Liste, &BosDegisken))
			{
				Gunluk("Ram yetersiz %d", a);
				return;
			}
	
			if (Tik < GetTickCount())
			{
				Tik = GetTickCount() + 1000;
				Gunluk("Eleman %d eklendi", a);
			}
		}
		Gunluk("Liste %d eleman icin %d bayt alan kullandi", _Kiyaslama_Eleman_Sayisi, configTOTAL_HEAP_SIZE - YT_BosAlan());
	
		ToplamSure = 0;
		for(Tip_u32 b = 0; b < _Kiyaslama_Denenme_Sayisi; b++)
		{
			Tik = GetTickCount();
			Liste_Kuyruk_DegiskeniniOlustur(Liste, KuyrukDegiskeni);
			while (KuyrukDegiskeni)
			{
				okunan = Liste_Kuyruk_SonrakiEleman(Liste, KuyrukDegiskeni);
				*okunan++;
			}
			SureOlcumleri_Liste[b] = GetTickCount() - Tik;
	
			ToplamSure += SureOlcumleri_Liste[b];
		}
		ToplamSure /= _Kiyaslama_Denenme_Sayisi;
		Liste_Sil(Liste, false);
		Gunluk("Liste -> Ortalama : %d msn", ToplamSure);
		Gunluk("Liste silindikten sonraki bostaki ram miktari %d bayt", YT_BosAlan());
	
		/////////////////////////////////////////////////////////////////////
	
		Tik = GetTickCount() + 1000;
		Tip_Isaretci_Dizi Dizi = Dizi_Yeni();
		for(Tip_u32 a = 0; a < _Kiyaslama_Eleman_Sayisi; a++)
		{
			if (!Dizi_Eleman_Ekle(Dizi, &BosDegisken))
			{
				Gunluk("Ram yetersiz %d", a);
				return;
			}
	
			if (Tik < GetTickCount())
			{
				Tik = GetTickCount() + 1000;
				Gunluk("Eleman %d eklendi", a);
			}
		}
		Gunluk("Dizi %d eleman icin %d bayt alan kullandi", _Kiyaslama_Eleman_Sayisi, configTOTAL_HEAP_SIZE - YT_BosAlan());
	
		okunan = Tip_null; (void)okunan;
		ToplamSure = 0;
		for(Tip_u32 b = 0; b < _Kiyaslama_Denenme_Sayisi; b++)
		{
			Tik = GetTickCount();
			for(Tip_u32 c = 0; c < _Kiyaslama_Eleman_Sayisi; c++)
			{
				okunan = Dizi_Elemani(Dizi, c);
				*okunan++;
			}
			SureOlcumleri_Dizi[b] = GetTickCount() - Tik;
	
			ToplamSure += SureOlcumleri_Dizi[b];
		}
		ToplamSure /= _Kiyaslama_Denenme_Sayisi;
		Dizi_Sil(Dizi, false);
		Gunluk("Dizi -> Ortalama : %d msn", ToplamSure);
		Gunluk("Dizi silindikten sonraki bostaki ram miktari %d bayt", YT_BosAlan());
	
		//Eleman Ekle / Sil süresi 		-> Dizi > Liste*
		//Elemanlar arasinda dolasma 	-> Birbirine denk
		//Ram kullanimi 				-> Liste > Dizi*
	}

