#ifndef PROJECT_2_HEADER
#define PROJECT_2_HEADER

#include <iostream>
#include <vector>
#include <fstream>

#include "Colour.h"
#include "Pixel.h"
#include "Image.h"
#include "CompositeImage.h"

using namespace std;

class Project2
{
    private:
        Image A;
        bool isMin(int n1, int n2);
    public:
        Project2 (Image& original_img);
        Image get_image();
        vector<Pixel> get_minima_blue();
        Image get_img_blue_minima(vector<Pixel> L);
        Image make_gaussian(vector<Pixel> L,Image img);

};

#endif
