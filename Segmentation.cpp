#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <climits>
#include <queue>
#include <set>
#include "Segmentation.h"
using namespace std;


Segmentation::Segmentation()
{
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            colours[i][j] = 0;
        }
    }
    for(int i = 3; i<6; i++)
    {
        for(int j = 0; j<3; j++)
        {
            colours[i][j] = 255;
        }
    }
    for(int i = 0; i<3; i++)
    {
        colours[i][i] = 255;
    }
    for(int i = 0; i<3; i++)
    {
        colours[3+i][2-i] = 0;
    }
}

Segmentation::~Segmentation()
{

}

Segmentation::Segmentation(Image& image) : Image(image)
{
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            colours[i][j] = 0;
        }
    }
    for(int i = 3; i<6; i++)
    {
        for(int j = 0; j<3; j++)
        {
            colours[i][j] = 255;
        }
    }
    for(int i = 0; i<3; i++)
    {
        colours[i][i] = 255;
    }
    for(int i = 0; i<3; i++)
    {
        colours[3+i][2-i] = 0;
    }
    Histogram& h = *(new Histogram(image));
    vector <int> threshold = h.getThreshold();
    if(threshold.size() != 0)
    {
        int check = 0,size = threshold.size();
        for(int i = 0; i<_height; i++)
        {
            for(int j = 0; j<_width; j++)
            {
                int brightness = (image.getColourAtPos(i,j).getRed() + image.getColourAtPos(i,j).getBlue() + image.getColourAtPos(i,j).getGreen())/3;
                for(int k = 0; k<size; k++)
                {
                    if(brightness <= threshold[k])
                    {
                        if(k < 6)
                        {
                            _my_arr[i][j] = *(new Pixel(i,j,*(new Colour(colours[k][0],colours[k][1],colours[k][2]))));
                        }
                        else
                        {
                            _my_arr[i][j] = *(new Pixel(i,j,*(new Colour(0,0,0))));
                        }
                        break;
                    }
                }
                if(brightness > threshold[size-1])
                {
                    if(size < 6)
                    {
                        _my_arr[i][j] = *(new Pixel(i,j,*(new Colour(colours[size][0],colours[size][1],colours[size][2]))));
                    }
                    else
                    {
                        _my_arr[i][j] = *(new Pixel(i,j,*(new Colour(0,0,0))));
                    }
                }
            }
        }
    }
    else
    {
        Reflection& ref = *(new Reflection(image));
        for(int i = 0; i<_height; i++)
        {
            for(int j = 0; j<_width; j++)
            {
                _my_arr[i][j] = *(new Pixel(i,j,ref.getColourAtPos(i,j)));
            }
        }
    }
    CompositeImage& com = *(new CompositeImage(image,*this,0.4));
    for(int i = 0; i<_height; i++)
    {
        for(int j = 0; j<_width; j++)
        {
            _my_arr[i][j] = *(new Pixel(i,j,com.getColourAtPos(i,j)));
        }
    }
}
