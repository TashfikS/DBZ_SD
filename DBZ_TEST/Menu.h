#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

///////////// HOME & MENU ///////////////
int Screen = 1;
bool move[15];
int LoadingX = 303, LoadingY = 33, addX = 5;
void Home()
{
	iShowBMP(0, 0, "img\\Home\\Home.bmp");
	iSetColor(0, 0, 0);
	iRectangle(300, 30, 600, 30);
	iFilledRectangle(LoadingX, LoadingY, addX, 24);
	iText(550, 10, "Loading...", GLUT_BITMAP_TIMES_ROMAN_24);

}
void Loading()
{
	addX += 5;
	if (addX >= 594) {
		//addX = 594;
		Screen = 2;
		iPauseTimer(5);
	}


}
void Menu()
{
	iShowBMP(0, 0, "img\\Home\\menu1.bmp");
	if (move[0])
		iShowBMPAlternativeSkipRed(800, 500, "img\\Home\\Play.bmp");
	else
		iShowBMP2(800, 500, "img\\Home\\Play1.bmp", 255);
	if (move[1])
		iShowBMPAlternativeSkipRed(800, 400, "img\\Home\\HS1.bmp");
	else
		iShowBMP2(800, 400, "img\\Home\\HS.bmp", 255);
	if (move[2])
		iShowBMPAlternativeSkipRed(800, 300, "img\\Home\\About1.bmp");
	else
		iShowBMPAlternativeSkipRed(800, 300, "img\\Home\\About.bmp");
	if (move[3])
		iShowBMPAlternativeSkipRed(800, 200, "img\\Home\\ins1.bmp");
	else
		iShowBMPAlternativeSkipRed(800, 200, "img\\Home\\ins.bmp");
	if (move[4])
		iShowBMPAlternativeSkipRed(800, 100, "img\\Home\\Exit1.bmp");
	else
		iShowBMPAlternativeSkipRed(800, 100, "img\\Home\\Exit.bmp");
}
void pause()
{

	iShowBMPAlternativeSkipRed(0, 0, "img\\Home\\Pause_Menu.bmp");
	if (move[5])
		iShowBMPAlternativeSkipRed(650, 450, "img\\Home\\Resume1.bmp");
	else
		iShowBMPAlternativeSkipRed(750, 450, "img\\Home\\Resume.bmp");
	if (move[6])
		iShowBMPAlternativeSkipRed(650, 350, "img\\Home\\Main_Menu1.bmp");
	else
		iShowBMPAlternativeSkipRed(750, 350, "img\\Home\\Main_Menu.bmp");
	if (move[7])
		iShowBMPAlternativeSkipRed(650, 250, "img\\Home\\Exit1.bmp");
	else
		iShowBMPAlternativeSkipRed(750, 250, "img\\Home\\Exit.bmp");
}
void instruction()
{
	iShowBMP(0, 0, "img\\Home\\INS_2.bmp");
	iShowBMP(1050, 600, "img\\back3.bmp");

}
void highscore()
{
	iShowBMP(0, 0, "img\\Home\\hs_2.bmp");
	iShowBMP(1050, 600, "img\\back3.bmp");
}
void aboutus()
{
	iShowBMP(0, 0, "img\\Home\\about_2.bmp");
	iShowBMP(1050, 600, "img\\back3.bmp");
}


#endif // MENU_H_INCLUDED
