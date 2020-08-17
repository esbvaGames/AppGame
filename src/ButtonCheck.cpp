#include "ButtonCheck.hpp"

ButtonCheck::ButtonCheck()
{
   //ctor
}

ButtonCheck::~ButtonCheck()
{
   //dtor
}

ButtonCheck::ButtonCheck(float cx, float cy, float width, float height, \
                         std::string texto, sf::Font fontBase, float Scale) : Button(cx, cy, width, height, texto, fontBase, Scale)
{
    prompt.setPosition(sf::Vector2f(cx +25, cy));
    rcShape.setPosition(cx-4, cy -2);
    float WIDTH  = prompt.getLocalBounds().width + 40;
    float HEIGHT = prompt.getLocalBounds().height + 10;
    rcShape.setSize(sf::Vector2f(WIDTH, HEIGHT));
    rcForma = sf::Rect<float>(cx, cy, WIDTH, HEIGHT);


   rcCuadro.setPosition(cx, cy);
   rcCuadro.setSize(sf::Vector2f(18, 18));
   rcCuadro.setFillColor(styles.ColorNormal_alpha);
   rcCuadro.setOutlineColor(styles.ColorNormal);
   rcCuadro.setOutlineThickness(2);

   rcCentro.setPosition(cx+3, cy+3);
   rcCentro.setSize(sf::Vector2f(12,12));
   rcCentro.setFillColor(styles.ColorNormal_alpha);
   rcCentro.setOutlineColor(styles.ColorNormal);
   rcCentro.setOutlineThickness(1);

   set_idType(CTYPES::CButtonCheck);
   Selecto = false;
}

void ButtonCheck::Display(sf::RenderWindow* win)
{
   switch(State){
   case STATES::Select:
      prompt.setFillColor(styles.ColorSelect);
      rcCuadro.setFillColor(styles.ColorSelect_alpha);
      rcCuadro.setOutlineColor(styles.ColorSelect);
      rcCentro.setFillColor(styles.ColorSelect_alpha);
      rcCentro.setOutlineColor(styles.ColorSelect);
      break;

   case STATES::Pressed:
      prompt.setFillColor(styles.ColorActive);
      rcCuadro.setFillColor(styles.ColorActive_alpha);
      rcCuadro.setOutlineColor(styles.ColorActive);
      rcCentro.setFillColor(styles.ColorActive_alpha);
      rcCentro.setOutlineColor(styles.ColorActive);
      break;

   case STATES::Disable:
      prompt.setFillColor(styles.ColorDisable);
      rcCuadro.setFillColor(styles.ColorDisable_alpha);
      rcCuadro.setOutlineColor(styles.ColorDisable);
      rcCentro.setFillColor(styles.ColorDisable_alpha);
      rcCentro.setOutlineColor(styles.ColorDisable);
      break;

   default:
      if(Selecto){
         prompt.setFillColor(styles.ColorActive);
         rcCuadro.setFillColor(styles.ColorActive_alpha);
         rcCuadro.setOutlineColor(styles.ColorActive);
         rcCentro.setFillColor(styles.ColorActive_alpha);
         rcCentro.setOutlineColor(styles.ColorActive);
      } else {
         prompt.setFillColor(styles.ColorNormal);
         rcCuadro.setFillColor(styles.ColorNormal_alpha);
         rcCuadro.setOutlineColor(styles.ColorNormal);
         rcCentro.setFillColor(styles.ColorNormal_alpha);
         rcCentro.setOutlineColor(styles.ColorNormal);
      }
      break;

   };

   win->draw(rcCuadro);
   if(Selecto){
      win->draw(rcCentro);
   }
   win->draw(prompt);
}
