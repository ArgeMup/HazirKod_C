// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.1

#include "Gorev.h"

//ZamanAsimi_msn  < 0 Gorevi sil
//ZamanAsimi_msn == 0 Gorevi hemen calisacak sekilde kur
//ZamanAsimi_msn  > 0 Gorevi msn sonra calistir

struct _s_Gorev_
{
	struct s_Gorev_Detaylar_ Detaylar;
	Tip_Islem_Gorev Islem;
	enum e_Gorev_Bitler_
	{
		e_Gorev_Bitler_HemenCalistir
	}Bitler;
};

Tip_bool Gorev_Islem_Ekle(Tip_Isaretci_Gorev Gorev, Tip_Islem_Gorev Islem, Tip_Isaretci KullaniciNesnesi)
{
	if (Gorev == Tip_null || Islem == Tip_null) return false;

	struct _s_Gorev_ * Yeni = Liste_Eleman_Ekle_VeYerTahsisEt(Gorev, sizeof(struct _s_Gorev_));
	if (Yeni == Tip_null) return false;

	_Islem_memset_(Yeni, 0, sizeof(struct _s_Gorev_));
	Yeni->Islem = Islem;
	Yeni->Detaylar.KullaniciNesnesi = KullaniciNesnesi;

	return true;
}
Tip_bool Gorev_Islem_MevcutMu(Tip_Isaretci_Gorev Gorev, Tip_Islem_Gorev Islem)
{
	if (Gorev == Tip_null || Islem == Tip_null) return false;

	Liste_Kuyruk_DegiskeniniOlustur(Gorev, KuyrukDegiskeni);
	while(KuyrukDegiskeni != NULL)
	{
		struct _s_Gorev_ * Eleman = Liste_Kuyruk_SonrakiEleman(Gorev, KuyrukDegiskeni);
		if (Eleman->Islem == Islem) return true;
	}

	return false;
}
Tip_void Gorev_Islem_HemenCalistir(Tip_Isaretci_Gorev Gorev, Tip_Islem_Gorev Islem)
{
	if (Gorev == Tip_null || Islem == Tip_null) return;

	Liste_Kuyruk_DegiskeniniOlustur(Gorev, KuyrukDegiskeni);
	while(KuyrukDegiskeni != NULL)
	{
		struct _s_Gorev_ * Eleman = Liste_Kuyruk_SonrakiEleman(Gorev, KuyrukDegiskeni);
		if (Eleman->Islem == Islem)
		{
			Bit_Yaz_1(Eleman->Bitler, e_Gorev_Bitler_HemenCalistir);
			return;
		}
	}
}
Tip_void Gorev_Calistir(Tip_Isaretci_Gorev Gorev)
{
	if (Gorev == Tip_null) return;

	Liste_Kuyruk_DegiskeniniOlustur(Gorev, KuyrukDegiskeni);
	while(KuyrukDegiskeni != NULL)
	{
		struct _s_Gorev_ * Eleman = Liste_Kuyruk_SonrakiEleman(Gorev, KuyrukDegiskeni);

		if (Sure_DolduMu(Eleman->Detaylar.An) ||
			Bit_Oku(Eleman->Bitler, e_Gorev_Bitler_HemenCalistir) )
		{
			Bit_Yaz_0(Eleman->Bitler, e_Gorev_Bitler_HemenCalistir);

			Tip_i32 ZamanAsimi_msn = Eleman->Islem(&Eleman->Detaylar);

			if (ZamanAsimi_msn < 0) Liste_Eleman_Sil(Gorev, Eleman, true);	//Sil
			else Sure_MiliSaniye(Eleman->Detaylar.An, ZamanAsimi_msn);		//Kur
		}
	}
}
