// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.0

#include "Depo.h"

enum e_Depo_Sonuc_ Depo_Baslat(struct s_Depo_ * Depo)
{
	if (Depo->Tampon == _Ortak_Tip_null_ ||
		Depo->Kapasite == 0 ||
		Depo->AyirmaBirimi_KapladigiAlan_Bayt == 0 ||
		Depo->AyirmaBirimi_KapladigiAlan_Bayt > 4 ||
		Depo->YerKalmazsa > e_Depo_YerKalmazsa_TalebiReddet) return e_Depo_Sonuc_HataliParametre;
	
	Depo->_IcKullanim_.AyirmaBirimi_TamKapasitesi = (1 << (Depo->AyirmaBirimi_KapladigiAlan_Bayt * 8)) - 1;
	Depo->_IcKullanim_.Konum_Ekleme = 0;
	Depo->_IcKullanim_.Konum_Okuma = 0;
	Depo->_IcKullanim_.BosAlanMiktari = Depo->Kapasite;
	
	_Ortak_Islem_memcpy_(Depo->Tampon, &Depo->_IcKullanim_.Konum_Okuma, Depo->AyirmaBirimi_KapladigiAlan_Bayt);

	return e_Depo_Sonuc_Tamam;
}

enum e_Depo_Sonuc_ Depo_Ekle(struct s_Depo_ * Depo, _Ortak_Tip_Isaretci_ Tampon, _Ortak_Tip_uint32_t_ Adet)
{
	if (Depo == _Ortak_Tip_null_ ||
		Tampon == _Ortak_Tip_null_ ||
		Adet == 0 ||
		Adet > Depo->_IcKullanim_.AyirmaBirimi_TamKapasitesi ||  
		Adet > Depo->Kapasite - Depo->AyirmaBirimi_KapladigiAlan_Bayt) return e_Depo_Sonuc_HataliParametre;
	
	enum e_Depo_Sonuc_ Sonuc = e_Depo_Sonuc_Hata;
	_Ortak_Tip_uint32_t_ toplam;
	
	if (Depo->Islem_Mutex)
	{
		Sonuc = Depo->Islem_Mutex(e_Depo_Islem_Mutex_Tut, Depo->Hatirlatici);
		if (Sonuc != e_Depo_Sonuc_Tamam) return e_Depo_Sonuc_Mutex;
	}
	
	while (Depo->_IcKullanim_.BosAlanMiktari < Adet + Depo->AyirmaBirimi_KapladigiAlan_Bayt)
	{
		if (Depo->YerKalmazsa == e_Depo_YerKalmazsa_TalebiReddet) 
		{
			Sonuc = e_Depo_Sonuc_BosYerYok;
			goto Cikis;
		}
	
		_Ortak_Tip_uint32_t_ AnlikAdet = 0;
		_Ortak_Islem_memcpy_(&AnlikAdet, (_Ortak_Tip_Isaretci_)((_Ortak_Tip_uint32_t_)Depo->Tampon + Depo->_IcKullanim_.Konum_Okuma), Depo->AyirmaBirimi_KapladigiAlan_Bayt);
		
		if (Depo->Islem_Siliniyor)
		{
			Sonuc = Depo->Islem_Siliniyor((_Ortak_Tip_Isaretci_)((_Ortak_Tip_uint32_t_)Depo->Tampon + Depo->_IcKullanim_.Konum_Okuma + Depo->AyirmaBirimi_KapladigiAlan_Bayt), AnlikAdet, Depo->Hatirlatici);
			if (Sonuc != e_Depo_Sonuc_Tamam) 
			{
				Sonuc = e_Depo_Sonuc_SilmeIslemiIptalEdildi;
				goto Cikis;
			}
		}
		
		AnlikAdet += Depo->AyirmaBirimi_KapladigiAlan_Bayt;
		Depo->_IcKullanim_.Konum_Okuma += AnlikAdet;
		Depo->_IcKullanim_.BosAlanMiktari += AnlikAdet;
	} 
  
	if (Depo->Kapasite - Depo->_IcKullanim_.Konum_Ekleme <= Adet)
	{
		if (Depo->_IcKullanim_.Konum_Okuma > 0)
		{
		  	_Ortak_Tip_uint32_t_ fark = Depo->_IcKullanim_.Konum_Ekleme - Depo->_IcKullanim_.Konum_Okuma;
			_Ortak_Islem_memcpy_(Depo->Tampon, (_Ortak_Tip_Isaretci_)((_Ortak_Tip_uint32_t_)Depo->Tampon + Depo->_IcKullanim_.Konum_Okuma), fark);
		
			Depo->_IcKullanim_.Konum_Okuma = 0;
			Depo->_IcKullanim_.Konum_Ekleme = fark;
		}
	}
	  
	_Ortak_Islem_memcpy_((_Ortak_Tip_Isaretci_)((_Ortak_Tip_uint32_t_)Depo->Tampon + Depo->_IcKullanim_.Konum_Ekleme), &Adet, Depo->AyirmaBirimi_KapladigiAlan_Bayt);
	_Ortak_Islem_memcpy_((_Ortak_Tip_Isaretci_)((_Ortak_Tip_uint32_t_)Depo->Tampon + Depo->_IcKullanim_.Konum_Ekleme + Depo->AyirmaBirimi_KapladigiAlan_Bayt), Tampon, Adet);
	
	toplam = Depo->AyirmaBirimi_KapladigiAlan_Bayt + Adet;
	Depo->_IcKullanim_.Konum_Ekleme += toplam;
	Depo->_IcKullanim_.BosAlanMiktari -= toplam;
	Sonuc = e_Depo_Sonuc_Tamam;
	
	Cikis:
	if (Depo->Islem_Mutex)
	{
		Depo->Islem_Mutex(e_Depo_Islem_Mutex_Birak, Depo->Hatirlatici);
	}
  
	return Sonuc;
}

_Ortak_Tip_uint32_t_ Depo_Oku(struct s_Depo_ * Depo, _Ortak_Tip_Isaretci_ YazilacakTampon, _Ortak_Tip_uint32_t_ TamponKapasitesi)
{
	if (Depo == _Ortak_Tip_null_ ||
		Depo->_IcKullanim_.Konum_Ekleme <= Depo->_IcKullanim_.Konum_Okuma) return 0;

	if (Depo->Islem_Mutex)
	{
		enum e_Depo_Sonuc_ Sonuc = Depo->Islem_Mutex(e_Depo_Islem_Mutex_Tut, Depo->Hatirlatici);
		if (Sonuc != e_Depo_Sonuc_Tamam) return 0;
	}
	
	_Ortak_Tip_uint32_t_ OkunanAdet = 0;
	while (OkunanAdet < TamponKapasitesi && Depo->Kapasite - Depo->_IcKullanim_.BosAlanMiktari > 0)
	{
		_Ortak_Tip_uint32_t_ AnlikAdet = 0;
		_Ortak_Islem_memcpy_(&AnlikAdet, (_Ortak_Tip_Isaretci_)((_Ortak_Tip_uint32_t_)Depo->Tampon + Depo->_IcKullanim_.Konum_Okuma), Depo->AyirmaBirimi_KapladigiAlan_Bayt);
		
		if (OkunanAdet + AnlikAdet > TamponKapasitesi) break;
		
		_Ortak_Islem_memcpy_((_Ortak_Tip_Isaretci_)((_Ortak_Tip_uint32_t_)YazilacakTampon + OkunanAdet), (_Ortak_Tip_Isaretci_)((_Ortak_Tip_uint32_t_)Depo->Tampon + Depo->_IcKullanim_.Konum_Okuma + Depo->AyirmaBirimi_KapladigiAlan_Bayt), AnlikAdet);
		OkunanAdet += AnlikAdet;
		
		AnlikAdet += Depo->AyirmaBirimi_KapladigiAlan_Bayt;
		Depo->_IcKullanim_.Konum_Okuma += AnlikAdet;
		Depo->_IcKullanim_.BosAlanMiktari += AnlikAdet;
	}
	
	if (Depo->Islem_Mutex)
	{
		Depo->Islem_Mutex(e_Depo_Islem_Mutex_Birak, Depo->Hatirlatici);
	}
	
	return OkunanAdet;
}

_Ortak_Tip_uint32_t_ Depo_Oku_SiradakiAdet(struct s_Depo_ * Depo)
{
	if (Depo == _Ortak_Tip_null_ ||
		Depo->_IcKullanim_.Konum_Ekleme <= Depo->_IcKullanim_.Konum_Okuma) return 0;

	if (Depo->Islem_Mutex)
	{
		enum e_Depo_Sonuc_ Sonuc = Depo->Islem_Mutex(e_Depo_Islem_Mutex_Tut, Depo->Hatirlatici);
		if (Sonuc != e_Depo_Sonuc_Tamam) return 0;
	}
	
	_Ortak_Tip_uint32_t_ OkunanAdet = 0;
	_Ortak_Islem_memcpy_(&OkunanAdet, (_Ortak_Tip_Isaretci_)((_Ortak_Tip_uint32_t_)Depo->Tampon + Depo->_IcKullanim_.Konum_Okuma), Depo->AyirmaBirimi_KapladigiAlan_Bayt);
	
	if (Depo->Islem_Mutex)
	{
		Depo->Islem_Mutex(e_Depo_Islem_Mutex_Birak, Depo->Hatirlatici);
	}
	
	return OkunanAdet;
}

_Ortak_Tip_uint8_t_ Depo_DolulukOrani_Yuzde(struct s_Depo_ * Depo)
{
	return ((Depo->Kapasite - Depo->_IcKullanim_.BosAlanMiktari) * 100) / Depo->Kapasite;
}
