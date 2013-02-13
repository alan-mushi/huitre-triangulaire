/*
    Auteur          :   Serge Dubois
    Date            :   février 2013

    Sujet           :   Cours C++ deuxième année IUT informatique VANNES
*/
#ifndef CKEYBOARD_H
#define CKEYBOARD_H

#include "BiblioStd.h"

class CKeyboard {

   private:
      struct termios initial_settings, new_settings;

   public:
      void Initialisation();
      void Arret();
      int kbhit();
      int getch();
};

#endif
