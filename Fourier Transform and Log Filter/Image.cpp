/**********************************************************
 The original copy of the code can be found at http://web.eecs.utk.edu/~mkarakay/courses_files/testfiles.zip
 and it is modified for ELM463/667

 * Image.cpp - the image library which implements
 *             the member functions defined in Image.h
 *
 * Author: Hairong Qi, ECE, University of Tennessee
 *
 * Created: 02/05/02
 *
 * Copyright (C) hqi@utk.edu
 **********************************************************/

#include "Image.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>  // LAB3 için eklendi
//#include <bits/stdc++.h>
using namespace std;
#define pi 3.141592
/**
 * Default constructor.
 */
Image::Image() {
  image = NULL;
  nrows = 0;
  ncols = 0;
  maximum = 255;
  //createImage(0, 0);
}

/**
 * Constructor for grayscale images.
 * @param nrows Numbers of rows (height).
 * @param ncols Number of columns (width).
 * @return The created image.
 */
Image::Image(int nRows, int nCols) {
  if (nRows<=0 || nCols<=0) {
    cout << "Image: Index out of range.\n";
    exit(3);
  }
  image = NULL;
  createImage(nRows, nCols);
}

/**
 * Copy constructor.
 * @param img Copy image.
 * @return The created image.
 */
Image::Image(const Image &img) {
  int rows, cols;

  image = NULL;
  nrows = img.getRow();
  ncols = img.getCol();
  createImage(nrows, ncols);             // allocate memory

  for (rows=0; rows < nrows; rows++)
    for (cols=0; cols < ncols; cols++)
		image[rows * ncols + cols] = img(rows, cols);
}

/**
 * Destructor.  Frees memory.
 */
Image::~Image() {
  if (image)
    delete [] image;       // free the image buffer
}






/**
 * Allocate memory for the image and initialize the content to be 0.
 */
void Image::createImage() {

  if (image != NULL)
    delete [] image;

  maximum = 255;

  image = (float *) new float [nrows * ncols];
  if (!image) {
    cout << "CREATEIMAGE: Out of memory.\n";
    exit(1);
  }

  initImage();
}


/**
 * Allocate memory for the image and initialize the content to be zero.
 * @param r Numbers of rows (height).
 * @param c Number of columns (width).
 */
void Image::createImage(int numberOfRows, int numberOfColumns) {

  if (image != NULL)
    delete [] image;

  nrows = numberOfRows;
  ncols = numberOfColumns;
  maximum = 255;

  image = (float *) new float [nrows * ncols];
  if (!image) {
    cout << "CREATEIMAGE: Out of memory.\n";
    exit(1);
  }

  initImage();
}

/**
 * Initialize the image.
 * @para init The value the image is initialized to. Default is 0.0.
 */
void Image::initImage(float initialValue) {
  int i;

  for (i = 0; i < nrows * ncols; i++)
    image[i] = initialValue;
}

/**
 * Returns the total number of rows in the image.
 * @return Total number of rows.
 * \ingroup getset
 */
int Image::getRow() const {
  return nrows;
}

/**
 * Returns the total number of columns in the image.
 * @return Total number of columns.
 * \ingroup getset
 */
int Image::getCol() const {
  return ncols;
}

/**
 * Returns the maximum pixel value of a gray-level image.
 * @return The intensity of that pixel.
 * \ingroup getset
 */
float Image::getMaximum() const {
  int i, j;
  float maxi=-10000;


  for (i=0; i<nrows; i++)
    for (j=0; j<ncols; j++)
      if (maxi < image[i*ncols+j])
	maxi = image[i*ncols+j];

  return maxi;
}


/**
 * Returns the minimum pixel value of the image.
 * @return The minimum pixel value.
 * \ingroup getset
 */
float Image::getMinimum() const {
  int i, j;
  float mini=10000;

  for (i=0; i<nrows; i++)
    for (j=0; j<ncols; j++)
      if (mini > image[i*ncols+j])
	mini = image[i*ncols+j];

  return mini;
}



/**
 * Returns the pixel value at rows, cols
 * @return The pixel value
 * \ingroup getset
 */
float Image::getPix(int rows, int cols) {
  return image[rows * ncols + cols];
}


/**
 * Returns the image.
 * @return a gray-scale image
 * \ingroup getset
 */
Image Image::getImage() const {
  Image temp;
  int rows, cols;

  temp.createImage(nrows, ncols);   // temp is a gray-scale image
  for (rows = 0; rows < nrows; rows++)
    for (cols = 0; cols < ncols; cols++)
      temp(rows, cols) = image[rows * ncols + cols];

  return temp;
}

/**
 * Sets the total number of rows in an image.
 * @param r Total number of rows.
 * \ingroup getset
 */
void Image::setRow(int numberOfRows) {
  nrows = numberOfRows;
}

/**
 * Sets the total number of columns in an image.
 * @param c Total number of columns.
 * \ingroup getset
 */
void Image::setCol(int numberOfColumns) {
  ncols = numberOfColumns;
}


/**
 * Sets the pixel value at rows,cols.
 * @param row and col index.
 * \ingroup getset
 */
void Image::setPix(int rows, int cols, float value) {
  image[rows * ncols + cols] = value;
}


/**
 * Sets the image given a grayscale image.
 * \ingroup getset
 */
void Image::setImage(Image &img) {
  int rows, cols;

  for (rows = 0; rows < nrows; rows++)
    for (cols = 0; cols < ncols; cols++)
      image[rows * ncols + cols] = img(rows, cols);
}

/**
 * Overloading () operator
 * \ingroup overload
 * @param i Row
 * @param j Column
 */
float & Image::operator()(int rows, int cols) const {
  return image[rows * ncols + cols];
}

/**
 * Overloading = operator.
 * \ingroup overload
 * @param img Image to copy.
 * @return Newly copied image.
 */
const Image Image::operator=(const Image& img) {
  int rows, cols;

  if (this == &img)
    return *this;

  nrows = img.getRow();
  ncols = img.getCol();
  createImage(nrows, ncols);

  for (rows = 0; rows < nrows; rows++)
    for (cols = 0; cols < ncols; cols++)
	(*this)(rows, cols) = img(rows, cols);

  return *this;
}

/**
 * Overloading + operator.
 * \ingroup overload
 * @param img Image to add to specified image.
 * @return Addition of the two images.
 */
Image Image::operator+(const Image& img) const {
  int i, j, nr, nc;
  Image temp;

  nr = img.getRow();
  nc = img.getCol();

  if (nr != nrows || nc != ncols) {
    cout << "operator+: "
         << "Images are not of the same size or type, can't do addition\n";
    exit(3);
  }
  temp.createImage(nrows, ncols);

  for (i=0; i<nrows; i++)
    for (j=0; j<ncols; j++)
        temp(i,j) = image[i*ncols+j] + img(i,j);

  return temp;
}

/**
 * Overloading - operator.
 * \ingroup overload
 * @param img Image to subtract from specified image.
 * @return Subtraction of the two images.
 */
Image Image::operator-(const Image &img) const {
   int i, j, nr, nc;
  Image temp;

  nr = img.getRow();
  nc = img.getCol();

  if (nr != nrows || nc != ncols) {
    cout << "operator-: "
         << "Images are not of the same size or type, can't do subtraction\n";
    exit(3);
  }
  temp.createImage(nrows, ncols);

  for (i=0; i<nrows; i++)
    for (j=0; j<ncols; j++)
        temp(i,j) = image[i*ncols+j] - img(i,j);

  return temp;
}

/**
 * Overloading * operator.  This function does pixel by pixel multiplication.
 * \ingroup overload
 * @param img Image to multiply with specified image.
 * @return Multiplication of the two images.
 */
Image Image::operator*(const Image &img) const {
  int i, j, nr, nc;
  Image temp;

  nr = img.getRow();
  nc = img.getCol();

  if (nr != nrows || nc != ncols) {
    cout << "operator*: "
         << "Images are not of the same size or type, can't do multiplication\n";
    exit(3);
  }
  temp.createImage(nrows, ncols);

  for (i=0; i<nrows; i++)
    for (j=0; j<ncols; j++)
        temp(i,j) = image[i*ncols+j] * img(i,j);

  return temp;
}

/**
 * Overloading / operator.  This function does pixel by pixel division.
 * Specified image is the dividend.
 * \ingroup overload
 * @param img Image to be divided (divisor).
 * @return Quotient of the two images.
 */
Image Image::operator/(const Image &img) const {
  int i, j, nr, nc;
  Image temp;

  nr = img.getRow();
  nc = img.getCol();

  if (nr != nrows || nc != ncols) {
    cout << "operator/: "
         << "Images are not of the same size or type, can't do division\n";
    exit(3);
  }
  temp.createImage(nrows, ncols);

  for (i=0; i<nrows; i++)
    for (j=0; j<ncols; j++)
        temp(i,j) = image[i*ncols+j] / ( img(i,j) + 0.001 );

  return temp;
}


/**
 * Overloading << operator.  Output the image to the specified destination.
 * \ingroup overload
 * @param out The specified output stream (or output destination).
 * @param img Image to be output.
 * @result Output image to the specified file destination.
 */
ostream & operator<<(ostream &out, Image &img) {
  int rows, cols;


    for (rows = 0; rows < img.getRow(); rows++) {
      for (cols = 0; cols < img.getCol(); cols++)
        out << setw(4) << img(rows, cols) << ' ';
      out << endl;
    }

  return out;
}

/**
 * Overloading / operator.  The left operand is the image and the right
 * is the dividend (a double point number). Each pixel in the image is
 * divided by the double point number.
 * \ingroup overload
 * @param img Image as the left operand.
 * @param val A double point number as the right operand.
 * @result Image divided by a double point number.
 */
Image operator/(Image &img, double val) {
  int i, j, nr, nc;
  Image temp;

  nr = img.getRow();
  nc = img.getCol();
  temp.createImage(nr, nc);

  for (i=0; i<nr; i++)
    for (j=0; j<nc; j++)
        temp(i,j) = img(i,j) / val;

  return temp;
}

/**
 * Overloading * operator.  The left operand is the image and the right
 * is a double point number. Each pixel in the image is multiplied by the
 * double point number.
 * \ingroup overload
 * @param img Image as the left operand.
 * @param s A double point number as the right operand.
 * @result Image multiplied by a double point scalar.
 */
Image operator*(Image &img, double s) {
  int i, j, nr, nc;
  Image temp;

  nr = img.getRow();
  nc = img.getCol();
  temp.createImage(nr, nc);

  for (i=0; i<nr; i++)
    for (j=0; j<nc; j++)
        temp(i,j) = img(i,j) * s;

  return temp;
}


/**
 * Overloading + operator.  The left operand is the image and the right
 * is a double point number. Each pixel in the image is added by the
 * double point number.
 * \ingroup overload
 * @param img Image as the left operand.
 * @param s A double point number as the right operand.
 * @result Image add a double point scalar.
 */
Image operator+(Image &img, double s) {
  int i, j, nr, nc;
  Image temp;

  nr = img.getRow();
  nc = img.getCol();
  temp.createImage(nr, nc);

  for (i=0; i<nr; i++)
    for (j=0; j<nc; j++)
        temp(i,j) = img(i,j) + s;

  return temp;
}

/**
 * Overloading - operator.  The left operand is the image and the right
 * is a double point number. Each pixel in the image is subtracted by the
 * double point number.
 * \ingroup overload
 * @param img Image as the left operand.
 * @param s A double point number as the right operand.
 * @result Image subtract a double point scalar.
 */
Image operator-(Image &img, double s) {
  int i, j, nr, nc;
  Image temp;

  nr = img.getRow();
  nc = img.getCol();
  temp.createImage(nr, nc);

  for (i=0; i<nr; i++)
    for (j=0; j<nc; j++)
        temp(i,j) = img(i,j) - s;

  return temp;
}

/**
 * Read image from a file
 * @param fname The name of the file
 * @return An Image object
 */
  void Image::readImage(char *fname) {
  ifstream ifp;
  char dummy[80];
  unsigned char *img;
  int rows, cols;
  int nRows, nCols, nt, maxi;

  ifp.open(fname, ios::in | ios::binary);

  if (!ifp) {
    cout << "readImage: Can't read image: " << fname << endl;
    exit(1);
  }

  // identify image format
  ifp.getline(dummy, 80, '\n');

  if (dummy[0] == 'P' && dummy[1] == '5')
     ;
  else {
    cout << "readImage: Can't identify image format." << endl;
    exit(1);
  }

  // skip the comments
  ifp.getline(dummy, 80, '\n');

  while (dummy[0] == '#') {
    ifp.getline(dummy, 80, '\n');
  }

  // read the row number and column number
  sscanf(dummy, "%d %d", &nCols, &nRows);

  // read the maximum pixel value
  ifp.getline(dummy, 80, '\n');
  sscanf(dummy, "%d", &maxi);
  if (maxi > 255) {
    cout << "Don't know what to do: maximum value is over 255.\n";
    exit(1);
  }

  if (image != NULL)
  delete [] image;

  nrows = nRows;
  ncols = nCols;
  maximum = 255;

  // read the image data
  img = (unsigned char *) new unsigned char [nRows * nCols];
  if (!img) {
    cout << "READIMAGE: Out of memory.\n";
    exit(1);
  }
  image = (float *) new float [nRows * nCols];
  if (!image) {
    cout << "READIMAGE: Out of memory.\n";
    exit(1);
  }

    ifp.read((char *)img, (nRows * nCols * sizeof(unsigned char)));

    for (rows = 0; rows < nRows; rows++)
      for (cols = 0; cols < nCols; cols++)
          image[rows * nCols + cols] = (float) img[rows * nCols + cols];

  ifp.close();

  delete [] img;
}


/**
 * Write image buffer to a file.
 * @param fname The output file name.
 */
void Image::writeImage(char *fname, bool flag) {
  ofstream ofp;
  int i, j;
  int nRows, nCols, nt;
  unsigned char *img;

  ofp.open(fname, ios::out | ios::binary);

  if (!ofp) {
    cout << "writeImage: Can't write image: " << fname << endl;
    exit(1);
  }


  ofp << "P5" << endl;
  ofp << ncols << " " << nrows << endl;


  ofp << 255 << endl;



  // convert the image data type back to unsigned char
  img = (unsigned char *) new unsigned char [nrows * ncols];
  if (!img) {
    cout << "WRITEIMAGE: Out of memory.\n";
    exit(1);
  }

  float maxi = getMaximum();
  float mini = getMinimum();


    for (i = 0; i< nrows; i++)
      for (j = 0; j < ncols; j++) {
	  // rescale if the flag is set
	  if ((maxi != mini) && flag == true)
	    img[i * ncols + j] = (unsigned char)  ((image[i * ncols + j]-mini)/(float)(maxi-mini)*255.0);
	  // any intensity that is larger than the maximum would be set as maximum
	  else if (image[i * ncols + j] > 255)
	    img[i * ncols + j] = 255;
	  else if (image[i * ncols + j] < 0)
	    img[i * ncols + j] = 0;
	  else
	    img[i * ncols + j] = (unsigned char)  image[i * ncols + j];
      }

    ofp.write((char *)img, (nrows * ncols * sizeof(unsigned char)));


  ofp.close();
  delete [] img;
}




// YOUR FUNCTIONS

/**
 * Returns the image.
 * @return a gray-scale image
 * \ingroup getset
 */
Image Image::thresholdImage(float thresholdValue, float lowValue, float highValue) {
  Image temp;
  int rows, cols;

  temp.createImage(nrows, ncols);   // temp is a gray-scale image
  for (rows = 0; rows < nrows; rows++)
    for (cols = 0; cols < ncols; cols++)
      if (image[rows * ncols + cols] <= thresholdValue)
	temp(rows, cols) = lowValue;
      else
	temp(rows, cols) = highValue;


  return temp;
}
////////////////////////////////////////////////////////////////////// Lab için yazılan fonksiyonlar

///////////////// 1. SORU İÇİN /////////////////////////////////
void Image::Adjust_Image() {
    int i,j;
    setPix(0,0,50); // föyde istenildiği gibi en soldaki pixel değeri 50 olarak atandı

    /* İlk satır oluşturuldu */
    for(i=1; i<3; i++)
    {
        setPix(0,i,50+i);
    }

    /* İlk sütun oluşturuldu*/
    for(i=1; i<10; i++)
    {
        setPix(i,0,50+i);
    }


    /* İlk satır ve ilk sütun dışında kalan pixel değerleri belirlendi*/
    for(i=0; i<10; i++)
    {
        for(j=0; j<15; j++)
        {
            setPix(i,j,getPix(i,0)+j); // her satırda bulunan pixel değeri ilk sütundaki pixel değeri (image.getPix(i,0)) ve yer bilgisine (j) göre oluşturuldu
        }

    }
}
////////////////////////////////////////2. SORU İÇİN /////////////////////////////////////////
/*
Fonksiyon tam sayı bir değeri girdi olarak alır. Bu girdi 0 ise görüntünün boyutu
iki kat büyüyecek girdi 1 ise görüntünün boyutu iki kat küçülecek anlamına gelir.
*/
/*
Fonksiyonun Çalışma mantığı:
görüntünün boyutları arttırılmak istendiğinde normal boyuttaki görüntünün pixel değerleri birden çok kez kullanılmıştır. Örneğin (0,2)
koordinatlarındaki pixel değeri, (0,3) (0,2),(2,1) ve (1,2) pixel değerlerine yazılmıştır. Bu sayede görüntünün boyutları büyütülmüşütür.

Görüntünün boyutları azaltılmak istenilidğinde, oluşturulacak görüntünün daha az pixel değerine sahip olacağı için orijinal
görüntüdeki bazı pixel değerleri atlanarak alınmıştır.

*/

Image Image::  Change_Dimension(int a) {
    int i=0,j=0;
    int x,y;

    if(a==0) {
       Image image_out (getRow()*2 ,getCol()*2); // boyutları orijinalinden iki kat fazla olan obje oluşturuldu
        for(x=0;x<getRow();x=x+1) {
                for(y=0;y<getCol();y=y+1) {
                    /* Yukarıdaki açıklamada bahsedilen ilgili pixel koordinatlarının doldurulması  */
                    image_out.setPix(i,j,getPix(x,y)); // pixel değerinin koyulması hedeflenen asıl yeri
                    image_out.setPix(i,j+1,getPix(x,y)); // pixel değerinin asıl koyulması gereken koordinatın bir sağı
                    image_out.setPix(i+1,j,getPix(x,y)); //ixel değerinin asıl koyulması gereken koordinatın bir satır aşağısı
                    if(i!=0) // (0,0) koordinatı ise 4 farklı koordinatı doldurmaya gerek yoktur. Bu if (0,0) pixel koordinatını kontrol etmek için vardır.
                        image_out.setPix(i+1,j-1,getPix(x,y)); //ixel değerinin asıl koyulması gereken koordinatın sol çaprazı
                    j=j+2;
                }
            i=i+2;
            j=0;
        }
       return image_out;
    }

    else  {
        Image image_out (getRow()/2 ,getCol()/2);// boyutları orijinalinden iki kat küçük (yarısı kadar) olan obje oluşturuldu
        for(x=0;x<getRow();x=x+2) { // orijinal görüntüden pixel değerleri bir atlanarak alınacağı için x ve y artışı 2'şer 2'şer yapılmıştır.
                for(y=0;y<getCol();y=y+2) {
                    /* Yukarıda bahsedildiği gibi ilgili pixel koordinat değerleri orijinal görüntüden alınmıştır. Fakat orijinal görüntüden bazı pixel değerleri alınmamıştır (Boyut küçüldüğü için). */
                    image_out.setPix(i,j,getPix(x,y));
                    j=j+1;
                }
            i=i+1;
            j=0;
        }
    return image_out;
    }

}
/////////////////////////////////////////////////// LAB-1 FONKSİYONLARI /////////////////////////////////////////////////////////////
/*
_ImageNegatives Fonksiyonu: Bu fonksiyon giriş görüntüsünün pixel değerlerinin tam tersini alır belirli koordinatta ki pixel değeri r ise bu fonksiyon
sonunda bu koordinattaki güncel pixel değeri 255-r olacaktır.

*/
Image Image:: _ImageNegatives() {
    int i ,j;
    Image temp(getRow(),getCol());
    /* Her koordinattaki pixel değerinin tersi alınır*/
    for (i=0;i<getRow();i++) {
        for(j=0;j<getCol();j++) {
            temp.setPix(i,j,(255-getPix(i,j)));
        }
    }
/* return değeri olarak bir Image objesi döndürür. */
return temp ;
}

/*
_ImageLog() fonksiyonu:
görüntü üzerinde pixel değerlerini ayrı ayrı iyileştirir. Bu iyileştirme işlemeni logaritma fonksiyonu ile yapar.
s= c*log10(r)
s değerleri logaritma alındığı için doğal olarak çok küçük bir aralıkta değişme gösterecektir. Bunun için görüntü pizel değerlerini
(0-255) arasında ölçeklendirmek gerekir.c katsayısı 1 olarak alınmıştır.

 */
Image Image:: _ImageLog() {
    int i ,j;
    int c =1 ;
    Image temp(getRow(),getCol());
    for (i=0;i<getRow();i++) {
        for(j=0;j<getCol();j++) {
            temp.setPix(i,j,(255/2.4)*(c*log10(getPix(i,j)+1))); // log fonksiyonu uygulanması ve ölçekleme işleminin yapılması
        }
    }

return temp ;
}
/*
 _ImageGama Fonksiyonu: Giriş görüntüsünün her bir pixel değerini ayrı ayrı r=c* (r^gama) formulü aracılığyla
 günceller. c katsayısı 1 olarak alınmıştır. Gama değeri ise girdi olarak alınmıştır. Girilecek gama değeri 0<gama<1 aralığında
 olmak zorundadır. Formül sonucunda elde edilen değerler 0-255 aralığında ölçeklendirilmiştir.

*/
Image Image:: _ImageGama(double gama ) {
    int i ,j; // döngü değişkenleri
    int c =1 ; // formül için katsayı değeri
    int scale_value; // ölçek katsayısı
    /* Ölçek katsayısının yuvarlama işleminin gerçekleştirilmesi */
    if(gama==0.6)
        scale_value=28;  // 27.79 yuvarlandı
    else if (gama==0.4)
        scale_value=9; // 9.17 yuvarlandı
    else
        scale_value=5; // 5.27 den yuvarlandı

    /*Döndürülecek obje giriş görüntüsünün satır ve sütun sayılarına göre oluşturuldu */
    Image temp(getRow(),getCol());

    for (i=0;i<getRow();i++) {
        for(j=0;j<getCol();j++) {
            temp.setPix(i,j,(255/scale_value)*(c*pow(getPix(i,j),gama))); // yeni pixel değerinin gamalı formüle göre oluşturulması
        }
    }

return temp ;
}
/*
Bir önceki fonksiyon ile tamamen aynı işlem ve aynı formül uygulanmaktadır sadece bu fonksiyona girilecek gama değerinin 1 den büyük
olması gerekmektedir.
*/
Image Image:: _ImageGama_BiggerThanOne(double gama ){
    int i ,j;
    int c =1 ;
    double scale_value;  // uint64 iken çalışmadı neden acaba? (ölçeklendirme kat sayısının double olarak tanımlanması önemli)

    if(gama==3)
        scale_value=16581375;
    else if (gama==4)
        scale_value=4228250625;
    else
        scale_value=1078203903000;

    Image temp(getRow(),getCol());

    for (i=0;i<getRow();i++) {
        for(j=0;j<getCol();j++) {
            temp.setPix(i,j,(255/scale_value)*(c*pow(getPix(i,j),gama))); // yeni pixel değerinin gamalı formüle göre oluşturulması
        }
    }
return temp ;
}

/*
Kullanıcının gireceği sayıya göre bir filtre oluşturur. Bu filtreyi her bir pixel değeri ve pixel değerlerinin komşularına uygular.
Filtre uygulandığı pixel değerlerinin ortalamasını alır ve değiştirmesi gereken pixel değerini bu bulduğu ortalama değer ile günceller.

*/


Image Image:: _Average_Filter (int a) {

   Image temp(getRow(),getCol()) ; // yeni görüntü için obje oluşturuldu



   int filter [a][a]; // filtre girilen a değerine göre oluşturuldu
   int i,j ; // görüntü dönecek
   int x,y;  // filtre için
   int k,m;
   int l,n;
   int gecici_toplam=0; // filtrede bulunan pixel değerlerinin toplanması için.
    /*k ve m değerleri filtre arrayinin değerlerinin doldurulması için kullanılmıştır. */
   k= (-1)*((a-1)/2);
   m=(-1)*((a-1)/2);
    /* pixel(i,j) değeri filtrenin ortasına yerleştirmiştir. 5x5 lik bir filtrede örneğin 2,2 pixel koordinatı oluyor
        filtrenin geri kalan koordinatlarını doldurabilmek için iki adet for döngüsü daha yapılmıştır. k ve m değerlerinde güncellemeler
        yapılarak bu işlem sağlanmıştır.Doldurulan filtre koordinatlarındaki değerler daha sonra toplanıp ortalamaları alınmıştır.
    */
   for(i=0;i<getRow();i++){
        for(j=0;j<getCol();j++){
            for(x=0;x<a;x++){
                for(y=0;y<a;y++){
                    if((i+k)<0 || (i+k)>getRow() || (j+m)<0 || (j+m)> getCol()) // köşe veya filtrenin boyutlarına göre ,filtre görüntünün dışına taşabilir. Böyle durumlarda filtre koordinatına 0 değeri yazılmıştır.
                        filter[x][y]=0;
                    else // herhangi bir taşma yoksa ilgili koordinatta görüntünün pixel değeri mevcutsa else e girer.
                        filter[x][y]=getPix(i+k,j+m);
                    m=m+1;
                }
                m=(-1)*((a-1)/2);
                k=k+1;
            }
          k= (-1)*(a-1)/2;
          m= (-1)*(a-1)/2;
          /*Filtre pixel değerlerinin toplanması */
          for(l=0;l<a;l++)
              for(n=0;n<a;n++){
                gecici_toplam=gecici_toplam+filter[l][n];
              }
            //////////////////////////////////////
            /*filtre pixel değerlerinin ortalaması alınarak ilgili pixel değerinin güncellenmesi */
          temp.setPix(i,j,(int)(gecici_toplam/(a*a)));
          gecici_toplam=0; // bir sonraki işlemler için bu değer sıfırlanmalıdır.
        }

   }

 return temp;
}
/*
_Median_Filter fonksiyonu: Bir önceki fonksiyondan tek farkı filtrede bulunan değerlerinin ortalamsını alarak değilde ortanca değerini alarak
pixel değerini günceller.
*/


Image Image:: _Median_Filter(int a ) {
    ////////////////////////////////////////////////////////////   (//) bu çizgiler arasında kalan işlemlerin açıklamaları bir önceki fonksiyondayapılmıştır. Aynı işlemler olduğu için yeniden yorum eklenmemiştir.
    Image temp(getRow(),getCol()) ; // yeni görüntü için

    int filter [a][a]; // filtre girilen a değerine göre oluşturuldu
    int i,j ; // görüntü dönecek
    int x,y;  // filtre için
    int k,m;
    int l,n;
    int gecici_array[a*a];
    int gecici_array_sayac=0;
    int gecici_deger;
    k= (-1)*((a-1)/2);
    m=(-1)*((a-1)/2);

    for(i=0; i<getRow(); i++)
    {
        for(j=0; j<getCol(); j++)
        {
            for(x=0; x<a; x++)
            {
                for(y=0; y<a; y++)
                {
                    if((i+k)<0 || (i+k)>getRow() || (j+m)<0 || (j+m)> getCol())
                        filter[x][y]=0;
                    else
                        filter[x][y]=getPix(i+k,j+m);
                    m=m+1;
                }
                m=(-1)*((a-1)/2);
                k=k+1;
            }
            k= (-1)*(a-1)/2;
            m= (-1)*(a-1)/2;
    ///////////////////////////////////////////////////////////
            /* İki boyutlu filte tek boyuta indirgenir */
            for(l=0; l<a; l++)
                for(n=0; n<a; n++)
                {
                    gecici_array[gecici_array_sayac]=filter[l][n];
                    gecici_array_sayac=gecici_array_sayac+1;
                }
            gecici_array_sayac=0; // bir sonraki işlemler için sıfırlanmalı

            // Sıralama işlemi

            for(l=0;l<(a*a);l++){
                for(n=0;n<(a*a)-1;n++) {
                    if(gecici_array[n]>gecici_array[n+1]) {
                        gecici_deger=gecici_array[n];
                        gecici_array[n]=gecici_array[n+1];
                        gecici_array[n+1]=gecici_deger;
                    }
                }
            }

            // sırlama işleminden sonra ortanca değerin yeni pixel koordinatı ile güncellenmesi.
            temp.setPix(i,j,gecici_array[((a*a)-1)/2]); // ortanca değer yeni pixel değeri olarak atanır.

        }

    }

    return temp;

}
////////////////////////////////////////////////// LAB-2 FONKSİYONLARI //////////////////////////////////////////////////////////////
/*
Find_Different_Pixel_Values fonksiyonu bir görüntüde kaç farklı pixel değeri var
onu bulan fonksiyondur fakat bu lab için kullanılmamıştır.
*/

int Image:: Find_Different_Pixel_Values() {
    int sayac=0;
    int x = getCol()*getRow();
    int arr[x];
    int flag=0;
    int i,j,k;
    for(i=0;i<5;i++) {
         arr[i]=-1;
    }

   for(i=0;i<getRow();i++) {
        for(j=0;j<getCol();j++) {
            for(k=0;k<5;k++) {
                if(getPix(i,j)==arr[k]) {
                    flag=1;
                }
            }
            if(flag!=1) {
                arr[sayac]=getPix(i,j);
                sayac++;
            }
            flag=0;

	}
}

return sayac ;
}
/*
Öncelikle h_r pdf ve cdf dizileri oluşturulmuştur. Fonksiyon içerisinde tam sayı olmayan değerler ile
çalışılacağı için her dizi float olarak oluşturulmuştur.
h_r  => her pixel değerinden kaç tane olduğu bilgisini tutar
pdf => her pixel değerinin pdf değerini tutar örneğin pdf[0] demek 0 pixel değerinin pdf'i demek
cdf => her pixel değerinin cdf değerini tutar örneğin cdf[0] demek 0 pixel değerinin cdf'i demek
fonksiyonda diziler doldurulduktan sonra görüntünün pixel değerleri güncelleme işlemi yapılmıştır.
cdf değerleri math kütüphanesindeki round fonksiyonu kullanılarak yuvarlanmıştır.
*/
Image Image:: HistogramEqualization() {

    uint64_t i,j,k; // Döngü değişkenleri

    Image temp (getRow(),getCol()); // Fonlsiyonun döneceği obje oluşturuldu

    float h_r[256]; // her bir pixel değerinden kaç tane olduğu bilgisi saklanacak
    float pdf[256];  // her bir pixel değerinin pdf değeri saklanacak
    float cdf[256];   // her bir pixel değerinin cdf bilgisi saklanacak

    for(i=0;i<256;i++) {  // h_r dizisi için ilk değer ataması yapılıyor
        h_r[i]=0;
    }
   /* her bir pixel değerinden kaç adet olduğu hesaplanır  */
  // h(0) =5 demek 0 dan 5 adet var demek.
    for(i=0;i<getRow();i++) {
        for(j=0;j<getCol();j++) {
            for(k=0;k<256;k++) {
                if(getPix(i,j)==k) {
                    h_r[k]=h_r[k]+1;
                    break;
                }
            }
        }
    }

    /* Her bir pixel değerinin pdf değeri hesaplanır */

    float x =getCol()*getRow();

    for(i=0;i<256;i++) {
        pdf[i]= (float)(h_r[i]/x);
    }
    /* Her bir pixel değerinin cdf değeri hesaplanır ve 256 adet pixel 8 bit ile temsil edildiği için 255 ile çarpılır*/
     double gecici_toplam=0;
     for(i=0;i<256;i++) {
        cdf[i]=gecici_toplam+pdf[i];
        gecici_toplam=gecici_toplam+pdf[i];
        cdf[i]=255*cdf[i];
     }
     for(i=0;i<getRow();i++) {
        for(int j=0;j<getCol();j++) {
            for(k=0;k<256;k++){
                if(k==getPix(i,j)) {
                    temp.setPix(i,j,round(cdf[k]));// cdf değerleri tam sayı olmak zorunda olmadığı için pixel değerleri güncellemesi sırasında yuvarlama işlemi yapılır
                    break;
                }
            }
        }
     }
return temp;

}
/*
SpatialFilters fonksiyonu görüntüyü keskinleştirilmesi için oluşturulmuştur.
LAB'ın 2. sorusunda kullanılmıştır.
Ortlama filtresinde olduğu gibi filtre elemanları her pixel değeri için doldurulmuştur
daha sonra ise laplacian filtresi için uygun katsayılar ile çarpılarak toplanmıştır. yeni pixel değerleri bulunmuştur.

*/
Image Image:: SpatialFilters(int a,int b) {

   Image temp(getRow(),getCol()) ; // yeni görüntü için obje oluşturuldu

   int filter [a][a]; // filtre girilen a değerine göre oluşturuldu
   int i,j ; // görüntü dönecek
   int x,y;  // filtre için
   int k,m;
   int l,n;
   int gecici_toplam=0; // filtrede bulunan pixel değerlerinin toplanması için.
    /*k ve m değerleri filtre arrayinin değerlerinin doldurulması için kullanılmıştır. */
   k= (-1)*((a-1)/2);
   m=(-1)*((a-1)/2);
    /* pixel(i,j) değeri filtrenin ortasına yerleştirmiştir. 5x5 lik bir filtrede örneğin 2,2 pixel koordinatı oluyor
        filtrenin geri kalan koordinatlarını doldurabilmek için iki adet for döngüsü daha yapılmıştır. k ve m değerlerinde güncellemeler
        yapılarak bu işlem sağlanmıştır.Doldurulan filtre koordinatlarındaki değerler daha sonra kendilerine ait katsayılar ile çarpılıp birbirleri
        toplanarak yeni pixel değeri bulunur.
    */

   for(i=0;i<getRow();i++){
        for(j=0;j<getCol();j++){
            for(x=0;x<a;x++){
                for(y=0;y<a;y++){
                    if((i+k)<0 || (i+k)>getRow() || (j+m)<0 || (j+m)> getCol()) // köşe veya filtrenin boyutlarına göre ,filtre görüntünün dışına taşabilir. Böyle durumlarda filtre koordinatına 0 değeri yazılmıştır.
                        filter[x][y]=0;
                    else // herhangi bir taşma yoksa ilgili koordinatta görüntünün pixel değeri mevcutsa else e girer.
                        filter[x][y]=getPix(i+k,j+m);
                    m=m+1;
                }
                m=(-1)*((a-1)/2);
                k=k+1;
            }
          k= (-1)*(a-1)/2;
          m= (-1)*(a-1)/2;
          /*Filtre pixel değerlerinin toplanması */
             if(b==1) //fig3.37a mask
                gecici_toplam=filter[0][0]*0+filter[0][1]*(1)+filter[0][2]*0+filter[1][0]*(1)+filter[1][1]*(-4)+filter[1][2]*(1)+filter[2][0]*0+filter[2][1]*(1)+filter[2][2]*0;
            else if (b==2) // fig3.37b mask için
                 gecici_toplam=filter[0][0]*1+filter[0][1]*(1)+filter[0][2]*1+filter[1][0]*(1)+filter[1][1]*(-8)+filter[1][2]*(1)+filter[2][0]*1+filter[2][1]*(1)+filter[2][2]*1;
            else if(b==3)// fig3.37c mask için
                    gecici_toplam=filter[0][0]*0+filter[0][1]*(-1)+filter[0][2]*0+filter[1][0]*(-1)+filter[1][1]*(4)+filter[1][2]*(-1)+filter[2][0]*0+filter[2][1]*(-1)+filter[2][2]*0;
            else if(b==4) // fig3.37d mask için
                    gecici_toplam=filter[0][0]*(-1)+filter[0][1]*(-1)+filter[0][2]*(-1)+filter[1][0]*(-1)+filter[1][1]*(8)+filter[1][2]*(-1)+filter[2][0]*(-1)+filter[2][1]*(-1)+filter[2][2]*(-1);
            else   // Derste bahsedilen g çıkış fonksiyonu
                   gecici_toplam=filter[0][0]*0+filter[0][1]*(-1)+filter[0][2]*0+filter[1][0]*(-1)+filter[1][1]*(5)+filter[1][2]*(-1)+filter[2][0]*0+filter[2][1]*(-1)+filter[2][2]*0;
            //////////////////////////////////////
            /*filtre pixel değerlerinin ortalaması alınarak ilgili pixel değerinin güncellenmesi */
          temp.setPix(i,j,gecici_toplam);
          gecici_toplam=0; // bir sonraki işlemler için bu değer sıfırlanmalıdır.


        }

   }

 return temp;







}
/*
GaussianFilters fonksiyonu  bir gaussian filtresi uygulamak için tasarlanmıştır.Filtre elemanları
daha önceki filtrelerde yapıldığı gibi belrilenip daha sonra gaussian filtresinin katsayıları ile çarpılarak filtrenin
her bir elemanı toplanmıştır. yeni pixel değeri bu şekilde belirlenmiştir.


*/
Image Image:: GaussianFilters(int a) {
    /* Gaussian Filtresinin katsayılarını bulmak için kullanılan algoritma Geeks for Geeks sitesinden faydalanılarak oluşturulmuştur. */
    // Gaussian Filtresinin standart sapmasının belirlenmesi
    double sigma = 3.0;
    double r, s = 2.0 * sigma * sigma; // filtre katsayıları için gereken formül için kullanılacak değişkenler
    int x,y;  // filtrenin değerlerine erişmek için kullanılmıştır
    double coef[5][5]; // gaussian filtresinin katsayıları bu array de toplanacak.

    double sum = 0.0;



    // Gauss Fİltresinin katsayıları oluşturulacaktır.
    for (int x = -2; x <= 2; x++) {
        for (int y = -2; y <= 2; y++) {
            r = sqrt(x * x + y * y);
            coef[x + 2][y + 2] = (exp(-(r * r) / s)) / (3.14159* s); // Gaussian filtresi katsayılarını üretmek için kullanılan formül.
            sum =sum+ coef[x + 2][y + 2];
        }
    }

    // Oluşturulan katsayılar normalize edilmiştir.
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            coef[i][j] =coef[i][j]/sum;

    ///////////////////////////////////////////////////////////////
    /*Filtrenin iç değerlerinin toplanmaso  */

    Image temp(getRow(),getCol()) ; // yeni görüntü için obje oluşturuldu


   int i,j ; // görüntü dönecek
   int k,m;
   int l,n;
   double gecici_toplam=0; // filtrede bulunan pixel değerlerinin toplanması için.
   double filtre[a][a];
    /*k ve m değerleri filtre arrayinin değerlerinin doldurulması için kullanılmıştır. */
   k= (-1)*((a-1)/2);
   m=(-1)*((a-1)/2);
    /* pixel(i,j) değeri filtrenin ortasına yerleştirmiştir. 5x5 lik bir filtrede örneğin 2,2 pixel koordinatı oluyor
        filtrenin geri kalan koordinatlarını doldurabilmek için iki adet for döngüsü daha yapılmıştır. k ve m değerlerinde güncellemeler
        yapılarak bu işlem sağlanmıştır.Daha sonra Doldurulan filtre değerleri toplanarak güncel pixel değeri elde edilmiştir.
    */
   for(i=0;i<getRow();i++){
        for(j=0;j<getCol();j++){
            for(x=0;x<a;x++){
                for(y=0;y<a;y++){
                    if((i+k)<0 || (i+k)>getRow() || (j+m)<0 || (j+m)> getCol()) // köşe veya filtrenin boyutlarına göre ,filtre görüntünün dışına taşabilir. Böyle durumlarda filtre koordinatına 0 değeri yazılmıştır.
                        filtre[x][y]=0;
                    else // herhangi bir taşma yoksa ilgili koordinatta görüntünün pixel değeri mevcutsa else e girer.
                        filtre[x][y]=coef[x][y]*getPix(i+k,j+m);
                    m=m+1;
                }
                m=(-1)*((a-1)/2);
                k=k+1;
            }
          k= (-1)*(a-1)/2;
          m= (-1)*(a-1)/2;
          /*Filtre pixel değerlerinin toplanması */
          for(l=0;l<a;l++)
              for(n=0;n<a;n++){
                gecici_toplam=gecici_toplam+filtre[l][n];
              }
            //////////////////////////////////////
            temp.setPix(i,j,round(gecici_toplam));


          gecici_toplam=0; // bir sonraki işlemler için bu değer sıfırlanmalıdır.
        }

   }


 return temp;
}
////////////////////////////////////////////////////// LAB 3 İÇİN FONKSİYONLAR  ////////////////////////////////
 /*
 Önce satır için fourier dönüşümü alınacak sonra sütunlar için fourier dönüşümü alınacak
 en son elde edilen görüntünün merkeze shift edilmesi gerçekleştirilcek
 merkeze shift edilme işleminden sonra da normalize edilerek obje döndürülecek
 */

double fast_imag[1024][1024]; // fourier sonucu sanal kisim icin
double fast_real[1024][1024]; // fourier sonucu real kisim icin

double fast_imag_temp[1024][1024];
double fast_real_temp[1024][1024];


 Image Image::Fourier_Transform() {
   	double row=1024;
   	double col=1024;
    Image temp (getRow(),getCol());






	double gecici_toplam_real=0;
	double gecici_toplam_imag=0;


    int u,v,x,y,i,j;
    ////////////////////////
    for(int i=0;i<getRow();i++)
        for(int j=0;j<getCol();j++)
               setPix(i,j,pow(-1,(i+j))*getPix(i,j));




    ///////////////////////////////////////77
    for(x=0;x<row;x++) { //u
        for(v=0;v<col;v++) { // y
			for(y=0;y<col;y++) { // x
				gecici_toplam_real=gecici_toplam_real+getPix(x,y)*cos(2*pi*v*y/col); // real toplama
				gecici_toplam_imag =gecici_toplam_imag +(getPix(x,y)*(-1)*sin(2*pi*v*y/col)); // sanal toplama
			}
				fast_real_temp[x][v] =gecici_toplam_real;
				fast_imag_temp[x][v]=gecici_toplam_imag ;
				gecici_toplam_imag=0;
				gecici_toplam_real=0;
		}
	}

	gecici_toplam_imag=0;
	gecici_toplam_real=0;

    for(u=0;u<row;u++){ // u
		for(v=0;v<col;v++) {  // v
			for(x=0;x<row;x++) { //  y
				// gecici_toplam_imag=  gecici_toplam_imag + (fast_imag_temp[x][v]*-sin(2*3.14*u*x/3))  ; // sanal toplama
			  //	gecici_toplam_real=  gecici_toplam_real+fast_real_temp[x][v]*cos(2*3.14*u*x/3); // real toplama
			  	gecici_toplam_real=	gecici_toplam_real+ fast_real_temp[x][v]*cos(2*pi*u*x/(row))+sin(2*pi*u*x/row)*fast_imag_temp[x][v];
			  	gecici_toplam_imag= gecici_toplam_imag- fast_real_temp[x][v]*sin(2*pi*u*x/row)+cos(2*pi*u*x/row)*fast_imag_temp[x][v];
                        // (f_real+f_imag) * (cos-j*sin)
			}
			fast_real[u][v] =	gecici_toplam_real ;
			fast_imag[u][v]=	gecici_toplam_imag;
			gecici_toplam_imag=0;
			gecici_toplam_real=0;

		}
	}





	for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            temp.setPix(i,j,sqrt((fast_real[i][j]*fast_real[i][j])+(fast_imag[i][j]*fast_imag[i][j])));

   return temp;
 }
Image Image:: Create_Image(int row , int col ) {

    Image temp (row,col);
    int sayac=1;
    for(int i =0;i<row;i++) {
        for(int j=0;j<col;j++) {
            temp.setPix(i,j,sayac);
            sayac++;
        }
    }

    return temp ;
}


  //END OF YOUR FUNCTIONS //


