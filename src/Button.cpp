
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
Button::Button(Screen *scr, float cx, float cy, float width, float height, \
               std::string texto, float Scale) : Widget(scr)
{

   rcShape.setSize(sf::Vector2f(width, height));
   rcShape.setFillColor(styles.ColorNormal_alpha);
   rcShape.setOutlineColor(styles.ColorNormal);
   rcShape.setOutlineThickness(2.0f);
   rcShape.setPosition(cx, cy);

   rcForma = sf::Rect<float>(cx, cy, width, height);

   this->Scale = Scale;
   this->myFont = scr->getFontBase();
   prompt = sf::Text(texto, this->myFont, this->Scale);
   prompt.setFillColor(styles.ColorNormal);

   float px = (float) (width - (prompt.getLocalBounds().width)) / 2.0f;
   float py = (float) (height - (prompt.getLocalBounds().height)) / 2.0f -4.0;

   prompt.setPosition(cx + px , cy + py);
   set_idType(CTYPES::CButton);
   Toogled = false;
   Selecto = false;
}

void Button::MouseInRect(sf::RenderWindow *win)
{
   float px = sf::Mouse::getPosition(*win).x;
   float py = sf::Mouse::getPosition(*win).y;

   if(rcForma.contains( sf::Vector2<float>(px, py) )){
      if(Toogled){
         if(!Selecto){
            State = STATES::Select;
         }
      } else {
         State = STATES::Select;
      }

      if(!MouseEnter){
         MouseEnter = true;
         on_CallFunction(Event::on_MouseEntered);
         //LOG_WARN("Mouse-Entered");
      }


      if(sf::Mouse::isButtonPressed( sf::Mouse::Left )){
         std::cout << "Pressed Left"   << std::endl;
         State = STATES::Pressed;
         if(idTypes == CTYPES::CButton){
            if(Toogled){
               Selecto = ((Selecto == true) ? false : true);
               if(Selecto){
                  State = STATES::Pressed;
               } else {
                  State = STATES::Normal;
               }
            }
         }
         if(idTypes == CTYPES::CButtonRadio){
            Selecto = ((Selecto == true) ? false : true);
            //. FUNCTION FRIEND GENERAL.
            screen->Widget_Option(this->KeyName, this->idGroup );
            LOG_WARN("Button Options: " << Selecto);
         }
         if(idTypes == CTYPES::CButtonCheck){
            Selecto = ((Selecto == true) ? false : true);
            LOG_WARN("Button Checked: " << Selecto);
         }

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
      if(Toogled){
         if(Selecto){
            State = STATES::Pressed;
         } else {
            State = STATES::Normal;
         }

      } else {
         State = STATES::Normal;
      }
   }
   //std::cout << "(" << px <<","<< py <<")" << std::endl;
}

void Button::Display(sf::RenderWindow *win)
{
   switch(State){
   case STATES::Select:
      prompt.setFillColor(styles.ColorSelect);
      rcShape.setOutlineColor(styles.ColorSelect);
      rcShape.setFillColor(styles.ColorSelect_alpha);
      break;

   case STATES::Pressed:
      prompt.setFillColor(styles.ColorActive);
      rcShape.setOutlineColor(styles.ColorActive);
      rcShape.setFillColor(styles.ColorActive_alpha);
      break;

   case STATES::Disable:
      prompt.setFillColor(styles.ColorDisable);
      rcShape.setOutlineColor(styles.ColorDisable);
      rcShape.setFillColor(styles.ColorDisable_alpha);
      break;

   default:
      prompt.setFillColor(styles.ColorNormal);
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
