// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.4

#include "YerTahsisati.h"

#ifdef HazirKod_C_Kullan_YerTahsisati

	#define _Gunluk_Baslik "YerTahsisati"
	#include "Gunluk.h"

	Tip_Isaretci YT_Yeni(Tip_u32 Adet, Tip_bool Sifirla)
	{
		Tip_Isaretci Uretilen = _YT_Islem_malloc_(Adet);

	#ifdef _YT_Tahsis_Edilen_Alani_Kontrol_Et
			if ( ( (Tip_Isaretci_SayiKarsiligi)Uretilen >= (Tip_Isaretci_SayiKarsiligi)_YT_Ram_Baslangic ) && ( ((Tip_Isaretci_SayiKarsiligi)Uretilen + Adet) <= (Tip_Isaretci_SayiKarsiligi)_YT_Ram_Bitis ) )
		{
	#endif

				HazirKod_C_Gunluk("+++ %p - %p - %d adet", Uretilen, Uretilen + Adet, Adet);

				if (Sifirla && Uretilen != Tip_null) _Islem_memset_(Uretilen, 0, Adet);

				return Uretilen;

	#ifdef _YT_Tahsis_Edilen_Alani_Kontrol_Et
		}
		else
		{
				_YT_Islem_free_(Uretilen);

				HazirKod_C_Gunluk("Beklenmeyen Durum YT_Yeni %p - %p - %d adet", Uretilen, Uretilen + Adet, Adet);
			return Tip_null;
		}
	#endif
	}
	Tip_void YT_Sil(Tip_Isaretci Isaretci)
	{
		if (Isaretci == Tip_null) return;

		_YT_Islem_free_(Isaretci);
		HazirKod_C_Gunluk("--- %p", Isaretci);
	}

#endif
