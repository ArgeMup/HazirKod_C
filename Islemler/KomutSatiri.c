// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.3

#include "KomutSatiri.h"

//Ic Kullanim
Tip_void _KomutSatiri_KarakterSayisi(Tip_Isaretci_Tampon Tampon, char Ayirac)
{
	Tip_i32 Konum = AI_Bul_Bayt(Tampon->Isaretci, Tampon->Kapasite, Ayirac);

	if (Konum < 0) Tampon->Sayac = Tampon->Kapasite;
	else Tampon->Sayac = (Tip_u32)Konum;
}
Tip_void _KomutSatiri_Tampon_Kirp(Tip_Isaretci_Tampon Tampon, Tip_u32 Adet)
{
	if (!Tampon_Kirp(Tampon, Adet, 0)) Tampon->Kapasite = 0;
}

//Kontrol Islemleri
Tip_bool KomutSatiri_KontrolEt_TampondakiBilgiUygunMu(Tip_Isaretci_Tampon Tampon)
{
	if (Tampon->Sayac < _KomutSatiri_Komut_EnAzKaSa_Tum) return false;

	Tip_i32 Konum = AI_Bul_Blok(Tampon->Isaretci, Tampon->Sayac, _KomutSatiri_Komut_Baslangici, sizeof(_KomutSatiri_Komut_Baslangici) - 1);
	if (Konum < 0) return false;

	Konum += sizeof(_KomutSatiri_Komut_Baslangici) + 1 /*Ayirac*/;

	Konum = AI_Bul_Blok(Tampon_Isaretci(Tampon, Konum, Tip_char), Tampon->Sayac - Konum, _KomutSatiri_Komut_Bitisi, sizeof(_KomutSatiri_Komut_Bitisi) - 1);
	if (Konum < 0) return false;

	return true;
}
Tip_bool KomutSatiri_KontrolEt_DonanimAdresiUygunMu(Tip_Isaretci_Tampon Tampon)
{
	Tip_i32 Konum = AI_Bul_Blok(Tampon->Isaretci, Tampon->Kapasite, _KomutSatiri_Komut_Baslangici, sizeof(_KomutSatiri_Komut_Baslangici) - 1);
	if (Konum < 0) return false;

	_KomutSatiri_Tampon_Kirp(Tampon, Konum + sizeof(_KomutSatiri_Komut_Baslangici)); /*Ayirac uzerine denk gelecek*/

	Konum = AI_Bul_Blok(Tampon->Isaretci, Tampon->Kapasite, _KomutSatiri_Komut_Bitisi, sizeof(_KomutSatiri_Komut_Bitisi) - 1);
	if (Konum < 0) return false;

	Tampon->Sayac = (Tip_u32)Konum;
	Tampon_Paketle(Tampon);

	if (!KomutSatiri_Oku_TamSayi(Tampon, &Konum)) return false;

	if (Konum == 0 /*Genel Cagri*/ || Konum == _KomutSatiri_DonanimAdresi) return true;

	return false;
}
Tip_bool KomutSatiri_KontrolEt_Siradaki_BuMu(Tip_Isaretci_Tampon Tampon, Tip_char * Bu)
{
	Tip_u32 Aranan_Adet = _Islem_strlen_(Bu);
	_KomutSatiri_KarakterSayisi(Tampon, _KomutSatiri_Ayirac);
	if (Tampon->Sayac != Aranan_Adet) return false;

	if (!_Islem_memcmp_(Tampon->Isaretci, Bu, Aranan_Adet))
	{
		_KomutSatiri_Tampon_Kirp(Tampon, Aranan_Adet + 1 /*Ayirac*/);
		return true;
	}

	return false;
}
Tip_u32 KomutSatiri_KontrolEt_Siradaki_DizidekiElemanlardanBiriMi(Tip_Isaretci_Tampon Tampon, const Tip_char ** Dizi, Tip_u32 ElemanSayisi)
{
	for (Tip_u32 i = 0; i < ElemanSayisi; i++)
	{
		if (KomutSatiri_KontrolEt_Siradaki_BuMu(Tampon, (Tip_char *)Dizi[i])) return i;
	}

	return ElemanSayisi;
}

//Okuma Islemleri
Tip_bool KomutSatiri_Oku_TamSayi(Tip_Isaretci_Tampon Tampon, Tip_i32 * YazilacakTampon)
{
	Tip_char * Isrtc = NULL;
	*YazilacakTampon = _Islem_strtol_(Tampon->Isaretci, &Isrtc, 0);
	if (Tampon->Isaretci == Isrtc) return false;

	_KomutSatiri_Tampon_Kirp(Tampon, (Tip_u32)Isrtc - ((Tip_u32)Tampon->Isaretci) + 1 /*Ayirac*/);
	return true;
}
Tip_bool KomutSatiri_Oku_TamSayi_AraliktaMi(Tip_Isaretci_Tampon Tampon, Tip_i32 * YazilacakTampon, Tip_i32 EnDusuk, Tip_i32 EnYuksek)
{
	if (!KomutSatiri_Oku_TamSayi(Tampon, YazilacakTampon) ||
		(*YazilacakTampon < EnDusuk) ||
		(*YazilacakTampon > EnYuksek) ) return false;

	return true;
}
Tip_Isaretci_Tampon KomutSatiri_Oku_Hex(Tip_Isaretci_Tampon Tampon)
{
	if (_Islem_memcmp_(Tampon->Isaretci, "0x", 2)) return Tip_null;
	_KomutSatiri_Tampon_Kirp(Tampon, 2 /*0x*/);

	_KomutSatiri_KarakterSayisi(Tampon, _KomutSatiri_Ayirac);
	if (Tampon->Sayac == 0 || (Tampon->Sayac & ((Tip_u32)1) )) return Tip_null; //Karakter sayisi 0 veya tek sayi, hex icin cift olmali

	Tip_Isaretci_Tampon YazilacakTampon = Tampon_Yeni(Tampon->Sayac / 2);
	if (YazilacakTampon == Tip_null) return Tip_null;

	Tip_char Okunan[3] = { 0 }; //HH\0
	Tip_u16 * Kaynak = (Tip_u16 *)Tampon->Isaretci;

	for (Tip_u32 i = 0; i < YazilacakTampon->Kapasite; i++)
	{
		_Islem_memcpy_(Okunan, Kaynak++, 2);

		Tip_char * Isrtc = NULL;
		Tip_u8 Okunan_bayt = (Tip_u8)_Islem_strtol_(Okunan, &Isrtc, 16);
		if (Okunan == Isrtc) { Tampon_Sil(YazilacakTampon); return Tip_null; }

		Tampon_Bilgi_Ekle_GecerliKonumdanItibaren(YazilacakTampon, &Okunan_bayt, 1);
	}

	_KomutSatiri_Tampon_Kirp(Tampon, Tampon->Sayac + 1 /*Ayirac*/);
	YazilacakTampon->Sayac = 0;
	return YazilacakTampon;
}
Tip_Isaretci_Tampon KomutSatiri_Oku_Yazi(Tip_Isaretci_Tampon Tampon)
{
	Tip_bool Yazi_Ayirac_ile_baslayip_bitiyor = false;

	if (Tampon_Icerik(Tampon, 0, Tip_char) != _KomutSatiri_Ayirac_Yazi)
	{
		#ifdef _KomutSatiri_Yazi_Ayiracsiz_TekParca_Olabilir
			_KomutSatiri_KarakterSayisi(Tampon, _KomutSatiri_Ayirac);
		#else
		return Tip_null;
		#endif
	}
	else
	{
		_KomutSatiri_Tampon_Kirp(Tampon, 1 /*Ayirac*/);
		_KomutSatiri_KarakterSayisi(Tampon, _KomutSatiri_Ayirac_Yazi);
		Yazi_Ayirac_ile_baslayip_bitiyor = true;
	}

	if (Tampon->Sayac == 0) return Tip_null; //Karakter sayisi 0

	Tip_Isaretci_Tampon YazilacakTampon = Tampon_Yeni(Tampon->Sayac + 1 /* \0 */);
	if (YazilacakTampon == Tip_null) return Tip_null;

	_Islem_memcpy_(YazilacakTampon->Isaretci, Tampon->Isaretci, Tampon->Sayac);
	Tampon_Icerik(YazilacakTampon, Tampon->Sayac, Tip_char) = '\0';

	_KomutSatiri_Tampon_Kirp(Tampon, Tampon->Sayac + 1 /*Ayirac*/);
	if (Yazi_Ayirac_ile_baslayip_bitiyor) _KomutSatiri_Tampon_Kirp(Tampon, 1 /*Ayirac Yazi*/);

	#ifdef _KomutSatiri_Yazi_Icinde_OzelKarakter_Olabilir
	while (YazilacakTampon->Sayac < YazilacakTampon->Kapasite)
	{
		Tip_i32 Oz_Ka_basi = AI_Bul_Bayt(Tampon_Isaretci(YazilacakTampon, YazilacakTampon->Sayac, Tip_u8), YazilacakTampon->Kapasite - YazilacakTampon->Sayac, _KomutSatiri_Ayirac_Yazi_OzelKarakter);
		if (Oz_Ka_basi < 0) break;
		Oz_Ka_basi++;

		Tip_i32 Oz_Ka_sonu = AI_Bul_Bayt(Tampon_Isaretci(YazilacakTampon, YazilacakTampon->Sayac + Oz_Ka_basi, Tip_u8), YazilacakTampon->Kapasite - (YazilacakTampon->Sayac + Oz_Ka_basi), _KomutSatiri_Ayirac_Yazi_OzelKarakter);
		Oz_Ka_sonu++;

		if (Oz_Ka_sonu > 0 && Oz_Ka_sonu <= 4 /*XXX|*/)
		{
			char * kuyruk;
			Tip_u32 Ok = _Islem_strtoul_(Tampon_Isaretci(YazilacakTampon, YazilacakTampon->Sayac + Oz_Ka_basi, Tip_char), &kuyruk, 0);
			if (kuyruk != Tampon_Isaretci(YazilacakTampon, YazilacakTampon->Sayac + Oz_Ka_basi, Tip_char))
			{
				if (Ok < 256)
				{
					Tampon_Icerik(YazilacakTampon,  YazilacakTampon->Sayac + Oz_Ka_basi - 1, Tip_u8) = (Tip_u8)Ok;
					_Islem_memcpy_(Tampon_Isaretci(YazilacakTampon,  YazilacakTampon->Sayac + Oz_Ka_basi, Tip_u8), Tampon_Isaretci(YazilacakTampon,  YazilacakTampon->Sayac + Oz_Ka_basi + Oz_Ka_sonu, Tip_u8), YazilacakTampon->Kapasite - (YazilacakTampon->Sayac + Oz_Ka_basi));
					YazilacakTampon->Kapasite -= Oz_Ka_sonu;
				}
			}
		}
		YazilacakTampon->Sayac += Oz_Ka_basi;
	}
	YazilacakTampon->Sayac = 0;
	#endif

	return YazilacakTampon;
}

//Cevaplama Islemleri
Tip_void KomutSatiri_Cevapla_Hex(Tip_Isaretci_Tampon Hedef, Tip_Isaretci_Tampon Kaynak)
{
	KomutSatiri_Cevap_Ekle(Hedef, "%s0x", _KomutSatiri_Cevap_Baslangici);

	for (Tip_u32 i = 0; i < Kaynak->Kapasite; i++)
	{
		KomutSatiri_Cevap_Ekle(Hedef, "%02X", Tampon_Icerik(Kaynak, i, Tip_u8));
	}

	KomutSatiri_Cevap_Ekle(Hedef, "%s", _KomutSatiri_Cevap_Bitisi);
}
