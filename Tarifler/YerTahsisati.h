// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.3

#ifndef __HazirKod_C_YerTahsisati_H__
#define __HazirKod_C_YerTahsisati_H__

	#include "HazirKod_C_Ayarlar.h"

	#ifdef HazirKod_C_Kullan_YerTahsisati

		////////////////////////////////////////////////////////////////////////////////
		//Genel Goruse Acik Tanimlamalar
		////////////////////////////////////////////////////////////////////////////////
		Tip_Isaretci YT_Yeni(Tip_u32 Adet, Tip_bool Sifirla);
		Tip_void YT_Sil(Tip_Isaretci Isaretci);
		#define YT_Sill(Isaretci)				{ YT_Sil(Isaretci); Isaretci = Tip_null; }

		#ifdef _YT_Tanimli_HEAP_Kutuphanesini_kullanMA

		#include "heap_4.h"
			#define	YT_BosAlan() 				xPortGetFreeHeapSize()

			#define _YT_Islem_malloc_(Adet)		pvPortMalloc(Adet)
			#define _YT_Islem_free_(Isaretci)	vPortFree(Isaretci)

			#ifdef HazirKod_C_Kullan_DeneyselEklentiler
				#define	YT_Kapasite(Isaretci) 		( (Tip_u32)pvPortMalloc_Size(Isaretci) )
			#endif

			#ifdef _YT_Tahsis_Edilen_Alani_Kontrol_Et
				extern Tip_u8 ucHeap[];
				#define _YT_Ram_Baslangic			( Isaretci_Konumlandir(ucHeap, 0, Tip_u8, Tip_Isaretci_SayiKarsiligi) )
				#define _YT_Ram_Bitis				( Isaretci_Konumlandir(ucHeap, configTOTAL_HEAP_SIZE, Tip_u8, Tip_Isaretci_SayiKarsiligi) )
			#endif

		#endif

	#endif

#endif /*__HazirKod_C_YerTahsisati_H__ */
