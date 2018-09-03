#ifndef Image_Analyser_H_
#define Image_Analyser_H_

#include "Image.h"
#include<vector>
#include <algorithm>
using namespace std;

class Image_Analyser{
private:
  int *brightness;
  int max_pixel_count;
  int smooth;
  int *pixel_brightness;
  int image_area;
public:
  Image_Analyser();
  Image_Analyser(Image im,int s);
  ~Image_Analyser();
  void set_brightness(Image im);
  int countForIntensity(int i) const;
  int* get_brightness() const;
  int get_max_pixel_count() const;
  vector<int> find_thresholds();
  int find_median(vector<int> thresholds);
  Image_Analyser const& operator=(Image_Analyser const &ImA);
};
#endif
