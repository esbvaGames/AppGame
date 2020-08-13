
#include "Screen.hpp"
#include "Widget.hpp"
#include "Label.hpp"



Screen::Screen()
{
   //ctor
   fontScale  = 10.0f;
   fontFile   = "/acme.ttf";
   pathAssets = "./assets";
   if(!fontBase.loadFromFile( pathAssets + fontFile )) {
      std::cout << "Error Leyendo Font: " << fontFile << std::endl;
   }


}

Screen::~Screen()
{
   //dtor
   TablaWidgets.clear();
   QueueEventos.clear();

}

sf::Font Screen::getFontBase(){
   return fontBase;
}

void Screen::setFontBase(sf::Font fontBase, float fontScale){
   this->fontBase  = fontBase;
   this->fontScale = fontScale;

}


void Screen::Display(sf::RenderWindow *win){
   for(iterWidget = TablaWidgets.begin(); iterWidget != TablaWidgets.end(); ++iterWidget){
      Widget *data = (Widget*) iterWidget->second;
      //. Method Virtual
      //data->Display(win);

      //. Conversion <dynamic_cast> DEBUG USO
      if(data->get_idType() == CTYPES::CLabel){
         ((Label*)data)->Display(win);
      }
      //std::cout << iterWidget->first << " : " << data->get_idType() << std::endl;
   }


}

bool Screen::Widget_add(std::string idKey, Widget *widget){
   bool ioResult = false;

   iterWidget = TablaWidgets.find(idKey);
   if(iterWidget == TablaWidgets.end()){
      widget->setKeyName(idKey);
      TablaWidgets.insert(make_pair(idKey, widget));
      ioResult = true;
   } else {
      std::cout << "Error: Key (" << idKey << ") ya esta en la tabla" << std::endl;

   }
   return ioResult;
}

bool Screen::Widget_remove(std::string idKey){
   bool ioResult = false;
   iterWidget = TablaWidgets.find(idKey);
   if(iterWidget != TablaWidgets.end()){
      TablaWidgets.erase(idKey);
      ioResult = true;
   }
   return ioResult;
}

//... FUNCIONES DE CREACION DE WIDGETS ...
// TODO (esbva#1#): Agregar escala de la etiqueta

Label *Screen::Create_Label(float cx, float cy, std::string Texto){
   Label *label = new Label(cx, cy, Texto, this->fontBase);
   return label;
}

/*
Button       *Screen::Create_Button( ... )
ButtonRadio  *Screen::Create_ButtonRadio ( ... )
ButtonCheck  *Screen::Create_ButtonCheck ( ... )
   ...

*/
