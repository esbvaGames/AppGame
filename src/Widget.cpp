
#include <widget.hpp>

Widget::Widget()
{
   //ctor
   FocusNext = NULL;
   FocusPrevio = NULL;
}

Widget::~Widget()
{
   //dtor
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


