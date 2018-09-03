#include <iostream>
#include <cmath>
#include "FiveCircleMask.h"

using namespace std;

bool FiveCircleMask::distanceCheck(int i,int j,int center_x,int center_y,int radius)
{
    if((float)sqrt((center_x-i)*(center_x-i) + (center_y-j)*(center_y-j)) < (float)radius)
        return true;
    else
        return false;
}

float FiveCircleMask::minVal(float a,float b)
{
    return a<b?a:b;
}

void FiveCircleMask::markRegion(int start_x,int end_x,int start_y,int end_y,bool dont_alter_surr)
{
    Colour black(0,0,0);
    Colour white(255,255,255);

    int radius = minVal((float)(end_x-start_x),(float)(end_y-start_y)) / 2;

    int center_x = (end_x-start_x)/2 + start_x;
    int center_y = (end_y-start_y)/2 + start_y;
    for(int i = start_x ; i < end_x ; i++)
    {
        for(int j = start_y ; j < end_y ; j++)
        {
            if(distanceCheck(i,j,center_x,center_y,radius))
                _my_arr[i][j].setColour(black);
            else if(dont_alter_surr == false)
                _my_arr[i][j].setColour(white);
        }
    }
}

FiveCircleMask::FiveCircleMask(int height,int width) : Image(height,width)
{
    int start_x = 0,
        end_x = _width/2,
        start_y = 0,
        end_y = _height/2;

    markRegion(0,_height/2,0,_width/2,false);
    markRegion(_height/2,_height,0,_width/2,false);
    markRegion(0,_height/2,_width/2,_width,false);
    markRegion(_height/2,_height,_width/2,_width,false);
    markRegion(3*_height/8,5*_height/8,3*_width/8,5*_width/8,true);//called this first so that circles aren't covered in white
}
