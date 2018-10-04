#include"rh.h"

void bckpic()
{
    PIMAGE img;
    img=newimage();
    getimage(img,"new_year_light.jpg",0,0);
    putimage(0,0,960,600,img,0,0,1024,685);
    delimage(img);
}

void textiniZOOMA(PIMAGE img)
{
    setbkmode(TRANSPARENT);
    setcolor(EGERGB(0x54, 0xFC, 0xFC));//字體顏色；
    setfont(80, 0, "HeavenlyWings");//字體大小，縮放，字體名稱；
    outtextxy(0, 100, "CHRISTMAS CANDY!!!");//text x,y,內容；
    getimage(img,0,100,800,200);
    cleardevice();

}


void picZOOMA(PIMAGE nimg)
{
    int x,y;
        x=60;
        y=0;
    for ( ; is_run(); delay_fps(60))
    {
        y=y+15;
        bckpic();
        putimage_transparent(NULL,nimg,60,y,BLACK);
        //cleardevice();
        if(y>=200)break;
    }

    //end.
}
void clickbegin()
{

    //get mouse position.
    mouse_msg msg = {0};
	for ( ; is_run(); delay_fps(60))
    {
        cleardevice();
        PIMAGE img;
    img=newimage();
    getimage(img,"new_year_light.jpg",0,0);
    putimage(0,0,960,600,img,0,0,1024,685);
        bool stay=0;
        //setfont(16, 0, "HeavenlyWings");//字體大小，縮放，字體名稱；
        while (mousemsg()) {msg = getmouse();}
        //cleardevice();
        //xyprintf(0, 0, "x = %10d y = %10d", msg.x, msg.y);



        setcolor(EGERGB(0xFC, 0x54, 0x54));
        setfont(72, 0, "HeavenlyWings");
        outtextxy(200, 340, "RELAX MODE");
        outtextxy(200, 420, "CHALLENGE MODE");
        setfont(36, 0, "HeavenlyWings");
        outtextxy(200, 505,"HOW TO PLAY?");
        //mouse_msg msg={0};
        while (mousemsg()){msg = getmouse();}
        if((msg.x>=200)&&(msg.x<=640)&&(msg.y>=340)&&(msg.y<=400))
        {
            setfont(72, 0, "HeavenlyWings");
            setcolor(EGERGB(0x54, 0xFC, 0x54));
            outtextxy(200, 340, "RELAX MODE");
            setcolor(EGERGB(0xFC, 0x54, 0x54));
            outtextxy(200, 420, "CHALLENGE MODE");
            setfont(36, 0, "HeavenlyWings");
            outtextxy(200,505,"HOW TO PLAY");
            //Sleep(50);

        }

        if((msg.x>=200)&&(msg.x<=830)&&(msg.y>=420)&&(msg.y<=500))
        {
            setfont(72, 0, "HeavenlyWings");
            setcolor(EGERGB(0xFC, 0x54, 0x54));
            outtextxy(200, 340, "RELAX MODE");
            setcolor(EGERGB(0x54, 0xFC, 0x54));
            outtextxy(200, 420, "CHALLENGE MODE");
            setfont(36, 0, "HeavenlyWings");
            setcolor(EGERGB(0xFC, 0x54, 0x54));
            outtextxy(200,505,"HOW TO PLAY");

            //Sleep(50);

        }

        if((msg.x>=200)&&(msg.x<=450)&&(msg.y>520)&&(msg.y<=535))
        {
            setfont(36, 0, "HeavenlyWings");
            setcolor(EGERGB(0x54, 0xFC, 0x54));
            outtextxy(200,505,"HOW TO PLAY?");
            setfont(72, 0, "HeavenlyWings");
            setcolor(EGERGB(0xFC, 0x54, 0x54));
            outtextxy(200, 420, "CHALLENGE MODE");
            outtextxy(200, 340, "RELAX MODE");
            //Sleep(50);

        }

        if (msg.is_down())
        {
            if(msg.x>=200&&msg.x<=640&&msg.y>=340&&msg.y<=450)
            {
                setfont(300, 0, "HeavenlyWings");
                setcolor(EGERGB(0x54, 0xFC, 0xFC));
                cleardevice();
                outtextxy(450,150,"3");
                Sleep(1000);
                cleardevice();
                outtextxy(450,150,"2");
                Sleep(1000);
                cleardevice();
                outtextxy(450,150,"1");
                Sleep(1000);
                cleardevice();
                outtextxy(300,150,"GO");
                Sleep(1000);
                cleardevice();
                break;
            }

            if(msg.x>=200&&msg.x<=830&&msg.y>=420&&msg.y<=500)
            {
                setfont(300, 0, "HeavenlyWings");
                setcolor(EGERGB(0x54, 0xFC, 0xFC));
                cleardevice();
                outtextxy(450,150,"3");
                Sleep(1000);
                cleardevice();
                outtextxy(450,150,"2");
                Sleep(1000);
                cleardevice();
                outtextxy(450,150,"1");
                Sleep(1000);
                cleardevice();
                outtextxy(300,150,"GO");
                Sleep(1000);
                cleardevice();
                #define CHALLENGEMODE
                break;
            }

            if((msg.x>=200)&&(msg.x<=450)&&(msg.y>520)&&(msg.y<=535))
            {
            cleardevice();
            setfont(36, 0, "HeavenlyWings");
            setcolor(EGERGB(0x54, 0xFC, 0x54));

            outtextxy(320, 60, "MOVE THE CURSOR ");
            outtextxy(250, 120, "TO THE DESIRED DIRECTION ");
            outtextxy(260, 180, "CLICK TO SHOOT A CANDY ");
            outtextxy(70,  240, "MORE THAN THREE CANDY WITH THE SAME COLOR");
            outtextxy(245, 300, "VANISHES WHEN THEY MEET");
            outtextxy(300, 360, "GAME IS OVER WHEN :" );
            outtextxy(120, 420, "ANY CANDY REACHES THE END OF THE ORBIT" );
            setcolor(EGERGB(0xFC, 0x54, 0x54));
            outtextxy(360, 500, "BACK TO MENU");
            stay=1;
            }
            /* while (mousemsg()) {msg = getmouse();
            cleardevice();
            xyprintf(0, 0, "x = %10d y = %10d", msg.x, msg.y);}*/

        }

            if(stay==1)
            {
                for( ; is_run(); delay_fps(60))
                {
                while (mousemsg()) {msg = getmouse();}
                if(msg.x>=360&&msg.x<=620&&msg.y>=500&&msg.y<=530)
                {
                    setcolor(EGERGB(0x54, 0xFC, 0x54));
                    outtextxy(360, 500, "BACK TO MENU");
                    Sleep(300);
                    setcolor(EGERGB(0xFC, 0x54, 0x54));
                    outtextxy(360, 500, "BACK TO MENU");
                }
                 if((msg.x>=360&&msg.x<=620&&msg.y>=500&&msg.y<=530)&&msg.is_down())  {break;}
                }
            }

    }

}

void beginpage()
{
    PIMAGE img;
    img=newimage();
    textiniZOOMA(img);
    //background pic.
    bckpic();
    Sleep(500);
    //words.

    picZOOMA(img);
    //click.
    clickbegin();
    //end.
}
