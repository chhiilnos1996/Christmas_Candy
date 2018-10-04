#include"rh.h"
void total_score(int totalscore)
{
    setbkmode(TRANSPARENT);
    setcolor(EGERGB(255, 255, 255));//字體顏色；
    setfont(96, 0, "HeavenlyWings");//字體大小，縮放，字體名稱；
    char total[8];
    sprintf(total,"%d",totalscore);//transform int score into string;
    outtextxy(200,200,"total score");
    outtextxy(200,300,total);//text x,y,內容
}

void exit(MUSIC mus)
{
    mouse_msg msg= {0};
    for ( ; is_run(); delay_fps(60))
    {
        if (mus.GetPlayStatus() == MUSIC_MODE_STOP) { mus.Play(0);}
        if((msg.x<=200||msg.x>=400)&&(msg.y<=400||msg.y>=500))
            setcolor(EGERGB(0xFC, 0x54, 0x54));//字體顏色；
        outtextxy(200,400,"EXIT");

        mouse_msg msg={0};
        while(mousemsg())
        {
            msg=getmouse();
        }

        if(msg.x>=200&&msg.x<=400&&msg.y>=400&&msg.y<=500)
            setcolor(EGERGB(0x54, 0xFC, 0x54));//字體顏色；
        outtextxy(200,400,"EXIT");

        if(msg.is_down())
        {
            if(msg.x>=200&&msg.x<=400&&msg.y>=400&&msg.y<=500)
            {
                closegraph();
                break;
            }
        }
    }



}
void endpage(int totalscore,MUSIC mus)
{
    //print the total score.
    bckpic();
    total_score(totalscore);

    //exit.
    exit(mus);
    //Sleep(800);
    //closegraph();
}
