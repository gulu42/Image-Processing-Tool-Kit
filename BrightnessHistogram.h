#ifndef __HISTOGRAM_HEADER__
#define __HISTOGRAM_HEADER__

#include <vector>

class Image;
class Colour;

class BrightnessHistogram
{
    std::vector<int> _frequency;

  public:
    BrightnessHistogram();
    BrightnessHistogram(Image &a, int smoothFactor = 0);

    Image outputHistogram(int scaleHeight = 10, int window = 10, int lowerBoundMinima = 0, bool markThresholds = true);
    std::vector<int> getThresholds(int window = 10, int lowerBoundMinima = 0);
    std::vector<int> getFrequencyList();
    int brightness(Colour c);
};

#endif
