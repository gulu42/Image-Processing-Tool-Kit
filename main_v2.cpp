#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <string>
#include <ctype.h>
#include "Histogram.h"
#include "Image.h"
#include "ReflectedAlongY.h"
#include "FiveCircleMask.h"
#include "ClippedImage.h"
#include "StenciledImage.h"
#include "CompositeImage.h"
#include "Binary_Image.h"
#include "Connected_Image.h"
#include "Segmentation.h"
#include "Project2.h"
#include "Image_Analyser.h"

using namespace std;


//----------------------------------File read/write - start-------------------------------------------
void writeOutAsPPM(Image img,char* out_file_name)
{
    ofstream ofile(out_file_name);
    ofile << "P3\n" << img.getWidth() << " " << img.getHeight() << "\n" << 255 << endl;
    ofile << img;
}

Image readFromPPM(char* inputFile)
{
    ifstream ifile(inputFile);

    Image *img = NULL;

    if(ifile == NULL)
    {
        cout << "Image file not found\n";
        return *img;
    }

    char c1,c2;
    ifile >> c1 >> c2;
    if(c1 != 'P' || c2 != '3')
    {
        cout << "Can't handle this format(yet)\n";
        return *img;
    }

    int height,width,max_val;
    ifile >> width >> height >> max_val;
    img = new Image(height,width);

    Colour temp_colour;
    int r,g,b;
    for(int i = 0 ; i < height ; i++)
    {
        for(int j = 0 ; j < width ; j++)
        {
            ifile >> r >> g >> b;
            temp_colour.assignColour(r,g,b);//reusing memory location
            img->fillColourAtPos(i,j,temp_colour);
        }
    }

    return *img;
}

//----------------------------------File read/write - end-------------------------------------------


//----------------------------------Shivam/IMT2016114 code - start-------------------------------------------

int brightness(Colour c){
    return (c.getRed() + c.getBlue() + c.getGreen()) / 3;
}

Image getBinaryImage(Image a, int threshold, Colour lower, Colour higher)
{
    // binary will be transformed into binary image
    Image binary(a.getWidth(), a.getHeight());

    // Iterate through pixels, find brightness
    // if brightness is lower than threshold set color to lower
    // else set it to higher
    for (int i = 0; i < a.getHeight(); ++i)
    {
        for (int j = 0; j < a.getWidth(); ++j)
        {
            if (brightness(a.getColourAtPos(i, j)) > threshold)
            {
                binary.fillColourAtPos(i, j, higher);
            }
            else
            {
                binary.fillColourAtPos(i, j, lower);
            }
        }
    }

    return binary;
}

Image ReflectedAlongYIMT2016114(Image img)
{
    for (int i = 0; i < img.getWidth(); i++)
    {
        for (int j = 0; j <img.getHeight(); j++)
        {
            img.fillColourAtPos(j, i, img.getColourAtPos(j, img.getWidth() - i - 1));
        }
    }
    return (img);
}
Image ReflectedAlongXIMT2016114(Image img)
{
    for (int i = 0; i < img.getHeight(); i++)
    {
        for (int j = 0; j < img.getWidth(); j++)
        {
            img.fillColourAtPos(j, i, img.getColourAtPos(j, img.getHeight() - i - 1));
        }
    }
    return (img);
}

void task5(Image & a, int indexT1, int indexT2)
{
    // Create default images to compose afterwards
    Image *c, *d;
    // Get brightness histogram for a
    Histogram hist(a);

    // Declaration of Color constants
    const Colour BLUE(0, 0, 255),
        WHITE(255, 255, 255), YELLOW(255, 255, 0);

    std::vector<int> thresholds(hist.getThreshold());
    //If thresholds are lesser than 2 take reflections
    if (thresholds.size() < std::max(indexT1, indexT2))
    {
        *c = ReflectedAlongXIMT2016114(a);
        *d = ReflectedAlongYIMT2016114(a);
    }
    else
    {
        c = new Image(getBinaryImage(a, thresholds[indexT1], BLUE, WHITE));
        d = new Image(getBinaryImage(a, thresholds[indexT2], YELLOW, WHITE));

        // Compose image and write the result to file
        CompositeImage res(*d, *c, 0.2);
        ofstream x("output_task5_imt2016114.ppm");
        x << "P3\n";
        x << res.getWidth() << ' ' << res.getHeight() << ' ' << 255 << std::endl;
        x << res;
        x.close();
    }
}

//----------------------------------Shivam/IMT2016114 code - end-------------------------------------------


//----------------------------------Tasks - start-------------------------------------------

void task_id1(Image& img)
{
    Image *reflected = new ReflectedAlongY(img);

    Image *mask = new FiveCircleMask(img.getHeight(),img.getWidth());

    Image *clipped = new ClippedImage(img,*mask);

    Image *stenciled = new StenciledImage(*reflected,*mask);

    Image *composed = new CompositeImage(*clipped,*stenciled,0.5);
    char out[] = "output_task1_imt2016052.ppm";
    writeOutAsPPM(*composed,out);
}

void task_id2(Image& img)
{
    Project2 test(img);
    vector<Pixel> L = test.get_minima_blue();
    // cout << L.size() << endl;
    Image img_blue_minima = test.get_img_blue_minima(L);

    // char out1[] = "BlueMinima.ppm";
    // writeOutAsPPM(img_blue_minima,out1);

    img_blue_minima = test.make_gaussian(L, img_blue_minima);

    // char out2[] = "Gaussian.ppm";
    // writeOutAsPPM(img_blue_minima,out2);

    CompositeImage comp_img(test.get_image(), img_blue_minima, 0.75);
    char out3[] = "output_task2_imt2016095.ppm";
    writeOutAsPPM(comp_img,out3);
}

void task_id3(Image& img)
{
    //was to be done by IMT2015004
}

void task_id4(Image& img)
{
    Segmentation seg(img);

    char out[] = "output_task4_imt2016024.ppm";
    writeOutAsPPM(seg,out);
}

void task_id5(Image& img)
{
    task5(img,2,3);
}

void task_id6(Image& img)
{
    Image_Analyser IA(img,3); //smooth factor = 3
    Binary_Image b(img,IA.find_median(IA.find_thresholds()));
    Connected_Image c(b);

    char out[] = "output_task6_imt2016073.ppm";
    writeOutAsPPM(c,out);
}

//----------------------------------Tasks - end-------------------------------------------

int main(int argc, char const *argv[])
{
    if(argc != 2)
    {
        cout << "Parameter mismatch\n";
    }

    char* inp = const_cast<char*>(argv[1]);
    Image img = readFromPPM(inp);

    cout << "Our group task ID combination is : 1,2,3,4,5,6\n\n";

    void (*func_ptr[])(Image&) = {task_id1,task_id2,task_id3,task_id4,task_id5,task_id6};

    cout << "Enter all the tasks to execute(In one line): ";
    string st;
    // scanf("%s",st);

    getline(cin,st);//doesn't take int the delimiter
    // char c; cin >> c;

    for(int i = 0 ; i < st.size() ; i++)
    {
        if(isdigit(st[i])) // any delimiter will work
        {
            if(st[i] - 48 > 6 || st[i] == 48)
            {
                cout << "Invalid task " << st[i]-48 << endl;
            }
            else
            {
                (*func_ptr[(st[i]-48)-1])(img);
                cout << "Output for task " << st[i]-48 << " has been generated.\n";
            }
        }
    }
}
