// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.1

#ifndef __YaziIslemleri_H__
#define __YaziIslemleri_H__

#include <time.h>
#include <stdio.h>
#include <stdarg.h>

#include "HazirKod_C_Ayarlar.h"
#include "AramaIslemleri.h"

////////////////////////////////////////////////////////////////////////////////
//Genel Goruse Acik Tanimlamalar
////////////////////////////////////////////////////////////////////////////////
#define YI_Ara(Kaynak, Aranan)   AI_Bul_Blok((Tip_Isaretci)Kaynak, strlen(Kaynak), (Tip_Isaretci)Aranan, strlen(Aranan))
Tip_u32 YI_BulAyiklaKopyala(Tip_char * Kaynak, Tip_char * ArananBaslangic, Tip_char * ArananBitis, Tip_char * Hedef, Tip_u32 HedefBoyut);

Tip_char * YI_Yazdir(Tip_char * Hedef, Tip_u32 HedefKapasite, Tip_char * Sekil, ...);
Tip_char * YI_Yazdir_TarihSaat(Tip_char * Hedef, Tip_u32 HedefKapasite, Tip_time An);
Tip_char * YI_Yazdir_NoktaliSayi(Tip_char * Hedef, Tip_u32 HedefKapasite, Tip_float NoktaliSayi);
Tip_char * YI_Yazdir_TamSayi_Hex(Tip_char * Hedef, Tip_u32 HedefKapasite, Tip_u32 TamSayi);
Tip_char * YI_Yazdir_TamSayi(Tip_char * Hedef, Tip_u32 HedefKapasite, Tip_u32 TamSayi);
Tip_char * YI_Yazdir_Hex_Tampon(Tip_char * Hedef, Tip_u32 HedefKapasite, Tip_Isaretci Kaynak, Tip_u32 Adet);

#endif	//__YaziIslemleri_H__
