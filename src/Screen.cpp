
#include "Screen.hpp"
#include "Widget.hpp"
#include "Label.hpp"
#include "Button.hpp"
#include "ButtonRadio.hpp"




Screen::Screen()
{
   //ctor
   pathAssets = "./assets";

   //. Carga la font predeterminada
   fontFile = "./assets/acme.ttf";
   if(!fontBase.loadFromFile(fontFile)){
      LOG_ERRN( "falla leyendo: " << fontFile);
   }


}

Screen::~Screen()
{
   //dtor
   TablaWidgets.clear();
   QueueEventos.clear();

}

void Screen::Update(sf::RenderWindow* win)
{
   for(iterWidget = TablaWidgets.begin(); iterWidget != TablaWidgets.end(); ++iterWidget){
      Widget *data = (Widget*) iterWidget->second;
      switch(data->get_idType()){
      case CTYPES::CButton:
         ((Button *)data)->MouseInRect(win);
         break;
      case CTYPES::CButtonRadio:
         ((ButtonRadio*)(Button*)data)->MouseInRect(win);
         break;

      default:
         break;
      }
   }
}




void Screen::Display(sf::RenderWindow *win){
   for(iterWidget = TablaWidgets.begin(); iterWidget != TablaWidgets.end(); ++iterWidget){
      Widget *data = (Widget*) iterWidget->second;
      //. Method Virtual
      //data->Display(win);

      //. Conversion <dynamic_cast> DEBUG USO
      switch(data->get_idType()){
      case CTYPES::CLabel:
         ((Label*)data)->Display(win);
         break;
      case CTYPES::CButton:
         ((Button*)data)->Display(win);
         break;

      case CTYPES::CButtonRadio:
         ((ButtonRadio*)(Button*)data)->Display(win);
         break;

      default:
         break;
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

Widget* Screen::Search(std::string idKey)
{
   iterWidget = TablaWidgets.find(idKey);
   if(iterWidget != TablaWidgets.end()){
      return (Widget*)iterWidget->second;
   }
   return NULL;
}

void Screen::Widget_Option(std::string idKey, std::string idGroup)
{
   LOG_WARN("Actualizar: " << idKey << " :: " << idGroup);
   for(iterWidget = TablaWidgets.begin(); iterWidget != TablaWidgets.end(); ++iterWidget){
      Widget *data = (Widget*)iterWidget->second;
      if(data->get_idType() == CTYPES::CButtonRadio){
         ButtonRadio *option = (ButtonRadio*)(Button*)data;
         if(option->getGroup() == idGroup){
            if(option->getKeyName() == idKey){
               continue;
            }
         }
         //LOG_WARN(option->getKeyName() << " :: " << option->getGroup());
         option->setSelect(false);
      }
   }
}




//... FUNCIONES DE CREACION DE WIDGETS ...

Label *Create_Label(Screen *scr, float cx, float cy, std::string Texto, float Scale = 10.0f){
   Label *label = new Label(cx, cy, Texto, scr->fontBase, Scale);
   return label;
}

Button *Create_Button(Screen *scr, float cx, float cy, std::string texto, float Scale){
   Button *button = new Button(cx, cy, 70.0, 25.0, texto, scr->fontBase, Scale);
   return button;
}

ButtonRadio *Create_Option(Screen *scr, float cx, float cy, std::string texto, float Scale, \
                           std::string idGrupo){
   ButtonRadio *option = new ButtonRadio(cx, cy, 80, 25, texto, scr->fontBase, Scale);
   option->setGroup(idGrupo);
   return option;
}

/* PANTALLA GENERAL DE PRUEBA */
#ifndef MAIN
   extern Screen *myScreen;
#endif

void Option_Update(std::string idKey, std::string idGroup){
   myScreen->Widget_Option(idKey, idGroup);
}
/*
Button       *Screen::Create_Button( ... )
ButtonRadio  *Screen::Create_ButtonRadio ( ... )
ButtonCheck  *Screen::Create_ButtonCheck ( ... )
   ...

*/


