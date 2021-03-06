// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.4

#ifndef __Gorev_H__
#define __Gorev_H__

#include "HazirKod_C_Ayarlar.h"
#include "Zamanlama.h"
#include "Liste.h"

////////////////////////////////////////////////////////////////////////////////
//Genel Goruse Acik Tanimlamalar
////////////////////////////////////////////////////////////////////////////////
struct s_Gorev_Detaylar_
{
	Tip_Sure An;
	_Tip_Gorev_CalistirilacakAdim CalistirilacakAdim;
	Tip_Isaretci KullaniciNesnesi;
};
typedef Tip_Isaretci Tip_Isaretci_Gorev;
typedef Tip_i32 (*Tip_Islem_Gorev) (struct s_Gorev_Detaylar_ *);

#define Gorev_Yeni()							Liste_Yeni()
#define Gorev_Sil(s_Gorev)						Liste_Sil(s_Gorev, true)
Tip_void Gorev_Calistir(Tip_Isaretci_Gorev Gorev);

Tip_bool Gorev_Islem_Ekle(Tip_Isaretci_Gorev Gorev, Tip_Islem_Gorev Islem, Tip_Isaretci KullaniciNesnesi);
Tip_bool Gorev_Islem_MevcutMu(Tip_Isaretci_Gorev Gorev, Tip_Islem_Gorev Islem);
Tip_void Gorev_Islem_HemenCalistir(Tip_Isaretci_Gorev Gorev, Tip_Islem_Gorev Islem);

#define Gorev_Islem_CikVeSil()					return -1
#define Gorev_Islem_CikVeTekrarCalistir(msn)	return msn

#endif /* __Gorev_H__ */
