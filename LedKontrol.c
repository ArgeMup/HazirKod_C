// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.0

#include "LedKontrol.h"

#define LedKontrol_AnlikBildirim_Bekleme		50
#define LedKontrol_AnlikBildirim_Adet			5
#define LedKontrol_HerseyYolunda_Bekleme_Kisa	150
#define LedKontrol_HerseyYolunda_Bekleme_Uzun	1500
#define LedKontrol_HataVar_Bekleme_Kisa			500
#define LedKontrol_HataVar_Bekleme_Uzun			1500 - LedKontrol_HerseyYolunda_Bekleme_Kisa

enum e_LedKontrol_Islemler
{
	e_LedKontrol_Islem_Bosta,

	e_LedKontrol_Islem_AnlikBildirim_0,
	e_LedKontrol_Islem_AnlikBildirim_1,
	e_LedKontrol_Islem_AnlikBildirim_2,

	e_LedKontrol_Islem_HerseyYolunda_0,
	e_LedKontrol_Islem_HerseyYolunda_1,
	e_LedKontrol_Islem_HerseyYolunda_2,

	e_LedKontrol_Islem_HataVar_0,
	e_LedKontrol_Islem_HataVar_1,
	e_LedKontrol_Islem_HataVar_2,
	e_LedKontrol_Islem_HataVar_3
}LedKontrol_Islem = e_LedKontrol_Islem_Bosta;

_Ortak_Tip_bool_ LedKontrol_AnlikBildirim_Isteniyor = true;
_Ortak_Tip_uint8_t_ LedKontrol_SayacGenel;

void LedKontrol_AnlikBildirim()
{
	LedKontrol_AnlikBildirim_Isteniyor = true;
}

_Ortak_Tip_int32_t_ LedKontrol_Gorev()
{
	YenidenCalistir:
	switch (LedKontrol_Islem)
	{
		default:
		case (e_LedKontrol_Islem_Bosta):
			if (LedKontrol_AnlikBildirim_Isteniyor) LedKontrol_Islem = e_LedKontrol_Islem_AnlikBildirim_0;
			else
			{
				LedKontrol_SayacGenel = 0;
				for (; LedKontrol_SayacGenel < e_HataKontrol_Hata_SonEleman; LedKontrol_SayacGenel++) if (HataKontrol_HataDevamEdiyorMu(LedKontrol_SayacGenel)) break;

				if (LedKontrol_SayacGenel == e_HataKontrol_Hata_SonEleman) LedKontrol_Islem = e_LedKontrol_Islem_HerseyYolunda_0;
				else LedKontrol_Islem = e_LedKontrol_Islem_HataVar_0;
			}
			goto YenidenCalistir;

		//////////////////////////////////////////////////////////////////////////////////
		//Anlik Bildirim//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////
		case (e_LedKontrol_Islem_AnlikBildirim_0):
			LedKontrol_SayacGenel = LedKontrol_AnlikBildirim_Adet;
			LedKontrol_AnlikBildirim_Isteniyor = false;
			LedKontrol_Islem++;

		case (e_LedKontrol_Islem_AnlikBildirim_1):
			if (--LedKontrol_SayacGenel == 0)
			{
				LedKontrol_Islem = e_LedKontrol_Islem_Bosta;
				goto YenidenCalistir;
			}

			Bacak_Yaz_0(Bacak_LED);
			LedKontrol_Islem++;
			return LedKontrol_AnlikBildirim_Bekleme;

		case (e_LedKontrol_Islem_AnlikBildirim_2):
			Bacak_Yaz_1(Bacak_LED);
			LedKontrol_Islem--;
			return LedKontrol_AnlikBildirim_Bekleme;

		//////////////////////////////////////////////////////////////////////////////////
		//Hersey Yolunda//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////
		case (e_LedKontrol_Islem_HerseyYolunda_0):
			Bacak_Yaz_0(Bacak_LED);
			LedKontrol_Islem++;
			return LedKontrol_HerseyYolunda_Bekleme_Uzun;

		case (e_LedKontrol_Islem_HerseyYolunda_1):
			Bacak_Yaz_1(Bacak_LED);
			LedKontrol_Islem++;
			return LedKontrol_HerseyYolunda_Bekleme_Kisa;

		case (e_LedKontrol_Islem_HerseyYolunda_2):
			Bacak_Yaz_0(Bacak_LED);
			LedKontrol_Islem = e_LedKontrol_Islem_Bosta;
			return LedKontrol_HerseyYolunda_Bekleme_Uzun;

		//////////////////////////////////////////////////////////////////////////////////
		//Hata Var////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////
		case (e_LedKontrol_Islem_HataVar_0):
			LedKontrol_SayacGenel++;
			LedKontrol_Islem++;
			return LedKontrol_HataVar_Bekleme_Uzun;

		case (e_LedKontrol_Islem_HataVar_1):
			if (LedKontrol_SayacGenel-- == 0)
			{
				LedKontrol_Islem = e_LedKontrol_Islem_HataVar_3;
				goto YenidenCalistir;
			}

			Bacak_Yaz_0(Bacak_LED);
			LedKontrol_Islem++;
			return LedKontrol_HataVar_Bekleme_Kisa;

		case (e_LedKontrol_Islem_HataVar_2):
			Bacak_Yaz_1(Bacak_LED);
			LedKontrol_Islem--;
			return LedKontrol_HataVar_Bekleme_Kisa;

		case (e_LedKontrol_Islem_HataVar_3):
			LedKontrol_Islem = e_LedKontrol_Islem_Bosta;
			return LedKontrol_HataVar_Bekleme_Uzun;
	}

	LedKontrol_Islem = e_LedKontrol_Islem_Bosta;
	return LedKontrol_HataVar_Bekleme_Uzun; //Buraya ula�mamas� gerekiyor
}
