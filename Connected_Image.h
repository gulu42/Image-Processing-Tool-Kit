#ifndef Connected_Image_H_H
#define Connected_Image_H_H

#include "Image.h"
using namespace std;

class Connected_Image : public Image{
public:
  Connected_Image(Image im);
  ~Connected_Image();
  void construct_binary_array(Image im);
  int find(int x);
  void uni(int x,int y);
  void labeling(int i);
  void colouring_pixels(int v);
  int get_no_labels(int v);
private:
  int** binary_array;
  int* rank;
  int* parent;
};

#endif
