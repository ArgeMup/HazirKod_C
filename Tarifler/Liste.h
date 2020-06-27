// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.0

#ifndef __Liste_H__
#define __Liste_H__

#include "HazirKod_C_Ayarlar.h"
#include "YerTahsisati.h"

////////////////////////////////////////////////////////////////////////////////
//Ic Kullanim
////////////////////////////////////////////////////////////////////////////////
struct _s_Liste_
{
	struct _s_Liste_Elemani_
	{
		Tip_Isaretci Isaretci;
		struct _s_Liste_Elemani_ * SonrakiListeElemani;
	} * IlkEleman, * SonEleman;
};

#define _Liste_IlkEleman(s_Liste)								(((struct _s_Liste_ *)s_Liste)->IlkEleman)
#define _Liste_SonEleman(s_Liste)								(((struct _s_Liste_ *)s_Liste)->SonEleman)

////////////////////////////////////////////////////////////////////////////////
//Genel Goruse Acik Tanimlamalar
////////////////////////////////////////////////////////////////////////////////
typedef Tip_Isaretci Tip_Isaretci_Liste;
typedef Tip_Isaretci Tip_Isaretci_Liste_Kuyruk;

Tip_Isaretci_Liste Liste_Yeni();
Tip_void Liste_Sil(Tip_Isaretci_Liste Liste, Tip_bool ElemanlaridaSil);

Tip_bool Liste_Eleman_Ekle(Tip_Isaretci_Liste Liste, Tip_Isaretci EklenecekEleman);
Tip_Isaretci Liste_Eleman_Ekle_VeYerTahsisEt(Tip_Isaretci_Liste Liste, Tip_u32 Adet);
Tip_void Liste_Eleman_Sil(Tip_Isaretci_Liste Liste, Tip_Isaretci SilinecekEleman, Tip_bool TahsisEdilenAlanidaSil);

Tip_Isaretci _Liste_Kuyruk_SonrakiEleman(Tip_Isaretci_Liste Liste, Tip_Isaretci_Liste_Kuyruk * KuyrukDegiskeni);
#define Liste_Kuyruk_DegiskeniniOlustur(s_Liste, Degisken)		Tip_Isaretci_Liste_Kuyruk Degisken = _Liste_IlkEleman(s_Liste)
#define Liste_Kuyruk_SonrakiEleman(s_Liste, KuyrukDegiskeni)	_Liste_Kuyruk_SonrakiEleman(s_Liste, &KuyrukDegiskeni)

#define Liste_Eleman_Ilk(s_Liste)								(_Liste_IlkEleman(s_Liste)->Isaretci)
#define Liste_Eleman_Son(s_Liste)								(_Liste_SonEleman(s_Liste)->Isaretci)

#endif /*__Liste_H__ */
