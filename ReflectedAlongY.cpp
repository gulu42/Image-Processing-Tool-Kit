#include "ReflectedAlongY.h"

using namespace std;

ReflectedAlongY::ReflectedAlongY(Image img) : Image(img.getHeight(),img.getWidth())
{
    for(int i = 0 ; i < _width ; i++)
    {
        for(int j = 0 ; j < _height ; j++)
        {
            fillColourAtPos(j,i,img.getColourAtPos(j,_width-i-1));
        }
    }
}
