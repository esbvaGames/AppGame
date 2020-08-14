#ifndef LABEL_HPP
#define LABEL_HPP

#include <Screen.hpp>
#include <Widget.hpp>


class Label : public Widget
{
   public:
      Label();
      Label(float, float, std::string, sf::Font, float Scale=10.0f);
      virtual ~Label();

      void Display(sf::RenderWindow *win);
      std::string toString();

   protected:


   private:
      sf::Text    prompt;     //. Texto de la etiqueta
      sf::Font    myFont;     //. Debe conservar la Fuente de Creacion

};

#endif // LABEL_HPP
