
#include "Button.hpp"

Button::Button()
{
   //ctor
}

Button::~Button()
{
   //dtor
}
Button::Button(float cx, float cy, float width, float height, std::string texto, float Scale)
{
   rcShape.setSize(sf::Vector2f(width, height));
   rcShape.setFillColor(styles.ColorNormal_alpha);
   rcShape.setOutlineColor(styles.ColorNormal);
   rcShape.setOutlineThickness(2.0f);
   rcShape.setPosition(cx, cy);

   rcForma = sf::Rect<float>(cx, cy, width, height);
}

void Button::MouseInRect(sf::RenderWindow *win)
{
   float px = sf::Mouse::getPosition(*win).x;
   float py = sf::Mouse::getPosition(*win).y;

   if(rcForma.contains( sf::Vector2<float>(px, py) )){
      State = STATES::Select;
      if(sf::Mouse::isButtonPressed( sf::Mouse::Left )){
         std::cout << "Pressed Left"   << std::endl;
         State = STATES::Pressed;
// TODO (esbva#1#): Enviar eventos al queue

      } else if(sf::Mouse::isButtonPressed( sf::Mouse::Right )){
         std::cout << "Pressed Right"  << std::endl;
         State = STATES::Disable;
// TODO (esbva#1#): Enviar eventos al queue

      } else if(sf::Mouse::isButtonPressed( sf::Mouse::Middle)){
         std::cout << "Pressed Middle" << std::endl;
// TODO (esbva#1#): Enviar eventos al queue

      }


   } else {
      State = STATES::Normal;
   }
   //std::cout << "(" << px <<","<< py <<")" << std::endl;
}

void Button::Display(sf::RenderWindow *win)
{
   switch(State){
   case STATES::Select:
      rcShape.setOutlineColor(styles.ColorSelect);
      rcShape.setFillColor(styles.ColorSelect_alpha);
      break;

   case STATES::Pressed:
      rcShape.setOutlineColor(styles.ColorActive);
      rcShape.setFillColor(styles.ColorActive_alpha);
      break;

   case STATES::Disable:
      rcShape.setOutlineColor(styles.ColorDisabled);
      rcShape.setFillColor(styles.ColorDisable_alpha);
      break;

   default:
      rcShape.setOutlineColor(styles.ColorNormal);
      rcShape.setFillColor(styles.ColorNormal_alpha);
      break;

   }
   win->draw(rcShape);
}
