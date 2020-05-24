// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.1

#ifndef __ZamanAsimi_H__
#define __ZamanAsimi_H__

#include "HazirKod_C_Ayarlar.h"

////////////////////////////////////////////////////////////////////////////////
//Genel Goruse Acik Degiskenler
////////////////////////////////////////////////////////////////////////////////
struct s_ZamanAsimi_An_
{
	_Ortak_Tip_uint32_t_ MiliSaniye_Dusuk;
	_Ortak_Tip_uint32_t_ MiliSaniye_Yuksek;
	
	struct s_ZamanAsimi_ * ZamanAsimi;
};  

struct s_ZamanAsimi_Gorev_
{	
	enum 
	{
		e_Gorev_Durum_AdetliCalistir,
		e_Gorev_Durum_SurekliCalistir,
		e_Gorev_Durum_Durdur,
		e_Gorev_Durum_Sil
	}Durum;
	
	_Ortak_Tip_uint32_t_ Hatirlatici;
	_Ortak_Tip_uint32_t_ CalismaAdedi;
	_Ortak_Tip_uint32_t_ Aralik_MiliSaniye;  
	  
	_Ortak_Tip_uint32_t_ (*Islem)(struct s_ZamanAsimi_Gorev_ * Gorev);
	
	struct
	{
		struct s_ZamanAsimi_An_ An;
	}_IcKullanim_;
};

struct s_ZamanAsimi_
{
	void (*SayaciGuncelle)(struct s_ZamanAsimi_An_ * Simdi, _Ortak_Tip_uint32_t_ Hatirlatici);
	_Ortak_Tip_uint32_t_ Hatirlatici;
	
	struct
	{
		struct s_ZamanAsimi_An_ An;
		
		#if ZamanAsimi_AcKapat_Gorev_Adet
		struct s_ZamanAsimi_Gorev_ Gorevler[ZamanAsimi_AcKapat_Gorev_Adet];
		#endif
	}_IcKullanim_;
};  

#if ZamanAsimi_AcKapat_CokluZamanlayici == 0
	#define ZamanAsimi_Parametre_1
	#define ZamanAsimi_Parametre_2
	#define ZamanAsimi_Parametre_3

	void ZamanAsimi_Baslat();
	void ZamanAsimi_Baslat_An(struct s_ZamanAsimi_An_ * An);

	_Ortak_Tip_Isaretci_ ZamanAsimi_Gorev_Ekle(struct s_ZamanAsimi_Gorev_ Gorev);
	void ZamanAsimi_Gorev_Sil(_Ortak_Tip_Isaretci_ Tutacak);
	void ZamanAsimi_Gorev_Duzenle(_Ortak_Tip_Isaretci_ Tutacak, struct s_ZamanAsimi_Gorev_ Gorev);
	void ZamanAsimi_Gorev_Baslat(_Ortak_Tip_Isaretci_ Tutacak, _Ortak_Tip_int32_t_ Aralik_MiliSaniye);
	void ZamanAsimi_Gorev_Durdur(_Ortak_Tip_Isaretci_ Tutacak);
	void ZamanAsimi_Gorevler_Calistir();

	void ZamanAsimi_SayaciIlerlet(_Ortak_Tip_uint32_t_ MiliSaniye);
	
	void ZamanAsimi_Bekle_MiliSaniye(_Ortak_Tip_uint32_t_ Sure);
	void ZamanAsimi_Bekle_Saniye(_Ortak_Tip_uint32_t_ Sure);
#else
	#define ZamanAsimi_Parametre_1 struct s_ZamanAsimi_ * ZamanAsimi
	#define ZamanAsimi_Parametre_2 ZamanAsimi_Parametre_1,
	#define ZamanAsimi_Parametre_3 ZamanAsimi,

	void ZamanAsimi_Baslat(struct s_ZamanAsimi_ * ZamanAsimi);
	void ZamanAsimi_Baslat_An(struct s_ZamanAsimi_ * ZamanAsimi, struct An_ * An);

	_Ortak_Tip_Isaretci_ ZamanAsimi_Gorev_Ekle(struct s_ZamanAsimi_ * ZamanAsimi, struct Gorev_ Gorev);
	void ZamanAsimi_Gorev_Sil(_Ortak_Tip_Isaretci_ Tutacak);
	void ZamanAsimi_Gorev_Duzenle(_Ortak_Tip_Isaretci_ Tutacak, struct s_ZamanAsimi_Gorev_ Gorev);
	void ZamanAsimi_Gorev_Baslat(struct s_ZamanAsimi_ * ZamanAsimi, _Ortak_Tip_Isaretci_ Tutacak, _Ortak_Tip_int32_t_ Aralik_MiliSaniye);
	void ZamanAsimi_Gorev_Durdur(_Ortak_Tip_Isaretci_ Tutacak);
	void ZamanAsimi_Gorevler_Calistir(struct s_ZamanAsimi_ * ZamanAsimi);

	void ZamanAsimi_SayaciIlerlet(struct s_ZamanAsimi_ * ZamanAsimi, _Ortak_Tip_uint32_t_ MiliSaniye);
	
	void ZamanAsimi_Bekle_MiliSaniye(struct s_ZamanAsimi_ * ZamanAsimi, _Ortak_Tip_uint32_t_ Sure);
	void ZamanAsimi_Bekle_Saniye(struct s_ZamanAsimi_ * ZamanAsimi, _Ortak_Tip_uint32_t_ Sure);
#endif

void ZamanAsimi_Kur_MiliSaniye(struct s_ZamanAsimi_An_ * An, _Ortak_Tip_uint32_t_ Sure, _Ortak_Tip_bool_ UstuneEkle);
void ZamanAsimi_Kur_Saniye(struct s_ZamanAsimi_An_ * An, _Ortak_Tip_uint32_t_ Sure, _Ortak_Tip_bool_ UstuneEkle);
void ZamanAsimi_Kur_Dakika(struct s_ZamanAsimi_An_ * An, _Ortak_Tip_uint32_t_ Sure, _Ortak_Tip_bool_ UstuneEkle);
void ZamanAsimi_Kur_Saat(struct s_ZamanAsimi_An_ * An, _Ortak_Tip_uint32_t_ Sure, _Ortak_Tip_bool_ UstuneEkle);
void ZamanAsimi_Kur_Gun(struct s_ZamanAsimi_An_ * An, _Ortak_Tip_uint32_t_ Sure, _Ortak_Tip_bool_ UstuneEkle);
void ZamanAsimi_Kur_Hafta(struct s_ZamanAsimi_An_ * An, _Ortak_Tip_uint32_t_ Sure, _Ortak_Tip_bool_ UstuneEkle);
void ZamanAsimi_Kur_Yil(struct s_ZamanAsimi_An_ * An, _Ortak_Tip_uint32_t_ Sure, _Ortak_Tip_bool_ UstuneEkle);
_Ortak_Tip_bool_ ZamanAsimi_OlduMu(struct s_ZamanAsimi_An_ * An);

#endif /* __ZamanAsimi_H__ */
