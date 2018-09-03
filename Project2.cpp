//IMT2016095 - Nishant Malpani

#include "Project2.h"

using namespace std;

bool Project2::isMin(int n1, int n2)
{
    return n1 < n2 ? true : false;
}

Project2::Project2 (Image& original_img) :  A(original_img.getHeight(), original_img.getWidth())
{
    Image temp_img (original_img.getHeight(), original_img.getWidth());
    Colour temp_colour;

    for (int i = 0; i < original_img.getWidth(); i++)
    {
        for (int j = 0; j < original_img.getHeight(); j++)
        {
            temp_colour = original_img.getColourAtPos(j,original_img.getWidth()-i-1);
            temp_img.fillColourAtPos(j,i,temp_colour);
        }
    }
    A = temp_img;
}

Image Project2::get_image() { return A; }

vector<Pixel> Project2::get_minima_blue()
{
    vector<Pixel> L;

    for (int i = 1; i < A.getHeight()-1; i++)
    {
        for (int j = 1; j < A.getWidth()-1; j++)
        {
            vector<int> blue_comp;
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    blue_comp.push_back(A.getColourAtPos(i+x, j+y).getBlue());
                }
            }

            int count = 0;

            for (int n = 0; n < blue_comp.size(); n++)
            {
                if (isMin(blue_comp[4], blue_comp[n])) count++;
            }
            if (count == 8)
            {
                Pixel pix(i, j, A.getColourAtPos(i, j));
                L.push_back(pix);
            }
        }
    }

    return L;
}

Image Project2::get_img_blue_minima(vector<Pixel> L)
{
    int x_pos, y_pos;
    Colour black(0,0,0);
    Colour white(255,255,255);

    Image blue_minima_img(A.getHeight(), A.getWidth());
    for (int i = 0; i < A.getHeight(); i++)
    {
        for (int j = 0; j < A.getWidth(); j++)
            blue_minima_img.fillColourAtPos(i, j, black);
    }

    for (int p = 0; p < L.size(); p++)
    {
        x_pos = L[p].getX();
        y_pos = L[p].getY();

        for (int a = -2; a <=2 ; a++)
        {
            for (int b = -2 ; b <= 2; b++)
            {
                if (x_pos+a < A.getWidth() && x_pos+a >=0 && y_pos+b < A.getHeight() && y_pos+b >=0)
                    blue_minima_img.fillColourAtPos(x_pos+a, y_pos+b, white);
            }
        }
    }

    return blue_minima_img;
}

Image Project2::make_gaussian(vector<Pixel> L,Image img)
{
    int g[5][5] = {{1,4,7,4,1},{4,16,26,16,4},{7,26,41,26,7},{4,16,26,16,4},{1,4,7,4,1}};

    for(int i = 0; i < L.size(); i++)
    {
        int x_pos = L[i].getX();
        int y_pos = L[i].getY();
        int x1, x2, y1, y2;

        x1 = ((x_pos-2)<0 ? 0 : (x_pos-2));
        x2 = ((x_pos-2)<0 ? (2-x_pos) : 0);
        y1 = ((y_pos-2)<0 ? 0 : (y_pos-2));
        y2 = ((y_pos-2)<0 ? (2-y_pos) : 0);

        while (x1 <= x_pos+2 && x1 <= img.getWidth())//for(;x1<=x+2 && x1<img.get_height();x1++,x2++)
        {
            int a_y1 = y1;
            int a_y2 = y2;

            while (a_y1 <= y_pos+2 && a_y1 < img.getHeight())//for(;a_y<=y+2 && a_y<img.get_width();a_y++,a_y1++)
            {
                int temp = int((255* g[x2][a_y2])/273);

                if(img.getColourAtPos(x1,a_y2).getRed() != 255)
                {
                    temp += img.getColourAtPos(x1,a_y2).getRed();
                    temp /= 2;
                }
                Colour col(temp, temp, temp);
                img.fillColourAtPos(x1, a_y1, col);
                a_y1++; a_y2++;
            }
            x1++; x2++;
        }
    }

    Image temp = img;

    return temp;
}
