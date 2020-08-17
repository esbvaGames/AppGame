
#include "Button.hpp"

Button::Button()
{
   //ctor
   MouseEnter = false;
   set_idType(CTYPES::CButton);
}

Button::~Button()
{
   //dtor
}
Button::Button(float cx, float cy, float width, float height, \
               std::string texto, sf::Font myFont, float Scale)
{
   rcShape.setSize(sf::Vector2f(width, height));
   rcShape.setFillColor(styles.ColorNormal_alpha);
   rcShape.setOutlineColor(styles.ColorNormal);
   rcShape.setOutlineThickness(2.0f);
   rcShape.setPosition(cx, cy);

   rcForma = sf::Rect<float>(cx, cy, width, height);

   this->Scale = Scale;
   this->myFont = myFont;
   prompt = sf::Text(texto, this->myFont, this->Scale);
   prompt.setColor(styles.ColorNormal);

   float px = (prompt.getLocalBounds().width)  - (width * 0.5);
   float py = (prompt.getLocalBounds().height) - (height* 0.5);

   prompt.setPosition(cx + px , cy + py);
   set_idType(CTYPES::CButton);
}

void Button::MouseInRect(sf::RenderWindow *win)
{
   float px = sf::Mouse::getPosition(*win).x;
   float py = sf::Mouse::getPosition(*win).y;

   if(rcForma.contains( sf::Vector2<float>(px, py) )){
      State = STATES::Select;
      if(!MouseEnter){
         MouseEnter = true;
         on_CallFunction(Event::on_MouseEntered);
         //LOG_WARN("Mouse-Entered");
      }


      if(sf::Mouse::isButtonPressed( sf::Mouse::Left )){
         std::cout << "Pressed Left"   << std::endl;
         State = STATES::Pressed;
         if(idTypes == CTYPES::CButtonRadio){
            Selecto = ((Selecto == true) ? false : true);

            //. FUNCTION FRIEND GENERAL.
            Option_Update(this->KeyName, this->idGroup );
         }
         LOG_WARN(Selecto);
      //. Llama la funcion apuntada en (on_Pressed)
         on_CallFunction(Event::on_Pressed);

      } else if(sf::Mouse::isButtonPressed( sf::Mouse::Right )){
         std::cout << "Pressed Right"  << std::endl;
         State = STATES::Disable;
// TODO (esbva#1#): Enviar eventos al queue

      } else if(sf::Mouse::isButtonPressed( sf::Mouse::Middle)){
         std::cout << "Pressed Middle" << std::endl;
// TODO (esbva#1#): Enviar eventos al queue

      }


   } else {
      if(MouseEnter){
         MouseEnter = false;
         on_CallFunction(Event::on_MouseExited);
         //LOG_WARN("Mouse Exited");

      }
      State = STATES::Normal;
   }
   //std::cout << "(" << px <<","<< py <<")" << std::endl;
}

void Button::Display(sf::RenderWindow *win)
{
   switch(State){
   case STATES::Select:
      prompt.setColor(styles.ColorSelect);
      rcShape.setOutlineColor(styles.ColorSelect);
      rcShape.setFillColor(styles.ColorSelect_alpha);
      break;

   case STATES::Pressed:
      prompt.setColor(styles.ColorActive);
      rcShape.setOutlineColor(styles.ColorActive);
      rcShape.setFillColor(styles.ColorActive_alpha);
      break;

   case STATES::Disable:
      prompt.setColor(styles.ColorDisabled);
      rcShape.setOutlineColor(styles.ColorDisabled);
      rcShape.setFillColor(styles.ColorDisable_alpha);
      break;

   default:
      prompt.setColor(styles.ColorNormal);
      rcShape.setOutlineColor(styles.ColorNormal);
      rcShape.setFillColor(styles.ColorNormal_alpha);
      break;

   }
   win->draw(rcShape);
   win->draw(prompt);

}

void Button::setGroup(std::string idGroup)
{
   this->idGroup = idGroup;
}

std::string Button::getGroup()
{
   return idGroup;
}

void Button::setSelect(bool state)
{
   this->Selecto = state;
}

bool Button::is_Select()
{
   return this->Selecto;
}


std::string Button::toString()
{
   std::ostringstream buffer;
   buffer << "Button: {" \
          << KeyName << "," \
          << prompt.getString().toAnsiString() << "," \
          << "(" << prompt.getScale().x << "," << prompt.getScale().y << ")," \
          << rcForma.left << "," \
          << rcForma.top  << "," \
          << rcForma.width << "," \
          << rcForma.height << "}";

   return buffer.str();

}
