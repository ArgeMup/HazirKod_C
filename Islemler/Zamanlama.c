// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.3

#include "Zamanlama.h"

#ifdef HazirKod_C_Kullan_Zamanlama

	Tip_Islem_Zamanlama_An_Okuma _Zamanlama_An_Okuma_Islemi;

	Tip_void Zamanlama_Baslat(Tip_Islem_Zamanlama_An_Okuma AniOkuma_Islemi)
	{
		_Zamanlama_An_Okuma_Islemi = AniOkuma_Islemi;
	}

	#ifdef _Zamanlama_Tasmayan_Yontemi_Kullan

		struct s_Zamanlamm_
		{
			Tip_u32 SaatinSonOkundugundakiDegeri;
			Tip_Sure GuncelDeger;
			Tip_Islem_Zamanlama_Kilit Kilit_Islemi;
		} s_Zamanlama = { 0 };

		Tip_void Zamanlama_Baslat_Kilit_Islemi(Tip_Islem_Zamanlama_Kilit Kilit_Islemi)
		{
			s_Zamanlama.Kilit_Islemi = Kilit_Islemi;
		}

		Tip_void _An_Guncelle()
		{
			if (s_Zamanlama.Kilit_Islemi != NULL) s_Zamanlama.Kilit_Islemi(true); //Diger Islemlerin Girememesi icin Kilitle

			Tip_u32 simdi = _Zamanlama_An_Okuma_Islemi();
			Tip_u32 yedek = s_Zamanlama.GuncelDeger.Dusuk;

			s_Zamanlama.GuncelDeger.Dusuk += ( simdi - s_Zamanlama.SaatinSonOkundugundakiDegeri );
			if (s_Zamanlama.GuncelDeger.Dusuk < yedek) s_Zamanlama.GuncelDeger.Yuksek++;

			s_Zamanlama.SaatinSonOkundugundakiDegeri = simdi;

			if (s_Zamanlama.Kilit_Islemi != NULL) s_Zamanlama.Kilit_Islemi(false); //Diger Islemlerin Girebilmesi icin Serbest Birak
		}

		Tip_void _Sure_Ekle(Tip_Sure * Degisken, Tip_u32 Sure)
		{
			_An_Guncelle();

			Degisken->Dusuk = s_Zamanlama.GuncelDeger.Dusuk + Sure;
			Degisken->Yuksek = s_Zamanlama.GuncelDeger.Yuksek;

			if (Degisken->Dusuk < Sure) Degisken->Yuksek++;
		}

		Tip_bool _Sure_DolduMu(Tip_Sure * Degisken)
		{
			_An_Guncelle();

			return  ( 	( Degisken->Yuksek <= s_Zamanlama.GuncelDeger.Yuksek ) &&
						( Degisken->Dusuk <= s_Zamanlama.GuncelDeger.Dusuk )        );
		}

		Tip_u32 _Sure_KalanSure_MiliSaniye(Tip_Sure * Degisken)
		{
			if (_Sure_DolduMu(Degisken)) return 0;

			switch (Degisken->Yuksek - s_Zamanlama.GuncelDeger.Yuksek)
			{
			case 0:
			case 1:
				return Degisken->Dusuk - s_Zamanlama.GuncelDeger.Dusuk;

			default:
				return (Tip_u32)0 - 1; //tasacak kadar fazla, azami degeri dondur
			}
		}

		Tip_char * Sure_Yazdir(Tip_Sure Degisken, Tip_char * Hedef, Tip_u32 HedefKapasite)
		{
			if (Hedef == NULL || HedefKapasite == 0) return NULL;

			snprintf(Hedef, HedefKapasite, _Zamanlama_Yazdirma_Sablon "-" _Zamanlama_Yazdirma_Sablon, Degisken.Yuksek, Degisken.Dusuk * _Zamanlama_An_Aralik_Msn_);

			return Hedef;
		}

	#else

		Tip_Sure _Sure_Ekle(Tip_Sure Sure)
		{
			return (_Tip_Sure_Islem)( (_Tip_Sure_Islem)_Zamanlama_An_Okuma_Islemi() + (_Tip_Sure_Islem)( Sure ) );
		}

		Tip_char * Sure_Yazdir(Tip_Sure Degisken, Tip_char * Hedef, Tip_u32 HedefKapasite)
		{
			if (Hedef == NULL || HedefKapasite == 0) return NULL;

			snprintf(Hedef, HedefKapasite, _Zamanlama_Yazdirma_Sablon, Degisken * _Zamanlama_An_Aralik_Msn_);

			return Hedef;
		}

	#endif

#endif
