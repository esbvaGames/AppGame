#ifndef BUTTONCHECK_HPP
#define BUTTONCHECK_HPP

#include <Screen.hpp>
#include <Button.hpp>


class ButtonCheck : public Button
{
   public:
      ButtonCheck();
      virtual ~ButtonCheck();

      ButtonCheck(Screen *, float, float, float, float, std::string, float);
      void Display(sf::RenderWindow *win);

   protected:
      sf::RectangleShape      rcCuadro;
      sf::RectangleShape      rcCentro;

   private:

};

#endif // BUTTONCHECK_HPP
