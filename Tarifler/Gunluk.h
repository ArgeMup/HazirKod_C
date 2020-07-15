// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.3

#ifndef __Gunluk_H__
#define __Gunluk_H__

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

#include "HazirKod_C_Ayarlar.h"
#include "Zamanlama.h"

////////////////////////////////////////////////////////////////////////////////
//Genel Goruse Acik Tanimlamalar
////////////////////////////////////////////////////////////////////////////////
typedef Tip_void (*Tip_Islem_Gunluk_DisariAktarma) (Tip_Isaretci, Tip_u32);
Tip_void Gunluk_Baslat();
Tip_void Gunluk_Ekle(const Tip_char * Baslik, const Tip_char * Sekil, ...);
Tip_void Gunluk_Ekle_Hex(const Tip_char * Baslik, Tip_Isaretci Tampon, Tip_u16 Adet);
Tip_void Gunluk_SureliDurdur(Tip_u32 Saniye);

#endif /*__Gunluk_H__ */
