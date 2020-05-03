// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.0

#include "Tampon.h"

struct s_Tampon_Tutucu_
{
	struct s_Tampon_ Tampon;
	struct s_Tampon_Tutucu_ * SonrakiTamponTutucu;
} * _Tampon_Ilk_ = _Ortak_Tip_null_, * _Tampon_Son_ = _Ortak_Tip_null_;
_Ortak_Tip_bool_ _Tampon_Mutex_ = false;
_Ortak_Tip_uint32_t_ _Tampon_ToplamKullanim_ = 0;

_Ortak_Tip_Isaretci_ _Tampon_Ac_(_Ortak_Tip_uint32_t_ Adet)
{
	_Ortak_Tip_Isaretci_ Isaretci = _Ortak_Islem_malloc_(Adet);
	if (Isaretci) _Tampon_ToplamKullanim_ += Adet;
	return Isaretci;
}
void _Tampon_Kapat_(_Ortak_Tip_Isaretci_ Isaretci, _Ortak_Tip_uint32_t_ Adet)
{
	_Ortak_Islem_free_(Isaretci);
	_Tampon_ToplamKullanim_ -= Adet;
}

_Ortak_Tip_weak_ void Tampon_Mutex_Tut_Islemi()
{
	while(_Tampon_Mutex_);
	_Tampon_Mutex_ = true;
}
_Ortak_Tip_weak_ void Tampon_Mutex_Birak_Islemi()
{
	_Tampon_Mutex_ = false;
}

struct s_Tampon_ * Tampon_Ac(_Ortak_Tip_uint32_t_ Kapasite, _Ortak_Tip_uint32_t_ Hatirlatici)
{
	struct s_Tampon_Tutucu_ * Tampon_Tutucu = _Tampon_Ac_(sizeof(struct s_Tampon_Tutucu_));
	if (Tampon_Tutucu == _Ortak_Tip_null_) return _Ortak_Tip_null_;

	Tampon_Tutucu->Tampon.Isaretci = _Tampon_Ac_(Kapasite);
	if (Tampon_Tutucu->Tampon.Isaretci == _Ortak_Tip_null_)
	{
		_Tampon_Kapat_(Tampon_Tutucu, sizeof(struct s_Tampon_Tutucu_));
		return _Ortak_Tip_null_;
	}

	Tampon_Mutex_Tut_Islemi();
	
	Tampon_Tutucu->SonrakiTamponTutucu = _Ortak_Tip_null_;
	Tampon_Tutucu->Tampon.Hatirlatici = Hatirlatici;
	Tampon_Tutucu->Tampon.Kullanim = 0;
	Tampon_Tutucu->Tampon.Kapasite = Kapasite;
	
	if (_Tampon_Son_ == _Ortak_Tip_null_)
	{
		_Tampon_Son_ = Tampon_Tutucu;
		_Tampon_Ilk_ = Tampon_Tutucu;
	}
	else
	{
		_Tampon_Son_->SonrakiTamponTutucu = Tampon_Tutucu;
		_Tampon_Son_ = Tampon_Tutucu;
	}

	Tampon_Mutex_Birak_Islemi();
	return &Tampon_Tutucu->Tampon;
}
struct s_Tampon_ * Tampon_Bul_Hatirlatici(_Ortak_Tip_uint32_t_ Baslangic, _Ortak_Tip_uint32_t_ Bitis, struct s_Tampon_ * OncekiTampon)
{
	Tampon_Mutex_Tut_Islemi();

	struct s_Tampon_Tutucu_ * Simdiki;
	struct s_Tampon_ * Cikti = NULL;

	if (OncekiTampon == NULL) Simdiki = _Tampon_Ilk_;
	else Simdiki = ((struct s_Tampon_Tutucu_ *)OncekiTampon)->SonrakiTamponTutucu;

	while (Simdiki != _Ortak_Tip_null_ && Cikti == NULL)
	{
		if (Simdiki->Tampon.Hatirlatici >= Baslangic && Simdiki->Tampon.Hatirlatici <= Bitis) Cikti = &Simdiki->Tampon;

		Simdiki = Simdiki->SonrakiTamponTutucu;
	}

	Tampon_Mutex_Birak_Islemi();

	return Cikti;
}
void Tampon_Kapat(struct s_Tampon_ * Tampon)
{
	if (Tampon == NULL || _Tampon_Ilk_ == NULL) return;

	Tampon_Mutex_Tut_Islemi();
	
  	struct s_Tampon_Tutucu_ * Onceki = NULL;
	struct s_Tampon_Tutucu_ * Simdiki = _Tampon_Ilk_;
	
	while (Simdiki != _Ortak_Tip_null_)
	{
		if (Simdiki->Tampon.Isaretci == Tampon->Isaretci)
		{
			if (Onceki == NULL) _Tampon_Ilk_ = Simdiki->SonrakiTamponTutucu;
			else Onceki->SonrakiTamponTutucu = Simdiki->SonrakiTamponTutucu;

			_Tampon_Kapat_(Simdiki->Tampon.Isaretci, Simdiki->Tampon.Kapasite);
			_Tampon_Kapat_(Simdiki, sizeof(struct s_Tampon_Tutucu_));
			
			break;
		}
		
		Onceki = Simdiki;
		Simdiki = Simdiki->SonrakiTamponTutucu;
	} 

	Tampon_Mutex_Birak_Islemi();
}
void Tampon_Kapat_Hatirlatici(_Ortak_Tip_uint32_t_ Baslangic, _Ortak_Tip_uint32_t_ Bitis)
{
	struct s_Tampon_ * OncekiTampon = NULL;

	do
	{
		OncekiTampon = Tampon_Bul_Hatirlatici(Baslangic, Bitis, NULL);
		Tampon_Kapat(OncekiTampon);
	}
	while (OncekiTampon != NULL);
}
