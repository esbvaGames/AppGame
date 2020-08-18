
#include <label.hpp>

Label::Label()
{
   //ctor
}

Label::~Label()
{
   //dtor
}


Label::Label(Screen *scr, float cx, float cy, std::string texto, float Scale) : Widget(scr)
{
   this->fontScale = Scale;
   this->fontBase  = scr->getFontBase();

   prompt = sf::Text(texto, this->fontBase, this->fontScale);
   prompt.setPosition(cx, cy);
   set_idType(CTYPES::CLabel);
}



void Label::Display(sf::RenderWindow *win)
{
   //. Debug USO
   //std::string texto = std::string(prompt.getString());
   //std::cout << "Display Label: (" << prompt.getPosition().x << "," << prompt.getPosition().y << ") " << texto << std::endl;
   win->draw(prompt);
}

//. Configurar linea de datos para grabacion.-
std::string Label::toString(){
   std::ostringstream buffer;
   buffer << "Label: " << std::string(prompt.getString());
   return buffer.str();
}
