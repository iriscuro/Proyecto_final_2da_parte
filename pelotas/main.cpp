
#include <cstdlib>
#include <ctime>
#include "Juego.h"
#include "Menu.h"
#include <iostream>

using namespace std;

int main()
{
   srand(time(0));

   //Juego juego;
   //juego.correr();
   Menu menu;
   menu.accion();
   //Juego juego;
   //juego.correr();
   return 0;
}
