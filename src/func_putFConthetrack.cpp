#include"rh.h"
// judgment about color //whether to delete the ball or not


int putFConthetrack(candy&c,FrogCandy&f,int k,double angle)
{

    double FCangle=angle*180/PI;
    int roundstart=0;
    int fquadrant=0;
    int cquadrant=0;
    int start=0;

    //distance between the center and FC
    double FCdistance = sqrt(((Mid_X-f.FC[k].x)*(Mid_X-f.FC[k].x)+(Mid_Y-f.FC[k].y)*(Mid_Y-f.FC[k].y)));
    //判斷FC的象限
    if (FCangle>=0&&FCangle<90)fquadrant=4;
    else if (FCangle>=90&&FCangle<180)fquadrant=3;
    else if (FCangle>=180&&FCangle<270)fquadrant=2;
    else if (FCangle>=270&&FCangle<360)fquadrant=1;

    for (int j=0;j<=c.num;j++)
    {
        //判斷candy在第幾圈
        if (c.C[j].a<=360)c.C[j].round=0;
        else if (c.C[j].a>360&&c.C[j].a<=720)c.C[j].round=1;
        else if (c.C[j].a>720) c.C[j].round=2;
        //判斷candy象限
        if (c.C[j].a-c.C[j].round*360>=0&&c.C[j].a-c.C[j].round*360<90)cquadrant=4;
        else if (c.C[j].a-c.C[j].round*360>=90 &&c.C[j].a-c.C[j].round*360<180)cquadrant=3;
        else if (c.C[j].a-c.C[j].round*360>=180&&c.C[j].a-c.C[j].round*360<270)cquadrant=2;
        else if (c.C[j].a-c.C[j].round*360>=270&&c.C[j].a-c.C[j].round*360<360)cquadrant=1;
        //如果兩者象限一樣才開始下面的判斷
        if (cquadrant!=fquadrant)start++;
        else break;
    }


    for (int i=start;i<=c.num;i++)
    {

        if (c.C[i].a<=360)c.C[i].round=0;
        else if (c.C[i].a>360&&c.C[i].a<=720)c.C[i].round=1;
        else if (c.C[i].a>720) c.C[i].round=2;

        if (FCangle>(c.C[i].a-c.C[i].round*360)&&c.C[i].draw==true)
        {

        if (FCdistance>c.C[i].R&&c.C[i].draw==true&&f.FC[k].draw2==true&&abs(FCangle-(c.C[i].a-c.C[i].round*360))<15)

        {

        //後面的球編號+1

        for (int m=500;m>i;m--)
        {
            c.C[m].x=c.C[m-1].x;
            c.C[m].y=c.C[m-1].y;
            c.C[m].a=c.C[m-1].a;
            c.C[m].R=c.C[m-1].R;
            c.C[m].color=c.C[m-1].color;
            c.C[m].draw=c.C[m-1].draw;
            c.C[m].img1=c.C[m-1].img1;
        }
        //產生一顆與Frog candy一樣的candy C[i]，相當於把球塞進軌道


        c.C[i].x=f.FC[k].x;
        c.C[i].y=f.FC[k].y;
        c.C[i].color=f.FC[k].color;
        c.C[i].img1=f.FC[k].img2;
        f.FC[k].draw2=false;

        c.num++;


        return 1;

    }


    }


    }



}
