// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.5

#ifndef __Gunluk_H__
#define __Gunluk_H__

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

////////////////////////////////////////////////////////////////////////////////
//Genel Goruse Acik Tanimlamalar
////////////////////////////////////////////////////////////////////////////////
#define _Gunluk_Cikti_Onem_Seviye_Kapali			0
#define _Gunluk_Cikti_Onem_Seviye_BeklenmeyenDurum	1
#define _Gunluk_Cikti_Onem_Seviye_Hata				2
#define _Gunluk_Cikti_Onem_Seviye_Uyari				3
#define _Gunluk_Cikti_Onem_Seviye_Bilgi				4
#define _Gunluk_Cikti_Onem_Seviye_Geveze			5
#define _Gunluk_Cikti_Onem_Seviye_HazirKod_C		6

enum e_Gunluk_Gorunum_
{
	e_Gunluk_Gorunum_Duzyazi = 0,

	e_Gunluk_Gorunum_Yazi_Siyah = 1,
	e_Gunluk_Gorunum_Yazi_Kirmizi,
	e_Gunluk_Gorunum_Yazi_Yesil,
	e_Gunluk_Gorunum_Yazi_Sari,
	e_Gunluk_Gorunum_Yazi_Mavi,
	e_Gunluk_Gorunum_Yazi_Eflatun,
	e_Gunluk_Gorunum_Yazi_CamGobegi,
	e_Gunluk_Gorunum_Yazi_Beyaz,

	e_Gunluk_Gorunum_Yuzey_Siyah = ( e_Gunluk_Gorunum_Yazi_Siyah << 4 ),
	e_Gunluk_Gorunum_Yuzey_Kirmizi = ( e_Gunluk_Gorunum_Yazi_Kirmizi << 4 ),
	e_Gunluk_Gorunum_Yuzey_Yesil = ( e_Gunluk_Gorunum_Yazi_Yesil << 4 ),
	e_Gunluk_Gorunum_Yuzey_Sari = ( e_Gunluk_Gorunum_Yazi_Sari << 4 ),
	e_Gunluk_Gorunum_Yuzey_Mavi = ( e_Gunluk_Gorunum_Yazi_Mavi << 4 ),
	e_Gunluk_Gorunum_Yuzey_Eflatun = ( e_Gunluk_Gorunum_Yazi_Eflatun << 4 ),
	e_Gunluk_Gorunum_Yuzey_CamGobegi = ( e_Gunluk_Gorunum_Yazi_CamGobegi << 4 ),
	e_Gunluk_Gorunum_Yuzey_Beyaz = ( e_Gunluk_Gorunum_Yazi_Beyaz << 4 ),
};

#include "HazirKod_C_Ayarlar.h"
#include "Gunluk.h"
#include "Zamanlama.h"

Tip_void Gunluk_Baslat();
Tip_void Gunluk_SureliDurdur(Tip_u32 Saniye);
typedef Tip_void (*Tip_Islem_Gunluk_DisariAktarma) (Tip_Isaretci, Tip_u32);

////////////////////////////////////////////////////////////////////////////////
//Ic Kullanim
////////////////////////////////////////////////////////////////////////////////
Tip_void _Gunluk_Ekle(enum e_Gunluk_Gorunum_ Gorunum, const Tip_char * Baslik, const Tip_char * Sekil, ...);
Tip_void _Gunluk_Ekle_Hex(const Tip_char * Baslik, Tip_Isaretci Tampon, Tip_u16 Adet);

#ifdef _Gunluk_Renkli_Cikti_Uretsin
	#define __Gunluk_Renk_BeklenmeyenDurum			( _Gunluk_Renk_BeklenmeyenDurum )
	#define __Gunluk_Renk_Hata						( _Gunluk_Renk_Hata )
	#define __Gunluk_Renk_Uyari						( _Gunluk_Renk_Uyari )
	#define __Gunluk_Renk_Bilgi						( _Gunluk_Renk_Bilgi )
	#define __Gunluk_Renk_Geveze					( _Gunluk_Renk_Geveze )
#else
	#define __Gunluk_Renk_BeklenmeyenDurum			( e_Gunluk_Gorunum_Duzyazi )
	#define __Gunluk_Renk_Hata						( e_Gunluk_Gorunum_Duzyazi )
	#define __Gunluk_Renk_Uyari						( e_Gunluk_Gorunum_Duzyazi )
	#define __Gunluk_Renk_Bilgi						( e_Gunluk_Gorunum_Duzyazi )
	#define __Gunluk_Renk_Geveze					( e_Gunluk_Gorunum_Duzyazi )
#endif

#if _Gunluk_Cikti_Onem_Seviyesi == _Gunluk_Cikti_Onem_Seviye_Kapali
#undef _Gunluk_KullaniciTanimliIslemleriKullan
#endif

#ifndef _Gunluk_KullaniciTanimliIslemleriKullan
	#if _Gunluk_Cikti_Onem_Seviyesi >= _Gunluk_Cikti_Onem_Seviye_BeklenmeyenDurum
		#define Gunluk_BeklenmeyenDurum(Yazi , ...)		_Gunluk_Ekle(__Gunluk_Renk_BeklenmeyenDurum, _Gunluk_Baslik, Yazi, ##__VA_ARGS__)
	#else
		#define Gunluk_BeklenmeyenDurum(Yazi , ...)
	#endif

	#if _Gunluk_Cikti_Onem_Seviyesi >= _Gunluk_Cikti_Onem_Seviye_Hata
		#define Gunluk_Hata(Yazi , ...) 				_Gunluk_Ekle(__Gunluk_Renk_Hata, _Gunluk_Baslik, Yazi, ##__VA_ARGS__)
	#else
		#define Gunluk_Hata(Yazi , ...)
	#endif

	#if _Gunluk_Cikti_Onem_Seviyesi >= _Gunluk_Cikti_Onem_Seviye_Uyari
		#define Gunluk_Uyari(Yazi , ...) 				_Gunluk_Ekle(__Gunluk_Renk_Uyari, _Gunluk_Baslik, Yazi, ##__VA_ARGS__)
	#else
		#define Gunluk_Uyari(Yazi , ...)
	#endif

	#if _Gunluk_Cikti_Onem_Seviyesi >= _Gunluk_Cikti_Onem_Seviye_Bilgi
		#define Gunluk_Bilgi(Yazi , ...) 				_Gunluk_Ekle(__Gunluk_Renk_Bilgi, _Gunluk_Baslik, Yazi, ##__VA_ARGS__)
	#else
		#define Gunluk_Bilgi(Yazi , ...)
	#endif

	#if _Gunluk_Cikti_Onem_Seviyesi >= _Gunluk_Cikti_Onem_Seviye_Geveze
		#define Gunluk(Yazi , ...) 						_Gunluk_Ekle(__Gunluk_Renk_Geveze, _Gunluk_Baslik, Yazi, ##__VA_ARGS__)
		#define Gunluk_Hex(Tampon, Adet) 				_Gunluk_Ekle_Hex(_Gunluk_Baslik, Tampon, Adet)
	#else
		#define Gunluk(Yazi , ...)
		#define Gunluk_Hex(Tampon, Adet)
	#endif

	#if _Gunluk_Cikti_Onem_Seviyesi >= _Gunluk_Cikti_Onem_Seviye_HazirKod_C
		#define HazirKod_C_Gunluk(Yazi , ...) 			_Gunluk_Ekle(e_Gunluk_Gorunum_Duzyazi, _Gunluk_Baslik, Yazi, ##__VA_ARGS__)
		#define HazirKod_C_Gunluk_Hex(Tampon, Adet) 	_Gunluk_Ekle_Hex(_Gunluk_Baslik, Tampon, Adet)
	#else
		#define HazirKod_C_Gunluk(Yazi , ...)
		#define HazirKod_C_Gunluk_Hex(Tampon, Adet)
	#endif
#endif



#endif /*__Gunluk_H__ */
