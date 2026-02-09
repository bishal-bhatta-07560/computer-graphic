
//1. Plot basic graphic primitives Line, Circle, Rectangle, Triangle

#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Line
    line(50, 50, 200, 50);

    // Rectangle
    rectangle(50, 100, 200, 200);

    // Circle
    circle(350, 150, 50);

    // Triangle (using 3 lines)
    line(300, 250, 400, 250);
    line(400, 250, 350, 180);
    line(350, 180, 300, 250);

    getch();
    closegraph();
    return 0;
}
