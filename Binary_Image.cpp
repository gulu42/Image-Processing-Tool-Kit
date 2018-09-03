#include "Binary_Image.h"

using namespace std;

Binary_Image::Binary_Image(){}

Binary_Image::Binary_Image(Image im,int threshold) : Image(im.getHeight(),im.getWidth()){
  Colour c_black(0,0,0);
  Colour c_white(255,255,255);
  for(int i = 0;i < getHeight();i++){
    for(int j = 0;j < getWidth();j++){
      if(((im.getColourAtPos(i,j).getRed()+im.getColourAtPos(i,j).getGreen()+im.getColourAtPos(i,j).getBlue())/3)<threshold){
        fillColourAtPos(i,j,c_black);
      }
      else{
        fillColourAtPos(i,j,c_white);
      }
    }
  }
}

Binary_Image::~Binary_Image(){}
