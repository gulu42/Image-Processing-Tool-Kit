#ifndef COLOUR_HEADER
#define COLOUR_HEADER

#include <iostream>
using namespace std;

class Colour
{
private:
    int _red,_blue,_green;
public:
    Colour();
    Colour(const Colour& col);
    Colour(int r,int b,int g);//amke a colour with the r,g,b values
    virtual ~Colour();//made virtual in case want to free some memory explicitly in the derived class

    void assignColour(int r,int b,int g);
    int getRed() const;
    int getBlue() const;
    int getGreen() const;

    //operators
    Colour const& operator=(Colour const &c);//assigns r,g,b values of one colour to this colour object
    bool operator==(const Colour& col);//checks logical equality
    friend Colour& operator+(Colour c1,Colour c2);//any number above 255 is made 255
    friend ostream& operator<<(ostream &os, Colour &c);//writes out the r,g and b values
};

#endif
