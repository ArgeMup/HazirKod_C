// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.0

#ifndef __Tampon_H__
#define __Tampon_H__

#include "../HazirKod_C_Ayarlar.h"

////////////////////////////////////////////////////////////////////////////////
//Genel Goruse Acik Tanimlamalar
////////////////////////////////////////////////////////////////////////////////

#define IsaretciyiArttir(Tip, Isaretci, Adet) 	( (Tip *)( (uint32_t)Isaretci + (uint32_t)Adet ) )

struct s_Tampon_
{
	_Ortak_Tip_Isaretci_ Isaretci;
	_Ortak_Tip_uint32_t_ Kapasite;
	_Ortak_Tip_uint32_t_ Kullanim;
	_Ortak_Tip_uint32_t_ Hatirlatici;
};

struct s_Tampon_ * Tampon_Ac(_Ortak_Tip_uint32_t_ Kapasite, _Ortak_Tip_uint32_t_ Hatirlatici);
struct s_Tampon_ * Tampon_Bul_Hatirlatici(_Ortak_Tip_uint32_t_ Baslangic, _Ortak_Tip_uint32_t_ Bitis, struct s_Tampon_ * OncekiTampon);
void Tampon_Kapat(struct s_Tampon_ * Tampon);
void Tampon_Kapat_Hatirlatici(_Ortak_Tip_uint32_t_ Baslangic, _Ortak_Tip_uint32_t_ Bitis);

#endif /*__Tampon_H__ */
