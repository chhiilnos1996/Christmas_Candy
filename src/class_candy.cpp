#include "rh.h"

//draw the candies on the track
cpoint::cpoint()
{
    color=randcolor();//color of ball
    img1 = newimage();
    setfillcolor (color);
    setcolor(color);
    fillellipse (10, 10, 10, 10);
    getimage (img1,0,0,20,20);
}

void cpoint::renewxyR()
{
    R=Radius-0.25*a;
    x=Mid_X+R*cos(a*PI/180);
    y=Mid_Y+R*sin(a*PI/180);

}

void cpoint::newcpoint()
{
    a=0;
    x=Mid_X;
    y=Mid_Y;
    R=Radius;
    draw=true;
    renewxyR();
    putimage_transparent (NULL, img1, x, y, BLACK);
}
//track function begins



void candy::renewndc()
{
    for(int j=num-1; j>0; j--) //determine ndc
    {
            ndc[j]=-1;//ndc:nearest candy with draw==true
            for(int t=j-1; t>=0; t--) //find the first candy (index>j) with draw==true
            {
                if(C[t].draw==true)
                {
                    ndc[j]=t;
                    break;
                }
            }
    }
    ndc[0]=-1;
}
void candy::renewndc2()
{
     for(int j=0; j<num-1; j++)
    {
            if(C[j].draw==true)
            {
                ndc2[j]=-1;//ndc2:nearest candy(index>j) with draw==true
                for(int t=j+1; t<=num; t++) //find the first candy (index>j) with draw==true
                {
                    if(C[t].draw==true)
                    {
                    ndc2[j]=t;
                    break;
                    }
                }
            }
    }
    ndc2[num-1]=-1;
}

void candy::draw ()
{
    int i = 0;

    while (i<num)
    {

        if ( C[i].x>0 && C[i].x<2*Mid_X && C[i].y>0 && C[i].y<2*Mid_Y&&C[i].draw==true )
            putimage_transparent (NULL, C[i].img1, (int)C[i].x, (int)C[i].y, BLACK);
        i++;
    }

}

double candy::freeangle(int j)
{
if((C[j].draw==true)&&(ndc[j]!=-1))

    {
        double distancesquare=(C[j].x-C[ndc[j]].x)*(C[j].x-C[ndc[j]].x)+(C[j].y-C[ndc[j]].y)*(C[j].y-C[ndc[j]].y);
        double angle1=acos(((C[j].R)*(C[j].R)+(C[ndc[j]].R)*(C[ndc[j]].R)-distancesquare)/(2*(C[j].R)*(C[ndc[j]].R)));
        double angle2=acos(((C[j].R)*(C[j].R)+(C[ndc[j]].R)*(C[ndc[j]].R)-400)/(2*(C[j].R)*(C[ndc[j]].R)));
        return angle1-angle2;
    }
else return 0;
}

void candy::plusa()
{
    for(int j=0; j<=num; j++)//store temporary value of angle
    {ctem[j]=C[j].a;}

    renewndc();
    renewndc2();

       for(int j=0; j<num; j++)
       {
           if(C[j].draw==true)
           {
                needspace[j]=asin(20/C[j].R)*180/PI;
                if(ndc2[j]!=-1)
                {
                    if((ctem[j]-ctem[ndc2[j]])>needspace[j])
                    {C[j].a+=0;}
                    else if(ndc[j]==-1)
                    {C[j].a+=1/(1+100*C[j].a);}
                    else
                    {C[j].a+=min((ctem[ndc[j]]-ctem[j]+0.1*j)*0.05,freeangle(j));}
                }
                else
                {
                    if(ndc[j]==-1)
                    {C[j].a+=1;}
                    else

                    {C[j].a+=1/(1+C[j].a);}
                }
                 C[j].renewxyR();
           }
       }
}






void candy::nocollision()
{
    renewndc();

    for(int j=num; j>0; j--) // 調整順序及使小球無交集
    {
        if(C[j].draw==true)
        {

            if(ndc[j]!=-1)
            {
               needspace[j]=asin(20/C[j].R)*180/PI;
               C[ndc[j]].a=((needspace[j]+C[j].a-C[ndc[j]].a)>0?(needspace[j]+C[j].a):(C[ndc[j]].a));//not the precise solution but with acceptable error
               C[ndc[j]].renewxyR();
            }
        }
    }
}


void candy::update()
{
    int madc=-1;//cpoint with minimun angle and draw==true
    for(int j=num;j>=0;j--)
    {
    if(C[j].draw==true)
    {
        madc=j;
        break;
    }
    }

    if(madc==-1)
    {
        C[num].newcpoint();
        num++;
    }


    #if CHALLENGEMODE
    #endif MODESWITCHINGDONE// CHALLENGEMODE
    shoot=8;
    #define MODESWITCHINGDONE


        if(C[madc].a>shoot)
        {
        C[num].newcpoint();
        num++;
        }






    plusa();
    nocollision();
    draw();
    cleardevice();

    for(int j=0; j<num; j++)
    {
        if(C[j].a>800&&C[j].draw==true)
        {
            gamecont=false;
            break;
        }
    }
    newcandy+=1;

}
