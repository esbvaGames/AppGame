#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <Screen.hpp>

class Widget
{
   public:
      Widget();
      virtual ~Widget();

      virtual void Display(sf::RenderWindow *win) = 0;
      virtual std::string toString() = 0;

      void setPosition(COORD m);
      COORD getPosition();

      void setString(std::string idTexto);
      std::string getString();

      bool setVisible(bool state);
      bool is_visible();

      bool setEnabled(bool state);
      bool is_enabled();

      bool setFocused(bool state);
      bool is_focused();

      void newFont(std::string fileFont, float fontScale = 16.0f);
      void setFont(sf::Font fontBase, float fontScale = 16.0f);
      sf::Font getFont(float &fontScale);


      void set_idType(CTYPES idType);
      CTYPES get_idType();

      std::string getKeyName();
      void setKeyName(std::string keyName);

      bool Connect(Event idEvent, callback *command, std::string argument);
      bool Disconnect(Event idEvent);

      void on_CallFunction(Event idEvent);

   protected:
      STYLES         styles;
      std::string    Options;       //. Grupo de Boton Opciones

      sf::Text       prompt;        //. Nombre para Mostrar si es requerido
      sf::Font       fontBase;
      float          fontScale;
      std::string    fileFont;      //. Archivo de la fuente Base

      COORD          position;
      CTYPES         idTypes;      //. idType dynamic_cast<Derived*> (&Base)
      std::string    KeyName;

      bool           visible;
      bool           enabled;
      bool           focused;
      bool           toogled;      //. Boton de Toques (on | off)

      DIMENSION      dimActual;
      DIMENSION      dimMinima;
      DIMENSION      dimMaxima;

      Widget         *FocusNext;
      Widget         *FocusPrevio;


   private:
      //. idKey = "on_Update", [ Events { idEvent, myFuncion, arguments } ]
      std::map<int, EVENTS *> Eventos;
      std::map<int, EVENTS *>::iterator iterEventos;

      std::string    pathAssets;    //. Recursos de la GUI.
      std::string    fileToSave;      //. Archivo


};

#endif // WIDGET_HPP
