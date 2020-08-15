
#include <widget.hpp>


Widget::Widget()
{
   //ctor
   FocusNext = NULL;
   FocusPrevio = NULL;

   newFont(std::string("./assets/acme.ttf"));
}

Widget::~Widget()
{
   //dtor
}

void Widget::newFont(std::string fileFont, float fontScale){
   this->fileFont = fileFont;
   this->fontScale = fontScale;
   if(!fontBase.loadFromFile(fileFont)){
      assert( fontBase.loadFromFile(fileFont)  );
   }
}

sf::Font Widget::getFont( float &fontScale){
   fontScale = this->fontScale;
   return fontBase;
}


void Widget::setKeyName(std::string KeyName){
   this->KeyName = KeyName;
}

std::string Widget::getKeyName(){
   return this->KeyName;
}

void Widget::set_idType(CTYPES idTypes){
   this->idTypes = idTypes;
}

CTYPES Widget::get_idType(){
   return this->idTypes;
}


