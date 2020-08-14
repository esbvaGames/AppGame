#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <Screen.hpp>

class Widget
{
   public:
      Widget();
      virtual ~Widget();

      virtual void Display(sf::RenderWindow *win) = 0;

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

      void setFont(std::string filePath, float Scale);
      bool getFont(sf::Font &fuente, float &Scale);

      std::string toString();


      void set_idType(CTYPES idType);
      CTYPES get_idType();

      std::string getKeyName();
      void setKeyName(std::string keyName);

   protected:
      STYLES         styles;

   private:
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

      sf::Font       fontBase;      //. Fuente de letra base
      std::string    pathAssets;    //. Recursos de la GUI.

      std::string    fileName;      //. Archivo


};

#endif // WIDGET_HPP
