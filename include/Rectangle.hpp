#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <Screen.hpp>
#include <Widget.hpp>

class Rectangle : public Widget
{
   public:
      Rectangle();
      virtual ~Rectangle();
      Rectangle(Screen *scr, float cx, float cy, float width, float height, std::string=".");
      void Display(sf::RenderWindow *win);

      std::string toString();

   protected:
      sf::Texture          image;
      sf::Rect<float>      rcForma;
      sf::RectangleShape   rcBorde;

   private:
};

#endif // RECTANGLE_HPP
