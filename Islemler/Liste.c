// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.1

#include "Liste.h"

#ifdef HazirKod_C_Kullan_Liste

	Tip_Isaretci_Liste Liste_Yeni()
	{
		struct _s_Liste_ * Liste = YT_Yeni(sizeof(struct _s_Liste_));
		if (Liste == Tip_null) return Tip_null;

		_Islem_memset_(Liste, 0, sizeof(struct _s_Liste_));
		return Liste;
	}
	Tip_void Liste_Sil(Tip_Isaretci_Liste Liste, Tip_bool ElemanlaridaSil)
	{
		if (Liste == Tip_null) return;

		Liste_Kuyruk_DegiskeniniOlustur(Liste, KuyrukDegiskeni);
		while(KuyrukDegiskeni != NULL)
		{
			Tip_Isaretci Eleman = Liste_Kuyruk_SonrakiEleman(Liste, KuyrukDegiskeni);
			Liste_Eleman_Sil(Liste, Eleman, ElemanlaridaSil);
		}

		YT_Sil(Liste);
	}
	
	Tip_u32 Liste_Eleman_Sayisi(Tip_Isaretci_Liste Liste)
	{
		if (Liste == Tip_null) return 0;

		return _Liste_ElemanSayisi(Liste);
	}
	Tip_bool Liste_Eleman_Ekle(Tip_Isaretci_Liste Liste, Tip_Isaretci EklenecekEleman)
	{
		if (Liste == Tip_null || EklenecekEleman == Tip_null) return false;

		struct _s_Liste_Elemani_ * Eleman = YT_Yeni(sizeof(struct _s_Liste_Elemani_));
		if (Eleman == Tip_null) return false;

		Eleman->Isaretci = EklenecekEleman;
		Eleman->SonrakiListeElemani = Tip_null;

		if (_Liste_SonEleman(Liste) == Tip_null) _Liste_IlkEleman(Liste) = Eleman;
		else _Liste_SonEleman(Liste)->SonrakiListeElemani = Eleman;
	
		_Liste_SonEleman(Liste) = Eleman;
		_Liste_ElemanSayisi(Liste)++;
	
		return true;
	}
	Tip_Isaretci Liste_Eleman_Ekle_VeYerTahsisEt(Tip_Isaretci_Liste Liste, Tip_u32 Adet)
	{
		if (Liste == Tip_null || Adet == 0) return Tip_null;

		Tip_Isaretci YeniTahsisEdilenAlan = YT_Yeni(Adet);
		if (YeniTahsisEdilenAlan == Tip_null) return Tip_null;

		if (!Liste_Eleman_Ekle(Liste, YeniTahsisEdilenAlan))
		{
			YT_Sil(YeniTahsisEdilenAlan);
			return Tip_null;
		}

		return YeniTahsisEdilenAlan;
	}
	Tip_void Liste_Eleman_Sil(Tip_Isaretci_Liste Liste, Tip_Isaretci SilinecekEleman, Tip_bool TahsisEdilenAlanidaSil)
	{
		if (Liste == Tip_null || SilinecekEleman == Tip_null) return;
		
		struct _s_Liste_Elemani_ * Onceki = Tip_null;
		struct _s_Liste_Elemani_ * Simdiki = _Liste_IlkEleman(Liste);

		while (Simdiki != Tip_null)
		{
			if (Simdiki->Isaretci == SilinecekEleman)
			{
				if (Onceki == Tip_null) _Liste_IlkEleman(Liste) = Simdiki->SonrakiListeElemani;
				else Onceki->SonrakiListeElemani = Simdiki->SonrakiListeElemani;

				if (Simdiki == _Liste_SonEleman(Liste)) _Liste_SonEleman(Liste) = Onceki;

				if (TahsisEdilenAlanidaSil) YT_Sil(Simdiki->Isaretci);
				YT_Sil(Simdiki);

				_Liste_ElemanSayisi(Liste)--;
				return;
			}

			Onceki = Simdiki;
			Simdiki = Simdiki->SonrakiListeElemani;
		}
	}

	Tip_Isaretci _Liste_Kuyruk_SonrakiEleman(Tip_Isaretci_Liste Liste, Tip_Isaretci_Liste_Kuyruk * KuyrukDegiskeni)
	{
		if (Liste == Tip_null || KuyrukDegiskeni == Tip_null) return Tip_null;

		Tip_Isaretci Cikti = ((struct _s_Liste_Elemani_ *)(*KuyrukDegiskeni))->Isaretci;
		*KuyrukDegiskeni = ((struct _s_Liste_Elemani_ *)(*KuyrukDegiskeni))->SonrakiListeElemani;

		return Cikti;
	}

#endif
