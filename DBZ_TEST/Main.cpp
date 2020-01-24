#include "iGraphics.h"
#include "bitmap_loader.h"
#include "background.h"
#include "Player.h"
#include "Enemy.h"
#include "Name_Input.h"
#include "Menu.h"



void iDraw()
{	
	if (Screen==1)
	{
		iClear();
		Home();
	}
	if (Screen==2)
	{
		iClear();
		Menu();
	}
	if (Screen==3)
	{
		iClear();
		background();
		player_change();
		enemyMain_change();
		enemy_change();
		obstacle_change();
	}
	if (Screen == 4) 
		highscore();

	if (Screen==5)
		aboutus();

	if (Screen==6)
		pause();
	
	if (Screen==7)
		instruction();

	
	
	/*if (Screen == 8)
	{
		
		iSetColor(255, 255, 255);
		iFilledRectangle(0, 0, 400, 400);
		drawTextBox();
		if (mode == 1)
		{
			iSetColor(0, 0, 0);
			iText(55, 260, str, GLUT_BITMAP_TIMES_ROMAN_24);
		}

		iText(10, 10, "Click to activate the box, enter to finish.");
	}*/
	
	
	//iShowBMP2(100, 100, "img\\FG\\5.bmp",0);

	


}
void iMouseMove(int mx, int my)
{

}
void iPassiveMouseMove(int mx, int my)
{
	if (mx >= 800 && mx <= 1000 && my >= 500 && my <= 570 && Screen == 2)
		move[0] = true;  else move[0] = false;  //play
	if (mx >= 800 && mx <= 1000 && my >= 400 && my <= 470 && Screen == 2)
		move[1] = true;  else move[1] = false;  //high score
	if (mx >= 800 && mx <= 1000 && my >= 300 && my <= 370 && Screen == 2)
		move[2] = true;  else  move[2] = false;  //about
	if (mx >= 800 && mx <= 1000 && my >= 200 && my <= 270 && Screen == 2)
		move[3] = true; else move[3] = false;  //instruction
	if (mx >= 800 && mx <= 1000 && my >= 100 && my <= 170 && Screen == 2)
		move[4] = true; else move[4] = false; // exit

	if (mx >= 750 && mx <= 950 && my >= 450 && my <= 520 && Screen == 6)
		move[5] = true; else move[5] = false; //resume
	if (mx >= 750 && mx <= 950 && my >= 350 && my <= 420 && Screen == 6)
		move[6] = true; else move[6] = false; // Main Menu
	if (mx >= 750 && mx <= 950 && my >= 250 && my <= 320 && Screen == 6)
		move[7] = true; else move[7] = false; //exit

}

void iMouse(int button, int state, int mx, int my)
{
	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("x : %d\ty: %d\n", mx, my);
		if (mx >= 800 && mx <= 1000 && my >= 500 && my <= 570 && Screen == 2)
			Screen = 3; //Play Game
		if (mx >= 800 && mx <= 1000 && my >= 400 && my <= 470 && Screen == 2)
			Screen = 4; //Show High Score
		if (mx >= 800 && mx <= 1000 && my >= 300 && my <= 370 && Screen == 2)
			Screen = 5; //About
		if (mx >= 800 && mx <= 1000 && my >= 200 && my <= 270 && Screen == 2)
			Screen = 7; //Instructions
		if (mx >= 800 && mx <= 1000 && my >= 100 && my <= 170 && Screen == 2)
			exit(0);
		if (mx >= 750 && mx <= 950 && my >= 450 && my <= 520 && Screen == 6)
		{
			iResumeTimer(0);
			iResumeTimer(1);	//Resume
			iResumeTimer(2);
			iResumeTimer(3);
			iResumeTimer(4);
			Screen = 3;
		}
			
		if (mx >=750 && mx <= 950 && my >= 350 && my <= 420 && Screen == 6)
			Screen = 2,LifeY = 246,score = 0,life = 100,iResumeTimer(0),iResumeTimer(1),iResumeTimer(2), iResumeTimer(4), iResumeTimer(3);
			// Main Menu
		if (mx >= 750 && mx <= 950 && my >= 250 && my <= 320 && Screen == 6)
			exit(0);
		if (mx >= 1050 && mx <= 1150 && my >= 600 && my <= 660)
		{
			if (Screen == 4 || Screen == 5 || Screen == 7)
				Screen = 2;  //Back Button
		} 
		/*if (mx >= 50 && mx <= 300 && my >= 250 && my <= 280 && mode == 0)
		{
			mode = 1;
		}*/
	}

	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}

}

void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		iPauseTimer(0);
		iPauseTimer(1);
		iPauseTimer(3);
		iPauseTimer(2);
		iPauseTimer(4);
		Screen = 6;
	}
	if (key =='r')
	{
		iResumeTimer(0);
		iResumeTimer(1);
		iResumeTimer(2);
		iResumeTimer(3);
		iResumeTimer(4);
		Screen = 3;
	}
	if (key == '\r')
	{
		if (Screen == 1)
			Screen = 2;
	}
	if (key == 'x')
	{
		LifeY = LifeY - 10;
		life = life - 4;
	}
	if (key == 'z')
	{
		LifeY = LifeY + 10;
		life = life + 4;
	}
	if(key =='\b')
	{
		if(Screen==4 || Screen== 5 || Screen ==7)
			Screen = 2;
	}
	//input(key);
	/*if (mode == 1)
	{
		if (key == '\r')
		{
			mode = 0;
			strcpy(str2, str);
			printf("%s\n", str2);
			for (int i = 0; i < len; i++)
				str[i] = 0;
			len = 0;
		}
		else
		{
			str[len] = key;
			len++;
		}
	}*/

}

/*
function iSpecialKeyboard() is called whenver user hits special keys likefunction
keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11,
GLUT_KEY_F12, GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN,
GLUT_KEY_PAGE UP, GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END,
GLUT_KEY_INSERT */

/*DRAW FUNCTION: iSetColor(double r, double g, double b), iGetPixelColor (int x, int y, int rgb[]),
iPoint(double x, double y, int size=0), iLine(double x1, double y1, double x2, double y2),
iCircle(double x, double y, double r, int slices=100), iFilledCircle(double x, double y, double r, int slices=100),
iEllipse(double x, double y, double a, double b, int slices=100), iFilledEllipse(double x, double y, double a, double b, int
slices=100), iRectangle(double left, double bottom, double dx, double dy), iPolygon(double x[], double y[], int n),
iFilledPolygon(double x[], double y[], int n), iText(GLdouble x, GLdouble y, char *str, void*
font=GLUT_BITMAP_8_BY_13)

FONT : {GLUT_BITMAP_8_BY_13, GLUT_BITMAP_9_BY_15,
GLUT_BITMAP_TIMES_ROMAN_10, GLUT_BITMAP_TIMES_ROMAN_24,
GLUT_BITMAP_HELVETICA_10, GLUT_BITMAP_HELVETICA_12,
GLUT_BITMAP_HELVETICA_18}

iShowBMP(int x, int y, char filename[]), iShowBMP2(int x, int y, char filename[], int ignoreColor), iPauseTimer(int index), iResumeTimer(int index),
iRotate(double x, double y, double degree), iUnRotate(), iDelay(int sec), iDelayMS(int msec), displayFF(void), animFF(void)*/

void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	
}



int main()
{
	
	/*len = 0;
	mode = 0;
	str[0] = 0;
	index = strlen(str) - 1;*/
	setBackground();
	player_change();
	enemyMain_change();
	enemy_change();
	obstacle_change();
	iSetTimer(100, changebackground);
	iSetTimer(100, playerJump);
	iSetTimer(350, enemyJump);
	iSetTimer(350, enemyMain);
	iSetTimer(350, obstacle);
	iSetTimer(70, Loading);
	iInitialize(1200, 680, "Dragon Ball Z");
	return 0;
}