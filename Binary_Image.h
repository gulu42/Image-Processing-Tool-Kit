#ifndef Binary_Image_H_H
#define Binary_Image_H_H

#include "Image.h"
using namespace std;

class Binary_Image : public Image{
public:
  Binary_Image();
  Binary_Image(Image Im,int threshold);
  ~Binary_Image();
};


#endif
