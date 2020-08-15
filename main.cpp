
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

#include "Screen.hpp"
#include "Widget.hpp"
#include "Label.hpp"
#include "Button.hpp"

///////////////////////////////////////////////////

Label    *myLabel  = NULL;
sf::Font  myFont;
sf::Text  prompt;


///////////////////////////////////////////////////

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


    //. Crea la Window principal
    sf::RenderWindow win(sf::VideoMode(800, 480), "AppGame");
    //. No sera dibujada a 60fps, como un juego.-
    win.setFramerateLimit(30);

    running = true;

    COORD crd = COORD(10,10);
    std::cout << crd.toString() << std::endl;

    DIMENSION dm = DIMENSION(100, 100, 64, 24);
    std::cout << dm.toString() << std::endl;

    myScreen = new Screen();

    myLabel = Create_Label(myScreen, 40,40, "SFML GUI Interface", 20.0f);
    myScreen->Widget_add("tittle", myLabel);

    Label *lbName = Create_Label(myScreen, 40,80, "Texto de Etiqueta", 16.0f);
    myScreen->Widget_add("subtext", lbName);

    Button *myButton = Create_Button(myScreen, 40,120, "boton", 16.0f);
    myScreen->Widget_add("btnData", myButton);


// TODO (esbva#1#): Modos Pendientes
   /*
   myButton->setVisible( true | false )
   myButton->setEnabled( true | false )
   myButton->setToogled( true | false )

   */



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
            //myButton->MouseInRect(&win);
            myScreen->Update(&win);
         }
         win.clear(sf::Color(0,0,0));

         //TestDisplay_01(&win);
         //myButton->Display(&win);

         //Display en el Contenedor-Screen
         myScreen->Display(&win);

         win.display();
      }
      delete myButton;
      myButton = NULL;

      delete myScreen;
      myScreen = NULL;




    }



    std::cout << "Hello world!" << std::endl;
    return 0;
}
