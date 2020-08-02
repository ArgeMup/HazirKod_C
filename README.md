# HazirKod_C
Genel Amacli C Kutuphanesi ArgeMup@yandex.com

 - AramaIslemleri
 - Depo <- IlkGirenIlkCikar, YerTahsisati, HataKontrol
 - Gorev <- Liste
 - Gunluk <- Zamanlama
 - IlkGirenIlkCikar <- YerTahsisati, HataKontrol
 - KomutSatiri <- Tampon, AramaIslemleri
 - LedKontrol <- Gorev
 - Liste <- YerTahsisati
 - Tampon <- YerTahsisati
 - YaziIslemleri <- AramaIslemleri
 - YerTahsisati <- HataKontrol

### AramaIslemleri
    #include "AramaIslemleri.h"
    
    int main(void)
    {
    	uint8_t T1[] = { 4,4,4,4 };
    	uint8_t T2[] = { 3,4,5 };
    	uint8_t T10[] = { 1,2,3,     4,4,4,     5,6,     3,4,5,     7,8,     4,4,4,4,     9,10 };
    	uint32_t Bulunan = AI_Bul_Blok(T10, sizeof(T10), T1, sizeof(T1));
    	Bulunan = AI_Bul_Blok(T10, sizeof(T10), T2, sizeof(T2));
    
    	Bulunan = AI_Bul_Bayt(T10, sizeof(T10), 1);
    	Bulunan = AI_Bul_Bayt(T10, sizeof(T10), 4);
    	Bulunan = AI_Bul_Bayt(T10, sizeof(T10), 8);
    	Bulunan = AI_Bul_Bayt(T10, sizeof(T10), 10);
    
    	return EXIT_SUCCESS;
    }
    
### Depo
    #include "Depo.h"
    
    Tip_bool Islem_Siliniyor(Tip_Isaretci_IGIC IGIC, Tip_u32 Adet)
    {
    	return true;
    }
    
    int main(void)
    {
    	Tip_Isaretci_Depo Depo =  Depo_Yeni(sizeof(uint8_t), 100, e_IGIC_YerKalmazsa_EnEskiyiSil, Islem_Siliniyor);
    	if (Depo == NULL) return -1;
    
    	char * Bilgi = "1234567890ABCDEF";
    	bool sonuc = Depo_Bilgi_Ekle(Depo, Bilgi, strlen(Bilgi));
    	uint32_t Adet = Depo_Bilgi_SiradakiAdet(Depo);
    
    	sonuc = Depo_Bilgi_Ekle(Depo, Bilgi, strlen(Bilgi)/2);
    	Adet = Depo_Bilgi_SiradakiAdet(Depo);
    
    	char Okunan[50];
    	Adet = Depo_Bilgi_Oku(Depo, Okunan, strlen(Bilgi));
    	Adet = Depo_Bilgi_Oku(Depo, Okunan, strlen(Bilgi));
    	Adet = Depo_Bilgi_Oku(Depo, Okunan, strlen(Bilgi));
    
    	Depo_Bilgi_Ekle(Depo, Okunan, strlen(Okunan));
    	Depo_Bilgi_Ekle(Depo, Okunan, strlen(Okunan)); //Tasma, islem siliniyor
    
    	Depo_Sil(Depo);
    
    	return EXIT_SUCCESS;
    }
    
### Gorev
    #include <windows.h>
    #include "Gorev.h"
    
    Tip_Sure _Zamanlama_An_Okuma_Islemi()
    {
    	return GetTickCount();
    }
    
    Tip_Isaretci_Gorev Gorev = NULL;
    int32_t Islem_1(struct s_Gorev_Detaylar_ * Detaylar);
    int32_t Islem_2(struct s_Gorev_Detaylar_ * Detaylar);
    int32_t Islem_3(struct s_Gorev_Detaylar_ * Detaylar);
    
    int32_t Islem_1(struct s_Gorev_Detaylar_ * Detaylar)
    {
    	if (++*((uint32_t *)Detaylar->KullaniciNesnesi) > 5)
    	{
    		bool sonuc = Gorev_Islem_Ekle(Gorev, Islem_2, Detaylar->KullaniciNesnesi);
    
    		Gorev_Islem_CikVeSil();
    	}
    
    	Gorev_Islem_CikVeTekrarCalistir(100);
    }
    
    int32_t Islem_2(struct s_Gorev_Detaylar_ * Detaylar)
    {
    	bool sonuc = false;
    
    	switch (Detaylar->CalistirilacakAdim)
    	{
    	default:
    		sonuc = Gorev_Islem_Ekle(Gorev, Islem_3, NULL);
    		Detaylar->CalistirilacakAdim++;
    		Gorev_Islem_CikVeTekrarCalistir(1000);
    
    	case 1:
    		if (Gorev_Islem_MevcutMu(Gorev, Islem_3)) Gorev_Islem_CikVeTekrarCalistir(60000);
    		else
    		{
    			*((uint32_t *)Detaylar->KullaniciNesnesi) = 0;
    			sonuc = Gorev_Islem_Ekle(Gorev, Islem_1, Detaylar->KullaniciNesnesi);
    			Gorev_Islem_CikVeSil();
    		}
    	}
    }
    
    int32_t Islem_3(struct s_Gorev_Detaylar_ * Detaylar)
    {
    	switch (Detaylar->CalistirilacakAdim)
    	{
    	default:
    		Detaylar->CalistirilacakAdim++;
    		Gorev_Islem_CikVeTekrarCalistir(500);
    
    	case 5:
    		Gorev_Islem_HemenCalistir(Gorev, Islem_2);
    		Gorev_Islem_CikVeSil();
    	}
    }
    
    int main(void)
    {
    	int32_t KullaniciNesnesi = 0;
    
    	Gorev =  Gorev_Yeni();
    	if (Gorev == NULL) return -1;
    
    	bool sonuc = Gorev_Islem_Ekle(Gorev, Islem_1, &KullaniciNesnesi);
    
    	Tip_Sure ZamanAsimi;
    	Sure_Saniye(ZamanAsimi, 5);
    	while (!Sure_DolduMu(ZamanAsimi))
    	{
    		Gorev_Calistir(Gorev);

    		_An_KesmeIcinBekle_Islemi();
    	}
    
    	Gorev_Sil(Gorev);
    
    	return EXIT_SUCCESS;
    }
    
### Gunluk
    #include <windows.h>
	uint32_t _Zamanlama_An_Okuma_Islemi()
    {
    	return GetTickCount();
    }

    void _Gunluk_Aktarma_Islemi(void * Tampon, uint32_t Adet)
    {
    	char Gecici[Adet];
    	memcpy(Gecici, Tampon, Adet);
    	printf((char *)Tampon);
    }

	//////////////////////////////////////////////////////////////////////////////
	#define _Gunluk_Baslik "main"	//Kaynak kod içinde tanimlanmali
	#include "Gunluk.h"					//Kaynak kod içinde tanimlanmali
	//////////////////////////////////////////////////////////////////////////////

    int main(void)
    {
    	uint8_t Tampon[] = { 1, 2, 3, 4, 5 };

    	Gunluk_Baslat();

    	Gunluk_BeklenmeyenDurum("Hesapta olmayan bir duruma dair bilgi verir");
		Gunluk_Hata("Bilinen bir hataya dair bilgi verir");
		Gunluk_Uyari("Bilinen bir duruma dair bilgi verir");
		Gunluk_Bilgi("Asamalar arasi gecise dair bilgi verir");
		Gunluk("Gelisiguzel bir bilgi verir");

    	Gunluk_SureliDurdur(1);
    	Gunluk_BeklenmeyenDurum("1 sn boyunca durduruldugu icin hicbir bilgi veremez");

    	Sleep(1500);
    	Gunluk("1 sn sonunda calisabilir");

    	return EXIT_SUCCESS;
    }
    
### IlkGirenIlkCikar
    #include "IlkGirenIlkCikar.h"
    
    Tip_bool Islem_Siliniyor(Tip_Isaretci_IGIC IGIC, Tip_u32 Adet)
    {
    	return true;
    }
    
    int main(void)
    {
    	Tip_Isaretci_IGIC IGIC =  IGIC_Yeni(100, e_IGIC_YerKalmazsa_EnEskiyiSil, Islem_Siliniyor);
    	if (IGIC == NULL) return -1;
    
    	char * Bilgi = "1234567890ABCDEF";
    	bool sonuc = IGIC_Bilgi_Ekle(IGIC, Bilgi, strlen(Bilgi));
    	sonuc = IGIC_Bilgi_Ekle(IGIC, Bilgi, strlen(Bilgi) / 2);
    
    	uint32_t miktar = IGIC_Kapasite(IGIC);
    	miktar = IGIC_DoluAlan(IGIC);
    	miktar = IGIC_BosAlan(IGIC);
    
    	char Okunan[100];
    	miktar = IGIC_Bilgi_Oku(IGIC, Okunan, 100, true);
    
    	IGIC_Sil(IGIC);
    
    	return EXIT_SUCCESS;
    }
    
### KomutSatiri
    #include "KomutSatiri.h"
    
    int main(void)
    {
    	#define KomutMetni "GuRuLtu Kart 1 Komut1 -987654 Komut2 \"Ornek Yazi ornegidir\" 0x112233445566778899AABBCCDDEEFF\r\n GuRuLtu"
    	//#define KomutMetni "GuRuLtu Kart 2 Komut1 -987654 Komut2 \"Ornek Yazi ornegidir\" 0x112233445566778899AABBCCDDEEFF\r\n GuRuLtu"
    	//#define KomutMetni "GuRuLtu Kart 1 ASDF -987654 Komut2 \"Ornek Yazi ornegidir\" 0x112233445566778899AABBCCDDEEFF\r\n GuRuLtu"
    
    	Tip_Isaretci_Tampon Komut = Tampon_Yeni(256), Cevap = Tampon_Yeni(256), Hex;
    	Tampon_Bilgi_Ekle_Blok(Komut, KomutMetni, strlen(KomutMetni));
    
    	if (KomutSatiri_KontrolEt_TampondakiBilgiUygunMu(Komut))
    	{
    		if (KomutSatiri_KontrolEt_DonanimAdresiUygunMu(Komut))
    		{
    			if (KomutSatiri_KontrolEt_Siradaki_BuMu(Komut, _KomutSatiri_Komut_Komut1))
    			{
    				Tip_i32 Tamsayi;
    				if (KomutSatiri_Oku_TamSayi(Komut, &Tamsayi))
    				{
    					if (KomutSatiri_KontrolEt_Siradaki_BuMu(Komut, _KomutSatiri_Komut_Komut2))
    					{
    						Tip_Isaretci_Tampon OrnekYazi = KomutSatiri_Oku_Yazi(Komut);
    						if (OrnekYazi)
    						{
    							char * _OrnekYazi_ = Tampon_Isaretci_Konum(OrnekYazi, 0, char);
    
    							Hex = KomutSatiri_Oku_Hex(Komut);
    							if (Hex) KomutSatiri_Cevapla_Onay(Cevap);
    
    							Tampon_Sil(OrnekYazi);
    						}
    					}
    				}
    			}
    		}
    	}
    
    	char * _Cevap_ = Tampon_Isaretci_Konum(Cevap, 0, char);
    
    	if (Tampon_DoluAlan(Cevap) == 0) KomutSatiri_Cevapla_Ret(Cevap, "Parametrelerden biri hatali");
    	else
    	{
    		Tampon_DoluAlan(Cevap) = 0;
    		KomutSatiri_Cevap_Ekle(Cevap, "Serbest Cevap %d", 35);
    
    		Tampon_DoluAlan(Cevap) = 0;
    		KomutSatiri_Cevapla_Hex(Cevap, Hex);
    
    		Tampon_DoluAlan(Cevap) = 0;
    		KomutSatiri_Cevapla_Onay(Cevap);
    
    		Tampon_DoluAlan(Cevap) = 0;
    		KomutSatiri_Cevapla_TamSayi(Cevap, 35);
    
    		Tampon_DoluAlan(Cevap) = 0;
    		KomutSatiri_Cevapla_Yazi(Cevap, "Serbest Yazi");
    	}
    
    	Tampon_Sil(Hex);
    	Tampon_Sil(Komut);
    	Tampon_Sil(Cevap);
    
    	return EXIT_SUCCESS;
    }
    
### LedKontrol
    #include "LedKontrol.h"
    
    int main(void)
    {
    	LedKontrol_AnlikBildirim();
    
    	return EXIT_SUCCESS;
    }
    
### Liste
    #include "Liste.h"
    
    int main(void)
    {
    	Tip_Isaretci_Liste Liste =  Liste_Yeni();
    	if (Liste == NULL) return -1;
    
    	uint8_t Eleman1 = 1;
    	uint16_t Eleman2 = 2;
    
    	Liste_Eleman_Ekle(Liste, &Eleman1);
    	Liste_Eleman_Ekle(Liste, &Eleman2);
    
    	uint32_t * Eleman3 = Liste_Eleman_Ekle_VeYerTahsisEt(Liste, sizeof(uint32_t));
    	*Eleman3 = 3;
    
    	uint8_t Eleman1Okunan;
    	memcpy(&Eleman1Okunan, Liste_Eleman_Ilk(Liste), sizeof(uint8_t));
    
    	uint32_t Eleman3Okunan;
    	memcpy(&Eleman3Okunan, Liste_Eleman_Son(Liste), sizeof(uint32_t));
    
    	Liste_Kuyruk_DegiskeniniOlustur(Liste, KuyrukDegiskeni);
    	while (KuyrukDegiskeni)
    	{
    		Tip_Isaretci Isrt = Liste_Kuyruk_SonrakiEleman(Liste, KuyrukDegiskeni);
    		Isrt++;
    		//Sirayla
    	}
    
    	Liste_Eleman_Sil(Liste, &Eleman1, false);
    	Liste_Eleman_Sil(Liste, Eleman3, true);
    
    	Liste_Sil(Liste, false);
    
    	return EXIT_SUCCESS;
    }
    
### Tampon
    #include "Tampon.h"

    int main(void)
    {
    	Tip_Isaretci_Tampon Tampon =  Tampon_Yeni(10);
    	if (Tampon == NULL) return -1;

    	char Kaynak[] = "ArGeMuP";
    	bool sonuc = Tampon_Bilgi_Ekle_GecerliKonum(Tampon, Kaynak, strlen(Kaynak));

    	uint32_t Adet = Tampon_Kapasite(Tampon);
    	Adet = Tampon_DoluAlan(Tampon);
    	Adet = Tampon_BosAlan(Tampon);

    	char okunan_bayt = Tampon_Icerik_Konum(Tampon, 0, char);

    	char okunan_blok[strlen(Kaynak)];
    	Adet = Tampon_Bilgi_Oku_Konum(Tampon, 0, okunan_blok, sizeof(okunan_blok));

    	char okunan_blok2[2];
    	Adet = Tampon_Bilgi_Oku_GecerliKonum(Tampon, okunan_blok2, sizeof(okunan_blok2));
    	Adet = Tampon_Bilgi_Oku_GecerliKonum(Tampon, okunan_blok2, sizeof(okunan_blok2));
    	Adet = Tampon_Bilgi_Oku_GecerliKonum(Tampon, okunan_blok2, sizeof(okunan_blok2));

    	Adet = Tampon_DoluAlan(Tampon);

    	Tampon_Sil(Tampon);

    	return EXIT_SUCCESS;
    }
    
### YaziIslemleri
    #include "YaziIslemleri.h"
    
    int main(void)
    {
    	#define Kaynak1 "123456789"
    	#define Aranan1 "456"
    
    	uint32_t adet = YI_Ara(Kaynak1, Aranan1);
    
    	#define Kaynak2 "Adres : 192.168.0.1\r\nYol : 80\r\nKapasite : 8192"
    	#define ArananBaslangic "Yol :"
    	#define ArananBitis "\r\n"
    
    	char Bulunan[256];
    
    	memset(Bulunan, 0xFF, sizeof(Bulunan));
    	adet = YI_BulAyiklaKopyala(Kaynak2, ArananBaslangic, ArananBitis, Bulunan, sizeof(Bulunan));
    	printf("Adet : %d ->%s<-\r\n", adet, Bulunan);
    
    	memset(Bulunan, 0xFF, sizeof(Bulunan));
    	adet = YI_BulAyiklaKopyala(Kaynak2, NULL, ArananBitis, Bulunan, sizeof(Bulunan));
    	printf("Adet : %d ->%s<-\r\n", adet, Bulunan);
    
    	memset(Bulunan, 0xFF, sizeof(Bulunan));
    	adet = YI_BulAyiklaKopyala(Kaynak2, ArananBaslangic, NULL, Bulunan, sizeof(Bulunan));
    	printf("Adet : %d ->%s<-\r\n", adet, Bulunan);
    
    	printf("YI_Yazdir ->%s<-\r\n", YI_Yazdir(Bulunan, sizeof(Bulunan), "Deneme %d", 5));
    	printf("YI_Yazdir_TarihSaat ->%s<-\r\n", YI_Yazdir_TarihSaat(Bulunan, sizeof(Bulunan), 0));
    	printf("YI_Yazdir_NoktaliSayi ->%s<-\r\n", YI_Yazdir_NoktaliSayi(Bulunan, sizeof(Bulunan), 1.35));
    	printf("YI_Yazdir_TamSayi_Hex ->%s<-\r\n", YI_Yazdir_TamSayi_Hex(Bulunan, sizeof(Bulunan), 65535));
    	printf("YI_Yazdir_TamSayi ->%s<-\r\n", YI_Yazdir_TamSayi(Bulunan, sizeof(Bulunan), 65535));
    	printf("YI_Yazdir_Hex_Tampon ->%s<-\r\n", YI_Yazdir_Hex_Tampon(Bulunan, sizeof(Bulunan), Kaynak1, strlen(Kaynak1)));
    	return EXIT_SUCCESS;
    }
    
### YerTahsisati
    #include "YerTahsisati.h"
    
    int main(void)
    {
    	Tip_Isaretci Isrtc =  YT_Yeni(10);
    	if (Isrtc == NULL) return -1;
    	
    	YT_Sil(Isrtc);
    
    	return EXIT_SUCCESS;
    }
    
### Zamanlama
    #include <windows.h>
    #include "Zamanlama.h"
    
    Tip_Sure _Zamanlama_An_Okuma_Islemi()
    {
    	return GetTickCount();
    }
    
    int main(void)
    {
    	Tip_Sure Sure = 0;
    	Sure_MiliSaniye(Sure, 3500);
    
    	while(!Sure_DolduMu(Sure))
    	{
    		printf("Kalan sure : %d msn\r\n", Sure_KalanSure_MiliSaniye(Sure));
    		Sleep(500);
    	}
    
    	return EXIT_SUCCESS;
    }

> HazirKod_C, derleyici include sirasinda sonda (yada mantikli bir konumda) olmali
>
> gcc "-IC:\\deneme\\inc" "-IC:\\deneme\\HazirKod_C\\Tarifler" -O0 -g3 -Wall -c -fmessage-length=0 -o "src\\main.o" "..\\src\\main.c" gibi