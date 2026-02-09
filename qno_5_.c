#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = 250, yc = 250;
    int rx = 150, ry = 80;

    float dx, dy, d1, d2;
    int x = 0;
    int y = ry;

    d1 = (ry*ry) - (rx*rx*ry) + (0.25*rx*rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    // Region 1
    while(dx < dy)
    {
        putpixel(xc+x, yc+y, WHITE);
        putpixel(xc-x, yc+y, WHITE);
        putpixel(xc+x, yc-y, WHITE);
        putpixel(xc-x, yc-y, WHITE);

        if(d1 < 0)
        {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }

    // Region 2
    d2 = ((ry*ry)*((x+0.5)*(x+0.5))) +
         ((rx*rx)*((y-1)*(y-1))) -
         (rx*rx*ry*ry);

    while(y >= 0)
    {
        putpixel(xc+x, yc+y, WHITE);
        putpixel(xc-x, yc+y, WHITE);
        putpixel(xc+x, yc-y, WHITE);
        putpixel(xc-x, yc-y, WHITE);

        if(d2 > 0)
        {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }

    getch();
    closegraph();
    return 0;
}
