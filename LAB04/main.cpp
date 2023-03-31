/**************************************
 The original copy of the code can be found at http://web.eecs.utk.edu/~mkarakay/courses_files/testfiles.zip
 and it is modified for ELM463/667
 **************************************/

#include "Image.h"
#include <math.h>
using namespace std;
/*
Ömer Cebeci 171024007
Ödev-4

Main içerisinde kullanılan bütün fonksiyonların detaylı açıklamaları Image.cpp içerisinde verilmiştir.
LAB İÇİN YAZILAN BÜTÜN FONKSİYONLAR Image.cpp İÇERİSİNDE EN ALT KISIMDA YER ALMAKTADIR.



KULLANILMAYAN FONKSİYONLAR HEADER DOSYASINDA LAB4 İÇİN YAZILAN FONKSİYON TANIMLAMAALRINDA YORUM OLARAK GÖSTERİLMİŞTİR.

*/
int main(int argc, char **argv)
{




//// SORU-1 ////////////////////////

// Giriş görüntüsü için obje oluşturuldu
Image input_1 ;

// Çıkış görüntüsü için objeler oluşturuldu
Image output_1_b;
Image output_1_c;
Image output_1_d;
Image output_1_e;
Image output_1_f;
Image output_1_g;
Image output_1_h;

// Giriş görüntüsnü okumak için karakter dizisi
char input_1_FileName [] ="Fig0343(a)(skeleton_orig).pgm";

// Çıkış görüntülerinin isimleri için karakter dizileri
char output_fileName_1b [] ="output_soru1_b.pgm";
char output_fileName_1c [] ="output_soru1_c.pgm";
char output_fileName_1d [] ="output_soru1_d.pgm";
char output_fileName_1e [] ="output_soru1_e.pgm";
char output_fileName_1f [] ="output_soru1_f.pgm";
char output_fileName_1g [] ="output_soru1_g.pgm";
char output_fileName_1h [] ="output_soru1_h.pgm";

// Giriş görüntüsü okundu
input_1.readImage(input_1_FileName);
// 1.b maskelenmiş görüntü
output_1_b=input_1.SpatialFilters(3,4);
output_1_b.writeImage(output_fileName_1b,true);

// 1.C
output_1_c=input_1+output_1_b;
output_1_c.writeImage(output_fileName_1c);
//1.D
output_1_d=input_1.Sobel_Gradient();
output_1_d.writeImage(output_fileName_1d);

//1.E
output_1_e=output_1_d._Average_Filter(5);
output_1_e.writeImage(output_fileName_1e);

// f görselinin elde edilmesi, f görüntüsünün elde edilmesi için c ve e görüntüleri oluşturulduktan sonra imread ile okunmuştur.
///////////////////////////////////////////////////////////////
Image input1_e ;
Image input1_c;


char input_1e_FileName [] ="output_soru1_e.pgm";
char input_1c_FileName [] ="output_soru1_c.pgm";


input1_e .readImage(input_1e_FileName);
input1_c.readImage(input_1c_FileName);
output_1_f=input1_e*input1_c;
output_1_f.writeImage(output_fileName_1f,true);
//////////////////////////////////////////////////////
// g görüntüsnü elde etmek için f görüntüsü oluşturulduktan sonra okunmuştur.
Image input1_f;
char input_1f_FileName [] ="output_soru1_f.pgm";
input1_f.readImage(input_1f_FileName);

output_1_g=input1_f+input_1;
output_1_g.writeImage(output_fileName_1g);
/////////////////////////////////////////////////////////////
output_1_h=output_1_g._ImageGama(0.5);
output_1_h.writeImage(output_fileName_1h);

///////////////////////////////2. SORU ////////////
// Çıkış görüntüsü için objeler oluşturuldu
Image output_2_c;
Image output_2_d;
Image output_2_e;
Image output_2_f;
Image output_2_g;
Image output_2_h;

// Çıkış görüntülerinin isimleri için karakter dizileri
char output_fileName_2b [] ="output_soru2_b.pgm";
char output_fileName_2c [] ="output_soru2_c.pgm";
char output_fileName_2d [] ="output_soru2_d.pgm";
char output_fileName_2e [] ="output_soru2_e.pgm";
char output_fileName_2f [] ="output_soru2_f.pgm";
char output_fileName_2g [] ="output_soru2_g.pgm";
char output_fileName_2h [] ="output_soru2_h.pgm";


// Giriş görüntüsü için obje oluşturuldu
Image input_2 ;
// 2.b görüntüsü fourier ile elde edileceği için fazldan iki adet obje oluşturuldu
Image output_2b ;
Image output_2b_son ;
Image fourier;

// Giriş görüntüsnü okumak için karakter dizisi
char input_2_FileName [] ="Fig0343(a)(skeleton_orig).pgm";

// Giriş görüntüsü okundu
input_2.readImage(input_2_FileName);


// sobel gradient 2.d
output_2_d=input_2.Sobel_Gradient();
output_2_d.writeImage(output_fileName_2d);
/////////////////////////
// Sobel gradient uygulanan görüntünün bulanıklaştırılması 2.e
output_2_e=output_2_d._Average_Filter(5);
output_2_e.writeImage(output_fileName_2e);
/////////////////////////// FOURIER İLE 2.b NİN ELDE EDİLMESİ
input_2.readImage(input_2_FileName);
fourier=input_2.Fourier_Transform(); //Fourier transformu alındı
output_2b=fourier.H_uv(); // Freksnd ekseninde h_uv ve F_uv çarpıldı
output_2b_son=output_2b.InverseFourier2();//çarpım sonucunun inverse fourier dönüşümü alınarak zaman eksenine geçildi

output_2b_son.writeImage(output_fileName_2b,true);
//////////////////////////////////////////////////
// 2.c nin  elde edilmesi için oluşturulan 2.b görüntüsü okundu
Image input_2b ;
char input_2b_fileName [] ="output_soru2_b.pgm";
input_2b.readImage(input_2b_fileName);
input_2.readImage(input_2_FileName);

output_2_c=input_2+input_2b;
output_2_c.writeImage(output_fileName_2c);
///////////////////////////////////////////////


// 2.f nin  elde edilmesi için oluşturulan 2.c ve 2.e  görüntüleri okundu
//// f görselinin elde edilmesi
Image input2_e ;
Image input2_c;


char input_2e_FileName [] ="output_soru2_e.pgm";
char input_2c_FileName [] ="output_soru2_c.pgm";
//
//
input2_e .readImage(input_2e_FileName);
input2_c.readImage(input_2c_FileName);
output_2_f=input2_e*input2_c;
output_2_f.writeImage(output_fileName_2f,true);
////////////////////////////////////////////////////////
// 2.g ve 2.h görüntülerinin elde edilmesi .
Image input2_f;
char input_2f_FileName [] ="output_soru2_f.pgm";
input2_f.readImage(input_2f_FileName);

input_2.readImage(input_2_FileName);
output_2_g=input2_f+input_2;
output_2_g.writeImage(output_fileName_2g);

output_2_h=output_2_g._ImageGama(0.5);
output_2_h.writeImage(output_fileName_2h);



}
