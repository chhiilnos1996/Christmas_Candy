#ifndef RH_H_INCLUDED
#define RH_H_INCLUDED

#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <cmath>
#include <ctime>
#include <windows.h>

#define  LB  75
#define  RB  77
#define  ESC 27
#define  ms  100

#define MaxNum 500
#define PI 3.1415926
#define Mid_X 480
#define Mid_Y 300
#define Radius 250

using namespace std;

//balls on the track

color_t randcolor();

struct fpoint
{
    double x, y;
    double ang;
    PIMAGE img2;
    color_t color;
    fpoint();
    bool draw2=true;

};
class FrogCandy
{

    int  num;
public:
    fpoint FC[MaxNum];
    FrogCandy() ;
    ~FrogCandy ()
    {
        closegraph ();
    }
    void initial (int x0, int y0);
    void draw (int);
    void drawnext(int);
    void update (int,double);
    double mouse ();

};

struct cpoint
{
    double a;


    double x, y;
    double R;
    int round;//記錄轉了幾圈

    PIMAGE img1;
    color_t color;

    bool draw=false;//whether to disappear or not

    cpoint();

    void renewxyR();
    void newcpoint();
};


class candy
{
public:
    int num=0;
    cpoint C[MaxNum];
    int shoot=5;


    double ctem[MaxNum];//cpointtemporary : store the value of angle
    int ndc[MaxNum];
    int ndc2[MaxNum];
    double freeangle(int j);
    void renewndc();
    void renewndc2();
    double needspace[MaxNum];


    ~candy (){closegraph ();}
    void draw ();
    void nocollision();
    void plusa();
    void update ();


    bool gamecont=true;
    int newcandy=0;
};


int putFConthetrack(candy&c,FrogCandy&f,int k,double angle);
void printscorefunc(candy&c,FrogCandy&f,int score,int totalscore,int numball,int& numberoftimes);
void ThreeOrMoreSame(candy&c,int &score,int &totalscore,int &numball,int &numberoftimes);
void bckpic();
void text();
void clickbegin();
void getch();
void beginpage();
void endpage(int,MUSIC);
#endif // RH_H_INCLUDED
