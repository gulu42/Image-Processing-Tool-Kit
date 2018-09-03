#ifndef Segmentation_H_
#define Segmentation_H_

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
#include "Histogram.h"
#include "CompositeImage.h"
using namespace std;

class Segmentation : public Image
{
private:
    int colours[6][3];

public:
    Segmentation();

    ~Segmentation();

    Segmentation(Image& image);
};

#endif
