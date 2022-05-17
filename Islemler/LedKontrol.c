// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.4

#include "LedKontrol.h"

#ifdef HazirKod_C_Kullan_LedKontrol

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
		Tip_bool GorevinDurdurulmasi_Isteniyor;
		Tip_bool AnlikBildirim_Isteniyor;
		Tip_u8 SayacGenel;
	}_LedKontrol = { 0 };

	Tip_void LedKontrol_GoreviDurdur()
	{
		_LedKontrol.GorevinDurdurulmasi_Isteniyor = true;
	}
	Tip_void LedKontrol_AnlikBildirim()
	{
		_LedKontrol.AnlikBildirim_Isteniyor = true;
	}

	Tip_i32 LedKontrol_Gorev(Tip_Isaretci_Gorev_Detaylar Detaylar)
	{
		if (_LedKontrol.GorevinDurdurulmasi_Isteniyor) Gorev_Islem_CikVeSil();

		YenidenCalistir:
		switch (Detaylar->CalistirilacakAdim)
		{
			default:
			case (e_LedKontrol_Islem_IlkCalistirma):
				LedKontrol_AnlikBildirim();
				goto LedKontrol_Gorev_e_LedKontrol_Islem_Bosta;

			case (e_LedKontrol_Islem_Bosta):
			LedKontrol_Gorev_e_LedKontrol_Islem_Bosta:
				if (_LedKontrol.AnlikBildirim_Isteniyor) Detaylar->CalistirilacakAdim = e_LedKontrol_Islem_AnlikBildirim_0;
				else
				{
					_LedKontrol.SayacGenel = 0;
					for (; _LedKontrol.SayacGenel < _LedKontrol_GosterilebilecekHataSayisi; _LedKontrol.SayacGenel++) if (HataDurumu_HataDevamEdiyorMu(_LedKontrol_HataDurumuDegiskeni, _LedKontrol.SayacGenel)) break;

					if (_LedKontrol.SayacGenel == _LedKontrol_GosterilebilecekHataSayisi) Detaylar->CalistirilacakAdim = e_LedKontrol_Islem_HerseyYolunda_0;
					else Detaylar->CalistirilacakAdim = e_LedKontrol_Islem_HataVar_0;
				}
				goto YenidenCalistir;

			//////////////////////////////////////////////////////////////////////////////////
			//Anlik Bildirim//////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////////
			case (e_LedKontrol_Islem_AnlikBildirim_0):
				_LedKontrol.SayacGenel = _LedKontrol_AnlikBildirim_Adet;
				_LedKontrol.AnlikBildirim_Isteniyor = false;
				Detaylar->CalistirilacakAdim++;
				goto LedKontrol_Gorev_e_LedKontrol_Islem_AnlikBildirim_1;

			case (e_LedKontrol_Islem_AnlikBildirim_1):
			LedKontrol_Gorev_e_LedKontrol_Islem_AnlikBildirim_1:
				if (--_LedKontrol.SayacGenel == 0)
				{
					Detaylar->CalistirilacakAdim = e_LedKontrol_Islem_Bosta;
					goto YenidenCalistir;
				}

				_LedKontrol_LediYak();
				Detaylar->CalistirilacakAdim++;
				Gorev_Islem_CikVeTekrarCalistir(_LedKontrol_AnlikBildirim_Bekleme);

			case (e_LedKontrol_Islem_AnlikBildirim_2):
				_LedKontrol_LediSondur();
				Detaylar->CalistirilacakAdim--;
				Gorev_Islem_CikVeTekrarCalistir(_LedKontrol_AnlikBildirim_Bekleme);

			//////////////////////////////////////////////////////////////////////////////////
			//Hersey Yolunda//////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////////
			case (e_LedKontrol_Islem_HerseyYolunda_0):
				_LedKontrol_LediYak();
				Detaylar->CalistirilacakAdim++;
				Gorev_Islem_CikVeTekrarCalistir(_LedKontrol_HerseyYolunda_Bekleme_Uzun);

			case (e_LedKontrol_Islem_HerseyYolunda_1):
				_LedKontrol_LediSondur();
				Detaylar->CalistirilacakAdim++;
				Gorev_Islem_CikVeTekrarCalistir(_LedKontrol_HerseyYolunda_Bekleme_Kisa);

			case (e_LedKontrol_Islem_HerseyYolunda_2):
				_LedKontrol_LediYak();
				Detaylar->CalistirilacakAdim = e_LedKontrol_Islem_Bosta;
				Gorev_Islem_CikVeTekrarCalistir(_LedKontrol_HerseyYolunda_Bekleme_Uzun);

			//////////////////////////////////////////////////////////////////////////////////
			//Hata Var////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////////
			case (e_LedKontrol_Islem_HataVar_0):
				_LedKontrol.SayacGenel++;
				Detaylar->CalistirilacakAdim++;
				Gorev_Islem_CikVeTekrarCalistir(_LedKontrol_HataVar_Bekleme_Uzun);

			case (e_LedKontrol_Islem_HataVar_1):
				if (_LedKontrol.SayacGenel-- == 0)
				{
					Detaylar->CalistirilacakAdim = e_LedKontrol_Islem_HataVar_3;
					goto YenidenCalistir;
				}

				_LedKontrol_LediYak();
				Detaylar->CalistirilacakAdim++;
				Gorev_Islem_CikVeTekrarCalistir(_LedKontrol_HataVar_Bekleme_Kisa);

			case (e_LedKontrol_Islem_HataVar_2):
				_LedKontrol_LediSondur();
				Detaylar->CalistirilacakAdim--;
				Gorev_Islem_CikVeTekrarCalistir(_LedKontrol_HataVar_Bekleme_Kisa);

			case (e_LedKontrol_Islem_HataVar_3):
				Detaylar->CalistirilacakAdim = e_LedKontrol_Islem_Bosta;
				Gorev_Islem_CikVeTekrarCalistir(_LedKontrol_HataVar_Bekleme_Uzun);
		}

		Detaylar->CalistirilacakAdim = e_LedKontrol_Islem_Bosta;
		Gorev_Islem_CikVeTekrarCalistir(_LedKontrol_HataVar_Bekleme_Uzun); //Buraya ulasmamasi gerekiyor
	}

#endif
