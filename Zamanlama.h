// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.1

#ifndef __Zamanlama_H__
#define __Zamanlama_H__

#include "HazirKod_C_Ayarlar.h"

////////////////////////////////////////////////////////////////////////////////
//Ic Kullanim
////////////////////////////////////////////////////////////////////////////////
#define _An_(u)			( (_An_Tip_)( Zamanlama_An_Okuma_Islemi() + (_An_Tip_)u ) )
#define _Msn_(u)		( ( u / _An_Aralik_Msn_ ) + 1 )
#define _Saniye_(u)		( ( 1000 / _An_Aralik_Msn_ ) * u )
#define _Dakika_(u)		( 60 * _Saniye_(u) )
#define _Saat_(u)		( 60 * _Dakika_(u) )
#define _Gun_(u)		( 24 * _Saat_(u) )
#define _Hafta_(u)		(  7 * _Gun_(u) )

////////////////////////////////////////////////////////////////////////////////
//Genel Goruse Acik Tanimlamalar
////////////////////////////////////////////////////////////////////////////////
#define Sure_MiliSaniye(Degisken, Sure)	            Degisken = _An_(_Msn_(Sure))
#define Sure_Saniye(Degisken, Sure)		            Degisken = _An_(_Saniye_(Sure))
#define Sure_Dakika(Degisken, Sure)		            Degisken = _An_(_Dakika_(Sure))
#define Sure_Saat(Degisken, Sure)		            Degisken = _An_(_Saat_(Sure))
#define Sure_Gun(Degisken, Sure)		            Degisken = _An_(_Gun_(Sure))
#define Sure_Hafta(Degisken, Sure)		            Degisken = _An_(_Hafta_(Sure))
#define Sure_Hemen(Degisken)						Degisken = 0
#define Sure_Asla(Degisken)							Degisken = (_An_Tip_)0 - 1
#define Sure_Simdi(Degisken)						Degisken = _An_(0)
#define Sure_DolduMu(Degisken)			            ( Degisken <= _An_(0) )
#define Sure_Degiskeni(Degisken)					_An_Tip_ Sure_Hemen(Degisken)
#define Sure_Degiskeni_MiliSaniye(Degisken, Sure)	_An_Tip_ Sure_MiliSaniye(Degisken, Sure)
#define An_Simdi()						            _An_(0)
#define Bekle_MiliSaniye(Sure) 			            Zamanlama_Bekle_MiliSaniye_Islemi( Sure )

#endif /* __Zamanlama_H__ */