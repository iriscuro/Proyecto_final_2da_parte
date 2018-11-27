
#include <cmath>
#include <cstdlib>
#include "Pelota.h"

Pelota::Pelota()
{
}

void Pelota::inicializar(sf::Texture& tex, int max_ancho, int max_alto)
{
   m_sprite.setTexture(tex);
   m_sprite.setOrigin(tex.getSize().x / 2, tex.getSize().y / 2);

   m_ancho_nivel = max_ancho;
   m_alto_nivel = max_alto;

   salto=max_alto/2;
   // Velocidad inicial
   velocidad = 4.0;

   reiniciar();
}

const sf::Sprite& Pelota::obtenerSprite()
{
   return m_sprite;
}

float Pelota::obtenerX()
{
   return m_sprite.getPosition().x;
}

float Pelota::obtenerY()
{
   return m_sprite.getPosition().y;
}

void Pelota::actualizar()
{
   m_sprite.move(m_direccion);

   float posX = m_sprite.getPosition().x;
   float posY = m_sprite.getPosition().y;

   // Rebotar si las coordenadas sobrepasan el tamaño del nivel
   /*
   if (posX < 0 || posX > m_ancho_nivel)
   {
      m_direccion.x *= -1;
   }
*/
   if (posY < 0 || posY > salto)
   {
      m_direccion.y *= -1;
   }
}

void Pelota::reiniciar()
{
   m_sprite.setPosition(rand() % m_ancho_nivel, rand() %m_alto_nivel);

   int dir = rand() % 180;
  // m_direccion.x = cos(dir * 3.1416 / 180) * velocidad;
   m_direccion.y = sin(dir * 3.1416 / 180) * velocidad;

   // La velocidad será un poco más rápida al próximo reinicio
   velocidad += 0.1;
}


