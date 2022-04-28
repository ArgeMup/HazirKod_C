// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.8

#ifndef __HazirKod_C_Gorev_H__
#define __HazirKod_C_Gorev_H__

	#include "HazirKod_C_Ayarlar.h"

	#ifdef HazirKod_C_Kullan_Gorev

		#include "Zamanlama.h"
		#include "Dizi.h"

		////////////////////////////////////////////////////////////////////////////////
		//Ic Kullanim
		////////////////////////////////////////////////////////////////////////////////
		#ifdef _Gorev_Sablon_KullaniciNesnesi
			#define _Gorev_Sablon_KullaniciNesnesi_Islem		,Tip_Isaretci KullaniciNesnesi
		#else
			#define _Gorev_Sablon_KullaniciNesnesi_Islem
		#endif

		////////////////////////////////////////////////////////////////////////////////
		//Genel Goruse Acik Tanimlamalar
		////////////////////////////////////////////////////////////////////////////////
		typedef struct
		{
			Tip_Sure An;
			_Tip_Gorev_CalistirilacakAdim CalistirilacakAdim;

			#ifdef _Gorev_Sablon_KullaniciNesnesi
				Tip_Isaretci KullaniciNesnesi;
			#endif
		} _Tip_s_Gorev_Detaylar;

		typedef Tip_Isaretci Tip_Isaretci_Gorev;
		typedef _Tip_s_Gorev_Detaylar * Tip_Isaretci_Gorev_Detaylar;
		typedef Tip_i32 (*Tip_Islem_Gorev) (Tip_Isaretci_Gorev_Detaylar);

		#define Gorev_Yeni()							Dizi_Yeni()
		#define Gorev_Sil(s_Gorev)						Dizi_Sil(s_Gorev, true)
		Tip_u32 Gorev_Calistir(Tip_Isaretci_Gorev Gorev);

		Tip_bool Gorev_Islem_Ekle(Tip_Isaretci_Gorev Gorev, Tip_Islem_Gorev Islem _Gorev_Sablon_KullaniciNesnesi_Islem);
		Tip_bool Gorev_Islem_MevcutMu(Tip_Isaretci_Gorev Gorev, Tip_Islem_Gorev Islem);
		Tip_void Gorev_Islem_HemenCalistir(Tip_Isaretci_Gorev Gorev, Tip_Islem_Gorev Islem _Gorev_Sablon_KullaniciNesnesi_Islem, Tip_u32 Gecikme_msn);

		#define Gorev_Islem_CikVeSil()					return -1
		#define Gorev_Islem_CikVeTekrarCalistir(msn)	return msn

	#endif

#endif /* __HazirKod_C_Gorev_H__ */
