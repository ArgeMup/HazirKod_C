// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.2

#ifndef __Gorev_H__
#define __Gorev_H__

#include "HazirKod_C_Ayarlar.h"

////////////////////////////////////////////////////////////////////////////////
//Genel Goruse Acik Tanimlamalar
////////////////////////////////////////////////////////////////////////////////
_Ortak_Tip_int32_t_ Gorev_Ekle(_Ortak_Tip_int32_t_ (*Islem) (void));
_Ortak_Tip_int32_t_ Gorev_Sil(_Ortak_Tip_int32_t_ (*Islem) (void));
void Gorev_Calistir();

#endif /* __Gorev_H__ */