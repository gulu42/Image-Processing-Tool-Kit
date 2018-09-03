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
#include "Image.h"
#include "Colour.h"
#include "Pixel.h"
#include "Reflection.h"
using namespace std;

Reflection::Reflection()
{

}

Reflection::~Reflection()
{

}

Reflection::Reflection(Image& image) : Image(image)
{
    for(int i = 0; i<_height; i++)
    {
        for(int j = 0; j<=_width/2; j++)
        {
            Pixel temp = *(new Pixel(i,j,image.getColourAtPos(i,j)));
            _my_arr[i][j] = *(new Pixel(i,j,image.getColourAtPos(i,_width-j-1)));
            _my_arr[i][_width-j-1] = temp;
        }
    }
}
