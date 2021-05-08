// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.0

#ifndef __AramaIslemleri_H__
#define __AramaIslemleri_H__

#include "HazirKod_C_Ayarlar.h"

////////////////////////////////////////////////////////////////////////////////
//Genel Goruse Acik Tanimlamalar
////////////////////////////////////////////////////////////////////////////////
Tip_i32 AI_Bul_Bayt(Tip_Isaretci Kaynak, Tip_u32 KaynaktakiBilgiMiktari, Tip_u8 ArananBilgi);
Tip_i32 AI_Bul_Bayt_Sondan(Tip_Isaretci Kaynak, Tip_u32 KaynaktakiBilgiMiktari, Tip_u8 ArananBilgi);

Tip_i32 AI_Bul_Blok(Tip_Isaretci Kaynak, Tip_u32 KaynaktakiBilgiMiktari, Tip_Isaretci ArananBilgi, Tip_u32 ArananBilgiMiktari);
Tip_i32 AI_Bul_Blok_Sondan(Tip_Isaretci Kaynak, Tip_u32 KaynaktakiBilgiMiktari, Tip_Isaretci ArananBilgi, Tip_u32 ArananBilgiMiktari);

Tip_i32 AI_Degistir(Tip_Isaretci Kaynak, Tip_u32 KaynaktakiBilgiMiktari, Tip_Isaretci ArananBilgi, Tip_u32 ArananBilgiMiktari, Tip_Isaretci YeniBilgi, Tip_u32 YeniBilgiMiktari, Tip_Isaretci Hedef, Tip_u32 HedefKapasitesi, Tip_bool SadeceIlkBuldugunuDegistir);

#endif /*__AramaIslemleri_H__ */
