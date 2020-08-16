#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <Screen.hpp>
#include <Widget.hpp>


class Button : public Widget
{
   public:
      Button();
      virtual ~Button();

      Button(float, float, float, float, std::string, sf::Font, float Scale=16.0f);
      virtual void Display(sf::RenderWindow *);

      void MouseInRect(sf::RenderWindow *win);
      std::string toString();

   protected:
      bool     MouseEnter;

   private:
      sf::Font            myFont;
      float               Scale;
      STATES              State;
      sf::Rect<float>     rcForma;
      sf::RectangleShape  rcShape;
};

#endif // BUTTON_HPP
