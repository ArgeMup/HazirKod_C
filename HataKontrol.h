// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.0

#ifndef __HataKontrol_H__
#define __HataKontrol_H__

#include "../HazirKod_C_Ayarlar.h"
#include "BitIslemleri.h"

void HataKontrol_Baslat();
void HataKontrol_Hatali(enum e_HataKontrol_Hatalar Hata);
void HataKontrol_Hatasiz(enum e_HataKontrol_Hatalar Hata);
_Ortak_Tip_bool_ HataKontrol_HataDevamEdiyorMu(enum e_HataKontrol_Hatalar Hata);

#endif /* __HataKontrol_H__ */
