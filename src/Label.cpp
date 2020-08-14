
#include <label.hpp>

Label::Label()
{
   //ctor
}

Label::~Label()
{
   //dtor
}


Label::Label(float cx, float cy, std::string texto, sf::Font fontBase, float Scale)
{
   myFont = fontBase;
   //if(!myFont.loadFromFile("./assets/acme.ttf")){
   //   std::cout << "Error Leyendo: acme.ttf" << std::endl;
   //}
   prompt = sf::Text(texto, myFont, Scale);
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
