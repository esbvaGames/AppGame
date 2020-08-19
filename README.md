# AppGame
Estructura de interface GUI para SFML.-

Codeblock 2020.- SFML 2.5.1.- Mingw 9.0.2 - 64bits.-


 autor: esbva, 11-08-2020
 
 Este archivo es una forma de Pseudo diagrama, de la estructura de los controles
 y botones que se necesitan en una interface grafica, aunque tiene una tendencia
 que se identifican con el lenguaje C/C++, la intencion no es representar del 
 todo su sintaxis, es mas bien la expresion de la idea dentro de la estructura
 antes de llevar a cabo implementacion de la programacion correcta.
 Esta pensado para que los colaboradores les sea mas facil comprender en que lugar 
 va ensamblada cada pieza de esta libreria.-
 Toda colaboracion en este documento es bienvenida.-
 
 by esbva.-
 


// Modulo de Pantalla GUI

namespace scr {
	
	//. Esilos con colores predeterminados
	enum STYLES {
		ColorNormal,
		ColorSelect,
		ColorActive,
		ColorDisable,
	}
	
	//. Eventos posibles desde los WIDGET
	enum Events {
		on_Create,
		on_Destroy,
		on_Pressed,
		on_Released,
		on_Update,
		on_Display,
		on_Resize,
		on_Visible,
		on_Disabled,
		on_Connect,
		on_Disconnect,
	}
	enum CTYPES {
		CLabel, CButton, CButtonCheck, CButtonRadio ...
	}
	
	typedef  void (callback) (sdt::string, EVENTS *evn);

	struct EVENTS {
		int 			idEvent,
		callback 		*myFunction,
		std::string 	arguments;
	}
	
	struct COORD {
		float x, y;
	}
	
	struct DIMENSION {
		float x, y, width, height;
	}

	/*  CONTENEDOR DE PANTALLAS */

	class Screen {
		private:
			//. Tabla de Widgets en la Screen
			// TABLA <key, WIDGET>[];
			map<string, *Widget> TablaWidget  //. idKey, Widget_elemento  
			map<string, *Widget> iterWidget   //. indice iterador
			
			//. Podria ser plantilla, en final version
			// template<T> map<string, T> TablaWidget
			// template<T> map<string, T> iterWidget
			
			COORD 		position		//. Coordenada en la pantalla (punto centro)
			STYLES 		styles      	//. Colores Predeterminados
			uint 		idClass			//. Numero identificador del Screen
			uint		idTypes			//. Frame / Dialog / Splash
			string		idNames			//. Nombre identificador
			bool 		visible			//. Si es visible (true, false)
			bool 		enabled			//. Si esta disponible
			bool 		focused			//. Si tiene Focus Activo
			
			Screen 		*focusNext		//. Siguiente Screen a focalizar
			Screen 		*focusPrevio	//. Anterior Screen a focalizar
			
			DIMENSION   dimActual
			DIMENSION   dimMinima
			DIMENSION   dimMaxima
			
			FONT        fontBase     	//. Fuente predeterminada
			float       FontScale   	//. Escalar proporcional de la Fuente
			string  	pathConfig  	//. ruta a los recursos basicos.
		
		public:
			virtual void Display(sf::RenderWindow *)
			void Update()
			void Resize()
			bool is_visible()
			bool is_enabled()
			bool in_focused()
			
			bool Connect(EVENT, method, argument)
			bool Disconect()
			bool MouseEntered()
			bool MouseExited()
			bool MouseMoved()
			bool Search(WIDGET, EVENT SendEvent)
			bool remove(WIDGET)
			string toString()	

			Screen_SaveToFile(filename)
			Screen_LoadFromFile(filename)
	
		}
	}

	class Widget {
		//. Cada widget crea una tabla de eventos, y la envia
		//. a un puntero de una funcion en SCREEN
		//. EVENT<event, callFunction, argument)
		map<Events idEvent, EVENTS *evn> TablaEventos   //. Tabla de Eventos
		map<Events idEvent, EVENTS *evn> iterEventos    //. index iterador
		
		private:
			COORD 		position		//. Coordenada en la pantalla (punto centro)
			STYLES 		styles      	//. Colores Predeterminados
			uint 		idClass			//. Numero identificador del Widget
			uint		idTypes			//. (1=Label, 2=Button, 3=ButtonTexture ...)
			string		keyName			//. Nombre identificador en la TablaWidgets
			bool 		visible			//. Si es visible (true, false)
			bool 		enabled			//. Si esta disponible
			bool 		focused			//. Si tiene Focus Activo
			WIDGET 		*focusNext		//. Siguiente Screen a focalizar
			WIDGET 		*focusPrevio	//. Anterior Screen a focalizar	

			DIMENSION  dimActual     	
			DIMENSION  dimMinima
			DIMENSION  dimMaxima
			
			DIMENSION  factorMargen  	//. factor de margen  Centrado = (0.5, 0.5, 0.5, 0.5)
		
		//. Funciones a ser heredadas por cada Widget de la lista de abajo.
		protected:
			void setStyle( STYLES m);
			STYLES getStyle();
			
			void  setPosition(COORD m)	//. Fijar Posicion
			COORD getPosition()
			
			void setName(std::string)
			std::string getName()
			
			void setVisible(state)   	//. state = {true, false}
			bool is_visible()
			
			void setEnabled(state)		//. Si esta disponible
			bool is_enabled()

			void setToogled(state)		//. Si es Boton de Toque (on | off)
			bool is_Toogled()
			
			void setFocus(state)		//. Si esta focalizado
			bool is_focused()
			
			void setFocusNext(WIDGET *m)
			void setFocusPrevio(WIDGET *m)
			
			void setDimension(float width, height)				//. Dimension Actual (Ancho, alto)
			void setDimensionMin(float width, float height)		//. Dimesion Minima
			void setDimensionMax(float width, float height)		//. Dimesion Maxima
			
			DIMENSION getDimension()
			DIMENSION getDimensionMin()
			DIMENSION getDimensionMax()
		
			void setFactorMargen(DIMENSION m)
			DIMENSION getFactorMargen()
			
			std::string toString()		//. Retorna un String texto con los parametros configurados
		
			virtual Display(sf::RenderWindow *m)
			virtual Update()
			virtual Resize()
		
		//. Clases Heredadas (por hacer)
		//. Los Widget Predeterminados solo son dibujados
		//. Los Widget Personalizados son revestidos con texturas
		
		class Label;
		class Button;
			class ButtonTexture;
			class ButtonRadio;
			class ButtonCheck;
		class Rect
			class RectColor;
			class RectTexture;
			
		class H_BOX;
		class V_BOX;
		
		class TextBox;
		class TextView;
		class ListBox;
		class ComboBox;
		class SpinBox;
		class TabView
		
		class Panel;
			class PanelTexture;
			class PanelScroller;
			
		class Scroll_V;
		class Scroll_H;
		
		class Slider_V;
		class Slider_H;
		
		class ColorBox;
		class ImageBox;
		
		class TreeView;
		class ProgressBar
			class ProgressTextureRect;
			class ProgressTextureCircle;
			
		class fileOpen;
		class fileSave;
		
		class ChooseColor;
		class ChooseFonts;

}
