// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.0

#include "Zamanlama.h"

_Ortak_Tip_weak_ _An_Tip_ Zamanlama_An_Okuma_Islemi()
{
	//_An_Tip_ tipinde ve 1 LSB nin degeri _An_Aralik_Msn_ kadar olmali
	return 1;
}

_Ortak_Tip_weak_ void Zamanlama_Bekle_MiliSaniye_Islemi(_Ortak_Tip_uint32_t_ Sure)
{
	_An_Tip_ ZamanAsimi;
	Sure_MiliSaniye(ZamanAsimi, Sure);
	while (!Sure_DolduMu(ZamanAsimi));
}