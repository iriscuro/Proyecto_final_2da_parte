#ifndef PELOTA_HPP_INCLUDED
#define PELOTA_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Pelota
{
   sf::Sprite m_sprite;
   sf::Vector2f m_direccion;

   int m_ancho_nivel;
   int m_alto_nivel;
   int salto;

   float velocidad;

public:
   Pelota();

   void inicializar(sf::Texture& tex, int ventana_w, int ventana_h);

   const sf::Sprite& obtenerSprite();
   float obtenerX();
   float obtenerY();

   void actualizar();
   void reiniciar();
};

#endif // PELOTA_HPP_INCLUDED
