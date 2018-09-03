#include "Connected_Image.h"

#include<math.h>
#include<cstdlib>
using namespace std;

Connected_Image::Connected_Image(Image im) : Image(im.getHeight(),im.getWidth()){
  binary_array = new int*[getHeight()] ;
  for (int i = 0 ; i < getHeight() ; i++) {
    binary_array[i] = new int[getWidth()] ;
  }
  parent = new int[(getHeight()*getWidth())] ;
  rank = new int[(getHeight()*getWidth())] ;
  for(int i = 0;i < getHeight()*getWidth();i++){
    rank[i] = 0;
    parent[i] = i;
  }
  construct_binary_array(im);
  labeling(0);
  colouring_pixels(0);
  for(int i = 0;i < getHeight()*getWidth();i++){
    rank[i] = 0;
    parent[i] = i;
  }
  labeling(1);
  colouring_pixels(1);
}

Connected_Image::~Connected_Image(){
  for (int i = 0 ; i < getHeight() ; i++){
    delete[] binary_array[i] ;
  }
  delete[] binary_array;
  delete[] parent;
  delete[] rank;
}

void Connected_Image::construct_binary_array(Image im){
  for(int i = 0;i < getHeight();i++){
    for(int j = 0;j < getWidth();j++){
      if(im.getColourAtPos(i,j).getRed()==0){
        binary_array[i][j] = 0;
      }
      else{
        binary_array[i][j] = 1;
      }
    }
  }
}

int Connected_Image::find(int x){
	if (parent[x] != x){
		return find(parent[x]);
	}
	return x;
}

void Connected_Image::uni(int x, int y){
  int xRoot = find(x);
  int yRoot = find(y);
  if (xRoot == yRoot){
    return;
  }
  if (rank[xRoot] < rank[yRoot]){
    parent[xRoot] = yRoot;
  }
  else{
    if(rank[yRoot]<rank[xRoot]){
    parent[yRoot] = xRoot;
    }
    else{
      parent[yRoot] = xRoot;
      rank[xRoot] = rank[xRoot] + 1;
    }
  }
}

void Connected_Image::labeling(int i){
  int n = getHeight();
  int m = getWidth();
  for (int j=0; j<n; j++){
    for (int k=0; k<m; k++){
      if (binary_array[j][k] != i){continue;}

      if (j+1 < n && binary_array[j+1][k]==i){
         uni(j*(m)+k, (j+1)*(m)+k);
       }
      if (j-1 >= 0 && binary_array[j-1][k]==i){
        uni(j*(m)+k, (j-1)*(m)+k);
      }
      if (k+1 < m && binary_array[j][k+1]==i){
         uni(j*(m)+k, (j)*(m)+k+1);
       }
      if (k-1 >= 0 && binary_array[j][k-1]==i){
        uni(j*(m)+k, (j)*(m)+k-1);
      }
      if (j+1<n && k+1<m && binary_array[j+1][k+1]==i){
         uni(j*(m)+k, (j+1)*(m)+k+1);
       }
      if (j+1<n && k-1>=0 && binary_array[j+1][k-1]==i){
        uni(j*m+k, (j+1)*(m)+k-1);
      }
      if (j-1>=0 && k+1<m && binary_array[j-1][k+1]==i){
         uni(j*m+k, (j-1)*m+k+1);
       }
      if (j-1>=0 && k-1>=0 && binary_array[j-1][k-1]==i){
        uni(j*m+k, (j-1)*m+k-1);
      }
    }
  }
}

void Connected_Image::colouring_pixels(int v){
  int no_of_labels = get_no_labels(v);
  int count = 0;
  int temp;
  int* parents = new int[no_of_labels];
  Colour* label_colours = new Colour[no_of_labels];
  int* c = new int[getHeight()*getWidth()];
  for (int j=0; j<getHeight(); j++){
    for (int k=0; k<getWidth(); k++){
      if (binary_array[j][k]==v){
        int x = find(j*getWidth()+k);
        if (c[x]==0){
            c[x]++;
            parents[count] = parent[x];
            Colour c(rand()%256,rand()%256,rand()%256);
            label_colours[count] = c;
            count++;
        }
      }
    }
  }
  for(int i = 0;i < getHeight();i++){
    for(int j = 0;j < getWidth();j++){
      if(binary_array[i][j]==v){
        temp = find(i*getWidth()+j);
        for(int k = 0;k < no_of_labels;k++){
          if(temp==parents[k]){
            fillColourAtPos(i,j,label_colours[k]);
          }
        }
      }
    }
  }
}

int Connected_Image::get_no_labels(int v){
  int* c = new int[getHeight()*getWidth()];
  int numberOfIslands = 0;
  for (int j=0; j<getHeight(); j++){
    for (int k=0; k<getWidth(); k++){
      if (binary_array[j][k]==v){
        int x = find(j*getWidth()+k);
        if (c[x]==0){
            numberOfIslands++;
            c[x]++;
        }
        else{
          c[x]++;
        }
    }
  }
}
return numberOfIslands;
}
