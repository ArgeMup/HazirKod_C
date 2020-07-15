// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.1

#include "KomutSatiri.h"

//Ic Kullanim
Tip_u32 _KomutSatiri_KarakterSayisi(Tip_Isaretci_Tampon Tampon)
{
	Tip_u32 Tampon_Islenen = Tampon_DoluAlan(Tampon);
	Tip_char * Isrtc = Tampon_Isaretci_GecerliKonum(Tampon, Tip_char);

	while (Tampon_Islenen < Tampon_Kapasite(Tampon) && *Isrtc != _KomutSatiri_Ayirac && *Isrtc != _KomutSatiri_Komut_Bitisi[0]) { Isrtc++; Tampon_Islenen++; }
	return Tampon_Islenen - Tampon_DoluAlan(Tampon);
}
Tip_u32 _KomutSatiri_KarakterSayisi_Yazi(Tip_Isaretci_Tampon Tampon)
{
	Tip_u32 Tampon_Islenen = Tampon_DoluAlan(Tampon);
	Tip_char * Isrtc = Tampon_Isaretci_GecerliKonum(Tampon, Tip_char);

	while (Tampon_Islenen < Tampon_Kapasite(Tampon) && *Isrtc != '"') { Isrtc++; Tampon_Islenen++; }
	return Tampon_Islenen - Tampon_DoluAlan(Tampon);
}

//Kontrol Islemleri
Tip_bool KomutSatiri_KontrolEt_TampondakiBilgiUygunMu(Tip_Isaretci_Tampon Tampon)
{
	if (Tampon_DoluAlan(Tampon) < _KomutSatiri_Komut_EnAzKaSa_Tum) return false;

	Tip_u32 Konum = AI_Bul_Blok(Tampon_Isaretci_IlkKonum(Tampon, Tip_char), Tampon_DoluAlan(Tampon), _KomutSatiri_Komut_Baslangici, strlen(_KomutSatiri_Komut_Baslangici));
	if (Konum == 0) return false;

	Konum = AI_Bul_Blok(Tampon_Isaretci_Konum(Tampon, _KomutSatiri_Komut_EnAzKaSa_Bas, Tip_char), Tampon_DoluAlan(Tampon) - _KomutSatiri_Komut_EnAzKaSa_Bas, _KomutSatiri_Komut_Bitisi, strlen(_KomutSatiri_Komut_Bitisi));
	if (Konum == 0) return false;

	return true;
}
Tip_bool KomutSatiri_KontrolEt_DonanimAdresiUygunMu(Tip_Isaretci_Tampon Tampon)
{
	Tip_u32 Konum = AI_Bul_Blok(Tampon_Isaretci_IlkKonum(Tampon, Tip_char), Tampon_DoluAlan(Tampon), _KomutSatiri_Komut_Baslangici, strlen(_KomutSatiri_Komut_Baslangici));
	if (Konum == 0) return false;

	Tampon_Kapasite(Tampon) = Tampon_DoluAlan(Tampon);
	Tampon_DoluAlan(Tampon) = Konum + sizeof(_KomutSatiri_Komut_Baslangici) - 1 /*Ayirac uzerine denk gelecek*/;

	Tip_i32 Okunan;
	if (!KomutSatiri_Oku_TamSayi(Tampon, &Okunan)) return false;

	if (Okunan == 0 /*Genel Cagri*/ || Okunan == _KomutSatiri_DonanimAdresi) return true;

	return false;
}
Tip_bool KomutSatiri_KontrolEt_Siradaki_BuMu(Tip_Isaretci_Tampon Tampon, Tip_char * Bu)
{
    Tip_u32 Aranan_Adet = strlen(Bu);
    if (_KomutSatiri_KarakterSayisi(Tampon) != Aranan_Adet) return false;

	if (!memcmp(Tampon_Isaretci_GecerliKonum(Tampon, Tip_char), Bu, Aranan_Adet))
	{
		Tampon_DoluAlan(Tampon) += Aranan_Adet + 1 /*Ayirac*/;
		return true;
	}

	return false;
}

//Okuma Islemleri
Tip_bool KomutSatiri_Oku_TamSayi(Tip_Isaretci_Tampon Tampon, Tip_i32 * YazilacakTampon)
{
	if ( (Tampon_Icerik_GecerliKonum(Tampon, Tip_char) < '0' || Tampon_Icerik_GecerliKonum(Tampon, Tip_char) > '9') &&
		  Tampon_Icerik_GecerliKonum(Tampon, Tip_char) != '-' &&
		  Tampon_Icerik_GecerliKonum(Tampon, Tip_char) != '+' ) return false;

	Tip_char * Isrtc = Tampon_Isaretci_GecerliKonum(Tampon, Tip_char);
	*YazilacakTampon = strtol(Tampon_Isaretci_GecerliKonum(Tampon, Tip_char), &Isrtc, 0);

	Tampon_DoluAlan(Tampon) += (Tip_u32)Isrtc - (Tip_u32)Tampon_Isaretci_GecerliKonum(Tampon, Tip_char) + 1 /*Ayirac*/;
	return true;
}
Tip_Isaretci_Tampon KomutSatiri_Oku_Hex(Tip_Isaretci_Tampon Tampon)
{
	if (memcmp(Tampon_Isaretci_GecerliKonum(Tampon, Tip_char), "0x", 2)) return Tip_null;
	Tampon_DoluAlan(Tampon) += 2 /*0x*/;

	Tip_u32 Adet = _KomutSatiri_KarakterSayisi(Tampon);
	if (Adet == 0 || (Adet & ((Tip_u32)1) )) return Tip_null; //Karakter say�s� 0 veya tek sayi, hex icin cift olmali

	struct _s_Tampon_ * YazilacakTampon = Tampon_Yeni(Adet / 2);
	if (YazilacakTampon == Tip_null) return Tip_null;

	Tip_u8 Okunan[3] = { 0 };
	Tip_u16 * Kaynak = (Tip_u16 *)Tampon_Isaretci_GecerliKonum(Tampon, Tip_u8);

	for (Tip_u32 i = 0; i < Tampon_Kapasite(YazilacakTampon); i++)
	{
		_Islem_memcpy_(Okunan, Kaynak++, 2);
		Tampon_Bilgi_Ekle_Bayt(YazilacakTampon, (Tip_u8)strtol((Tip_char *)Okunan, Tip_null, 16));
	}

	Tampon_DoluAlan(Tampon) +=  Adet + 1 /*Ayirac*/;
	return YazilacakTampon;
}
Tip_Isaretci_Tampon KomutSatiri_Oku_Yazi(Tip_Isaretci_Tampon Tampon)
{
	if (Tampon_Icerik_GecerliKonum(Tampon, Tip_char) != '"') return Tip_null;
	Tampon_DoluAlan(Tampon) += 1 /*Ayirac*/;

	Tip_u32 Adet = _KomutSatiri_KarakterSayisi_Yazi(Tampon);
	if (Adet == 0) return Tip_null; //Karakter say�s� 0

	struct _s_Tampon_ * YazilacakTampon = Tampon_Yeni(Adet + 1 /* \0 */);
	if (YazilacakTampon == Tip_null) return Tip_null;

	_Islem_memcpy_(Tampon_Isaretci_GecerliKonum(YazilacakTampon, Tip_char), Tampon_Isaretci_GecerliKonum(Tampon, Tip_char), Adet);
	Tampon_Icerik_Konum(YazilacakTampon, Adet, Tip_char) = '\0';

	Tampon_DoluAlan(Tampon) += Adet + 1 /*Ayirac*/ + 1 /*Sonraki Yazi*/;
	return YazilacakTampon;
}

//Cevaplama Islemleri
Tip_void KomutSatiri_Cevapla_Hex(Tip_Isaretci_Tampon Hedef, Tip_Isaretci_Tampon Kaynak)
{
	KomutSatiri_Cevap_Ekle(Hedef, "%s0x", _KomutSatiri_Cevap_Baslangici);

	for (Tip_u32 i = 0; i < Tampon_DoluAlan(Kaynak); i++)
	{
		KomutSatiri_Cevap_Ekle(Hedef, "%02X", Tampon_Icerik_Konum(Kaynak, i, Tip_u8));
	}

	KomutSatiri_Cevap_Ekle(Hedef, "%s", _KomutSatiri_Cevap_Bitisi);
}
