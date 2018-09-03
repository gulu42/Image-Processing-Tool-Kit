#include"Histogram_73.h"

using namespace std;

Histogram_73::Histogram_73(Image_Analyser ima) : Image(ima.get_max_pixel_count(),256){
  ImA = ima;
  Colour c_black(0,0,0);
  Colour c_white(255,255,255);
  Colour c_green(0,255,0);
  Colour c_red(255,0,0);
  for(int i = 0;i < 256;i++){
    for(int j = 0;j < getHeight();j++){
      if((getHeight()-j)>ima.countForIntensity(i)){
        fillColourAtPos(j,i,c_white);
      }
      else{
        fillColourAtPos(j,i,c_black);
      }
    }
  }
  vector<int> thresholds = ImA.find_thresholds();
  for(int i = 0;i < thresholds.size();i++){
    for(int j = 0;j < getHeight();j++){
      fillColourAtPos(j,thresholds[i],c_green);
    }
  }
  for(int i = 0;i < getHeight();i++){
    fillColourAtPos(i,ImA.find_median(thresholds),c_red);
  }
}

Histogram_73::~Histogram_73(){

}
