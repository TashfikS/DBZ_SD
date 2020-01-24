#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

char UpperBackgroundPicture[10][50]={"img\\1.bmp","img\\2.bmp","img\\3.bmp","img\\4.bmp","img\\5.bmp","img\\6.bmp","img\\7.bmp","img\\8.bmp","img\\9.bmp","img\\10.bmp"};
char LowerBackgroundPicture[10][50]={"img\\11.bmp","img\\22.bmp","img\\33.bmp","img\\44.bmp","img\\55.bmp","img\\66.bmp","img\\77.bmp","img\\88.bmp","img\\99.bmp","img\\100.bmp"};
#define upperbackgroundSpeed 10
#define lowerbackgroundSpeed 12

//// Scoring & Life Variables ////

int score = 0,life = 100,LifeY = 250;
char Score[10],Life[4];

struct background
{
	int x;
	int y;

}upperbackground[10],lowerbackground[10];

void background()
{
	for(int i=0; i<10; i++)
	{
		iShowBMP(upperbackground[i].x,upperbackground[i].y,UpperBackgroundPicture[i]);
		iShowBMP(lowerbackground[i].x,lowerbackground[i].y,LowerBackgroundPicture[i]);
	}
	//////////// SCORE BAR //////////////
	iShowBMP(0, 0, "img\\Home\\Score_Menu.bmp");
	iSetColor(255, 255, 255);
	iText(35, 220, Score, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(45, 555, Life, GLUT_BITMAP_HELVETICA_18);
	iFilledRectangle(50, 300, 20, 250);
	if (life >= 15)
		iSetColor(0, 130, 0);
	else
		iSetColor(255, 0, 0);
	
	iFilledRectangle(52,302, 16, LifeY);
	if (LifeY <=0)
		LifeY = 0;
	if (life <= 0)
		life = 0;
	if (LifeY >= 246)
		LifeY = 246;
	if (life >= 100)
		life = 100;
}

void setBackground()
{
	int sum= 0;
	for(int i =0; i<10; i++)
	{
		upperbackground[i].y = 120;
		lowerbackground[i].y = 0;
		upperbackground[i].x = sum;
		lowerbackground[i].x = sum;
		sum+=120;
	}
}
void changebackground()
{
	for(int i=0; i<10; i++)
	{
		upperbackground[i].x -= upperbackgroundSpeed;
		lowerbackground[i].x -= lowerbackgroundSpeed;
		if(upperbackground[i].x<=0)
			upperbackground[i].x = 1190;
		if(lowerbackground[i].x<=0)
			lowerbackground[i].x = 1188;
	}
	//// Conversion of Score to String  ////
	score++;
	itoa(score, Score, 10);
	itoa(life, Life, 10);
	strcat(Life, "%");
}

#endif // BACKGROUND_H_INCLUDED
