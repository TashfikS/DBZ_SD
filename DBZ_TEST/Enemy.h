#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

char enemyPic[3][20]={ "img\\e\\1.bmp","img\\e\\2.bmp" ,"img\\e\\3.bmp"};
char obstaclePic[3][30] = { "img\\e\\Obstacle\\1.bmp","img\\e\\Obstacle\\2.bmp","img\\e\\Obstacle\\3.bmp"};
char enemyMainpic[10][15]={"img\\F\\1.bmp","img\\F\\2.bmp","img\\F\\3.bmp","img\\F\\4.bmp","img\\F\\5.bmp","img\\F\\6.bmp","img\\F\\7.bmp","img\\F\\8.bmp","img\\F\\9.bmp","img\\F\\10.bmp"};
int enemyX = 850;
int enemyY = 80;
int obstacleX = 600, obstacleY = 100;
int enemyMainPicX=820;
int enemyMainPicY=320;
int j = 0;int k=0,m=0;
void enemyMain()
{
	if (k == 9)
			k = 0;
		k++;
}
void enemyMain_change()
{

	iShowBMP2(enemyMainPicX, enemyMainPicY, enemyMainpic[k],0);
	
}

void enemyJump()
{	
		if (j == 2)
			j = 0;
		j++;
}
void enemy_change()
{

	iShowBMP2(enemyX, enemyY, enemyPic[j],0);
	
}
void obstacle(){
	if(m ==2)
		m=0;
	m++;
}
void obstacle_change()
{
	iShowBMP2(obstacleX,obstacleY,obstaclePic[m],255);
}

#endif // ENEMY_H_INCLUDED
