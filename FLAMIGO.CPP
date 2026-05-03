#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>

void drawBackground(int cloudOffset) {
    rectangle(0,0,638,478);

    setcolor(YELLOW);
    circle(300,100,20);
    circle(300,100,18);

    line(300,80,300,65);  
    line(300,120,300,135); 

    line(320,100,335,100); 
    line(280,100,265,100); 

    line(315,85,330,70);   
    line(285,85,270,70);  

    line(315,115,330,130);
    line(285,115,270,130); 

    setcolor(GREEN);
    line(0,150,638,150);
    ellipse(630,420,89,180,654,244);

    setcolor(LIGHTCYAN);
    ellipse(80 + cloudOffset,82,0,170,30,10);
    ellipse(30 + cloudOffset,76,14,180,30,10);
    ellipse(100 + cloudOffset,92,320,90,30,10);
    ellipse(122 + cloudOffset,115,284,94,30,16);
    ellipse(90 + cloudOffset,130,180,24,40,10);
    ellipse(40 + cloudOffset,135,180,340,40,10);
    ellipse(-20 + cloudOffset,120,160,300,50,20);
    ellipse(-20 + cloudOffset,84,45,170,30,10);
    ellipse(-40 + cloudOffset,105,90,220,40,22);

    ellipse(504 + cloudOffset,50,0,170,20,10);
    ellipse(488 + cloudOffset,60,96,270,15,10);
    ellipse(504 + cloudOffset,70,176,320,20,10);
    ellipse(548 + cloudOffset,74,180,320,30,10);
    ellipse(588 + cloudOffset,86,170,340,40,10);
    ellipse(630 + cloudOffset,96,180,320,48,18);
    ellipse(540 + cloudOffset,40,0,170,30,10);
    ellipse(600 + cloudOffset,40,0,156,60,25);
}

void drawBirds(int offset, int flap) {
    setcolor(LIGHTMAGENTA);
    int i;
    int baseY[] = {20, 50, 50, 20, 12, 50, 16, 16, 100};
    for(i = 0; i < 9; i++) {
	int x = 40 + i * 70 + offset;
	int y = baseY[i];
	int wing = (flap ? 4 : -4);
	line(x, y, x + 10, y + wing);
	line(x + 10, y + wing, x + 20, y);
    }
}

void drawWater(int offset) {
    setcolor(BLUE);
    ellipse(630,420,89,180,650,240);
    ellipse(630 + offset,420,100,130,560,200);
    ellipse(630 + offset,420,100,120,400,150);
    ellipse(630 + offset,420,100,150,300,80);
    ellipse(600 + offset,480,140,170,500,170);
}

void drawFlamingo(int headY) {
    setcolor(LIGHTMAGENTA);
    ellipse(306,394,0,360,30,14);
    ellipse(306,394,140,220,26,12);
    ellipse(304,396,10,132,26,12);
    ellipse(340,410,100,152,60,16);

    ellipse(306,394,320,30,32,16);
    line(334,386,370,414 + headY/2);
    line(330,406,370,414 + headY/2);

    setcolor(MAGENTA);
    line(288,406,294,414);
    line(300,408,299,414);
    line(307,408,317,414);
    line(321,407,322,413);

    setcolor(BROWN);
    line(295,414,293,446);
    line(298,414,296,446);
    line(291,457,284,478);
    line(294,458,288,478);
    line(293,446,290,452);
    line(290,452,291,457);

    line(296,446,297,453);
    line(297,453,294,458);

    line(318,414,336,444);
    line(322,414,338,440);
    line(335,450,310,478);
    line(338,453,315,478);
    line(336,444,335,450);
    line(338,440,343,450);
    line(343,450,338,453);

    setcolor(LIGHTMAGENTA);
    line(283,316 + headY/2,290,330 + headY/2);
    line(278,328 + headY/2,290,330 + headY/2);
    line(270,315 + headY/2,283,316 + headY/2);
    line(270,329 + headY/2,278,328 + headY/2);
    line(283,316 + headY/2,258,376);
    line(290,330 + headY/2,272,372);
    line(258,376,270,372);
    line(258,376,272,386);
    line(272,372,284,382);
    line(272,386,284,382);

    ellipse(268,322 + headY/2,0,360,10,7);
    circle(264,320 + headY/2,2);

    setcolor(BROWN);
    line(260,318 + headY/2,246,322 + headY/2);
    line(246,322 + headY/2,240,340 + headY/2);
    line(240,340 + headY/2,250,328 + headY/2);
    line(252,323 + headY/2,253,322 + headY/2);
    line(240,340 + headY/2,252,330 + headY/2);
    line(252,330 + headY/2,262,328 + headY/2);
}

void main() {
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");

    int waveOffset = 0, waveDir = 1;
    float angle = 0;
    int birdOffset = 0;
    int flap = 0;
    int flapDelay = 0;
    int cloudOffset = 0;

    while(!kbhit()) {
	cleardevice();

	drawBackground(cloudOffset);
	drawBirds(birdOffset, flap);
	drawWater(waveOffset);
	drawFlamingo((int)(10*sin(angle)));

	delay(50);

	waveOffset += waveDir;
	if(waveOffset > 10 || waveOffset < -10) waveDir = -waveDir;

	angle += 0.2;

	birdOffset -= 1;
	if(birdOffset < -300) birdOffset = 0;
	flapDelay++;
	if(flapDelay > 6) {
	    flap = !flap;
	    flapDelay = 0;
	}

	cloudOffset += 1;
	if(cloudOffset > 50) cloudOffset = 0;
    }

    getch();
    closegraph();
}