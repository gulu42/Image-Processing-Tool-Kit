#include <iostream>
#include "CompositeImage.h"
#include "Image.h"

using namespace std;

CompositeImage::CompositeImage(Image i1,Image i2,float alpha) : Image(i1.getHeight(),i1.getWidth())
{
    if(i1.getHeight() != i2.getHeight() || i1.getWidth() != i2.getWidth())
    {
        cout << "Can't compose images\n";
        // ~Image();
    }
    else
    {
        this->reCompose(i1,i2,alpha);
    }
}

void CompositeImage::reCompose(Image i1,Image i2,float alpha)
{
    _alpha = alpha;
    float r,b,g;
    for(int i = 0 ; i < _height ; i++)//_height will be height of the composite image
    {
        for(int j = 0 ; j < _width ; j++)
        {
            r = ((1-_alpha)*(i1.getColourAtPos(i,j).getRed())) + ((_alpha)*(i2.getColourAtPos(i,j).getRed()));
            b = (1-_alpha)*(i1.getColourAtPos(i,j).getBlue()) + (_alpha)*(i2.getColourAtPos(i,j).getBlue());
            g = (1-_alpha)*(i1.getColourAtPos(i,j).getGreen()) + (_alpha)*(i2.getColourAtPos(i,j).getGreen());

            Colour c(r,g,b);
            _my_arr[i][j].setColour(c);
        }
    }
}
