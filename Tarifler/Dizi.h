// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.0

#ifndef __HazirKod_C_Dizi_H__
#define __HazirKod_C_Dizi_H__

	#include "HazirKod_C_Ayarlar.h"

	#ifdef HazirKod_C_Kullan_Dizi

		#include "YerTahsisati.h"

		////////////////////////////////////////////////////////////////////////////////
		//Ic Kullanim
		////////////////////////////////////////////////////////////////////////////////
		typedef struct
		{
			Tip_Isaretci Isaretci;
			Tip_u32 ElemanSayisi;
		} _Tip_s_Dizi;

		#define _Dizi_(s_Dizi)						((_Tip_s_Dizi *)s_Dizi)
		#define _Dizi_Icerigi_Sayi(s_Dizi, Konum) 	Isaretci_Icerigi( _Dizi_(s_Dizi)->Isaretci, ( Konum ), Tip_Isaretci_SayiKarsiligi,  Tip_Isaretci_SayiKarsiligi )

		////////////////////////////////////////////////////////////////////////////////
		//Genel Goruse Acik Tanimlamalar
		////////////////////////////////////////////////////////////////////////////////
		typedef Tip_Isaretci Tip_Isaretci_Dizi;

		#define Dizi_Yeni() 						YT_Yeni(sizeof(_Tip_s_Dizi), true)
		Tip_void Dizi_Sil(Tip_Isaretci_Dizi Dizi, Tip_bool ElemanlaridaSil);

		Tip_u32 Dizi_Eleman_Sayisi(Tip_Isaretci_Dizi Dizi);
		Tip_bool Dizi_Eleman_Ekle(Tip_Isaretci_Dizi Dizi, Tip_Isaretci EklenecekEleman);
		Tip_Isaretci Dizi_Eleman_Ekle_VeYerTahsisEt(Tip_Isaretci_Dizi Dizi, Tip_u32 Adet, Tip_bool Sifirla);
		Tip_bool Dizi_Eleman_Sil(Tip_Isaretci_Dizi Dizi, Tip_u32 Konumu, Tip_bool TahsisEdilenAlanidaSil);

		#define Dizi_Elemani(s_Dizi, Konum) 		( (Tip_Isaretci)_Dizi_Icerigi_Sayi(s_Dizi, Konum) )

	#endif

#endif /*__HazirKod_C_Dizi_H__ */
