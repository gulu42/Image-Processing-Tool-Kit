#ifndef PIXEL_HEADER
#define PIXEL_HEADER

#include <iostream>
#include "Colour.h"
using namespace std;

class Pixel
{
private:
    int _x,_y;//the coordinates of the pixel in the image
    Colour _my_colour;
public:
    Pixel();
    Pixel(const Pixel& p);
    Pixel(int x,int y,Colour c);//x-coordinate,y-coordinate,colour of the pixel
    virtual ~Pixel();//made virtual in case want to free some memory explicitly in the derived class

    Colour getColour() const;//returns the value of the colour
    void setColour(Colour c);//fills in the colour of the pixel

    int getX() const;
    int getY() const;

    //operators
    Pixel const& operator=(Pixel const &p);
    bool operator==(Pixel const& p);
    friend ostream& operator<<(ostream &os, Pixel &p);
    //istream operator was not used
};

#endif
