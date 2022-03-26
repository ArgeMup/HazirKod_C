// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.5

#ifndef __HazirKod_C_Zamanlama_H__
#define __HazirKod_C_Zamanlama_H__

	#include "HazirKod_C_Ayarlar.h"

	#ifdef HazirKod_C_Kullan_Zamanlama

		#include <stdio.h>

		////////////////////////////////////////////////////////////////////////////////
		//Ic Kullanim
		////////////////////////////////////////////////////////////////////////////////
		#ifdef _Zamanlama_Tasmayan_Yontemi_Kullan
			typedef struct { Tip_u32 Yuksek, Dusuk; } Tip_Sure;
			typedef Tip_u32 Tip_Sure_Islem;
		#else
			#ifdef _An_Okuma_Islemi_8bayt_Deger_Uretiyor
				typedef Tip_u64 Tip_Sure;
				typedef Tip_u64 Tip_Sure_Islem;
			#else
				typedef Tip_u32 Tip_Sure;
				typedef Tip_u32 Tip_Sure_Islem;
			#endif

			#define _Sure_Ekle(u)		(Tip_Sure_Islem)( (Tip_Sure_Islem)_An_Okuma_Islemi() + (Tip_Sure_Islem)( u ) )
		#endif

		#define _Msn_(u)		( (Tip_Sure_Islem)( (Tip_Sure_Islem)(u) / (Tip_Sure_Islem)(_An_Aralik_Msn_) ) + (Tip_Sure_Islem)1 )
		#define _Saniye_(u)		_Msn_	( (Tip_Sure_Islem)(u) * (Tip_Sure_Islem)1000 )
		#define _Dakika_(u)		_Saniye_( (Tip_Sure_Islem)(u) * (Tip_Sure_Islem)60 )
		#define _Saat_(u)		_Dakika_( (Tip_Sure_Islem)(u) * (Tip_Sure_Islem)60 )
		#define _Gun_(u)		_Saat_	( (Tip_Sure_Islem)(u) * (Tip_Sure_Islem)24 )
		#define _Hafta_(u)		_Gun_	( (Tip_Sure_Islem)(u) * (Tip_Sure_Islem)7 )

		////////////////////////////////////////////////////////////////////////////////
		//Genel Goruse Acik Tanimlamalar
		////////////////////////////////////////////////////////////////////////////////
		#ifdef _Zamanlama_Tasmayan_Yontemi_Kullan
			typedef Tip_void (*Tip_Islem_Zamanlama_Kilit) (Tip_bool);
			void Zamanlama_Baslat(Tip_Islem_Zamanlama_Kilit Kilit_Islemi);
			Tip_char * Sure_Yazdir(Tip_Sure * Degisken, Tip_char * Hedef, Tip_u32 HedefKapasite);

			void _An_Guncelle();
			void _Sure_Ekle(Tip_Sure * Degisken, Tip_u32 Sure);
			Tip_bool _Sure_DolduMu(Tip_Sure * Degisken);
			Tip_u32 _Sure_KalanSure_MiliSaniye(Tip_Sure * Degisken);

			#define Sure_DegiskeniniOlustur(Ad)					Tip_Sure Ad = { 0 }
			#define Sure_DolduMu(Degisken)			            ( _Sure_DolduMu(&Degisken) )
			#define Sure_KalanSure_MiliSaniye(Degisken)			( ( _Sure_KalanSure_MiliSaniye((&Degisken)) ) * ( _An_Aralik_Msn_ ) )

			#define Sure_Hemen(Degisken)						_Islem_memset_( &Degisken, 0, sizeof(Tip_Sure) )
			#define Sure_MiliSaniye(Degisken, Sure)	            _Sure_Ekle(&Degisken, (_Msn_(Sure) ) )
			#define Sure_Saniye(Degisken, Sure)		            _Sure_Ekle(&Degisken, (_Saniye_(Sure) ) )
			#define Sure_Dakika(Degisken, Sure)		            _Sure_Ekle(&Degisken, (_Dakika_(Sure) ) )
			#define Sure_Saat(Degisken, Sure)		            _Sure_Ekle(&Degisken, (_Saat_(Sure) ) )
			#define Sure_Gun(Degisken, Sure)		            _Sure_Ekle(&Degisken, (_Gun_(Sure) ) )
			#define Sure_Hafta(Degisken, Sure)		            _Sure_Ekle(&Degisken, (_Hafta_(Sure) ) )
			#define Sure_Asla(Degisken)							_Islem_memset_( &Degisken, 0xFF, sizeof(Tip_Sure) )
		#else
			#define Sure_DegiskeniniOlustur(Ad)					Tip_Sure Ad = _Sure_Ekle(0)
			#define Sure_DolduMu(Degisken)			            ( Degisken <= _Sure_Ekle(0) )
			#define Sure_KalanSure_MiliSaniye(Degisken)			( ( Degisken - _Sure_Ekle(0) ) * ( _An_Aralik_Msn_ ) )

			#define Sure_Hemen(Degisken)						Degisken = 0
			#define Sure_MiliSaniye(Degisken, Sure)	            Degisken = _Sure_Ekle(_Msn_(Sure))
			#define Sure_Saniye(Degisken, Sure)		            Degisken = _Sure_Ekle(_Saniye_(Sure))
			#define Sure_Dakika(Degisken, Sure)		            Degisken = _Sure_Ekle(_Dakika_(Sure))
			#define Sure_Saat(Degisken, Sure)		            Degisken = _Sure_Ekle(_Saat_(Sure))
			#define Sure_Gun(Degisken, Sure)		            Degisken = _Sure_Ekle(_Gun_(Sure))
			#define Sure_Hafta(Degisken, Sure)		            Degisken = _Sure_Ekle(_Hafta_(Sure))
			#define Sure_Asla(Degisken)							Degisken = ( (Tip_Sure_Islem)0 - 1 )

			Tip_char * Sure_Yazdir(Tip_Sure Degisken, Tip_char * Hedef, Tip_u32 HedefKapasite);
			#define Zamanlama_Baslat() //hata vermemesi icin
		#endif

	#endif

#endif /* __HazirKod_C_Zamanlama_H__ */
