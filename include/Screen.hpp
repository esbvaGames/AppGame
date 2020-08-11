#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SFML/Graphics.hpp>
#include <sstream>
#include <map>

struct COORD {
   float x, y;

   COORD() {
      this->x = -1;
      this->y = -1;
   }

   COORD(float x, float y){
      this->x = x;
      this->y = y;
   }

   COORD operator+(const COORD &other){
      this->x += other.x;
      this->y += other.y;
      return *this;
   }

   COORD operator=(const COORD &other){
      this->x = other.x;
      this->y = other.y;
      return *this;
   }

   std::string toString(){
      std::ostringstream buffer;
      buffer << "COORD(" << x << "," << y << ")";
      return buffer.str();

   }
};


struct DIMENSION {
   float px, py, width, height;   //. Posiciones px, py, ancho, alto
   float cx, cy;                  //. Centro en (x, y)

   DIMENSION(){
      this->px = 0;
      this->py = 0;
      this->cx = 0;
      this->cy = 0;
      this->width = 0;
      this->height = 0;
   }

   DIMENSION(float cx, float cy, float width, float height){
      this->cx = cx;
      this->cy = cy;
      dimensionar(width, height);
   }

   std::string toString(){
      std::ostringstream buffer;
      buffer << "Dimension(" << px << "," << py << "," << width << "," << height << ")";
      return buffer.str();
   }

protected:
   void dimensionar(float width, float height){
      this->width  = width;
      this->height = height;

      this->px = this->cx - (width / 2);
      this->py = this->cy - (height /2);
    }

};

struct STYLES {
   sf::Color ColorNormal;
   sf::Color ColorSelect;
   sf::Color ColorActive;
   sf::Color ColorDisabled;
   sf::Color ColorMargen;
   sf::Color ColorBordes;
   sf::Color ColorFrames;

   sf::Color ColorNormal_alpha;
   sf::Color ColorSelect_alpha;
   sf::Color ColorActive_alpha;
   sf::Color ColorDisable_alpha;
   sf::Color ColorMargen_alpha;
   sf::Color ColorBordes_alpha;
   sf::Color ColorFrames_alpha;

   STYLES(){
      ColorNormal = sf::Color(74, 134, 232);
      ColorSelect = sf::Color(0,255,0);
      ColorActive = sf::Color(0,255,255);
      ColorDisabled = sf::Color(116, 116, 116);
      ColorMargen  = sf::Color(255, 0,0);
      ColorBordes  = sf::Color(0,0,255);
      ColorFrames  = sf::Color(0,150,136);

      ColorNormal_alpha = sf::Color(74, 134, 232, 100);
      ColorSelect_alpha = sf::Color(0, 255, 0, 100);
      ColorActive_alpha = sf::Color(0, 255, 255, 100);
      ColorDisable_alpha = sf::Color(116, 116, 116, 100);
      ColorMargen_alpha = sf::Color(255, 0, 0, 100);
      ColorBordes_alpha = sf::Color(0, 0, 255, 100);
      ColorFrames_alpha = sf::Color(0, 150, 136, 100);
   }
};


enum EVENTS {
   on_Create,
   on_Destroy,
   on_Update,
   on_Display,
   on_Resize,
   on_Visible,
   on_Enabled,
   on_Pressed,
   on_Released,
   on_MouseEntered,
   on_MouseMoved,
   on_MouseExited,
   on_Connected,
   on_Disconnect,
};

typedef void (*callback) (void *Sender, EVENTS evn);

class Widget;

struct Events {
   std::string   idClass;
   Widget   *widget;
   EVENTS   *evn;
   callback *command;
};


class Screen
{
   public:
      Screen();
      virtual ~Screen();

      void Display(sf::RenderWindow *win);
      void Update();
      void Resize();

      void MouseEntered();
      void MouseMoved();
      void MouseExited();

      Widget *Search(std::string idKey);
      bool Remove(std::string idKey);

      std::string toString();

      bool Save_ScreenToFile( std::string filePath);
      bool Load_ScreenFromFile( std::string filePath);

      void setStyles(STYLES m);
      STYLES getStyles();

      void setPosition(COORD m);
      COORD getPosition();

      void setName(std::string);
      std::string getName();

      void setVisible(bool state);
      bool is_Visible();

      void setEnabled(bool state);
      bool is_Enabled();


   protected:
      bool Connect(EVENTS evt, callback *, void *argument);
      bool Disconnet(EVENTS evt, std::string idKey);


   private:
      std::map<std::string, Widget *> TablaWidgets;
      std::map<std::string, Events *> QueueEventos;

      COORD   position;    //. Pisicion en coordenadas del Screen
      STYLES  Styles;      //. Styles predeterminados de Colores
      int     idClass;     //. Numero identificador de la Classe
      int     idTypes;     //. (Label, Button, SpinBox ...)
      std::string idKey;   //. Nombre clave a la Tabla.

      bool visible;
      bool enabled;
      bool focused;

      Screen *FocusNext;
      Screen *FocusPrevio;

      DIMENSION dimNormal;       //. Dimensiones del Screen Normal
      DIMENSION dimMinima;       //. Dimensiones del Screen Minimo
      DIMENSION dimMaxima;       //. Dimensiones del Screen Maximo
      DIMENSION factorMargen;    //. Porcentaje margen: centro(0.5, 0.5, 0.5, 0.5)

      sf::Font     font;         //. Fuente predeterminada
      float        fontScale;    //. Escalar Proporcional a la Fuente Activa
      std::string  pathConfig;   //. Ruta a los Assetes Predeterminados
};

#endif // SCREEN_HPP
