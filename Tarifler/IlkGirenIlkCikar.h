// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.0

#ifndef __HazirKod_C_IlkGirenIlkCikar_H__
#define __HazirKod_C_IlkGirenIlkCikar_H__

	#include "HazirKod_C_Ayarlar.h"

	#ifdef HazirKod_C_Kullan_IlkGirenIlkCikar

		#include "YerTahsisati.h"

		////////////////////////////////////////////////////////////////////////////////
		//Ic Kullanim
		////////////////////////////////////////////////////////////////////////////////
		#ifdef _IGIC_Sablon_KullaniciNesnesi
			#define _IGIC_Sablon_KullaniciNesnesi_Islem		,Tip_Isaretci KullaniciNesnesi
		#else
			#define _IGIC_Sablon_KullaniciNesnesi_Islem
		#endif

		////////////////////////////////////////////////////////////////////////////////
		//Genel Goruse Acik Tanimlamalar
		////////////////////////////////////////////////////////////////////////////////
		typedef Tip_bool (*Tip_Islem_IGIC_Siliniyor) (Tip_Isaretci, Tip_u32);

		typedef struct
		{
			Tip_Isaretci Tampon;
			Tip_u32 Kapasite;
			Tip_u32 DoluAlan;

			enum e_IGIC_YerKalmazsa_
			{
				e_IGIC_YerKalmazsa_EnEskiyiSil,
				e_IGIC_YerKalmazsa_TalebiReddet
			} YerKalmazsa;
			Tip_Islem_IGIC_Siliniyor Islem_Siliniyor;

			Tip_u32 Konum_Ekleme;
			Tip_u32 Konum_Okuma;

			#ifdef _IGIC_Sablon_KullaniciNesnesi
				Tip_Isaretci KullaniciNesnesi;
			#endif

		} _Tip_s_IGIC, *Tip_Isaretci_IGIC;
		#define _IGIC_(s_IGIC)				((_Tip_s_IGIC *)s_IGIC)

		#define IGIC_Kapasite(s_IGIC)		(_IGIC_(s_IGIC)->Kapasite)
		#define IGIC_DoluAlan(s_IGIC)		(_IGIC_(s_IGIC)->DoluAlan)
		#define IGIC_BosAlan(s_IGIC)		(IGIC_Kapasite(s_IGIC) - IGIC_DoluAlan(s_IGIC))
		#define IGIC_Sil(s_IGIC)			YT_Sil(s_IGIC)
		#define IGIC_Sill(s_IGIC)			YT_Sill(s_IGIC)

		Tip_Isaretci_IGIC IGIC_Yeni(Tip_u32 Kapasite, enum e_IGIC_YerKalmazsa_ YerKalmazsa, Tip_Islem_IGIC_Siliniyor Islem_Siliniyor _IGIC_Sablon_KullaniciNesnesi_Islem);
		Tip_u32 IGIC_Bilgi_Oku(Tip_Isaretci_IGIC IGIC, Tip_Isaretci YazilacakTampon, Tip_u32 TamponKapasitesi, Tip_bool VeBosYerAc);
		Tip_bool IGIC_Bilgi_Ekle(Tip_Isaretci_IGIC IGIC, Tip_Isaretci OkunacakTampon, Tip_u32 Adet);

	#endif

#endif /* __HazirKod_C_IlkGirenIlkCikar_H__ */
