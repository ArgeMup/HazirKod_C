// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.0

#include "HataKontrol.h"

_Ortak_Tip_uint32_t_ HataKontrol_Hatalar;

void HataKontrol_Baslat()
{
	HataDegiskeniniBaslat(HataKontrol_Hatalar);
}

void HataKontrol_Hatali(enum e_HataKontrol_Hatalar Hata)
{
	Hatali(HataKontrol_Hatalar, Hata);
}

void HataKontrol_Hatasiz(enum e_HataKontrol_Hatalar Hata)
{
	HataliDegil(HataKontrol_Hatalar, Hata);
}

_Ortak_Tip_bool_ HataKontrol_HataDevamEdiyorMu(enum e_HataKontrol_Hatalar Hata)
{
	return HataliMi(HataKontrol_Hatalar, Hata);
}
