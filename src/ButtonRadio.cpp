

#include "ButtonRadio.hpp"


ButtonRadio::ButtonRadio()
{
   //ctor
}

ButtonRadio::~ButtonRadio()
{
   //dtor
}
ButtonRadio::ButtonRadio(float cx, float cy, float width, float height, \
                         std::string texto, sf::Font myFont, float Scale) : \
                         Button(cx, cy, width, height, texto, myFont, Scale)
{
    prompt.setPosition(sf::Vector2f(cx +25, cy));
    rcShape.setPosition(cx -4, cy -2);
    float WIDTH  = prompt.getLocalBounds().width + 40;
    float HEIGHT = prompt.getLocalBounds().height + 10;
    rcShape.setSize(sf::Vector2f(WIDTH, HEIGHT));
    rcForma = sf::Rect<float>(cx-4, cy-2, WIDTH, HEIGHT);

    //sf::CircleShape circle;
    circle.setPosition(cx, cy);
    circle.setRadius(10);
    circle.setFillColor(styles.ColorNormal_alpha);
    circle.setOutlineColor(styles.ColorNormal);
    circle.setOutlineThickness(2);
    //sf::CircleShape centro;
    centro.setPosition(cx+4, cy+4);
    centro.setRadius(6);
    centro.setFillColor(styles.ColorNormal);
    centro.setOutlineColor(styles.ColorNormal);
    centro.setOutlineThickness(1);

    set_idType(CTYPES::CButtonRadio);
    Selecto = false;
}

void ButtonRadio::Display(sf::RenderWindow* win)
{
   switch(State){
   case STATES::Select:
      prompt.setColor(styles.ColorSelect);
      circle.setFillColor(styles.ColorSelect_alpha);
      circle.setOutlineColor(styles.ColorSelect);
      centro.setFillColor(styles.ColorSelect_alpha);
      centro.setOutlineColor(styles.ColorSelect);
      break;

   case STATES::Pressed:
      prompt.setColor(styles.ColorActive);
      circle.setFillColor(styles.ColorActive_alpha);
      circle.setOutlineColor(styles.ColorActive);
      centro.setFillColor(styles.ColorActive_alpha);
      centro.setOutlineColor(styles.ColorActive);
      break;

   case STATES::Disable:
      prompt.setColor(styles.ColorDisabled);
      circle.setFillColor(styles.ColorDisable_alpha);
      circle.setOutlineColor(styles.ColorDisabled);
      centro.setFillColor(styles.ColorDisable_alpha);
      centro.setOutlineColor(styles.ColorDisabled);
      break;

   default:
      if(Selecto){
         prompt.setColor(styles.ColorActive);
         circle.setFillColor(styles.ColorActive_alpha);
         circle.setOutlineColor(styles.ColorActive);
         centro.setFillColor(styles.ColorActive_alpha);
         centro.setOutlineColor(styles.ColorActive);
      } else {
         prompt.setColor(styles.ColorNormal);
         circle.setFillColor(styles.ColorNormal_alpha);
         circle.setOutlineColor(styles.ColorNormal);
         centro.setFillColor(styles.ColorNormal_alpha);
         centro.setOutlineColor(styles.ColorNormal);
      }
      break;
   }

   win->draw(circle);
   if(Selecto){
      win->draw(centro);
   }

   //win->draw(rcShape);
   win->draw(prompt);

}
