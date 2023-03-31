/**************************************
 The original copy of the code can be found at http://web.eecs.utk.edu/~mkarakay/courses_files/testfiles.zip
 and it is modified for ELM463/667
 **************************************/

#include "Image.h"
#include <math.h>
using namespace std;
/*
Ömer Cebeci 171024007
Ödev-2

Main içerisinde kullanılan bütün fonksiyonların detaylı açıklamaları Image.cpp içerisinde verilmiştir.
LAB İÇİN YAZILAN BÜTÜN FONKSİYONLAR Image.cpp İÇERİSİNDE EN ALT KISIMDA YER ALMAKTADIR.

*/
int main(int argc, char **argv)
{
Image input ;

Image output ;
char inputFilename[]="Fig0424(a)(rectangle).pgm";
char outputFilename[]="output2.pgm";

input.readImage(inputFilename);
output=input.Fourier_Transform();
output=output._ImageLog();
output.writeImage(outputFilename,true);


}
