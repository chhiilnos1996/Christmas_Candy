#include"rh.h"
//fpoint constructure
fpoint::fpoint()
{
    img2 = newimage();
    color=randcolor();
    setfillcolor (color);
    setcolor(color);
    fillellipse (10, 10, 10, 10);
    getimage (img2,0,0,20,20);
}
