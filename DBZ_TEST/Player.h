#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

//char playerPic[6][20]={ "img\\FG\\1.bmp","img\\FG\\2.bmp" ,"img\\FG\\3.bmp","img\\FG\\4.bmp" ,"img\\FG\\5.bmp","img\\FG\\6.bmp" };
char playerPic[4][20] = { "img\\b\\1.bmp","img\\b\\2.bmp" ,"img\\b\\3.bmp","img\\b\\003.bmp" };
int playerX = 180;
int playerY = 320;
int i = 0;

void playerJump()
{	
		if (i == 3)
			i = 0;
		i++;
}
void player_change()
{

	iShowBMP2(playerX, playerY, playerPic[i], 255);
}


#endif // PLAYER_H_INCLUDED
