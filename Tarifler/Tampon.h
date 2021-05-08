// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.4

#ifndef __Tampon_H__
#define __Tampon_H__

#include "HazirKod_C_Ayarlar.h"
#include "Zamanlama.h"
#include "YerTahsisati.h"

////////////////////////////////////////////////////////////////////////////////
//Ic Kullanim
////////////////////////////////////////////////////////////////////////////////
struct s_Tampon_
{
	Tip_Isaretci Isaretci;
	Tip_u32 Kapasite;
	Tip_u32 Sayac;
};

////////////////////////////////////////////////////////////////////////////////
//Genel Goruse Acik Tanimlamalar
////////////////////////////////////////////////////////////////////////////////
typedef struct s_Tampon_ * Tip_Isaretci_Tampon;

#define Tampon_Isaretci(s_Tampon, Konum, Tip)	Isaretci_Konumlandir(s_Tampon->Isaretci, Konum, Tip)
#define Tampon_Icerik(s_Tampon, Konum, Tip)		Isaretci_Icerigi(s_Tampon->Isaretci, Konum, Tip)

#define Tampon_Kapasite(s_Tampon)				( s_Tampon->Kapasite )
#define Tampon_DoluAlan(s_Tampon)				( s_Tampon->Sayac )
#define Tampon_BosAlan(s_Tampon)				( Tampon_Kapasite(s_Tampon) - Tampon_DoluAlan(s_Tampon) )

Tip_Isaretci_Tampon Tampon_Yeni(Tip_u32 Kapasite);
Tip_void Tampon_Paketle(Tip_Isaretci_Tampon Tampon);
Tip_bool Tampon_Kirp(Tip_Isaretci_Tampon Tampon, Tip_u32 Bastan, Tip_u32 Sondan);
Tip_void Tampon_Sil(Tip_Isaretci_Tampon Tampon);

Tip_u32 Tampon_Bilgi_Oku_Konum(Tip_Isaretci_Tampon Tampon, Tip_u32 BaslangicKonumu, Tip_Isaretci Hedef, Tip_u32 HedefKapasitesi);
Tip_bool Tampon_Bilgi_Ekle_Konum(Tip_Isaretci_Tampon Tampon, Tip_u32 BaslangicKonumu, Tip_Isaretci Kaynak, Tip_u32 Adet);

Tip_u32 Tampon_Bilgi_Oku_BaslangictanGecerliKonumaKadar(Tip_Isaretci_Tampon Tampon, Tip_Isaretci Hedef, Tip_u32 HedefKapasitesi);
Tip_bool Tampon_Bilgi_Ekle_GecerliKonumdanItibaren(Tip_Isaretci_Tampon Tampon, Tip_Isaretci Kaynak, Tip_u32 Adet);

#ifdef _YT_Heap_Kullanimini_HazirKod_C_Duzenlesin
	Tip_void Tampon_Yenile(Tip_Isaretci_Tampon Tampon);
#endif

#endif /*__Tampon_H__ */
