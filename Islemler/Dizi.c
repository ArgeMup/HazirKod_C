// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.0

#include "Dizi.h"

#ifdef HazirKod_C_Kullan_Dizi

	#define _Gunluk_Baslik "Dizi"
	#include "Gunluk.h"

	Tip_bool _Dizi_Tampon_Yenile(Tip_Isaretci_Dizi Dizi, Tip_u32 YeniElemanSayisi)
	{
		if (YeniElemanSayisi > 0)
		{
			Tip_Isaretci Isaretci  = YT_Yeni(Isaretci_KapladigiAlan_Bayt * YeniElemanSayisi, false);
			if (Isaretci == Tip_null) return false;

			if (_Dizi_(Dizi)->Isaretci != Tip_null)
			{
				_Islem_memcpy_(Isaretci, _Dizi_(Dizi)->Isaretci, EnKucuk(_Dizi_(Dizi)->ElemanSayisi, YeniElemanSayisi) * Isaretci_KapladigiAlan_Bayt);
				YT_Sil(_Dizi_(Dizi)->Isaretci);
			}

			_Dizi_(Dizi)->Isaretci = Isaretci;
		}
		else
		{
			YT_Sil(_Dizi_(Dizi)->Isaretci);
			_Dizi_(Dizi)->Isaretci = Tip_null;
		}

		_Dizi_(Dizi)->ElemanSayisi = YeniElemanSayisi;

		return true;
	}

	Tip_void Dizi_Sil(Tip_Isaretci_Dizi Dizi, Tip_bool ElemanlaridaSil)
	{
		if (Dizi == Tip_null) return;

		if (ElemanlaridaSil)
		{
			for(Tip_u32 i = 0; i < _Dizi_(Dizi)->ElemanSayisi; i++)
			{
				YT_Sil(Dizi_Elemani(Dizi, i));
			}
		}

		YT_Sil(_Dizi_(Dizi)->Isaretci);
		YT_Sil(Dizi);
	}
	
	Tip_u32 Dizi_Eleman_Sayisi(Tip_Isaretci_Dizi Dizi)
	{
		if (Dizi == Tip_null) return 0;

		return _Dizi_(Dizi)->ElemanSayisi;
	}
	Tip_bool Dizi_Eleman_Ekle(Tip_Isaretci_Dizi Dizi, Tip_Isaretci EklenecekEleman)
	{
		if (Dizi == Tip_null || EklenecekEleman == Tip_null) return false;

		if (!_Dizi_Tampon_Yenile(Dizi, _Dizi_(Dizi)->ElemanSayisi + 1)) return false;

		_Dizi_Icerigi_Sayi(Dizi, _Dizi_(Dizi)->ElemanSayisi - 1)	= (Tip_Isaretci_SayiKarsiligi)EklenecekEleman;

		return true;
	}
	Tip_Isaretci Dizi_Eleman_Ekle_VeYerTahsisEt(Tip_Isaretci_Dizi Dizi, Tip_u32 Adet, Tip_bool Sifirla)
	{
		if (Dizi == Tip_null || Adet == 0) return Tip_null;

		Tip_Isaretci YeniTahsisEdilenAlan = YT_Yeni(Adet, Sifirla);
		if (YeniTahsisEdilenAlan == Tip_null) return Tip_null;

		if (!Dizi_Eleman_Ekle(Dizi, YeniTahsisEdilenAlan))
		{
			YT_Sil(YeniTahsisEdilenAlan);
			return Tip_null;
		}

		return YeniTahsisEdilenAlan;
	}
	Tip_bool Dizi_Eleman_Sil(Tip_Isaretci_Dizi Dizi, Tip_u32 Konumu, Tip_bool TahsisEdilenAlanidaSil)
	{
		if (Dizi == Tip_null || Konumu >= _Dizi_(Dizi)->ElemanSayisi ) return false;

		if (TahsisEdilenAlanidaSil) YT_Sil(Dizi_Elemani(Dizi, Konumu));

		if (Konumu != ( _Dizi_(Dizi)->ElemanSayisi - 1 ) )
		{
			_Islem_memcpy_(Isaretci_Konumlandir(_Dizi_(Dizi)->Isaretci, Konumu, Tip_Isaretci_SayiKarsiligi, Tip_void), Isaretci_Konumlandir(_Dizi_(Dizi)->Isaretci, Konumu + 1, Tip_Isaretci_SayiKarsiligi, Tip_void), ( _Dizi_(Dizi)->ElemanSayisi - Konumu - 1 ) * Isaretci_KapladigiAlan_Bayt);
		}

		return _Dizi_Tampon_Yenile(Dizi, _Dizi_(Dizi)->ElemanSayisi - 1);
	}

#endif
