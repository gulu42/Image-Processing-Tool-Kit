#include <iostream>
#include "StenciledImage.h"

using namespace std;

StenciledImage::StenciledImage(Image img,Image mask) : Image(img.getHeight(),img.getWidth())
{
    if(img.getHeight() != mask.getHeight() || img.getWidth() != mask.getWidth())
    {
        cout << "Incompatable image and mask\n";
        // ~StenciledImage();
    }
    else
    {
        Colour white(255,255,255);
        Colour black(0,0,0);
        for(int i = 0 ; i < mask.getHeight() ; i++)
        {
            for(int j = 0 ; j < mask.getWidth() ; j++)
            {
                if(mask.getColourAtPos(i,j) == white)
                    mask.fillColourAtPos(i,j,black);
                else
                    mask.fillColourAtPos(i,j,white);
            }
        }
        for(int i = 0 ; i < img.getHeight() ; i++)
        {
            for(int j = 0 ; j < img.getWidth() ; j++)
            {
                _my_arr[i][j].setColour(img.getColourAtPos(i,j) + mask.getColourAtPos(i,j));
            }
        }
    }
}
