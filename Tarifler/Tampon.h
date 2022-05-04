// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.7

#ifndef __HazirKod_C_Tampon_H__
#define __HazirKod_C_Tampon_H__

	#include "HazirKod_C_Ayarlar.h"

	#ifdef HazirKod_C_Kullan_Tampon

		#include "YerTahsisati.h"

		////////////////////////////////////////////////////////////////////////////////
		//Genel Goruse Acik Tanimlamalar
		////////////////////////////////////////////////////////////////////////////////
		typedef struct
		{
			Tip_Isaretci Isaretci;
			Tip_u32 Kapasite;
			Tip_u32 Sayac;

			#ifdef _Tampon_Sablon_KullaniciNesnesi
				_Tampon_Sablon_KullaniciNesnesi KullaniciNesnesi;
			#endif
		} * Tip_Isaretci_Tampon, _Tip_s_Tampon;

		#define Tampon_Kapasite(s_Tampon)										( s_Tampon->Kapasite )
		#define Tampon_DoluAlan(s_Tampon)										( s_Tampon->Sayac )
		#define Tampon_BosAlan(s_Tampon)										( Tampon_Kapasite(s_Tampon) - Tampon_DoluAlan(s_Tampon) )

		Tip_Isaretci_Tampon Tampon_Yeni(Tip_u32 Kapasite, Tip_bool Sifirla);
		Tip_void Tampon_Paketle(Tip_Isaretci_Tampon Tampon);
		Tip_bool Tampon_Kirp(Tip_Isaretci_Tampon Tampon, Tip_u32 Bastan, Tip_u32 Sondan);
		Tip_void Tampon_Sil(Tip_Isaretci_Tampon Tampon);
		#define Tampon_Sill(s_Tampon)											{ Tampon_Sil(s_Tampon); s_Tampon = Tip_null; }

		Tip_u32 Tampon_Bilgi_Oku_Konum(Tip_Isaretci_Tampon Tampon, Tip_u32 BaslangicKonumu, Tip_Isaretci Hedef, Tip_u32 HedefKapasitesi);
		Tip_bool Tampon_Bilgi_Ekle_Konum(Tip_Isaretci_Tampon Tampon, Tip_u32 BaslangicKonumu, Tip_Isaretci Kaynak, Tip_u32 Adet);

		Tip_u32 Tampon_Bilgi_Oku_BaslangictanGecerliKonumaKadar(Tip_Isaretci_Tampon Tampon, Tip_Isaretci Hedef, Tip_u32 HedefKapasitesi);
		Tip_bool Tampon_Bilgi_Ekle_GecerliKonumdanItibaren(Tip_Isaretci_Tampon Tampon, Tip_Isaretci Kaynak, Tip_u32 Adet);

		#ifdef _YT_Tanimli_HEAP_Kutuphanesini_kullanMA

			#ifdef HazirKod_C_Kullan_DeneyselEklentiler

			Tip_void Tampon_Yenile(Tip_Isaretci_Tampon Tampon);

			#endif

		#endif

	#endif

#endif /*__HazirKod_C_Tampon_H__ */
