#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <Screen.hpp>
#include <Widget.hpp>


class Button : public Widget
{
   public:
      Button();
      virtual ~Button();

      Button(Screen *scr, float, float, float, float, std::string, float Scale=16.0f);
      virtual void Display(sf::RenderWindow *win);

      void MouseInRect(sf::RenderWindow *win);

      void setSelect(bool state);
      bool is_Select();

      void setGroup(std::string idGroup);
      std::string getGroup();

      void setToggled(bool state){ this->Toogled = state; };
      bool is_Toggled() { return this->Toogled; }

      std::string toString();

   protected:
      std::string         idGroup;
      bool                Selecto;
      bool                Toogled;
      bool                MouseEnter;

      sf::Font            myFont;
      float               Scale;
      STATES              State;
      sf::Rect<float>     rcForma;
      sf::RectangleShape  rcShape;

   private:
};

#endif // BUTTON_HPP
