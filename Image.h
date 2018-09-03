#ifndef IMAGE_HEADER
#define IMAGE_HEADER

#include <iostream>
#include "Pixel.h"
using namespace std;

class Image
{
protected:
    int _height,_width;
    Pixel **_my_arr;//this is equivalent to a 2d array

public:
    Image();//makes an image of height and width 0
    Image(const Image& i);//copy all the details of i to make this image
    Image(int height,int width);//make a un-populated image. Takes height and then width
    virtual ~Image();//made virtual in case want to free some memory explicitly in the derived class

    int getHeight() const;//returns height of the image
    int getWidth() const;//returns width of the image
    Colour getColourAtPos(int i,int j)  const;//used to read.only get a copy
    void fillColourAtPos(int i,int j,Colour c);//used to populate.only pass a copy

    //operators
    Image const& operator=(Image const &i);
    friend istream& operator>>(istream &is, Image &img);//only reads in the bit map,not the file headers
    friend ostream& operator<<(ostream &os, Image &i);//only writes out the bit map,not the file headers
};

#endif
