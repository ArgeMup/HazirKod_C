// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.3

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
		Tip_bool AnlikBildirim_Isteniyor;
		Tip_u8 SayacGenel;
		Tip_u32 HataDurumu;
	}_LedKontrol = { 0 };

	#define _LedKontrol_SonEleman ( sizeof(Tip_u32) * 8 )

	Tip_void LedKontrol_HataDurumunuGuncelle(Tip_u32 HataDurumu)
	{
		_LedKontrol.HataDurumu = HataDurumu;
	}

	Tip_void LedKontrol_AnlikBildirim()
	{
		_LedKontrol.AnlikBildirim_Isteniyor = true;
	}

	Tip_i32 LedKontrol_Gorev(Tip_Isaretci_Gorev_Detaylar Detaylar)
	{
		YenidenCalistir:
		switch (Detaylar->CalistirilacakAdim)
		{
			default:
			case (e_LedKontrol_Islem_IlkCalistirma):
				LedKontrol_AnlikBildirim();

			case (e_LedKontrol_Islem_Bosta):
				if (_LedKontrol.AnlikBildirim_Isteniyor) Detaylar->CalistirilacakAdim = e_LedKontrol_Islem_AnlikBildirim_0;
				else
				{
					_LedKontrol.SayacGenel = 0;
					for (; _LedKontrol.SayacGenel < _LedKontrol_SonEleman; _LedKontrol.SayacGenel++) if (HataKontrol_HataDevamEdiyorMu(_LedKontrol.HataDurumu, _LedKontrol.SayacGenel)) break;

					if (_LedKontrol.SayacGenel == _LedKontrol_SonEleman) Detaylar->CalistirilacakAdim = e_LedKontrol_Islem_HerseyYolunda_0;
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

			case (e_LedKontrol_Islem_AnlikBildirim_1):
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
