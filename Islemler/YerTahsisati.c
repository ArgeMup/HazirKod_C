// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.1

//////////////////////////////////////////////////////////////////////////////
#define _Gunluk_Baslik "Gunluk"		//Kaynak kod içinde tanimlanmali
#include "Gunluk.h"					//Kaynak kod içinde tanimlanmali
//////////////////////////////////////////////////////////////////////////////
#include "YerTahsisati.h"

Tip_Isaretci YT_Yeni(Tip_u32 Adet)
{
	Tip_u32 Uretilen = (Tip_u32)_YT_Islem_malloc_(Adet);

	if (Uretilen >= _YT_Ram_Baslangic && (Uretilen + Adet) <= _YT_Ram_Bitis)
	{
		HazirKod_C_Gunluk("+++ 0x%X - 0x%X - Adet : %d", Uretilen, Uretilen + Adet, Adet);
		return (Tip_Isaretci)Uretilen;
	}
	else
	{
		_YT_Islem_free_((Tip_Isaretci)Uretilen);
		HataKontrol_Hatali(e_HataKontrol_Hata_YerTahsisati);

		HazirKod_C_Gunluk("!!! 0x%X - 0x%X - Adet : %d", Uretilen, Uretilen + Adet, Adet);
		return Tip_null;
	}
}
Tip_void YT_Sil(Tip_Isaretci Isaretci)
{
	_YT_Islem_free_(Isaretci);
	HazirKod_C_Gunluk("--- 0x%X", Isaretci);
}
