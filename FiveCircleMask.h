#ifndef FIVE_CIRCLE_MASK_HEADER
#define FIVE_CIRCLE_MASK_HEADER

#include "Image.h"

class FiveCircleMask : public Image
{
private:
    bool distanceCheck(int i,int j,int center_x,int center_y,int radius);
    float minVal(float a,float b);
    void markRegion(int start_x,int end_x,int start_y,int end_y,bool dont_alter_surr);
public:
    FiveCircleMask(int height,int width);
};

#endif
