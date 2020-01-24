#ifndef NAME_INPUT_H_INCLUDED
#define NAME_INPUT_H_INCLUDED

char str[100], str2[100];
int len;
int mode;
int index = 0;

void drawTextBox()
{
	iSetColor(150, 150, 150);
	iRectangle(50, 250, 250, 30);
}

//////// USING BACKSPACE //////////

void input(unsigned char key)
{
	if (key != '\b')
	{
		str[index] = key;
		index++;
		str[index] = '\0';

	}
	else
	{
		if (index <= 0)
			index = 0;
		else
			index--;

		str[index] = '\0';

	}

}

#endif // NAME_INPUT_H_INCLUDED
