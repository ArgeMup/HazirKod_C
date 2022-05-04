// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.4

#ifndef __HazirKod_C_KomutSatiri_H__
#define __HazirKod_C_KomutSatiri_H__

	#include "HazirKod_C_Ayarlar.h"

	#ifdef HazirKod_C_Kullan_KomutSatiri

		#include "Tampon.h"
		#include "AramaIslemleri.h"
		#include "YaziIslemleri.h"

		////////////////////////////////////////////////////////////////////////////////
		//Genel Goruse Acik Tanimlamalar
		////////////////////////////////////////////////////////////////////////////////
		typedef struct
		{
			Tip_Isaretci Komut_Baslangici;
			Tip_Isaretci Komut_Bitisi;
			Tip_bool YeterliSayidaKarakterVarMi;
			Tip_i32 DonanimAdresi;
		} Tip_s_KomutSatiri_Tampon_Detaylar;

		#define KomutSatiri_Cevap_Ekle(Tampon, Sekil, ...)		Tampon->Sayac += snprintf(Isaretci_Konumlandir(Tampon->Isaretci, Tampon->Sayac, Tip_char, Tip_char), Tampon_BosAlan(Tampon), Sekil, ##__VA_ARGS__)
		#define KomutSatiri_Cevapla_Onay(Tampon) 				KomutSatiri_Cevap_Ekle(Tampon, "%s%s%s", _KomutSatiri_Cevap_Baslangici, _KomutSatiri_Cevap_Onay, _KomutSatiri_Cevap_Bitisi)
		#define KomutSatiri_Cevapla_Ret(Tampon, Aciklama) 		KomutSatiri_Cevap_Ekle(Tampon, "%s%s%c%s%s", _KomutSatiri_Cevap_Baslangici, _KomutSatiri_Cevap_Ret, _KomutSatiri_Ayirac, Aciklama, _KomutSatiri_Cevap_Bitisi)
		#define KomutSatiri_Cevapla_Yazi(Tampon, Yazi) 			KomutSatiri_Cevap_Ekle(Tampon, "%s\"%s\"%s", _KomutSatiri_Cevap_Baslangici, Yazi, _KomutSatiri_Cevap_Bitisi)
		#define KomutSatiri_Cevapla_TamSayi(Tampon, TamSayi)	KomutSatiri_Cevap_Ekle(Tampon, "%s%d%s", _KomutSatiri_Cevap_Baslangici, TamSayi, _KomutSatiri_Cevap_Bitisi)

		Tip_bool KomutSatiri_Baslat(Tip_Isaretci_Tampon Tampon, Tip_bool UzunKomut, Tip_s_KomutSatiri_Tampon_Detaylar * Detaylar);

		Tip_bool KomutSatiri_KontrolEt_Siradaki_BuMu(Tip_Isaretci_Tampon Tampon, Tip_char * Bu);
		Tip_i32 KomutSatiri_KontrolEt_Siradaki_DizidekiElemanlardanBiriMi(Tip_Isaretci_Tampon Tampon, const Tip_char ** Dizi, Tip_u32 ElemanSayisi);

		Tip_bool KomutSatiri_Oku_TamSayi(Tip_Isaretci_Tampon Tampon, Tip_i32 * YazilacakTampon);
		Tip_bool KomutSatiri_Oku_TamSayi_AraliktaMi(Tip_Isaretci_Tampon Tampon, Tip_i32 * YazilacakTampon, Tip_i32 EnDusuk, Tip_i32 EnYuksek);
		Tip_Isaretci_Tampon KomutSatiri_Oku_Hex(Tip_Isaretci_Tampon Tampon);
		Tip_Isaretci_Tampon KomutSatiri_Oku_Yazi(Tip_Isaretci_Tampon Tampon);

		Tip_void KomutSatiri_Cevapla_Hex(Tip_Isaretci_Tampon Hedef, Tip_Isaretci_Tampon Kaynak);

	#endif

#endif /*__HazirKod_C_KomutSatiri_H__ */
