// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.2

#ifndef __Tampon_H__
#define __Tampon_H__

#include "HazirKod_C_Ayarlar.h"
#include "Zamanlama.h"
#include "YerTahsisati.h"

////////////////////////////////////////////////////////////////////////////////
//Ic Kullanim
////////////////////////////////////////////////////////////////////////////////
struct _s_Tampon_
{
	Tip_Isaretci Isaretci;
	Tip_u32 Kapasite;
	Tip_u32 Kullanim;
};
#define _Tampon_(s_Tampon)						( (struct _s_Tampon_ *)s_Tampon )

////////////////////////////////////////////////////////////////////////////////
//Genel Goruse Acik Tanimlamalar
////////////////////////////////////////////////////////////////////////////////
typedef Tip_Isaretci Tip_Isaretci_Tampon;

#define Tampon_Isaretci_Konum(s_Tampon, Konum, Tip)		Isaretci_Konumlandir(_Tampon_(s_Tampon)->Isaretci, Konum, Tip)
#define Tampon_Icerik_Konum(s_Tampon, Konum, Tip)		Isaretci_Icerigi(_Tampon_(s_Tampon)->Isaretci, Konum, Tip)

#define Tampon_Isaretci_GecerliKonum(s_Tampon, Tip)		Tampon_Isaretci_Konum(s_Tampon, _Tampon_(s_Tampon)->Kullanim, Tip)
#define Tampon_Icerik_GecerliKonum(s_Tampon, Tip)       Tampon_Icerik_Konum(s_Tampon, _Tampon_(s_Tampon)->Kullanim, Tip)

#define Tampon_Isaretci_IlkKonum(s_Tampon, Tip)			Tampon_Isaretci_Konum(s_Tampon, 0, Tip)

#define Tampon_Kapasite(s_Tampon)						( _Tampon_(s_Tampon)->Kapasite )
#define Tampon_DoluAlan(s_Tampon)						( _Tampon_(s_Tampon)->Kullanim )
#define Tampon_BosAlan(s_Tampon)						( Tampon_Kapasite(s_Tampon) - Tampon_DoluAlan(s_Tampon) )

Tip_Isaretci_Tampon Tampon_Yeni(Tip_u32 Kapasite);
Tip_void Tampon_Sil(Tip_Isaretci_Tampon Tampon);

Tip_bool Tampon_Bilgi_Ekle_Bayt(Tip_Isaretci_Tampon Tampon, Tip_u8 Bayt);
Tip_bool Tampon_Bilgi_Ekle_Blok(Tip_Isaretci_Tampon Tampon, Tip_Isaretci Kaynak, Tip_u32 KaynakBoyut);

#endif /*__Tampon_H__ */
