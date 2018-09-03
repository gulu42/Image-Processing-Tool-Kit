#ifndef Histogram_H_
#define Histogram_H_

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
#include "Pixel.h"
#include "Colour.h"
using namespace std;

class Histogram
{
private:
    vector <int> histogram;
    vector <int> threshold;
public:
    Histogram();

    ~Histogram();

    Histogram(Image& image);

    vector <int> getThreshold();
};

#endif
