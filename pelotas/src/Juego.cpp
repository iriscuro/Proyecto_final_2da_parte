/*
#include <iostream>
#include <sstream>

#include "Juego.h"

#define ANCHO     1200
#define ALTO      630
#define TITULO    "Hit the Ball"


Juego::Juego()
{
   iniciado = inicializar();
}

bool Juego::inicializar()
{
   // Se cargan los archivos necesarios.
   if (!fuente.loadFromFile("Fuentes/fuente.ttf"))
   {
      return false;
   }

   if (!tx_pelota.loadFromFile("imagenes/pelota.png"))
   {
      return false;
   }

   if (!tx_fondo.loadFromFile("imagenes/a.png"))
   {
      return false;
   }



   // Crear la ventana
   ventana.create(sf::VideoMode(ANCHO, ALTO), TITULO);

   // Limitar los FPS
   ventana.setFramerateLimit(50);


   // Fijar fuente para los textos
   texto_score.setFont(fuente);
   texto_score.setCharacterSize(40);
   texto_tiempo.setFont(fuente);
   texto_tiempo.setCharacterSize(40);
   texto_fin.setFont(fuente);
   texto_fin.setCharacterSize(40);

   // Inicializar el score
   texto_score.setString("Score");
   texto_score.setPosition(50, 50);
   score = 0;

   // Inicializar el tiempo
   texto_tiempo.setPosition(500, 20);
   tiempo = 30.0;
   actualizarTiempo();

   // Textura del fondo
   fondo.setTexture(tx_fondo);

   // Inicializar los dos sprites
   pelota1.inicializar(tx_pelota, ANCHO, ALTO);
   pelota2.inicializar(tx_pelota, ANCHO, ALTO);
   pelota3.inicializar(tx_pelota, ANCHO, ALTO);

   return true;
}

void Juego::aumentarScore()
{
   score += 1;

   // Actualizar "texto_score" con el nuevo score.
   std::stringstream s_score;
   s_score << "Score" << std::endl << score;
   texto_score.setString(s_score.str());

   if (tiempo < 10)
   {
      tiempo += 1.0;
   }
}

void Juego::actualizarTiempo()
{
   std::stringstream s_tiempo;
   s_tiempo << "Tiempo" << std::endl << tiempo;
   texto_tiempo.setString(s_tiempo.str());
}

void Juego::actualizar()
{
   pelota1.actualizar();
   pelota2.actualizar();
   pelota3.actualizar();
}

void Juego::dibujarSprites()
{
   ventana.draw(fondo);
   ventana.draw(pelota1.obtenerSprite());
   ventana.draw(pelota2.obtenerSprite());
   ventana.draw(pelota3.obtenerSprite());
   ventana.draw(texto_score);
   ventana.draw(texto_tiempo);
}

void Juego::dibujarFinal()
{
   ventana.draw(texto_fin);
}

void Juego::correr()
{
   if (!iniciado)
   {
      std::cout << "Falló al iniciar el juego..." << std::endl;
      return;
   }

   sf::Clock reloj;
   bool finalizado = false;

   // Empieza el "loop" del juego
   while (ventana.isOpen())
   {
      // Procesar los eventos de SFML
      sf::Event event;
      while (ventana.pollEvent(event))
      {
         // Evento: El usuario hace clic en el botón de cerrar [X]
         if (event.type == sf::Event::Closed)
         {
            ventana.close();
         }

         // Evento: El usuario hace clic en la pantalla del juego
         if (event.type == sf::Event::MouseButtonPressed
         && sf::Mouse::isButtonPressed(sf::Mouse::Left))
         {
            // Obtener las coordenadas del mouse
            int mouseX = sf::Mouse::getPosition(ventana).x;
            int mouseY = sf::Mouse::getPosition(ventana).y;


            // Obtener las coordenadas de la primera pelota
            float pelotaX = pelota1.obtenerX();
            float pelotaY = pelota1.obtenerY();

            // ¿El mouse tocó la pelota1?
            if (mouseX > pelotaX - 40 && mouseX < pelotaX + 40
            && mouseY > pelotaY - 40 && mouseY < pelotaY + 40)
            {
               aumentarScore();
               actualizarTiempo();
               pelota1.reiniciar();
            }


            // Obtener las coordenadas de la segunda pelota
            pelotaX = pelota2.obtenerX();
            pelotaY = pelota2.obtenerY();

            // ¿El mouse tocó la pelota2?
            if (mouseX > pelotaX - 40 && mouseX < pelotaX + 40
            && mouseY > pelotaY - 40 && mouseY < pelotaY + 40)
            {
               aumentarScore();
               actualizarTiempo();
               pelota2.reiniciar();
            }
         }

         // Evento: Hubo una tecla presionada
         if (event.type == sf::Event::KeyPressed && finalizado)
         {
            // Cerrar el juego en la escena final
            ventana.close();
            return;
         }
      }

      if (reloj.getElapsedTime().asSeconds() >= 1.0)
      {
         if (tiempo == 0 && !finalizado)
         {
            // Poner el texto de fin y finalizar.
            std::stringstream str;

            str << "  Tiempo!";
            str << "\n";
            str << "\n";
            str << "Tu puntuacion final es: " << score;

            texto_fin.setString(str.str());
            texto_fin.setPosition(500, 250);

            finalizado = true;
         }

         // El tiempo decrece cada segundo
         --tiempo;
         actualizarTiempo();
         reloj.restart();
      }

      // Dibujar todo a la pantalla
      if (!finalizado)
      {
         actualizar();
         ventana.clear();
         dibujarSprites();
      }
      else
      {
         ventana.clear(sf::Color(128, 128, 255));
         dibujarFinal();
      }

      // Mostrar todo
      ventana.display();
   }
}


*/
