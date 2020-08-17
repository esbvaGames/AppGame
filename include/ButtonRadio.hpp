#ifndef BUTTONRADIO_HPP
#define BUTTONRADIO_HPP

#include <Screen.hpp>
#include <Button.hpp>

class ButtonRadio : public Button
{
   public:
      ButtonRadio();
      virtual ~ButtonRadio();
      ButtonRadio(float, float, float, float, std::string, sf::Font, float Scale);

      void Display(sf::RenderWindow *win);

   protected:
      sf::CircleShape     circle;
      sf::CircleShape     centro;

   private:
      COORD               coord;



};

#endif // BUTTONRADIO_HPP
