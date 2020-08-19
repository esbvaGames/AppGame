
#include "Rectangle.hpp"

Rectangle::Rectangle()
{
   //ctor
}

Rectangle::~Rectangle()
{
   //dtor
}

Rectangle::Rectangle(Screen* scr, float cx, float cy, float width, float height, std::string fileImage) : Widget(scr)
{
   rcBorde = sf::RectangleShape(sf::Vector2f(width, height));
   rcBorde.setOutlineColor(styles.ColorNormal);
   rcBorde.setOutlineThickness(2);
   rcBorde.setPosition(cx, cy);

   if(fileImage != "."){
      if(!image.loadFromFile(get_pathAssets() + "/" + fileImage)){
         LOG_ERRN("falla leyendo: " + fileImage);
      }
      rcBorde.setTexture(&image);
   } else {
      rcBorde.setFillColor(styles.ColorNormal_alpha);
   }


   set_idType(CTYPES::CRectangle);
}

void Rectangle::Display(sf::RenderWindow* win)
{
   win->draw(rcBorde);
}
std::string Rectangle::toString()
{
   std::ostringstream buffer;
   buffer << "Rectangle { " <<
            rcBorde.getPosition().x << "," << \
            rcBorde.getPosition().y << "," << \
            rcBorde.getSize().x << "," << \
            rcBorde.getSize().y << ",";
   return buffer.str();

}

