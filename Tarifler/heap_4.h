// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.1

#ifdef _YT_Heap_Kullanimini_HazirKod_C_Duzenlesin
	#ifndef __Heap_4_H__
	#define __Heap_4_H__

	#include "HazirKod_C_Ayarlar.h"

	////////////////////////////////////////////////////////////////////////////////
	//Ic Kullanim
	////////////////////////////////////////////////////////////////////////////////
	void *pvPortMalloc( size_t xWantedSize );
	size_t pvPortMalloc_Size( void *pv );
	void vPortFree( void *pv );
	size_t xPortGetFreeHeapSize( void );

	#define configASSERT(Kistas)		if ( !(Kistas) ) HataKontrol_Hatali(e_HataKontrol_Hata_YerTahsisati);
	#define portBYTE_ALIGNMENT_MASK		( (Tip_u16)(portBYTE_ALIGNMENT - 1) )

	#endif /* __Heap_4_H__ */
#endif
