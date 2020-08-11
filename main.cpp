
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

#include "Screen.hpp"


bool running = false;

int main()
{
    sf::RenderWindow win(sf::VideoMode(800, 480), "AppGame");

    running = true;

    COORD crd = COORD(10,10);
    std::cout << crd.toString() << std::endl;

    DIMENSION dm = DIMENSION(100, 100, 64, 24);
    std::cout << dm.toString() << std::endl;



    if(win.isOpen()){
      while(running){
         sf::Event event;

         while(win.pollEvent(event)){
            if(event.type == sf::Event::Closed){
               win.close();
               running = false;
            }
         }
         win.clear(sf::Color(0,0,0));
         win.display();
      }


    }



    std::cout << "Hello world!" << std::endl;
    return 0;
}
