// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.2

#ifndef __HazirKod_C_Liste_H__
#define __HazirKod_C_Liste_H__

	#include "HazirKod_C_Ayarlar.h"

	#ifdef HazirKod_C_Kullan_Liste

		#include "YerTahsisati.h"

		////////////////////////////////////////////////////////////////////////////////
		//Ic Kullanim
		////////////////////////////////////////////////////////////////////////////////
		typedef struct
		{
			uint32_t ElemanSayisi;

			struct _s_Liste_Elemani_
			{
				Tip_Isaretci Isaretci;
				struct _s_Liste_Elemani_ * SonrakiListeElemani;
			} * IlkEleman, * SonEleman;
		} _Tip_s_Liste;

		#define _Liste_(s_Liste)										((_Tip_s_Liste *)s_Liste)
		////////////////////////////////////////////////////////////////////////////////
		//Genel Goruse Acik Tanimlamalar
		////////////////////////////////////////////////////////////////////////////////
		typedef Tip_Isaretci Tip_Isaretci_Liste;
		typedef Tip_Isaretci Tip_Isaretci_Liste_Kuyruk;

		Tip_Isaretci_Liste Liste_Yeni();
		Tip_void Liste_Sil(Tip_Isaretci_Liste Liste, Tip_bool ElemanlaridaSil);
		#define Liste_Sill(s_Liste, ElemanlaridaSil) 					{ Liste_Sil(s_Liste, ElemanlaridaSil); s_Liste = Tip_null; }

		#define Liste_Eleman_Sayisi(s_Liste)							( s_Liste == NULL ? 0 : _Liste_(s_Liste)->ElemanSayisi )
		Tip_bool Liste_Eleman_Ekle(Tip_Isaretci_Liste Liste, Tip_Isaretci EklenecekEleman);
		Tip_Isaretci Liste_Eleman_Ekle_VeYerTahsisEt(Tip_Isaretci_Liste Liste, Tip_u32 Adet, Tip_bool Sifirla);
		Tip_bool Liste_Eleman_Sil(Tip_Isaretci_Liste Liste, Tip_Isaretci SilinecekEleman, Tip_bool TahsisEdilenAlanidaSil);
		#define Liste_Eleman_Sill(s_Liste, SilinecekEleman, TahsisEdilenAlanidaSil) { Liste_Eleman_Sil(s_Liste, SilinecekEleman, TahsisEdilenAlanidaSil); SilinecekEleman = Tip_null; }

		Tip_Isaretci _Liste_Kuyruk_SonrakiEleman(Tip_Isaretci_Liste Liste, Tip_Isaretci_Liste_Kuyruk * KuyrukDegiskeni);
		#define Liste_Kuyruk_DegiskeniniOlustur(s_Liste, Degisken)		Tip_Isaretci_Liste_Kuyruk Degisken = _Liste_(s_Liste)->IlkEleman
		#define Liste_Kuyruk_SonrakiEleman(s_Liste, KuyrukDegiskeni)	_Liste_Kuyruk_SonrakiEleman(s_Liste, &KuyrukDegiskeni)

		#define Liste_Eleman_Ilk(s_Liste)								(_Liste_(s_Liste)->IlkEleman->Isaretci)
		#define Liste_Eleman_Son(s_Liste)								(_Liste_(s_Liste)->SonEleman->Isaretci)

	#endif

#endif /*__HazirKod_C_Liste_H__ */
