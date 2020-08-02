// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.2

#include "Tampon.h"

Tip_Isaretci_Tampon Tampon_Yeni(Tip_u32 Kapasite)
{
	struct _s_Tampon_ * Yeni = YT_Yeni(sizeof(struct _s_Tampon_) + Kapasite);
	if (Yeni == Tip_null) return Tip_null;

	Yeni->Kullanim = 0;
	Yeni->Kapasite = Kapasite;
	Yeni->Isaretci = Isaretci_Konumlandir(Yeni, sizeof(struct _s_Tampon_), Tip_u8);

	return Yeni;
}
Tip_void Tampon_Sil(Tip_Isaretci_Tampon Tampon)
{
	if (Tampon == Tip_null) return;
	
	YT_Sil(Tampon);
}

Tip_bool Tampon_Bilgi_Ekle_GecerliKonum(Tip_Isaretci_Tampon Tampon, Tip_Isaretci Kaynak, Tip_u32 Adet)
{
	if (Tampon == Tip_null) return false;
	if (Adet > Tampon_BosAlan(Tampon)) return false;

	_Islem_memcpy_(Tampon_Isaretci_GecerliKonum(Tampon, Tip_u8), Kaynak, Adet);
	Tampon_DoluAlan(Tampon) += Adet;
	return true;
}
Tip_u32 Tampon_Bilgi_Oku_GecerliKonum(Tip_Isaretci_Tampon Tampon, Tip_Isaretci Hedef, Tip_u32 HedefKapasitesi)
{
	if (Tampon == Tip_null) return 0;
	if (Tampon_DoluAlan(Tampon) < HedefKapasitesi) HedefKapasitesi = Tampon_DoluAlan(Tampon);

	_Islem_memcpy_(Hedef, Tampon_Isaretci_IlkKonum(Tampon, Tip_u8), HedefKapasitesi);
	Tampon_DoluAlan(Tampon) -= HedefKapasitesi;

	if (Tampon_DoluAlan(Tampon) > 0) _Islem_memcpy_(Tampon_Isaretci_IlkKonum(Tampon, Tip_u8), Tampon_Isaretci_Konum(Tampon, HedefKapasitesi, Tip_u8), Tampon_DoluAlan(Tampon));
	return HedefKapasitesi;
}

Tip_u32 Tampon_Bilgi_Oku_Konum(Tip_Isaretci_Tampon Tampon, Tip_u32 BaslangicKonumu, Tip_Isaretci Hedef, Tip_u32 HedefKapasitesi)
{
	if (Tampon == Tip_null) return 0;
	if ( (Tampon_Kapasite(Tampon) - BaslangicKonumu) < HedefKapasitesi) HedefKapasitesi = Tampon_Kapasite(Tampon) - BaslangicKonumu;

	_Islem_memcpy_(Hedef, Tampon_Isaretci_Konum(Tampon, BaslangicKonumu, Tip_u8), HedefKapasitesi);
	return HedefKapasitesi;
}
