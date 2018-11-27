
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#define ANCHO    1200
#define ALTO      630
#define TITULO    "Hit the Ball"

Menu::Menu()
{
   inicio = inicializa();
}

bool Menu::inicializa()
{
   // Se cargan los archivos necesarios.
  if (!fuente1.loadFromFile("Fuentes/Abtecia.ttf"))
   {
      return false;
   }
   if (!fuente2.loadFromFile("Fuentes/ACafe.ttf"))
   {
      return false;
   }

  if (!tx_fondo1.loadFromFile("imagenes/opciones.jpg"))
   {
      return false;
   }

    // Crear la ventana
   ventana1.create(sf::VideoMode(ANCHO, ALTO), TITULO);

   // Limitar los FPS
   ventana1.setFramerateLimit(50);

   // Textura del fondo
   fondo1.setTexture(tx_fondo1);

   // Fijar fuente para los textos
   opcion[0].setFont(fuente1);
   opcion[1].setFont(fuente1);
   opcion[2].setFont(fuente1);
   opcion[3].setFont(fuente2);
   opcion[4].setFont(fuente2);

    // Inicializar el opcion
   opcion[0].setString("PLAY");
   opcion[0].setCharacterSize(40);
   opcion[0].setPosition(520, 190);
   opcion[0].setColor(sf::Color(255, 180, 255));

   opcion[1].setString("ESCORES");
   opcion[1].setCharacterSize(40);
   opcion[1].setPosition(463, 305);
   opcion[1].setColor(sf::Color(100, 0, 50));

   opcion[2].setString("MINIJUEGO");
   opcion[2].setCharacterSize(40);
   opcion[2].setPosition(450, 423);
   opcion[2].setColor(sf::Color(100, 0, 50));

   opcion[3].setString("CREDITOS");
   opcion[3].setCharacterSize(60);
   opcion[3].setPosition(70, 500);
   opcion[3].setColor(sf::Color(100, 0, 50));

   opcion[4].setString("SALIR");
   opcion[4].setCharacterSize(60);
   opcion[4].setPosition(950, 500);
   opcion[4].setColor(sf::Color(100, 0, 50));

   selectedItemIndex = 0;

   return true;
}


void Menu::dibujarSprites()
{
    ventana1.draw(fondo1);
    for(int i=0; i< MAX_NUMBER_OF_ITEMS ;i++){
        ventana1.draw(opcion[i]);
    }

}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		opcion[selectedItemIndex].setColor(sf::Color(100, 0, 50));
		selectedItemIndex--;
        opcion[selectedItemIndex].setColor(sf::Color(255, 180, 255));
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		opcion[selectedItemIndex].setColor(sf::Color(100, 0, 50));
		selectedItemIndex++;
		opcion[selectedItemIndex].setColor(sf::Color(255, 180, 255));
	}
}

void Menu::accion()
{
   if (!inicio)
   {
      std::cout << "Falló al iniciar el juego..." << std::endl;
      return;
   }

   // Empieza el "loop" del juego
   while (ventana1.isOpen())
   {
      // Procesar los eventos de SFML
      sf::Event event;
      while (ventana1.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					MoveUp();
					break;

				case sf::Keyboard::Down:
					MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (GetPressedItem())
					{
					case 0:
						std::cout << "Play apretaste el boton" << std::endl;
						break;
					case 1:
						std::cout << "Scores apretaste el boton" << std::endl;
						break;
                    case 2:
						std::cout << "Minijuego apretaste el boton" << std::endl;
						break;
                    case 3:
						std::cout << "Creditos apretaste el boton" << std::endl;
						break;

					case 4:
						ventana1.close();
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				ventana1.close();

				break;

			}
		}

      ventana1.clear();


      // Mostrar todo
      dibujarSprites();
      ventana1.display();
   }
}


