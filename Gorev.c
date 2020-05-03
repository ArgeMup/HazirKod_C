// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.0

#include "Gorev.h"

struct s_Gorev_
{
	_An_Tip_ An;
	_Ortak_Tip_int32_t_ (*Islem)(void);	
}Gorevler[_Gorev_Sayisi_] = {0};

_Ortak_Tip_int32_t_ Gorev_Ekle(_Ortak_Tip_int32_t_ (*Islem) (void))
{
	for (_Ortak_Tip_int32_t_ i = 0; i < _Gorev_Sayisi_; i++)
	{
		if (Gorevler[i].Islem != _Ortak_Tip_null_) continue;
		
		Gorevler[i].Islem = Islem;
		Gorevler[i].An = 0;
		return i;
	}
	
	return -1;
}
_Ortak_Tip_int32_t_ Gorev_Sil(_Ortak_Tip_int32_t_ (*Islem) (void))
{
	for (_Ortak_Tip_int32_t_ i = 0; i < _Gorev_Sayisi_; i++)
	{
		if (Gorevler[i].Islem != Islem) continue;
		
		Gorevler[i].Islem = _Ortak_Tip_null_;
		return i;
	}
	
	return -1;
}
void Gorev_Calistir()
{
	for (_Ortak_Tip_int32_t_ i = 0; i < _Gorev_Sayisi_; i++)
	{
		if (Gorevler[i].Islem == _Ortak_Tip_null_) continue;
		if (!Sure_DolduMu(Gorevler[i].An)) continue;
			
		_Ortak_Tip_int32_t_ Gecikme = Gorevler[i].Islem();
		
		if (Gecikme >= 0) Sure_MiliSaniye(Gorevler[i].An, Gecikme); //Kur
		else Gorevler[i].Islem = _Ortak_Tip_null_; 					//Sil
	}
}