
//Scan convert Circle using Midpoint Circle Algorithm
#include <graphics.h>
#include <conio.h>

void drawCircle(int xc, int yc, int x, int y)
{
    putpixel(xc+x, yc+y, WHITE);
    putpixel(xc-x, yc+y, WHITE);
    putpixel(xc+x, yc-y, WHITE);
    putpixel(xc-x, yc-y, WHITE);
    putpixel(xc+y, yc+x, WHITE);
    putpixel(xc-y, yc+x, WHITE);
    putpixel(xc+y, yc-x, WHITE);
    putpixel(xc-y, yc-x, WHITE);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = 250, yc = 250, r = 100;
    int x = 0, y = r;
    int p = 1 - r;

    drawCircle(xc, yc, x, y);

    while(x < y)
    {
        x++;
        if(p < 0)
            p = p + 2*x + 1;
        else
        {
            y--;
            p = p + 2*x - 2*y + 1;
        }
        drawCircle(xc, yc, x, y);
    }

    getch();
    closegraph();
    return 0;
}
