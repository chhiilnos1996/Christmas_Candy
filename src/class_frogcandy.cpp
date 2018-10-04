#include"rh.h"
//frogcandy constructure
FrogCandy::FrogCandy()
{
    initial (Mid_X, Mid_Y);
}

//Initialize
void FrogCandy::initial (int x0, int y0)
{
    // Initialize every Frogcandy
    for (int i=0; i<MaxNum; i++)
    {
        FC[i].x      = x0;
        FC[i].y      = y0;

    }
}
// draw Frogcandy
void FrogCandy::draw (int k)
{
    if(FC[k].draw2==true)
    putimage_transparent (NULL, FC[k].img2, (int)FC[k].x, (int)FC[k].y, BLACK);//draw out the shooting ball

}
void FrogCandy::drawnext(int k)
{
    putimage_transparent (NULL, FC[k+1].img2, (int)FC[k+1].x, (int)FC[k+1].y, BLACK);//show the color of the next ball
}
// update the position of every Frogcandy
void FrogCandy::update (int k,double angle)
{
    FC[k].x += cos ( angle) * 10;
    FC[k].y += sin ( angle  ) * 10;

}
//about mouse control
double FrogCandy::mouse()
{
    char str[32];
    int x, y;
    double sin;
    double ang;
    mousepos(&x, &y);
    //sprintf(str, "%4d %4d", x, y);
    //outtextxy(0, 0, str);
    if(x>Mid_X&&y<Mid_Y)//quadrant = 1
    {
        ang=2*PI-asin((Mid_Y-y)/sqrt((x-Mid_X)*(x-Mid_X)+(y-Mid_Y)*(y-Mid_Y)));
        return ang;
    }
    if (x<=Mid_X&&y<Mid_Y)//quadrant = 2
    {
        ang=PI+asin((Mid_Y-y)/sqrt((x-Mid_X)*(x-Mid_X)+(y-Mid_Y)*(y-Mid_Y)));
        return ang;
    }
    if(x<=Mid_X&&y>Mid_Y)//quadrant = 3
    {
        ang=PI-asin((y-Mid_Y)/sqrt((x-Mid_X)*(x-Mid_X)+(y-Mid_Y)*(y-Mid_Y)));
        return ang;
    }
    if (x>Mid_X&&y>Mid_Y)//quadrant = 4
    {
        ang=asin((y-Mid_Y)/sqrt((x-Mid_X)*(x-Mid_X)+(y-Mid_Y)*(y-Mid_Y)));
        return ang;
    }

}
