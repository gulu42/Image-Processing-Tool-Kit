#ifndef Reflection_H_
#define Reflection_H_

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
using namespace std;

class Reflection : public Image
{
public:
    Reflection();

    Reflection(Image& image);

    ~Reflection();
};

#endif
