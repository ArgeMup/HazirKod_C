// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.2

#ifndef __HazirKod_C_YaziIslemleri_H__
#define __HazirKod_C_YaziIslemleri_H__

	#include "HazirKod_C_Ayarlar.h"

	#ifdef HazirKod_C_Kullan_YaziIslemleri

		#include <time.h>
		#include <stdio.h>
		#include <stdarg.h>

		#include "AramaIslemleri.h"

		////////////////////////////////////////////////////////////////////////////////
		//Genel Goruse Acik Tanimlamalar
		////////////////////////////////////////////////////////////////////////////////
		#define YI_Bul(Kaynak, Aranan) AI_Bul_Blok((Tip_Isaretci)Kaynak, _Islem_strlen_(Kaynak), (Tip_Isaretci)Aranan, _Islem_strlen_(Aranan))
		Tip_i32 YI_BulAyiklaKopyala(Tip_char * Kaynak, Tip_char * ArananBaslangic, Tip_char * ArananBitis, Tip_char * Hedef, Tip_u32 HedefKapasite);
		#define YI_Degistir(Kaynak, Aranan, YeniYazi, Hedef, HedefKapasitesi, SadeceIlkiniDegistir) AI_Degistir((Tip_Isaretci)Kaynak, _Islem_strlen_(Kaynak), (Tip_Isaretci)Aranan, _Islem_strlen_(Aranan), (Tip_Isaretci)YeniYazi, _Islem_strlen_(YeniYazi), (Tip_Isaretci)Hedef, HedefKapasitesi, SadeceIlkiniDegistir)

		Tip_char * YI_Yazdir(Tip_char * Hedef, Tip_u32 HedefKapasite, Tip_char * Sekil, ...);
		Tip_char * YI_Yazdir_TarihSaat(Tip_char * Hedef, Tip_u32 HedefKapasite, Tip_time An);
		Tip_char * YI_Yazdir_NoktaliSayi(Tip_char * Hedef, Tip_u32 HedefKapasite, Tip_float NoktaliSayi);
		Tip_char * YI_Yazdir_TamSayi_Hex(Tip_char * Hedef, Tip_u32 HedefKapasite, Tip_u32 TamSayi);
		Tip_char * YI_Yazdir_TamSayi(Tip_char * Hedef, Tip_u32 HedefKapasite, Tip_i32 TamSayi);
		Tip_char * YI_Yazdir_Hex_Tampon(Tip_char * Hedef, Tip_u32 HedefKapasite, Tip_Isaretci Kaynak, Tip_u32 Adet);

	#endif

#endif	//__HazirKod_C_YaziIslemleri_H__
