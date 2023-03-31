/**************************************
 The original copy of the code can be found at http://web.eecs.utk.edu/~mkarakay/courses_files/testfiles.zip
 and it is modified for ELM463/667
 **************************************/

#include "Image.h"

using namespace std;
/*
Ömer Cebeci 171024007
Ödev-2



*/
int main(int argc, char **argv)
{
/*
/////////////////////////////////////////////// 1. SORU BAŞLANGICI //////////////////////////////////////////////
//////////////// GİRİŞ OBJELERİ /////////////////////
Image inputImage3_4;
Image inputImage3_5;
Image inputImage3_8;
Image inputImage3_9;
Image inputImage3_33;//
Image inputImage3_35;//

////////////////////////
Image outputImage3_4;
/////////////////////////
Image outputImage3_5;


///////////////////// ÇIKIŞ OBJELERİ //////////////////
///////////////////////////////
Image outputImage3_33b; // 3x3
Image outputImage3_33c; // 5x5
Image outputImage3_33d; // 9x9
Image outputImage3_33e; // 15x15
Image outputImage3_33f; // 35x35
////////////////////////////////////////
// gama değerlerine göre obje oluşturuldu  gama<1
Image outputImage3_8_6;
Image outputImage3_8_4;
Image outputImage3_8_3;
///////////////////////////////////////////
// gama değerlerine göre obje oluşturuldu  gama>1
Image outputImage3_9_3;
Image outputImage3_9_4;
Image outputImage3_9_5;
/////////////////////////////////
Image outputImage3_35b; // average_filtre
Image outputImage3_35c; // Median Filtre
//////////////////////////////////////////////


////////// GİRİŞ DOSYALARININ İSİMLERİ//////////////////////////
//////////////////////////////////////////////////
char inputFileName3_4[] = "Fig0304(a)(breast_digital_Xray).pgm";   //
char inputFileName3_5[] = "Fig0305(a)(DFT_no_log).pgm";  //
char inputFileName3_8[] = "Fig0308(a)(fractured_spine).pgm";
char inputFileName3_9[] = "Fig0309(a)(washed_out_aerial_image).pgm";
char inputFileName3_33[] = "Fig0333(a)(test_pattern_blurring_orig).pgm";
char inputFileName3_35[]= "Fig0335(a)(ckt_board_saltpep_prob_pt05).pgm";

/////////////////////ÇIKIŞ DOSYALARININ İSİMLERİ ///////////////////////////


///////////////////////////////////////////////////
char outputFileName3_4[] = "Fig0304(a).pgm";
char outputFileName3_5[] = "Fig0305(a).pgm";
//////////////////////////////////////////////////

char outputFileName3_33b[] = "Fig0333(b).pgm";
char outputFileName3_33c[] = "Fig0333(c).pgm";
char outputFileName3_33d[] = "Fig0333(d).pgm";
char outputFileName3_33e[] = "Fig0333(e).pgm";
char outputFileName3_33f[] = "Fig0333(f).pgm";
////////////////////////////////////////////////

// gama değerlerine göre çıktı alındı gama<1
char outputFileName3_8_6[] = "Fig0308(b).pgm";
char outputFileName3_8_4[] = "Fig0308(c).pgm";
char outputFileName3_8_3[] = "Fig0308(d).pgm";

// gama değerlerine göre çıktı alındı gama>1
char outputFileName3_9_3[] = "Fig0309(b).pgm";
char outputFileName3_9_4[] = "Fig0309(c).pgm";
char outputFileName3_9_5[] = "Fig0309(d).pgm";
//////////////////////////////////////////
char outputFileName3_35b[] = "Fig0335(b).pgm";
char outputFileName3_35c[] = "Fig0335(c).pgm";


///////////////////////////////////////////////////////////
// FIGURE 3.4 İÇİN
 // read the input fig3.4
inputImage3_4.readImage(inputFileName3_4);

outputImage3_4 =inputImage3_4._ImageNegatives();
outputImage3_4.writeImage(outputFileName3_4);

// FIGURE 3.5 İÇİN
/////// fig3.5
inputImage3_5.readImage(inputFileName3_5);
outputImage3_5=inputImage3_5._ImageLog();
outputImage3_5.writeImage(outputFileName3_5);



// FIGURE 3.8 İÇİN
/////// fig3.8
inputImage3_8.readImage(inputFileName3_8);
// gama is equal to 0.6
outputImage3_8_6=inputImage3_8._ImageGama(0.6);
outputImage3_8_6.writeImage(outputFileName3_8_6);
// gama is equal to 0.4
outputImage3_8_4=inputImage3_8._ImageGama(0.4);
outputImage3_8_4.writeImage(outputFileName3_8_4);
// gama is equal to 0.3
outputImage3_8_3=inputImage3_8._ImageGama(0.3);
outputImage3_8_3.writeImage(outputFileName3_8_3);


// FIGURE 3.9 İÇİN
/////// fig3.9
inputImage3_9.readImage(inputFileName3_9);
// gama is equal to 3
outputImage3_9_3=inputImage3_9._ImageGama_BiggerThanOne(3);
outputImage3_9_3.writeImage(outputFileName3_9_3);
// gama is equal to 4
outputImage3_9_4=inputImage3_9._ImageGama_BiggerThanOne(4);
outputImage3_9_4.writeImage(outputFileName3_9_4);
// gama is equal to 5
outputImage3_9_5=inputImage3_9._ImageGama_BiggerThanOne(5);
outputImage3_9_5.writeImage(outputFileName3_9_5);


// FIGURE 3.33 İÇİN
// fig3.33b
inputImage3_33.readImage(inputFileName3_33);
outputImage3_33b =inputImage3_33._Average_Filter(3);
outputImage3_33b.writeImage(outputFileName3_33b);

// fig3.33c
outputImage3_33c =inputImage3_33._Average_Filter(5);
outputImage3_33c.writeImage(outputFileName3_33c);

// fig3.33d
outputImage3_33d =inputImage3_33._Average_Filter(9);
outputImage3_33d.writeImage(outputFileName3_33d);


// fig3.33f
outputImage3_33e =inputImage3_33._Average_Filter(15);
outputImage3_33e.writeImage(outputFileName3_33e);

// fig3.33g
outputImage3_33f =inputImage3_33._Average_Filter(35);
outputImage3_33f.writeImage(outputFileName3_33f);


// FIGURE 3.35 İÇİN
// fig3.35b
inputImage3_35.readImage(inputFileName3_35);
outputImage3_35b =inputImage3_35._Average_Filter(3);
outputImage3_35b.writeImage(outputFileName3_35b);

// fig3.35c
outputImage3_35c =inputImage3_35._Median_Filter(3);
outputImage3_35c.writeImage(outputFileName3_35c);

/////////////////////////////////////////////// 1. SORU BİTİŞİ //////////////////////////////////////////////
*/
////////////////////////// 2. SORU BAŞLANGICI ///////////////////////////////////////////////////7

Image Karanlik_Goruntu;
Image Aydinlik_Goruntu;
Image LowConstrast_1 ;
Image LowConstrast_2;

Image outputLowContrast_1;
Image outputLowContrast_2;
Image outputKaranlik_Goruntu_gama;
Image outputKaranlık_Goruntu_log;
Image outputKaranlık_Goruntu_Ortanca;


Image outputAydinlik_Goruntu_log;

///////////////////////////////////////////////////////////////////
char input_Karanlik_Goruntu[] = "Fig0323(a)(mars_moon_phobos).pgm";
char input_Aydinlik_Goruntu [] = "brightness_1.pgm";
char input_LowContrast_1 [] ="LowConstrast.pgm";
char input_LowContrast_2 [] ="low_constrast2.pgm";
////////////////////////////////////////////////////
char output_Karanlik_Goruntu_gama[] = "output_Karanlik_Goruntu_gama.pgm";
char output_Karanlik_Goruntu_log[] = "output_Karanlik_Goruntu_log.pgm";
char output_Karanlik_Goruntu_Ortanca[] = "output_Karanlik_Goruntu_ortanca.pgm";
char output_Aydinlik_Goruntu_log[] ="output_Aydinlik_goruntu_log.pgm";

char output_LowContrast_1 [] ="output_LowContrast_1.pgm";
char output_LowContrast_2 [] ="output_LowContrast_2.pgm";

/////////////////////////////////////////////////////
Karanlik_Goruntu.readImage(input_Karanlik_Goruntu);

outputKaranlik_Goruntu_gama=Karanlik_Goruntu._ImageGama(0.3);
outputKaranlik_Goruntu_gama.writeImage(output_Karanlik_Goruntu_gama);

outputKaranlık_Goruntu_log=Karanlik_Goruntu._ImageLog();
outputKaranlık_Goruntu_log.writeImage(output_Karanlik_Goruntu_log);

outputKaranlık_Goruntu_Ortanca=Karanlik_Goruntu._Median_Filter(3);
outputKaranlık_Goruntu_Ortanca.writeImage(output_Karanlik_Goruntu_Ortanca);
/////////////////////////////////////////////////////

Aydinlik_Goruntu.readImage(input_Aydinlik_Goruntu);
outputAydinlik_Goruntu_log=Aydinlik_Goruntu._ImageGama_BiggerThanOne(5);
outputAydinlik_Goruntu_log.writeImage(output_Aydinlik_Goruntu_log);

/////////////////////////////////////////////////////////
LowConstrast_1.readImage(input_LowContrast_1);
outputLowContrast_1=LowConstrast_1._ImageGama(0.3);
outputLowContrast_1.writeImage(output_LowContrast_1);

LowConstrast_2.readImage(input_LowContrast_2);
outputLowContrast_2=LowConstrast_2._ImageGama_BiggerThanOne(3);
outputLowContrast_2.writeImage(output_LowContrast_2);

}
