// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.1

#include "LedKontrol.h"

enum e_LedKontrol_Islemler_
{
	e_LedKontrol_Islem_IlkCalistirma,

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
};

struct s_LedKontrol_
{
	Tip_bool AnlikBildirim_Isteniyor;
	Tip_u8 SayacGenel;
}_LedKontrol = { 0 };

Tip_void LedKontrol_AnlikBildirim()
{
	_LedKontrol.AnlikBildirim_Isteniyor = true;
}

Tip_i32 LedKontrol_Gorev(struct s_Gorev_Detaylar_ * Gorev)
{
	YenidenCalistir:
	switch (Gorev->CalistirilacakAdim)
	{
		default:
		case (e_LedKontrol_Islem_IlkCalistirma):
			LedKontrol_AnlikBildirim();

		case (e_LedKontrol_Islem_Bosta):
			if (_LedKontrol.AnlikBildirim_Isteniyor) Gorev->CalistirilacakAdim = e_LedKontrol_Islem_AnlikBildirim_0;
			else
			{
				_LedKontrol.SayacGenel = 0;
				for (; _LedKontrol.SayacGenel < e_HataKontrol_Hata_SonEleman; _LedKontrol.SayacGenel++) if (HataKontrol_HataDevamEdiyorMu(_LedKontrol.SayacGenel)) break;

				if (_LedKontrol.SayacGenel == e_HataKontrol_Hata_SonEleman) Gorev->CalistirilacakAdim = e_LedKontrol_Islem_HerseyYolunda_0;
				else Gorev->CalistirilacakAdim = e_LedKontrol_Islem_HataVar_0;
			}
			goto YenidenCalistir;

		//////////////////////////////////////////////////////////////////////////////////
		//Anlik Bildirim//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////
		case (e_LedKontrol_Islem_AnlikBildirim_0):
			_LedKontrol.SayacGenel = _LedKontrol_AnlikBildirim_Adet;
			_LedKontrol.AnlikBildirim_Isteniyor = false;
			Gorev->CalistirilacakAdim++;

		case (e_LedKontrol_Islem_AnlikBildirim_1):
			if (--_LedKontrol.SayacGenel == 0)
			{
				Gorev->CalistirilacakAdim = e_LedKontrol_Islem_Bosta;
				goto YenidenCalistir;
			}

			_LedKontrol_LediYak();
			Gorev->CalistirilacakAdim++;
			Gorev_Islem_CikVeTekrarCalistir(_LedKontrol_AnlikBildirim_Bekleme);

		case (e_LedKontrol_Islem_AnlikBildirim_2):
			_LedKontrol_LediSondur();
			Gorev->CalistirilacakAdim--;
			Gorev_Islem_CikVeTekrarCalistir(_LedKontrol_AnlikBildirim_Bekleme);

		//////////////////////////////////////////////////////////////////////////////////
		//Hersey Yolunda//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////
		case (e_LedKontrol_Islem_HerseyYolunda_0):
			_LedKontrol_LediYak();
			Gorev->CalistirilacakAdim++;
			Gorev_Islem_CikVeTekrarCalistir(_LedKontrol_HerseyYolunda_Bekleme_Uzun);

		case (e_LedKontrol_Islem_HerseyYolunda_1):
			_LedKontrol_LediSondur();
			Gorev->CalistirilacakAdim++;
			Gorev_Islem_CikVeTekrarCalistir(_LedKontrol_HerseyYolunda_Bekleme_Kisa);

		case (e_LedKontrol_Islem_HerseyYolunda_2):
			_LedKontrol_LediYak();
			Gorev->CalistirilacakAdim = e_LedKontrol_Islem_Bosta;
			Gorev_Islem_CikVeTekrarCalistir(_LedKontrol_HerseyYolunda_Bekleme_Uzun);

		//////////////////////////////////////////////////////////////////////////////////
		//Hata Var////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////
		case (e_LedKontrol_Islem_HataVar_0):
			_LedKontrol.SayacGenel++;
			Gorev->CalistirilacakAdim++;
			Gorev_Islem_CikVeTekrarCalistir(_LedKontrol_HataVar_Bekleme_Uzun);

		case (e_LedKontrol_Islem_HataVar_1):
			if (_LedKontrol.SayacGenel-- == 0)
			{
				Gorev->CalistirilacakAdim = e_LedKontrol_Islem_HataVar_3;
				goto YenidenCalistir;
			}

			_LedKontrol_LediYak();
			Gorev->CalistirilacakAdim++;
			Gorev_Islem_CikVeTekrarCalistir(_LedKontrol_HataVar_Bekleme_Kisa);

		case (e_LedKontrol_Islem_HataVar_2):
			_LedKontrol_LediSondur();
			Gorev->CalistirilacakAdim--;
			Gorev_Islem_CikVeTekrarCalistir(_LedKontrol_HataVar_Bekleme_Kisa);

		case (e_LedKontrol_Islem_HataVar_3):
			Gorev->CalistirilacakAdim = e_LedKontrol_Islem_Bosta;
			Gorev_Islem_CikVeTekrarCalistir(_LedKontrol_HataVar_Bekleme_Uzun);
	}

	Gorev->CalistirilacakAdim = e_LedKontrol_Islem_Bosta;
	Gorev_Islem_CikVeTekrarCalistir(_LedKontrol_HataVar_Bekleme_Uzun); //Buraya ulasmamasi gerekiyor
}
