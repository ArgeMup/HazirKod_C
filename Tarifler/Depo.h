// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.2

#ifndef __HazirKod_C_Depo_H__
#define __HazirKod_C_Depo_H__

	#include "HazirKod_C_Ayarlar.h"

	#ifdef HazirKod_C_Kullan_Depo

		#include "IlkGirenIlkCikar.h"

		////////////////////////////////////////////////////////////////////////////////
		//Ic Kullanim
		////////////////////////////////////////////////////////////////////////////////
		typedef struct
		{
			Tip_Isaretci_IGIC IGIC;
			Tip_u8 AyirmaBirimi_KapladigiAlan_Bayt;
			Tip_u32 AyirmaBirimi_TamKapasitesi;
		} _Tip_s_Depo;

		#define _Depo_(s_Depo)				( (_Tip_s_Depo *)s_Depo )
		#define _Depo_IGIC_(s_Depo)			( _IGIC_(_Depo_(s_Depo)->IGIC) )

		////////////////////////////////////////////////////////////////////////////////
		//Genel Goruse Acik Degiskenler
		////////////////////////////////////////////////////////////////////////////////
		typedef Tip_Isaretci Tip_Isaretci_Depo;

		#define Depo_Kapasite(s_Depo)		( _Depo_IGIC_(s_Depo)->Kapasite )
		#define Depo_DoluAlan(s_Depo)		( _Depo_IGIC_(s_Depo)->DoluAlan )
		#define Depo_BosAlan(s_Depo)		( Depo_Kapasite(s_Depo) - Depo_DoluAlan(s_Depo) )

		Tip_Isaretci_Depo Depo_Yeni(Tip_u8 AyirmaBirimi_KapladigiAlan_Bayt, Tip_u32 Kapasite, enum e_IGIC_YerKalmazsa_ YerKalmazsa, Tip_Islem_IGIC_Siliniyor Islem_Siliniyor);
		Tip_void Depo_Sil(Tip_Isaretci_Depo Depo);

		Tip_bool Depo_Bilgi_Ekle(Tip_Isaretci_Depo Depo, Tip_Isaretci OkunacakTampon, Tip_u32 Adet);
		Tip_u32 Depo_Bilgi_Oku(Tip_Isaretci_Depo Depo, Tip_Isaretci YazilacakTampon, Tip_u32 TamponKapasitesi);
		Tip_u32 Depo_Bilgi_SiradakiAdet(Tip_Isaretci_Depo Depo);

	#endif

#endif /* __HazirKod_C_Depo_H__ */
