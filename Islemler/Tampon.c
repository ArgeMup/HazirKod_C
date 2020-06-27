// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.1

#include "Tampon.h"

Tip_Isaretci_Tampon Tampon_Yeni(Tip_u32 Kapasite)
{
	struct _s_Tampon_ * Yeni = YT_Yeni(sizeof(struct _s_Tampon_));
	if (Yeni == Tip_null) return Tip_null;

	Yeni->Isaretci = YT_Yeni(Kapasite);
	if (Yeni->Isaretci == Tip_null)
	{
		YT_Sil(Yeni);
		return Tip_null;
	}
	
	Yeni->Kullanim = 0;
	Yeni->Kapasite = Kapasite;

	return Yeni;
}
Tip_void Tampon_Sil(Tip_Isaretci_Tampon Tampon)
{
	if (Tampon == Tip_null) return;
	
	YT_Sil(Tampon_Isaretci_Konum(Tampon, 0, Tip_u8));
	YT_Sil(Tampon);
}

Tip_bool Tampon_Bilgi_Ekle_Bayt(Tip_Isaretci_Tampon Tampon, Tip_u8 Bayt)
{
	if (Tampon_BosAlan(Tampon) == 0) return false;

	Tampon_Icerik_GecerliKonum(Tampon, Tip_u8) = Bayt;
	Tampon_DoluAlan(Tampon) += 1;
	return true;
}
Tip_bool Tampon_Bilgi_Ekle_Blok(Tip_Isaretci_Tampon Tampon, Tip_Isaretci Kaynak, Tip_u32 KaynakBoyut)
{
	if (KaynakBoyut > Tampon_BosAlan(Tampon)) return false;

	_Islem_memcpy_(Tampon_Isaretci_GecerliKonum(Tampon, Tip_u8), Kaynak, KaynakBoyut);
	Tampon_DoluAlan(Tampon) += KaynakBoyut;
	return true;
}
