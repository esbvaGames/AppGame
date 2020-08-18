
#include <widget.hpp>


Widget::Widget()
{
   //ctor
   screen = NULL;
   FocusNext = NULL;
   FocusPrevio = NULL;
   newFont(std::string("./assets/acme.ttf"));
}

Widget::Widget(Screen *scr)
{
   FocusNext = NULL;
   FocusPrevio = NULL;
   newFont(std::string("./assets/acme.ttf"));

   this->screen = scr;
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

bool Widget::Connect(Event idEvent, callback* command, std::string argument)
{
   iterEventos = Eventos.find(idEvent);
   if(iterEventos == Eventos.end()){
      EVENTS *evn = new EVENTS(idEvent, command, argument);
      Eventos.insert(std::make_pair(idEvent, evn));
      return true;
   } else {
      LOG_ERRN( "Evento: " << (int)idEvent << " ya fue asignado");
   }
   return false;
}

bool Widget::Disconnect(Event idEvent)
{
   iterEventos = Eventos.find(idEvent);
   if(iterEventos != Eventos.end()){
      Eventos.erase(iterEventos);
      return true;
   }
   return false;
}


void Widget::on_CallFunction(Event idEvent)
{
   iterEventos = Eventos.find(idEvent);
   if(iterEventos != Eventos.end()){
      ((EVENTS*)iterEventos->second)->command(KeyName, iterEventos->second);
   }
}




