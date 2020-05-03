// Copyright ArgeMup GNU GENERAL PUBLIC LICENSE Version 3 <http://www.gnu.org/licenses/> <https://github.com/ArgeMup/HazirKod_C>
// V1.0

#ifndef __BitIslemleri_H__
#define __BitIslemleri_H__

////////////////////////////////////////////////////////////////////////////////
//Genel Goruse Acik Tanimlamalar
////////////////////////////////////////////////////////////////////////////////
#define Bit_Yaz_1(Degisken, No)			Degisken |= (1 << No) 
#define Bit_Yaz_0(Degisken, No)			Degisken &= ~(1 << No)
#define Bit_Oku(Degisken, No)			( ( Degisken & (1 << No) ) > 0 )

#define HataDegiskeniniBaslat(Degisken)	Degisken = 0
#define HataliMi(Degisken, Hata)		!Bit_Oku(Degisken, Hata)
#define	Hatali(Degisken, Hata)			Bit_Yaz_0(Degisken, Hata)
#define	HataliDegil(Degisken, Hata)		Bit_Yaz_1(Degisken, Hata)

#endif /* __BitIslemleri_H__ */