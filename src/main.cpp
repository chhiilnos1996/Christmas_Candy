
#include "rh.h"
#include<ctime>

int main()
{

    MUSIC mus; // 定義一個音樂對象
    mus.OpenFile("music.mp3"); // 打開音樂檔
    mus.SetVolume(0.5f); //設置音量，從0.0-1.0f

    srand(time(NULL));
    setinitmode(INIT_RENDERMANUAL|INIT_NOFORCEEXIT);
    initgraph (960,600);

    //start page.
    beginpage();
    cleardevice();
    candy c;//construct the classes
    FrogCandy f;

    int k = 0;
    int score=0;
    int totalscore=0;
    int numball=0;
    int numberoftimes=0;//for printing the score
    char NUM[8];

    PIMAGE img;
    img=newimage();
    getimage(img,"MTXX_20141226_track_meitu_1_meitu_1.jpg",0,0);



    for (; is_run(); delay_fps(60))
    {

        if (mus.GetPlayStatus() == MUSIC_MODE_STOP) { mus.Play(0);}
        cleardevice ();
        c.update ();
        putimage(0,0,960,600,img,0,0,1449,944);
        c.draw ();

        setfont(30, 0, "HeavenlyWings");
        setcolor(EGERGB(255, 245, 66));
        outtextxy(730,270,"Start");
        outtextxy(420,350,"End");

        if(c.gamecont)
        {

            f.draw(k);
            ThreeOrMoreSame(c,score,totalscore,numball,numberoftimes);
            printscorefunc(c,f,score,totalscore,numball,numberoftimes);

            mouse_msg msg = {0};
            while (mousemsg())
            {
                msg = getmouse();
            }
            if(msg.x>=50&&msg.x<=250&&msg.y>=500&&msg.y<=600)
                setcolor(EGERGB(0x54, 0xFC, 0x54));
            else
                setcolor(EGERGB(0xFC, 0x54, 0x54));
            if (msg.is_down())
            {
                double angle=f.mouse();
                //if the wants to jump to the end page;
                if(msg.x>=50&&msg.x<=250&&msg.y>=500&&msg.y<=600)
                {
                    c.gamecont=false;
                }
                while(f.FC[k].x<2*Mid_X&&f.FC[k].x>0&&f.FC[k].y<2*Mid_Y&&f.FC[k].y>0&&f.FC[k].draw2==true)//當發出去的球還在畫面上時
                {
                    cleardevice ();

                    putimage(0,0,960,600,img,0,0,1449,944);
                    putFConthetrack(c,f,k,angle);
                    f.update (k,angle);
                    c.draw();
                    ThreeOrMoreSame(c,score,totalscore,numball,numberoftimes);
                    printscorefunc(c,f,score,totalscore,numball,numberoftimes);

                    outtextxy(50,500,"QUIT");
                    setfont(30, 0, "HeavenlyWings");
                    setcolor(EGERGB(255, 245, 66));
                    outtextxy(730,270,"Start");
                    outtextxy(420,350,"End");


                    if(c.gamecont==true)
                    {f.draw(k);
                    f.drawnext(k);}

                    Sleep(10);

                }
                k++;
                angle=0;


            }
            outtextxy(50,500,"QUIT");

        }
        else
            break;
        outtextxy(50,500,"QUIT");//show the exit option;
    }

    endpage(totalscore,mus);
    mus.Close();
    closegraph();


    return 0;
}
