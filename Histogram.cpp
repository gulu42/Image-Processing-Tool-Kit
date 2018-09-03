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
#include "Histogram.h"
using namespace std;

Histogram::Histogram()
{

}

Histogram::~Histogram()
{

}

Histogram::Histogram(Image& image)
{
    int height = image.getHeight(),width = image.getWidth();
    vector < vector <int> > brightness(height,vector <int> (width));
    for(int i = 0; i<height; i++)
    {
        for(int j = 0; j<width; j++)
        {
            brightness[i][j] = (image.getColourAtPos(i,j).getRed() + image.getColourAtPos(i,j).getBlue() + image.getColourAtPos(i,j).getGreen())/3;
        }
    }
    vector <int> histogram(256,0);
    for(int i = 0; i<height; i++)
    {
        for(int j = 0; j<width; j++)
        {
            histogram[brightness[i][j]]++;
        }
    }
    for(int i = 5; i<251; i++)
    {
        int flag = 0;
        for(int j = 1; j<=5; j++)
        {
            if(histogram[i] < histogram[i-j] && histogram[i] <= histogram[i+j])
            {
                continue;
            }
            else
            {
                flag = 1;
            }
        }
        if(flag == 0)
        {
            threshold.push_back(i);
        }
    }
}

vector <int> Histogram::getThreshold()
{
    return threshold;
}
