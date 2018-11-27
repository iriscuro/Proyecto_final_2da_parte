/*
#ifndef JUEGO_HPP_INCLUDED
#define JUEGO_HPP_INCLUDED

#include <vector>
#include <SFML/Graphics.hpp>

#include "Pelota.h"

class Juego
{
   //---------------------
    // Variables privadas
   //-------------------------

   bool iniciado;

   sf::RenderWindow ventana;
   sf::Font fuente;

   sf::Text texto_score;
   sf::Text texto_tiempo;
   sf::Text texto_fin;

   int score;
   int tiempo;

   sf::Texture tx_fondo;
   sf::Texture tx_pelota;

   sf::Sprite fondo;

   Pelota pelota1;
   Pelota pelota2;
   Pelota pelota3;

   //--------------------
     //Funciones privadas
   //--------------------

   bool inicializar();
   void aumentarScore();
   void actualizarTiempo();
   void actualizar();
   void dibujarSprites();
   void dibujarFinal();

public:
   Juego();
   void correr();
};

#endif // JUEGO_HPP_INCLUDED

*/
