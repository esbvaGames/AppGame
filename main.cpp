
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

#include "Screen.hpp"
#include "Widget.hpp"
#include "Label.hpp"

///////////////////////////////////////////////////7
Label    *myLabel = NULL;
sf::Font  myFont;
sf::Text  prompt;

void TestDisplay_02(sf::RenderWindow *win){
   win->draw(prompt);
}

void TestDisplay_01(sf::RenderWindow *win){
   TestDisplay_02( win );
   //myLabel->Display(win);
}

///////////////////////////////////////////////////
Screen   *myScreen = NULL;
bool running = false;

int main()
{
    sf::RenderWindow win(sf::VideoMode(800, 480), "AppGame");

    running = true;

    COORD crd = COORD(10,10);
    std::cout << crd.toString() << std::endl;

    DIMENSION dm = DIMENSION(100, 100, 64, 24);
    std::cout << dm.toString() << std::endl;

    myScreen = new Screen();

    myLabel = myScreen->Create_Label(40,40, "SFML GUI Interface");
    //... Otros ajustes ...
    myScreen->Widget_add("tittle", myLabel);
    //myScreen->Display( &win );

    //. Pruebas locales antes de encapsular
    /*
    if(!myFont.loadFromFile("./assets/acme.ttf")){
      std::cout << "Error Leyendo: acme.ttf" << std::endl;
    }
    prompt = sf::Text("SFML GUI Interface", myFont, 40);
    prompt.setPosition(40, 40);
    */

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

         //TestDisplay_01(&win);
         myScreen->Display(&win);

         win.display();
      }
      delete myScreen;
      myScreen = NULL;


    }



    std::cout << "Hello world!" << std::endl;
    return 0;
}
