// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.1

#ifndef __Gunluk_H__
#define __Gunluk_H__

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include "../HazirKod_C_Ayarlar.h"

////////////////////////////////////////////////////////////////////////////////
//Genel Goruse Acik Tanimlamalar
////////////////////////////////////////////////////////////////////////////////

void Gunluk_Baslat();
void Gunluk_Ekle(const _Ortak_Tip_char_ * Baslik, const _Ortak_Tip_char_ * Metin, ...);
void Gunluk_Ekle_Hex(const _Ortak_Tip_char_ * Baslik, _Ortak_Tip_Isaretci_ Tampon, _Ortak_Tip_uint16_t_ Adet);
void Gunluk_SureliDurdur(_Ortak_Tip_uint32_t_ Saniye);

#endif /*__Gunluk_H__ */
