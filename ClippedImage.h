#ifndef CLIPPED_IMAGE_HEADER
#define CLIPPED_IMAGE_HEADER

#include "Image.h"

class ClippedImage : public Image
{
public:
    ClippedImage(Image img,Image mask);//can take in any image as a mask
};

#endif
