// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.4

#ifndef __Zamanlama_H__
#define __Zamanlama_H__

#include "HazirKod_C_Ayarlar.h"

////////////////////////////////////////////////////////////////////////////////
//Ic Kullanim
////////////////////////////////////////////////////////////////////////////////
typedef Tip_u64 Tip_Sure;
typedef Tip_void (*Tip_Islem_Sure_AnOkuma) ();
typedef Tip_void (*Tip_Islem_Sure_KesmeIcinBekle) ();

#define _An_(u)			(Tip_Sure)( _An_Okuma_Islemi() + (Tip_Sure)( u ) )
#define _Msn_(u)		( ( u ) / _An_Aralik_Msn_ ) + 1
#define _Saniye_(u)		_Msn_( ( u ) * 1000 )
#define _Dakika_(u)		_Saniye_( ( u ) * 60 )
#define _Saat_(u)		_Dakika_( ( u ) * 60 )
#define _Gun_(u)		_Saat_( ( u ) * 24 )
#define _Hafta_(u)		_Gun_( ( u )* 7 )

////////////////////////////////////////////////////////////////////////////////
//Genel Goruse Acik Tanimlamalar
////////////////////////////////////////////////////////////////////////////////
#define Sure_MiliSaniye(Degisken, Sure)	            Degisken = _An_(_Msn_(Sure))
#define Sure_Saniye(Degisken, Sure)		            Degisken = _An_(_Saniye_(Sure))
#define Sure_Dakika(Degisken, Sure)		            Degisken = _An_(_Dakika_(Sure))
#define Sure_Saat(Degisken, Sure)		            Degisken = _An_(_Saat_(Sure))
#define Sure_Gun(Degisken, Sure)		            Degisken = _An_(_Gun_(Sure))
#define Sure_Hafta(Degisken, Sure)		            Degisken = _An_(_Hafta_(Sure))

#define An_Simdi()						            _An_(0)

#define Sure_Hemen(Degisken)						Degisken = 0
#define Sure_Simdi(Degisken)						Degisken = An_Simdi()
#define Sure_Asla(Degisken)							Degisken = ( (Tip_Sure)0 - 1 )

#define Sure_DegiskeniniOlustur(Ad)					Tip_Sure Ad = An_Simdi()
#define Sure_DolduMu(Degisken)			            ( Degisken <= An_Simdi() )
#define Sure_KalanSure_MiliSaniye(Degisken)			( ( Degisken - An_Simdi() ) * _An_Aralik_Msn_ )

#endif /* __Zamanlama_H__ */
