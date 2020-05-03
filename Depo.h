// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.0

#ifndef __Depo_H__
#define __Depo_H__

#include "../HazirKod_C_Ayarlar.h"

////////////////////////////////////////////////////////////////////////////////
//Genel Goruse Acik Degiskenler
////////////////////////////////////////////////////////////////////////////////
enum e_Depo_Sonuc_
{
	e_Depo_Sonuc_Tamam,
	e_Depo_Sonuc_Hata,
	
	e_Depo_Sonuc_SilmeIslemiIptalEdildi,
	e_Depo_Sonuc_HataliParametre,
	e_Depo_Sonuc_BosYerYok,
	e_Depo_Sonuc_Mutex
};

enum e_Depo_YerKalmazsa_
{
	e_Depo_YerKalmazsa_EnEskiyiSil,
	e_Depo_YerKalmazsa_TalebiReddet
};

enum e_Depo_Islem_Mutex_
{
	e_Depo_Islem_Mutex_Tut,
	e_Depo_Islem_Mutex_Birak
};

struct s_Depo_
{
  	_Ortak_Tip_Isaretci_ Tampon;
	_Ortak_Tip_uint32_t_ Kapasite;
	_Ortak_Tip_uint32_t_ Hatirlatici;
	
	_Ortak_Tip_uint8_t_ AyirmaBirimi_KapladigiAlan_Bayt;
	enum e_Depo_YerKalmazsa_ YerKalmazsa;			
	
	enum e_Depo_Sonuc_ (*Islem_Mutex) (enum e_Depo_Islem_Mutex_ OlayTipi, _Ortak_Tip_uint32_t_ Hatirlatici);
	enum e_Depo_Sonuc_ (*Islem_Siliniyor) (_Ortak_Tip_Isaretci_ SilinenBilgininIsaretcisi, _Ortak_Tip_uint32_t_ Adet, _Ortak_Tip_uint32_t_ Hatirlatici);
	
	struct
	{
	 	_Ortak_Tip_uint32_t_ AyirmaBirimi_TamKapasitesi;
  
		_Ortak_Tip_uint32_t_ Konum_Ekleme;
		_Ortak_Tip_uint32_t_ Konum_Okuma;

		_Ortak_Tip_uint32_t_ BosAlanMiktari;
	}_IcKullanim_;
};

enum e_Depo_Sonuc_ Depo_Baslat(struct s_Depo_ * Depo);
enum e_Depo_Sonuc_ Depo_Ekle(struct s_Depo_ * Depo, _Ortak_Tip_Isaretci_ Tampon, _Ortak_Tip_uint32_t_ Adet);
_Ortak_Tip_uint32_t_ Depo_Oku(struct s_Depo_ * Depo, _Ortak_Tip_Isaretci_ YazilacakTampon, _Ortak_Tip_uint32_t_ TamponKapasitesi);
_Ortak_Tip_uint32_t_ Depo_Oku_SiradakiAdet(struct s_Depo_ * Depo);
_Ortak_Tip_uint8_t_ Depo_DolulukOrani_Yuzde(struct s_Depo_ * Depo);

#endif /* __Depo_H__ */