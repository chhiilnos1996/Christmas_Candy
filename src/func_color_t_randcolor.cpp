#include "rh.h"
//color control function
color_t randcolor()
{
    int i=rand()%5;
    char col[6]= {'a','b','c','d','e'};
    char c=col[i];

    switch(c)
    {
    case 'a':
        return EGERGB(0xFC,0xA8,0x54);
        break;
    case 'b':
        return EGERGB(255,50,50);
        break;
    case 'c':
        return EGERGB(100,252,100);
        break;
    case 'd':
        return EGERGB(252,84,252);
        break;
    case 'e':
        return EGERGB(84,84,252);
    }
}
