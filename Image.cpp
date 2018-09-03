#include "Image.h"

using namespace std;

Image::Image()
{
    _height = 0;//default image has zero size
    _width = 0;
    _my_arr = NULL;//since image is empty
}

Image::Image(const Image& im)
{
    _height = im._height;
    _width = im._width;

    Pixel **temp = new Pixel*[_height]();//assigning memory to the pointer which will store the bitmap
    for(int i = 0 ; i < _height ; i++)
    {
        temp[i] = new Pixel[_width]();
    }

    _my_arr = temp;

    for(int i = 0 ; i < _height ; i++)
    {
        for(int j = 0 ; j < _width ; j++)
        {
            _my_arr[i][j] = im._my_arr[i][j];
        }
    }
}

Image::Image(int height,int width)
{
    _height = height;
    _width = width;

    Pixel **temp = new Pixel*[height]();
    for(int i = 0 ; i < height ; i++)
    {
        temp[i] = new Pixel[width]();
    }

    _my_arr = temp;
}

int Image::getHeight() const
{
    return _height;
}

int Image::getWidth() const
{
    return _width;
}

void Image::fillColourAtPos(int i,int j,Colour c)
{
    Pixel p(i,j,c);//since image map just has copies of the values
    _my_arr[i][j] = p;
}

Image::~Image()
{
    //left blank
}

Colour Image::getColourAtPos(int i,int j) const
{
    return _my_arr[i][j].getColour();
}

Image const& Image::operator=(Image const &img)
{
    _height = img._height;
    _width = img._width;
    for(int i = 0 ; i < _height ; i++)
    {
        for(int j = 0 ; j < _width ; j++)
        {
            _my_arr[i][j] = img._my_arr[i][j];
        }
    }
    return (*this);
}

ostream& operator<<(ostream &os, Image &im)
{
    for(int i = 0 ; i < im._height ; i++)//print every pixel
    {
        for(int j = 0 ; j < im._width ; j++)
        {
            os << im._my_arr[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

istream& operator>>(istream &is, Image &img)//populates the pixel values,not the header
{
    Colour temp_colour;
    int r,g,b;
    for(int i = 0 ; i < img._height ; i++)
    {
        for(int j = 0 ; j < img._width ; j++)
        {
            is >> r >> g >> b;
            temp_colour.assignColour(r,g,b);//reusing memory location
            img.fillColourAtPos(i,j,temp_colour);
        }
    }
    return is;
}
