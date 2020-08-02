// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.1

#ifndef __YerTahsisati_H__
#define __YerTahsisati_H__

#include "HazirKod_C_Ayarlar.h"

////////////////////////////////////////////////////////////////////////////////
//Genel Goruse Acik Tanimlamalar
////////////////////////////////////////////////////////////////////////////////
Tip_Isaretci YT_Yeni(Tip_u32 Adet);
Tip_void YT_Sil(Tip_Isaretci Isaretci);

#ifdef _YT_Heap_Kullanimini_HazirKod_C_Duzenlesin
	#include "heap_4.h"
	#define	YT_BosAlan() 			xPortGetFreeHeapSize()
	#define _YT_Islem_malloc_(x)	pvPortMalloc(x)
	#define _YT_Islem_free_(x)		vPortFree(x)
	extern uint8_t ucHeap[];
	#define _YT_Ram_Baslangic		( (Tip_u32)Isaretci_Konumlandir(ucHeap, 0, Tip_u8) )
	#define _YT_Ram_Bitis			( (Tip_u32)Isaretci_Konumlandir(ucHeap, configTOTAL_HEAP_SIZE, Tip_u8) )
#endif

#endif /*__YerTahsisati_H__ */
