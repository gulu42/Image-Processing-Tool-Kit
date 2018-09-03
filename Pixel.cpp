#include "Pixel.h"

using namespace std;

Pixel::Pixel()
{
    _x = 0;
    _y = 0;
    Colour *temp =new Colour();
    _my_colour = *temp;
}

Pixel::Pixel(const Pixel& p)
{
    _x = p._x;
    _y = p._y;
    _my_colour = p._my_colour;
}

Pixel::Pixel(int x,int y,Colour c)//construct with given values
{
    _x = x;
    _y = y;
    _my_colour = c;
}

Pixel::~Pixel()
{
    //left blank
}

Colour Pixel::getColour() const
{
    return _my_colour;
}

void Pixel::setColour(Colour c)
{
    _my_colour = c;
}

int Pixel::getX() const
{
    return _x;
}

int Pixel::getY() const
{
    return _y;
}

Pixel const& Pixel::operator=(Pixel const &p)
{
    _x = p._x;
    _y = p._y;
    _my_colour = p._my_colour;
    return (*this);
}

bool Pixel::operator==(Pixel const& p)
{
    return _my_colour == p._my_colour;
}

ostream& operator<<(ostream &os, Pixel &p)
{
    os << p._my_colour;
    return os;
}
