#include"Image_Analyser.h"
using namespace std;

Image_Analyser::Image_Analyser(){
  max_pixel_count = 0;
  brightness = new int[256] ;
  for(int i = 0;i < 256;i++){
    brightness[i] = 0;
  }
}

Image_Analyser::Image_Analyser(Image im,int s) : smooth(s),image_area(im.getHeight()*im.getWidth()){
  max_pixel_count = 0;
  brightness = new int[256] ;
  for(int i = 0;i < 256;i++){
    brightness[i] = 0;
  }
  pixel_brightness = new int[image_area] ;
  for(int i = 0;i < im.getHeight();i++){
    for(int j = 0;j < im.getWidth();j++){
      int intensity = (int)(im.getColourAtPos(i,j).getRed()+im.getColourAtPos(i,j).getGreen()+im.getColourAtPos(i,j).getBlue())/3;
      pixel_brightness[i*im.getWidth()+j] = intensity;
      brightness[intensity]++;
      if(max_pixel_count<brightness[intensity]){
        max_pixel_count = brightness[intensity];
      }
    }
  }
}

Image_Analyser::~Image_Analyser(){
  // delete[] brightness;
}

void Image_Analyser::set_brightness(Image im){
  for(int i = 0;i < im.getHeight();i++){
    for(int j = 0;j < im.getWidth();j++){
      brightness[(int)(im.getColourAtPos(i,j).getRed()+im.getColourAtPos(i,j).getGreen()+im.getColourAtPos(i,j).getBlue())/3]++;
    }
  }
  return ;
}
int Image_Analyser::countForIntensity(int i) const{
  return brightness[i];
}

int* Image_Analyser::get_brightness() const{
  return brightness;
}

int Image_Analyser::get_max_pixel_count() const{
  return max_pixel_count;
}

vector<int> Image_Analyser::find_thresholds(){
  std::vector<int> thresholds;
  for(int i = smooth;i < 256-smooth;i++){
    int min_left = max_pixel_count;
    int min_right = max_pixel_count;
    for(int j = 1;j < smooth+1;j++){
      if(i-j>=0){
        if(min_left>brightness[i-j]){
          min_left = brightness[i-j];
        }
      }
    }
    for(int j = 1;j < smooth+1;j++){
      if(i+j<256-smooth){
        if(min_right>brightness[i+j]){
          min_right = brightness[i+j];
        }
      }
    }
    if((brightness[i]<=min_left)&&(brightness[i]<=min_right)){
      if(brightness[i]!=0){
        thresholds.push_back(i);
      }
    }
  }
  int *temp = new int[256];
  for(int i = 0;i < 256;i++){
    temp[i] = 0;
  }
  if(thresholds.size()==0){
    for(int i = 0;i < image_area;i++){
      if(temp[pixel_brightness[i]]==0){
        thresholds.push_back(pixel_brightness[i]);
        temp[pixel_brightness[i]]++;
      }
    }
    sort(thresholds.begin(), thresholds.end());
  }
  return thresholds;
}

int Image_Analyser::find_median(vector<int> thresholds){
  int no_of_thresholds = thresholds.size();
  int median_threshold;
  if(no_of_thresholds%2!=0){
    median_threshold = thresholds[(no_of_thresholds/2)];
  }
  else{
    median_threshold = (thresholds[(no_of_thresholds/2)-1] + thresholds[(no_of_thresholds/2)])/2;
  }
  return median_threshold;
}

Image_Analyser const& Image_Analyser::operator=(Image_Analyser const &ImA){
  int* local_name = new int[256];
  for(int i = 0;i < 256;i++){
     local_name[i] = ImA.brightness[i];
   }
   delete[] brightness;
   brightness = local_name;
   max_pixel_count = ImA.max_pixel_count;
   smooth = ImA.smooth;
   image_area = ImA.image_area;
   pixel_brightness = new int[image_area] ;
   for(int i = 0;i < image_area;i++){
     pixel_brightness[i] = ImA.pixel_brightness[i];
   }
  return *this;
}
