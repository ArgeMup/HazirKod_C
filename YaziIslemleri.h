// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.0

#ifndef __MetinIslemleri_H__
#define __MetinIslemleri_H__

#include <time.h>
#include <stdio.h>
#include <stdarg.h>

#include "HazirKod_C_Ayarlar.h"

////////////////////////////////////////////////////////////////////////////////
//Genel Goruse Acik Tanimlamalar
////////////////////////////////////////////////////////////////////////////////
Tip_char * YI_Ara(Tip_char * Kaynak, Tip_u32 KaynakBoyut, Tip_char * Aranan);
Tip_u32 YI_BulAyiklaKopyala(Tip_char * Kaynak, Tip_u32 KaynakBoyut, Tip_char * ArananBaslangic, Tip_char * ArananBitis, Tip_char * Hedef, Tip_u32 HedefBoyut);

Tip_char * YI_Yazdir(Tip_char * Tampon, Tip_u32 TamponKapasitesi, Tip_char * Sekil, ...);
Tip_char * YI_Yazdir_TarihSaat(Tip_time An, Tip_char * Tampon, Tip_u32 TamponKapasitesi);
Tip_char * YI_Yazdir_NoktaliSayi(Tip_float NoktaliSayi, Tip_char * Tampon, Tip_u32 TamponKapasitesi);
Tip_char * YI_Yazdir_TamSayi_Hex(Tip_u32 TamSayi, Tip_char * Tampon, Tip_u32 TamponKapasitesi);
Tip_char * YI_Yazdir_TamSayi(Tip_u32 TamSayi, Tip_char * Tampon, Tip_u32 TamponKapasitesi);
Tip_char * YI_Yazdir_Hex_Tampon(Tip_Isaretci Girdi, Tip_u32 GirdiAdet, Tip_char * Tampon, Tip_u32 TamponKapasitesi);

#endif	//__MetinIslemleri_H__
