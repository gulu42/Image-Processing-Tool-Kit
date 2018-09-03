#include "Colour.h"

using namespace std;

Colour::Colour()
{
    _red = 0;
    _blue = 0;
    _green = 0;
}

Colour::Colour(const Colour& col)
{
    _red = col._red;
    _blue = col._blue;
    _green = col._green;
}

Colour::Colour(int r,int g,int b)
{
    _red = r;
    _green = g;
    _blue = b;
}

Colour::~Colour()
{
    //left blank
}

void Colour::assignColour(int r,int g,int b)
{
    _red = r;
    _green = g;
    _blue = b;
}

int Colour::getRed() const
{
    return _red;
}

int Colour::getBlue() const
{
    return _blue;
}

int Colour::getGreen() const
{
    return _green;
}

bool Colour::operator==(const Colour& col)
{
    if(_red == col._red && _green == col._green && _blue == col._blue)
        return true;
    return false;
}

Colour const& Colour::operator=(Colour const &c)
{
    _red = c._red;
    _blue = c._blue;
    _green = c._green;

    return *this;
}

Colour& operator+(Colour c1,Colour c2)
{
    Colour *res = new Colour();

    res->_red = c1._red + c2._red;
    if(res->_red > 255) res->_red = 255;

    res->_green = c1._green + c2._green;
    if(res->_green > 255) res->_green = 255;

    res->_blue = c1._blue + c2._blue;
    if(res->_blue> 255) res->_blue = 255;

    return *res;//returns a reference so that it can directly be used with the output stream
}

ostream& operator<<(ostream &os, Colour &c)
{
    os << c._red << " " << c._green << " " << c._blue;
    return os;
}
