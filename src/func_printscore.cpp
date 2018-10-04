
#include"rh.h"

void printscorefunc(candy&c,FrogCandy&f,int score,int totalscore,int numball,int& numberoftimes)
{
    char printscore[5];
    char printtotalscore[8];
    char s='+';
    char t[]="Total Score:";
    setfont(30, 0, "HeavenlyWings");

    if (numberoftimes<=20&&score>0)//if numberoftimes>20 ,remove the score
    {
        setbkmode(TRANSPARENT);
        sprintf(printscore, "%d", score*score*100);
        outtextxy(c.C[numball].x-60,c.C[numball].y-numberoftimes,s);
        outtextxy(c.C[numball].x-20, c.C[numball].y-numberoftimes, printscore);

    }
    setfont(40, 0, "HeavenlyWings");
    setbkmode(TRANSPARENT);
    setcolor(EGERGB(0xFC, 0x54, 0x54));
    outtextxy(350,40,t);
    sprintf(printtotalscore,"%d",totalscore);
    outtextxy(550,40,printtotalscore);
    numberoftimes++;



}
