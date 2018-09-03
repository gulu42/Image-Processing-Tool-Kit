#ifndef Histogram_H_H
#define Histogram_H_H

#include "Image.h"
#include "Image_Analyser.h"
using namespace std;

class Histogram_73 : public Image{
public:
  Histogram_73(Image_Analyser ima);
  ~Histogram_73();
  //Histogram(int* a,int pixel_count);
  //void create_histogram(Image_Analyser ima);
private:
  Image_Analyser ImA;
};
#endif
