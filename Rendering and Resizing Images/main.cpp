/**************************************
 The original copy of the code can be found at http://web.eecs.utk.edu/~mkarakay/courses_files/testfiles.zip
 and it is modified for ELM463/667
 **************************************/

#include "Image.h"

using namespace std;

int main(int argc, char **argv)
{
  ///////// 1. SORU İÇİN //////////////////////////////////////////////////////////////
  Image image(10,15) ; // 10 satır 15 sütundan oluşan image objesi oluşturuldu
  char output_filename_soru1 [] = "soru_1_cikti.pgm";  // görüntünün incelenmesi için çıktı dosya ismi atandı
  image.Adjust_Image();

  image.writeImage(output_filename_soru1);

  ///////////////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////2. SORU İÇİN //////////////////////////////////////////
  Image image_soru2 ;
  Image image_output;
  char input_filename [] = "Test_image.pgm";  // input görüntüsünü almak için oluşturuldu
  char output_filename_soru2_1 [] = "output_image_soru2.1.pgm"; // çıktı görüntüsünü almak için oluşturuldu.
  char output_filename_soru2_2 [] = "output_image_soru2.2.pgm"; // çıktı görüntüsünü almak için oluşturuldu.

  image_soru2.readImage(input_filename); // Orijinal görüntü okundu

  image_output=image_soru2.Change_Dimension(0); // Görüntünün boyutları büyütüldü
  image_output.writeImage(output_filename_soru2_1); // Boyutları büyütülen görüntü dosyaya yazıldı
  image_output=image_soru2.Change_Dimension(1);  // Görüntünün boyutları küçültüldü
  image_output.writeImage(output_filename_soru2_2); // Boyutları küçültülen görüntü bastırıldı.
}
