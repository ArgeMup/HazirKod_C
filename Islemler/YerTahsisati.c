// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.2

#include "YerTahsisati.h"

//////////////////////////////////////////////////////////////////////////////
#define _Gunluk_Baslik "YerTahsisati"		//Kaynak kod i�inde tanimlanmali
#include "Gunluk.h"					//Kaynak kod i�inde tanimlanmali
//////////////////////////////////////////////////////////////////////////////

Tip_Isaretci YT_Yeni(Tip_u32 Adet)
{
	Tip_u32 Uretilen = (Tip_u32)_YT_Islem_malloc_(Adet);

#ifdef _YT_Tahsis_Edilen_Alani_Kontrol_Et
	if (Uretilen >= _YT_Ram_Baslangic && (Uretilen + Adet) <= _YT_Ram_Bitis)
	{
#endif

		HazirKod_C_Gunluk("+++ 0x%X - 0x%X - Adet : %d", Uretilen, Uretilen + Adet, Adet);
		return (Tip_Isaretci)Uretilen;

#ifdef _YT_Tahsis_Edilen_Alani_Kontrol_Et
	}
	else
	{
		_YT_Islem_free_((Tip_Isaretci)Uretilen);
		HataKontrol_Hatali(e_HataKontrol_Hata_YerTahsisati);

		HazirKod_C_Gunluk("!!! 0x%X - 0x%X - Adet : %d", Uretilen, Uretilen + Adet, Adet);
		return Tip_null;
	}
#endif
}
Tip_void YT_Sil(Tip_Isaretci Isaretci)
{
	_YT_Islem_free_(Isaretci);
	HazirKod_C_Gunluk("--- 0x%X", Isaretci);
}
