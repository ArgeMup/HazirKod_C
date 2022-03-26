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
		Tip_i32 LedKontrol_Gorev(struct s_Gorev_Detaylar_ * Detaylar);
		Tip_void LedKontrol_HataDurumunuGuncelle(Tip_u32 HataDurumu);
		Tip_void LedKontrol_AnlikBildirim();

	#endif

#endif /* __HazirKod_C_LedKontrol_H__ */
