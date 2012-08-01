#include<stdio.h>
#include<process.h>
#include<iostream.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
void draw()
{
setbkcolor(0);
setlinestyle(0,0,0);
setcolor(9);
circle(320,240,3);
setcolor(11);  // for changing the colour around boundary of clock
setfillstyle(6,13);
circle(320,240,155); // for drawing inner-circle
circle(320,240,165); // for drawing outer-circle
floodfill(156,242,11);
settextstyle(2,0,5);
setcolor(140); // for changing the colour of numbers of clock
outtextxy(314,98,"12");
outtextxy(384,114,"1");
outtextxy(434,163,"2");
outtextxy(454,230,"3");
outtextxy(317,369,"6");
outtextxy(177,230,"9");
outtextxy(436,300,"4");
outtextxy(195,302,"8");
outtextxy(195,163,"10");
outtextxy(244,112,"11");
outtextxy(388,353,"5");
outtextxy(248,353,"7");
}
void main()
{

int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");

draw();
//line(320,240,320,130);
//line(320,240,320,150);
//getch();
float s;
float df;
//s=282*M_PI/180;
//float angle=4.712389;
//float an=4.712389;
float anf=4.712389;
int x,y;
int q,w;
int ta,d;
int count=0;
struct  time t;
gettime(&t);
float angle=4.712389+t.ti_sec*.1047198;
float an=4.712389+t.ti_min*.1047198;
while(!kbhit())
{
draw();
gettime(&t);
gotoxy(5,5);
angle=4.712389+t.ti_sec*.1047198; // degree of rotation of seconds hand
an=4.712389+t.ti_min*.1047198; // degree of rotation of minute hand
anf=4.712389+t.ti_hour*5*.1047198 ; // degree of rotation of hour hand
if(t.ti_min>=12&&t.ti_min<24)
{
anf=anf+2*.1047198;
}
if(t.ti_min>=24&&t.ti_min<36)
{
anf=anf+(3*.1047198);
}
if(t.ti_min>=36&&t.ti_min<48)
{
anf=anf+(4*.1047198);
}
if(t.ti_min>=48&&t.ti_min<60)
{
anf=anf+(5*.1047198);
}
//cout<<"   ";
setlinestyle(0,0,0);
setcolor(0); // to put black color on the existing line
line(320,240,x,y);
line(320,240,q,w);line(320,240,ta,d);
x=320+140*cos(angle);
y=240+140*sin(angle);
q=320+122*cos(an);
w=240+122*sin(an);
ta=320+86*cos(anf);
d=240+86*sin(anf);
setcolor(120); // color of seconds hand
setlinestyle(0,0,0);
line(320,240,x,y);
setlinestyle(0,0,2);
setcolor(5); // color of minute hand
line(320,240,q,w);
setlinestyle(0,0,3);
setcolor(4);
line(320,240,ta,d);
angle+=.1047198;
delay(100); // sets delay time of outtext credits
count++;
setcolor(count);
outtextxy(30,410,"COMPUTER GRAPHICS PROJECT BY :");
outtextxy(30,430,"Palak Kala, Kunj Karia and Ketan Kaul");
outtextxy(30,450,"D7/22/23/24");
}
getch();
closegraph();
}

