#ifndef COMPOSITE_IMAGE_HEADER
#define COMPOSITE_IMAGE_HEADER

#include "Image.h"

class CompositeImage : public Image
{
private:
    float _alpha;
public:
    CompositeImage(Image i1,Image i2,float alpha);//doesn't make sense to have a parameterless constructor
    void reCompose(Image i1,Image i2,float alpha);
};

#endif
