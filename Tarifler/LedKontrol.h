// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.5

#ifndef __HazirKod_C_LedKontrol_H__
#define __HazirKod_C_LedKontrol_H__

	#include "HazirKod_C_Ayarlar.h"

	#ifdef HazirKod_C_Kullan_LedKontrol

		#include "Gorev.h"

		////////////////////////////////////////////////////////////////////////////////
		//Genel Goruse Acik Tanimlamalar
		////////////////////////////////////////////////////////////////////////////////
		Tip_i32 LedKontrol_Gorev(Tip_Isaretci_Gorev_Detaylar Detaylar);
		Tip_void LedKontrol_GoreviDurdur();
		Tip_void LedKontrol_AnlikBildirim();

	#endif

#endif /* __HazirKod_C_LedKontrol_H__ */
