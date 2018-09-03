#include <iostream>
#include "ClippedImage.h"

using namespace std;

ClippedImage::ClippedImage(Image img,Image mask) : Image(img.getHeight(),img.getWidth())
{
    if(img.getHeight() != mask.getHeight() || img.getWidth() != mask.getWidth())
    {
        cout << "Incompatable image and mask\n";
        // ~ClippedImage();
    }
    else
    {
        // cout << _height << " " << _width << endl;
        // cout << img.getHeight() << " " << img.getWidth() << " " << mask.getHeight() << " " << mask.getWidth() << endl;
        for(int i = 0 ; i < img.getHeight() ; i++)
        {
            for(int j = 0 ; j < img.getWidth() ; j++)
            {
                _my_arr[i][j].setColour(img.getColourAtPos(i,j) + mask.getColourAtPos(i,j));
                // cout << i << " " << j << endl;
            }
        }
    }
}
