// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.0

#include "YerTahsisati.h"

Tip_Isaretci YT_Yeni(Tip_u32 Adet)
{
	Tip_u32 Uretilen = (Tip_u32)_Islem_malloc_(Adet);
	printf("+++%X", Uretilen);

	if (Uretilen >= _YT_Ram_Baslangic && (Uretilen + Adet) <= _YT_Ram_Bitis) return (Tip_Isaretci)Uretilen;
	else
	{
		_Islem_free_((Tip_Isaretci)Uretilen);
		HataKontrol_Hatali(e_HataKontrol_Hata_YerTahsisati);
		return Tip_null;
	}
}
Tip_void YT_Sil(Tip_Isaretci Isaretci)
{
	_Islem_free_(Isaretci);
	printf("---%X", (Tip_u32)Isaretci);
}
