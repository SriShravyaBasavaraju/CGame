#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
char menu,submenu;
int life=3,score=0,speed=1000,X,Y,item;
int a1=35,a2=125,b1=195,b2=285,c1=355,c2=445,d1=515,d2=605;
char *points;
void baskets(void);
void biscuit(void);
void chocolate(void);
void flower(void);
void fruit(void);
void direction(char);
void mainmenu(void);
void menuloop(void);
void difficulty(void);
void start(void);
void credits(void);
void instruct(void);
void thanq(void);
void main()
{
 int t;
 int gdriver = DETECT, gmode;
 initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
 do
 {
  menuloop();
 }while(menu!='1' && menu!='4');
 if(menu=='1')
 {
 randomize();
 while(life!=0)
 {
  item=random(3);
  X=random(485);
  Y=10;
  t=move();
  if(t!=0) score+=t;
  else life-=1;
 }
 if(life==0)
 {
 cleardevice();
 setcolor(WHITE);
 settextstyle(TRIPLEX_FONT,0,2);
 outtextxy(200,200,"oops...!!GAME OVER");
 }
 }
 cleardevice();
 closegraph();
}
int move()
{
 char c;
 while(!kbhit())
 {
  baskets();
  switch(item)
  {
   case 0: biscuit();break;
   case 1: chocolate();break;
   case 2: fruit();break;
   case 3: flower();break;
  }
 delay(speed);
 cleardevice();
 X+=random(10);
 Y+=10;
 if(X>=a1+5 && X<=a2-5 && Y>=440 && item==0)
  return(10);
 if(X>=b1+5 && X<=b2-5 && Y>=440 && item==1)
  return(10);
 if(X>=c1+5 && X<=c2-5 && Y>=440 && item==2)
  return(10);
 if(X>=d1+5 && X<=d2-5 && Y>=440 && item==3)
  return(10);
 if(Y>440) return(0);
 }
 c=getch();
 direction(c);
}
void direction(char c)
{
 switch(c)
 {
  case '4': X-=10; if(X<0) X=0;break;
  case '6': X+=10; if(X>490) X=490;break;
  case '2': Y+=10;break;
 }
 move();
}
void biscuit()
{
 setfillstyle(BKSLASH_FILL,BROWN);
 bar3d(X,Y,X+37,Y+18,3,10);
 setfillstyle(SOLID_FILL,DARKGRAY);
 bar3d(X+5,Y+4,X+32,Y+14,1,1);
// settextstyle(SMALL_FONT,0,2);
 /*outtextxy(X+10,Y+7,"Tiger");*/
}
void chocolate()
{
 setfillstyle(BKSLASH_FILL,3);
 bar3d(X,Y-5,X+18,Y+5,1,1);
 gotoxy(X,Y);
 line(X-10,Y-4,X,Y);
 line(X-10,Y+8,X,Y);
 line(X+20,Y,X+30,Y-4);
 line(X+30,Y+8,X+20,Y-4);
}
void flower()
{
 /* x=10;
 y=15;
 setfillstyle(SOLID_FILL,4);*/
 setcolor(4);
 circle(X,Y,5);
 circle(X,Y+5,5);
 circle(X,Y-5,5);
 circle(X+5,Y,5);
 circle(X-5,Y,5);
}
void fruit()
{
 int stangle = 60, endangle = 120, radius = 20;
 setfillstyle(SOLID_FILL,RED);
 pieslice(X,Y,stangle, endangle, radius);
 line(X,Y-20,X,Y-40);
}
void baskets()
{
cleardevice();
 setcolor(WHITE);
 setfillstyle(BKSLASH_FILL,BROWN);
 bar3d(a1,430,a2,479,1,10);
 bar3d(b1,430,b2,479,1,10);
 bar3d(c1,430,c2,479,1,10);
 bar3d(d1,430,d2,479,1,10);
 setfillstyle(SOLID_FILL,BLACK);
 fillellipse(80,430,45,5);
 fillellipse(240,430,45,5);
 fillellipse(400,430,45,5);
 fillellipse(560,430,45,5);
 setcolor(BLACK);
 line(5,440,650,440);
 setcolor(WHITE);
 outtextxy(a1+17,450,"Biscuits");
 outtextxy(b1+6,450,"Chocolates");
 outtextxy(c1+23,450,"Fruits");
 outtextxy(d1+23,450,"Flowers");
 outtextxy(10,10,"LIFE: ");
 outtextxy(48,10,itoa(life,points,10));
 outtextxy(550,10,"SCORE: ");
 outtextxy(600,10,itoa(score,points,10));
}
void mainmenu()
{
 setcolor(BLACK);
 setfillstyle(SOLID_FILL,YELLOW);
 bar3d(0,5,getmaxx(),80,1,10);
 setcolor(BLACK);
 settextstyle(GOTHIC_FONT,0,5);
 outtextxy(210,15,"lucky basket");
 //setcolor(BLACK);
 setfillstyle(SOLID_FILL,WHITE);
 bar3d(20,100,getmaxx()-20,getmaxy()-30,1,10);
 setfillstyle(SOLID_FILL,BLACK);
 bar3d(205,100,205,getmaxy()-30,1,10);
 fillellipse(45,155,12,12);
 setcolor(WHITE);
 settextstyle(DEFAULT_FONT,0,1);
 outtextxy(43,150,"1");
 //setcolor(BLACK);
 setfillstyle(SOLID_FILL,BLACK);
 bar3d(58,140,190,170,1,10);
 setcolor(WHITE);
 settextstyle(DEFAULT_FONT,0,1);
 outtextxy(75,150,"START GAME");
 bar3d(225,120,getmaxx()-40,getmaxy()-50,1,10);
 setfillstyle(SOLID_FILL,BLACK);
 fillellipse(45,225,12,12);
 setcolor(WHITE);
 settextstyle(DEFAULT_FONT,0,1);
 outtextxy(43,221,"2");
 //setcolor(BLACK);
 setfillstyle(SOLID_FILL,BLACK);
 bar3d(58,210,190,240,1,10);
 setcolor(WHITE);
 settextstyle(DEFAULT_FONT,0,1);
 outtextxy(75,220,"INSTRUCTIONS");
 setfillstyle(SOLID_FILL,BLACK);
 fillellipse(45,300,12,12);
 setcolor(WHITE);
 settextstyle(DEFAULT_FONT,0,1);
 outtextxy(42,297,"3");
 //setcolor(BLACK);
 setfillstyle(SOLID_FILL,BLACK);
 bar3d(58,285,190,315,1,10);
 setcolor(WHITE);
 settextstyle(DEFAULT_FONT,0,1);
 outtextxy(75,295,"CREDITS");
 setfillstyle(SOLID_FILL,BLACK);
 fillellipse(45,375,12,12);
 setcolor(WHITE);
 settextstyle(DEFAULT_FONT,0,1);
 outtextxy(42,371,"4");
 //setcolor(BLACK);
 setfillstyle(SOLID_FILL,BLACK);
 bar3d(58,360,190,390,1,10);
 setcolor(WHITE);
 settextstyle(DEFAULT_FONT,0,1);
 outtextxy(75,370,"EXIT");
}
void menuloop()
{
 mainmenu();
 while(!kbhit())
{
setcolor(WHITE);
 settextstyle(SMALL_FONT,HORIZ_DIR,5);
outtextxy(50,455,"select main menu option number.....");
settextstyle(TRIPLEX_FONT,0,3);
outtextxy(350,200,"WELCOME");
outtextxy(390,250,"TO");
outtextxy(300,300,"LUCKY BASKET GAME");
}
 menu=getch();
  switch(menu)
  {
   case '1': difficulty();break;
   case '2': instruct();break;
   case '3': credits();break;
   case '4': thanq();break;
  }
}
void thanq(void)
{
 cleardevice();
 mainmenu();
 outtextxy(360,200,"BYE...BYE...");
 outtextxy(320,250,"Press any key to exit...");
 getch();
}
void difficulty(void)
{
  cleardevice();
  mainmenu();
  outtextxy(350,150,"Difficulty levels");
  outtextxy(380,220,"1: EASY");
  outtextxy(380,260,"2: MEDIUM");
  outtextxy(380,300,"3: HARD");
  outtextxy(300,380,"Press your choice level number...");
  submenu=getch();
  switch(submenu)
  {
   case '1': speed=1500;break;
   case '2': speed=1000;break;
   case '3': speed=200;break;
   //default:  outtextxy(300,380,"Wrong choice...press any key...");

  }
}
void instruct(void)
{
 cleardevice();
 mainmenu();
 outtextxy(350,150,"Game Instructions");
 outtextxy(230,200,"Four bins are placed at the bottom. Containg");
 delay(1000);
 outtextxy(230,210,"biscuits,chocolates,flowers,fruits. Any of the");
 delay(1000);
 outtextxy(230,220,"four objects fall randomly from the top of the");
 delay(1000);
 outtextxy(230,230,"screen. With the help of user keys, the user ");
 delay(1000);
 outtextxy(230,240,"should direct the object to the right bin....");
 delay(1000);
 outtextxy(230,250,"if u win---(+10points)...if u lose---(life-1).");
 delay(1000);
 outtextxy(320,290,"2->To move object Down");
 delay(1000);
 outtextxy(320,300,"4->To move object Left");
 delay(1000);
 outtextxy(320,310,"6->To move object Right");
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
 outtextxy(240,420,"Select another menu option to continue...");
 getch();
}
void credits(void)
{
 cleardevice();
 mainmenu();
 outtextxy(380,150,"Credits");
 outtextxy(240,200,"This game was developed under C Language...");
 outtextxy(400,220,"by");
 outtextxy(360,250,"P.SWATHI");
 outtextxy(360,270,"B.SRI SHRAVYA");
 outtextxy(360,290,"B.HIMABINDHU");
 outtextxy(240,320,"Under the guidance of...");
 outtextxy(360,345,"B.SRINIVAS");
 outtextxy(360,360,"Asst.Professor, CSE Dept,");
 outtextxy(360,375,"SNIST, Hyderadad.");
 outtextxy(240,420,"Select another menu option to continue...");
 getch();
}
