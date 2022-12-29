//  Write C++ program to draw the following pattern. Use DDA line and Bresenham‘s circle
// drawing algorithm. Apply the concept of encapsulation.

#include <graphics.h>
#include <math.h>
using namespace std;

class fig
{
public:
    void DDA_line(int x1, int y1, int x2, int y2, int icolor)
    {
        int steps;
        float xinc, yinc, x, y;
        int dx = x2 - x1;
        int dy = y2 - y1;

        if (fabs(dx) > fabs(dy))
        {
            steps = fabs(dx);
        }
        else
        {
            steps = fabs(dy);
        }

        xinc = (float)(dx) / steps;
        yinc = (float)(dy) / steps;
        x = x1;
        y = y1;

        for (int i = 0; i < steps; i++)
        {
            putpixel(floor(x), floor(y), icolor);
            x += xinc;
            y += yinc;
        }
    }

    void Breh_Circle(int x, int y, int r)
    {
        int D = 3 - (2 * r);
        int icolor = 14;
        int xi = 0, yi = r;
        while (xi < yi)
        {
            
            putpixel(x + xi, y - yi, icolor);
            putpixel(x + yi, y - xi, icolor);
            putpixel(x - xi, y + yi, icolor);
            putpixel(x - yi, y + xi, icolor);
            putpixel(x + xi, y + yi, icolor);
            putpixel(x + yi, y + xi, icolor);
            putpixel(x - xi, y - yi, icolor);
            putpixel(x - yi, y - xi, icolor);
            
            if (D < 0)
            {
                D += (4 * xi) + 6;
            }
            else
            {
                D += (4 * (xi - yi)) + 10;
                yi--;
            }
            xi++;
        }
    }
};

int main()
{
    int gm, gd = DETECT;
    initgraph(&gd, &gm, NULL);

    fig f;
    f.Breh_Circle(320, 240, 60);
    f.Breh_Circle(320, 240, 30);
    f.DDA_line(320,180,372,270,14);
    f.DDA_line(320,180,268,270,14);
    f.DDA_line(268,270,372,270,14);
    
    delay(5000);
    closegraph();
}