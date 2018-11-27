
#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 5
class Menu
{
    public:



        sf::RenderWindow ventana1;
        //sf::IntRect rectangulo;
        bool inicio;
        int tiem;
        bool inicializa();


        sf::Texture tx_fondo1;
        sf::Texture tx_fondo2;
        sf::Sprite fondo1;
        sf::Sprite fondo2;
        void evento();
        void dibujarSprites();

        void MoveUp();
        void MoveDown();

        int GetPressedItem() { return selectedItemIndex; }


        Menu();
        void accion();

    private:
        int selectedItemIndex;

        sf::Text opcion[MAX_NUMBER_OF_ITEMS];
        sf::Font fuente1;
        sf::Font fuente2;



};

#endif // MENU_H


