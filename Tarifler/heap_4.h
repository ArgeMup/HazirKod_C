// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.2

#ifndef __HazirKod_C_Heap_4_H__
#define __HazirKod_C_Heap_4_H__

	#include "HazirKod_C_Ayarlar.h"

	#ifdef HazirKod_C_Kullan_YerTahsisati

		#ifdef _YT_Tanimli_HEAP_Kutuphanesini_kullanMA

			////////////////////////////////////////////////////////////////////////////////
			//Ic Kullanim
			////////////////////////////////////////////////////////////////////////////////
			void *pvPortMalloc( size_t xWantedSize );
			size_t pvPortMalloc_Size( void *pv );
			void vPortFree( void *pv );
			size_t xPortGetFreeHeapSize( void );

			#define configASSERT(Kistas)		if ( !(Kistas) ) HazirKod_C_Gunluk("Beklenmeyen Durum");
			#define portBYTE_ALIGNMENT_MASK		( (Tip_u16)(portBYTE_ALIGNMENT - 1) )

		#endif

	#endif

#endif /* __HazirKod_C_Heap_4_H__ */
