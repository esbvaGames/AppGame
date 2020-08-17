
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

#include "Screen.hpp"
#include "Widget.hpp"
#include "Label.hpp"
#include "Button.hpp"
#include "ButtonRadio.hpp"


#define MAIN
///////////////////////////////////////////////////

Label    *myLabel  = NULL;
sf::Font  myFont;
sf::Text  prompt;
Screen   *myScreen = NULL;


///////////////////////////////////////////////////

void TestDisplay_02(sf::RenderWindow *win){
   win->draw(prompt);
}

void TestDisplay_01(sf::RenderWindow *win){
   TestDisplay_02( win );
   //myLabel->Display(win);
}

void myFuncion(std::string idKey, EVENTS *evn){
   LOG_WARN("LLAMADA DESDE: " << idKey);
   // Para recuperar el Sender
   Widget *wdt = myScreen->Search(idKey);
   // Para ubicar el tipo de la class y convertir
   if(wdt->get_idType() == CTYPES::CButton){
      Button *btn = (Button *)wdt;
      //. Para imprimir los datos
      LOG_INFO( btn->toString() );
   }

}

void myMouseEntered(std::string idKey, EVENTS *evn){
   LOG_WARN("Llamanda al MouseEntered desde: " << idKey);

}

void myMouseExited(std::string idKey, EVENTS *evn){
   LOG_WARN("Llamada a MouseExited desde: " << idKey);
   LOG_WARN("Argumantos: " << evn->arguments);
}

///////////////////////////////////////////////////
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
    myButton->Connect(Event::on_Pressed, (callback*)&myFuncion, "8489:yryy:59069");
    myButton->Connect(Event::on_MouseEntered, (callback*)&myMouseEntered, "arg1,arg2,arg3");
    myButton->Connect(Event::on_MouseExited, (callback*)&myMouseExited, "111,222,333,444");
    myScreen->Widget_add("btnData", myButton);


    ButtonRadio *myOption1 = Create_Option(myScreen, 40, 160 +(30*0), "Color-Normal", 16.0f, "grpColor");
    myScreen->Widget_add("btnOptn-1", (Button*)myOption1);

    ButtonRadio *myOption2 = Create_Option(myScreen, 40, 160 +(30*1), "Color-Dark", 16.0f, "grpColor");
    myScreen->Widget_add("btnOptn-2", (Button*)myOption2);

    ButtonRadio *myOption3 = Create_Option(myScreen, 40, 160 +(30*2), "Color-Light", 16.0f, "grpColor");
    myScreen->Widget_add("btnOptn-3", (Button*)myOption3);

    ButtonRadio *myOption4 = Create_Option(myScreen, 40, 160 +(30*3), "Color-Neon", 16.0f, "grpColor");
    myScreen->Widget_add("btnOptn-4", (Button*)myOption4);
// TODO (esbva#1#): Modos Pendientes
   /*
   myButton->setVisible( true | false )
   myButton->setEnabled( true | false )
   myButton->setToogled( true | false )

   */



    //. Pruebas locales antes de encapsular


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

         myScreen->Display(&win);
         win.display();
      }
      //delete myButton;
      //myButton = NULL;

      delete myScreen;
      myScreen = NULL;




    }



    std::cout << "Hello world!" << std::endl;
    return 0;
}
