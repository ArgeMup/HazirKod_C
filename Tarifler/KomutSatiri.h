// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.0

#ifndef __KomutSatiri_H__
#define __KomutSatiri_H__

#include "HazirKod_C_Ayarlar.h"
#include "Tampon.h"
#include "YaziIslemleri.h"

////////////////////////////////////////////////////////////////////////////////
//Genel Goruse Acik Tanimlamalar
////////////////////////////////////////////////////////////////////////////////
#define KomutSatiri_Cevap_Ekle(Tampon, Sekil, ...)		Tampon_DoluAlan(Tampon) += snprintf(Tampon_Isaretci_GecerliKonum(Tampon, Tip_char), Tampon_BosAlan(Tampon), Sekil, ##__VA_ARGS__)
#define KomutSatiri_Cevapla_Onay(Tampon) 				KomutSatiri_Cevap_Ekle(Tampon, "%s%s%s", _KomutSatiri_Cevap_Baslangici, _KomutSatiri_Cevap_Onay, _KomutSatiri_Cevap_Bitisi)
#define KomutSatiri_Cevapla_Ret(Tampon, Aciklama) 		KomutSatiri_Cevap_Ekle(Tampon, "%s%s%c%s%s", _KomutSatiri_Cevap_Baslangici, _KomutSatiri_Cevap_Ret, _KomutSatiri_Ayirac, Aciklama, _KomutSatiri_Cevap_Bitisi)
#define KomutSatiri_Cevapla_Yazi(Tampon, Yazi) 			KomutSatiri_Cevap_Ekle(Tampon, "%s\"%s\"%s", _KomutSatiri_Cevap_Baslangici, Yazi, _KomutSatiri_Cevap_Bitisi)
#define KomutSatiri_Cevapla_TamSayi(Tampon, TamSayi)	KomutSatiri_Cevap_Ekle(Tampon, "%s%d%s", _KomutSatiri_Cevap_Baslangici, TamSayi, _KomutSatiri_Cevap_Bitisi)

Tip_bool KomutSatiri_KontrolEt_TampondakiBilgiUygunMu(Tip_Isaretci_Tampon Tampon);
Tip_bool KomutSatiri_KontrolEt_DonanimAdresiUygunMu(Tip_Isaretci_Tampon Tampon);
Tip_bool KomutSatiri_KontrolEt_Siradaki_BuMu(Tip_Isaretci_Tampon Tampon, Tip_char * Bu);

Tip_bool KomutSatiri_Oku_TamSayi(Tip_Isaretci_Tampon Tampon, Tip_i32 * YazilacakTampon);
Tip_Isaretci_Tampon KomutSatiri_Oku_Hex(Tip_Isaretci_Tampon Tampon);
Tip_Isaretci_Tampon KomutSatiri_Oku_Yazi(Tip_Isaretci_Tampon Tampon);

Tip_void KomutSatiri_Cevapla_Hex(Tip_Isaretci_Tampon Hedef, Tip_Isaretci_Tampon Kaynak);

#endif /*__KomutSatiri_H__ */
