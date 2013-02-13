/*
	Auteur          :   Serge Dubois
	Date            :   février 2013

	Sujet           :   Cours C++ deuxième année IUT informatique VANNES
*/


#include "CKeyboard.h"

int CKeyboard::getch() {
	char ch=0;

	read(0,&ch,1);
	return ch;
}

/***********************************/

int CKeyboard::kbhit() {
	char ch=0;

	new_settings.c_cc[VMIN]=0;
	tcsetattr(0,TCSANOW, &new_settings);
	read(0,&ch,1);
	new_settings.c_cc[VMIN]=1;
	tcsetattr(0,TCSANOW, &new_settings);
	return ch;
}

/***********************************/

void CKeyboard::Initialisation() {

	tcgetattr(0, &initial_settings);
	new_settings = initial_settings;
	new_settings.c_lflag &= ~ICANON;
	new_settings.c_lflag &= ~ECHO;
	new_settings.c_lflag &= ~ISIG;
	new_settings.c_oflag &= ~NL0;
	new_settings.c_oflag &= ~CR0;
	new_settings.c_oflag &= ~TAB0;
	new_settings.c_oflag &= ~BS0;
	new_settings.c_cc[VMIN] = 1;
	new_settings.c_cc[VTIME] = 0;
	cfsetospeed(&new_settings, B230400);
	cfsetispeed(&new_settings, 0);
	tcsetattr(0, TCSANOW, &new_settings);
}

/***********************************/

void CKeyboard::Arret() {

	tcsetattr(0, TCSANOW, &initial_settings);
}

 
