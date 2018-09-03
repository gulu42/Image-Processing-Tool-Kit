#ifndef STENCILED_IMAGE_HEADER
#define STENCILED_IMAGE_HEADER

#include "Image.h"

class StenciledImage : public Image
{
public:
    StenciledImage(Image img,Image mask);
};

#endif
