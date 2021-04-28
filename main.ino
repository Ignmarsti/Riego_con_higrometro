#include <Keypad.h>
#include <RTClib.h>
#include <SDHT.h>
#include <lcdgfx.h>
//Objeto pantalla OLED
int8_t ResetPin =  -1;         //Cambiar por -1 si no hay pin de reset
int8_t Dir_Pantalla = 0x3C;   //Cambiar por 0x3C si esta direccion no funciona
DisplaySSD1306_128x64_I2C display(ResetPin, { - 1, Dir_Pantalla, -1, -1, 0});

const uint8_t dibujo_menu[] PROGMEM = {
   
// Page7
//--------------------------------------------------------------------------
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xFF, 0x00, 0x00, 0xC0, 0xE0, 0xF0, 
0xFC, 0xFE, 0xFC, 0xF0, 0xE0, 0xC0, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 
0x00, 0xFC, 0x02, 0x02, 0xFC, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// Page6
//--------------------------------------------------------------------------
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xFF, 0x00, 0x00, 0xC3, 0x87, 0x4F, 
0x8F, 0x4F, 0x8F, 0x4F, 0x87, 0xC3, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x80, 
0xC0, 0xFF, 0xFC, 0xFC, 0xFF, 0xC0, 0x80, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// Page5
//--------------------------------------------------------------------------
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xFF, 0x00, 0x00, 0x07, 0x08, 0x10, 
0x10, 0xE0, 0x10, 0x10, 0x08, 0x07, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xFF, 0x20, 0x20, 0x27, 
0x2F, 0x3F, 0x3F, 0x3F, 0x3F, 0x2F, 0x27, 0x20, 
0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 

// Page4
//--------------------------------------------------------------------------
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xFF, 0x80, 0x80, 0x8F, 0x92, 0xA4, 
0xC8, 0xFF, 0xC8, 0xA4, 0x92, 0x8F, 0x80, 0x80, 
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
0x80, 0x80, 0x80, 0x80, 0xFF, 0x00, 0x00, 0xE0, 
0xF0, 0xF8, 0xFE, 0xFF, 0xFE, 0xF8, 0xF0, 0xE0, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0x80, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// Page3
//--------------------------------------------------------------------------
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x01, 
0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 
0x00, 0x00, 0x78, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 
0xFE, 0xFC, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// Page2
//--------------------------------------------------------------------------
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xFF, 0x04, 0x04, 0x24, 
0x44, 0x84, 0x04, 0x04, 0x04, 0x04, 0x74, 0x04, 
0x04, 0x04, 0x04, 0x04, 0x85, 0x45, 0x05, 0x05, 
0x05, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 

// Page1
//--------------------------------------------------------------------------
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x10, 0x10, 
0x10, 0x00, 0x7C, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFE, 0x7C, 0x01, 0x10, 0x10, 0x10, 0x10, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// Page0
//--------------------------------------------------------------------------
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x08, 
0x04, 0x02, 0x00, 0x00, 0x01, 0x01, 0x1D, 0x01, 
0x01, 0x00, 0x00, 0x01, 0x02, 0x04, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

};

//Objeto KEYPAD
const byte filas = 4;
const byte columnas = 4;
char teclas [filas][columnas] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte pinesFilas [filas] = {11, 10, 9, 8};//Definimos los pines correspondientes a las filas del teclado matricial
byte pinesColumnas [columnas] = {7, 6, 5, 4};//Definimos los pines correspondientes a las filas del teclado matricial
Keypad teclado = Keypad(makeKeymap(teclas), pinesFilas, pinesColumnas, filas, columnas); ///Crea el mapa del teclado

//Objeto RTC
RTC_DS1307 rtc;
DateTime hoy;

//Objeto DHT
#define pinsensorT 2////Definimos el puerto donde conectaremos el sensor de temperatura
#define TipoSensor DHT11/////Definimos el tipo de sensor que es
SDHT dht;

//Variables y pines
#define ldr_pin A2  //PIN 11
const int higrometro = A0;
int humedad_tierra =0;

char tecla_pulsada;
int horariego1_00[3] = {8, 0, 0};
int horariego2_00[3] = {15, 0, 0};
int horariego3_00[3] = {22, 0, 0};
char hora_aux1[6];///Esta cadena de caracteres contendrá la hora final programada
char hora_aux2[6];
char hora_aux3[6];
int estadoriegoint=0;
char estadoriego[2];



byte ano, mes, dia, hora, minuto, segundo;
char fecha[] = ("  :  :  ");
char calendario[] = ("  /  /20  ");

char opcion_seleccionada;
bool menu = true;
bool error = false;
bool banderariego = false;
bool mantener = false;

////---------Variables Conversion Datos---------////

char dht_temp[20];
char tmp[6]; 
char dht_hum[17];
char hmd[6]; 
char luxometro[5];
char hgrmtro[4];
char porcent[1]={'%'};
char lu[2];
int luz;

unsigned long tiempo=0;//Aquí guardaremos el tiempo desde que se inició por primera vez el microcontrolador.
unsigned long tiempoldr = 0;///Iniciamos la variable, que usaremos para calcular que haya pasado 500 ms desde la última lectura del ldr, en 0.
unsigned long tiempobomba = 0;//Iniciamos la variable que usaremos para guardar el momento exacto en el que se inicia la activación de la bomba.
unsigned long tiempohigrometro = 0;
bool banderatiempo = 0;

void setup() {
  
  pinMode(LED_BUILTIN, OUTPUT);
  display.begin();
  rtc.begin();
  //rtc.adjust(DateTime(__DATE__, __TIME__));///ESTA LINEA SE TIENE QUE COMENTAR NADA MAS SE CARGUE UNA VEZ, Y VOLVER A CARGAR EL SKECTH PARA QUE DE ESTA MANERA SOLO SE PONGA EN HORA UNA VEZ A TRAVÉS DEL ORDENADOR
  //rtc.adjust(DateTime(2021, 02, 17, 19, 44, 00));
  
  
}

void loop() {

  tiempo = millis();
  if (menu) {
    menu_principal();
  }
  if(mantener){
    conversion_datos();
    escribir_texto(96, 13, tmp, 1);
    escribir_texto(96, 26, hmd, 1);

  if(millis()-tiempohigrometro>=18000000){///Si han pasado 5 horas desde la última lectura del higrometro tomamos una nueva (esto lo hacemos porque se corroe facilmente con las lecturas)
    sprintf(hgrmtro, "%i", humedad_tierra);
    strcat(lu,porcent);
    escribir_texto(58, 15, hgrmtro, 1);
    tiempohigrometro=millis();
  }

  if(millis()-tiempoldr>=500){//Si ha pasado 500 ms, desde que se tomó la última lectura del ldr, tomamos una nueva.
    
    if(luz>=10){
      sprintf(lu, "%i", luz);
      strcat(lu, porcent);
      escribir_texto(105, 55, lu, 1);
    }
    else{/////////////////--------------He tenido que hacer esto porque no se como añadirle SOLO UN CARACTER % a la cadena si i<10 (SIEMPRE ME SALEN 2 %)-------------///////////
      luz=10;
      sprintf(lu, "%i", luz);
      strcat(lu, porcent);
      escribir_texto(105, 55, lu, 1);
    }
    tiempoldr=millis();
  }

    mostrar_horas_riego();  
    escribir_texto(0, 0, hora_aux1, 1);
    escribir_texto(0, 10, hora_aux2, 1);
    escribir_texto(0, 20, hora_aux3, 1);
    
  }

 
   escribir_texto(47, 41, "RIEGO", 1);
   sprintf(estadoriego, "%i", estadoriegoint);
   escribir_texto(56, 51, estadoriego, 1);
  
  
  hora_de_regar();
  recuperar_fecha();
  dht.read(TipoSensor, pinsensorT);
  
  //t = dht.readTemperature();////En grados celsius por defecto
  hoy = rtc.now();///Recuperamos la fecha actual
  tecla_pulsada = teclado.getKey();//Comprobamos que tecla se ha pulsado
  opcion_seleccionada = tecla_pulsada; //La guardamos en una nueva variable
  //Tenemos varias opciones
  if (opcion_seleccionada == 'A') {
    programar_Horarios(horariego1_00, "A");
    opcion_seleccionada = '\0';
    error = false;
  }
  if (opcion_seleccionada == 'B') {
    programar_Horarios(horariego2_00, "B");
    opcion_seleccionada = '\0';
    error = false;
  }
  if (opcion_seleccionada == 'C') {
    programar_Horarios(horariego3_00, "C");
    opcion_seleccionada = '\0';
    error = false;
  }
  if (opcion_seleccionada == 'D') {
    opcion_seleccionada = '\0';
    ver_fecha();
  }
  if (opcion_seleccionada == '#') {
    opcion_seleccionada = '\0';
    opcion_sensado();
  }
}

//Aquí tenemos las distintas funciones en las que podemos programar la hora de riego

void programar_Horarios(int horario[3], char *opcion) {
  int horario_Ant[3] = {horario[0], horario[1], horario[2]};
  char msj[22] = "Opcion ";
  strcat(msj, opcion);
  strcat(msj, " seleccionada");
  display.fill(0x00);
  escribir_texto(0, 0, msj, 1);
  programar_H_M_S(horario);
  if (error) {
    horario[0] = horario_Ant[0];///En caso de que se produzca un error al introducir la hora, nos quedamos con la hora anteriormente programada
    horario[1] = horario_Ant[1];
    horario[2] = horario_Ant[2];
    return 0;
  }
  char HORA_FINAL[9];///Esta cadena de caracteres contendrá la hora final programada
  HORA_FINAL[0] = 0;//Iniciamos en 0
  char HORA_F[3];//Esta cadena la usaremos para ir guardando los números enteros correspondientes a las horas, minutos y segundos convertidos en caracteres
  HORA_F[0] = 0;///Iniciamos en 0
  for (int j = 0; j < 3; j++) {
    if (horario[j] < 10) {
      strcat(HORA_FINAL, "0");////En caso de que el número sea menor de 10, añadimos un 0 para que quede en formato: "09"
    }
    sprintf(HORA_F, "%i", horario[j]);////Función para convertir el entero horario[j] en una cadena de caracteres que se guarda en HORA_F. %i indica que el número a convertir es un entero
    strcat(HORA_FINAL, HORA_F);//Unimos las horas, minutos y segundos..
    if ( j < 2) {
      strcat(HORA_FINAL, ":");///..separando cada dos digitos por : para que el formato quede así 00:00:00 
    }
  }
  display.fill(0x00);///Limpiamos la pantalla
  escribir_texto(15, 0, "Se ha programado", 1);
  escribir_texto(9, 9, "la hora de riego :", 1);
  escribir_texto(40, 20, HORA_FINAL, 1);
  delay(2000);
  display.fill(0x00);
  menu = true;
}

void programar_H_M_S(int horario_temp[3]) {
  char Hora[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};///Iniciamos la variable en 0
  recolecta_datos(24, 0, 9, ":", Hora);
  if (!strcmp(Hora, "invalido")) {///Esta funcion compara caracter por caracter, y en caso de que sean iguales devuelve un 0
    Invalido();
    error = true;
    menu = true;
    return 0;
  }
  char Minutos[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};//Iniciamos la variable en 0
  recolecta_datos(60, 21, 9, ":", Minutos);
  if (!strcmp(Minutos, "invalido")) {
    Invalido();
    error = true;
    menu = true;
    return 0;
  }
  char Segundos[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};//Iniciamos la variable en 0
  recolecta_datos(60, 40, 9, " ", Segundos);
  if (!strcmp(Segundos, "invalido")) {
    Invalido();
    error = true;
    menu = true;
    return 0;
  }
  horario_temp[0] = atoi(Hora);///La función atoi(matriz) convierte una cadena de caracteres en un entero
  horario_temp[1] = atoi(Minutos);
  horario_temp[2] = atoi(Segundos);
}

void recolecta_datos(int limite, int C_X, int C_Y, char *separador, char buf[9]) {////La variable char * indica que no se puede modificar, ya que esto podría causar un comportamiento indefinido
  char T_pulsada[2];
  T_pulsada[1] = 0;//Iniciamos la variable en 0
  for (int j = 0; j < 2; j++) {
    T_pulsada[0] = teclado.waitForKey(); ////Esta función es importante, ya que hasta que no pulsemos una tecla, el micro se queda parado en está instrucción. La unica manera de avanzar es pulsar una tecla o salir de bucle for
    if (isDigit(T_pulsada[0]) && T_pulsada[0] != '*' && T_pulsada[0] != '#') {
      escribir_texto(C_X, C_Y, T_pulsada, 1);
      strcat(buf, T_pulsada);///Vamos concatenando uno a uno los dígitos pulsados
      C_X += 7;///Hacemos esto para que no se superpongan los caracteres al imprimirlo por pantalla
    } else {
      j = 2;
      strcpy(buf, "invalido");
      return 0;
    }
  }
  int numero = atoi(buf);///Convertimos la cadena de digitos en un entero con la función atoi
  if (numero >= limite) {///Comprobamos que no el número introducido no supere el límite
    strcpy(buf, "invalido");///Si lo ha superado, metemos en buf la palabra inválido
    return 0;
  } else {
    escribir_texto(C_X, C_Y, separador, 1);
  }
}

void Invalido() {
  unsigned long tiempo_invalido = tiempo;
  display.fill(0x00);
  while(millis() - tiempo_invalido <= 2000){
    escribir_texto(15, 24, "Invalido", 2);
  }
  //delay(1000);
  //display.fill(0x00);
  menu = true;
}
void menu_principal() {

  mantener = true;
  display.fill(0x00);
  display.drawBitmap1(0, 0, 128, 64, dibujo_menu);///coordenada x, y, ancho en pixeles, alto en pixeles, mapa del dibujo
  menu = false;
  /*display.fill( 0x00 );
  escribir_texto(40, 16, "Menu", 2);
  escribir_texto(10, 32, "Principal", 2);
  delay(1000);
  // Limpiamos la pantalla, cambiamos el tamaño del texto y resituamos el cursor para escribir el nuevo mensaje. Luego lo mandamos
  display.fill( 0x00 );
  escribir_texto(0, 0, "Pulse A, B y C para  cambiar las horas de riego 1, 2 y 3 respectivamente", 1);
  menu = false;*/
}

void recuperar_fecha(){
  hoy = rtc.now();///Recuperamos la fecha actual
  ano = hoy.year() % 100; // Eliminamos el siglo y queda el año con dos dígitos
  mes = hoy.month();
  dia = hoy.day();
  hora = hoy.hour();
  minuto = hoy.minute();
  segundo = hoy.second();

  fecha[7] = segundo % 10 + 48;
  fecha[6] = segundo / 10 + 48;
  fecha[4] = minuto % 10 + 48;
  fecha[3] = minuto / 10 + 48;
  fecha[1] = hora % 10 + 48;
  fecha[0] = hora / 10 + 48;

  calendario[9] = ano % 10 + 48;
  calendario[8] = ano / 10 + 48;
  calendario[4] = mes % 10 + 48;
  calendario[3] = mes / 10 + 48;
  calendario[1] = dia % 10 + 48;
  calendario[0] = dia / 10 + 48;

}

void ver_fecha() {
  unsigned long tiempo_fecha = tiempo;
  display.fill(0x00);
  mantener = false;
  while(millis() - tiempo_fecha <= 2000){ 
    escribir_texto(15, 14, fecha, 2);
    escribir_texto(4, 35, calendario, 2);
  }
  menu = true;
  
}

void hora_de_regar() {
  //A pesar de que cuando introducimos manualmente la hora de riego se piden la hora, los minutos y los segundos, en esta parte del código nos fijaremos solo en la hora y los minutos
  ///De esta manera si por casualidad estamos tocando el keypad justo a la hora de riego y nos encontramos con un delay, no perderemos el riego, si no que regaremos una vez pase el delay
  ///Y levantaremos una bandera para que solo se riegue una sola vez.

  //int horabandera1 = horariego1_00[1] + 1;

  
  if (horariego1_00[0]==hora && horariego1_00[1]==minuto && banderariego == false) {
    
    /////ENCENDEMOS LA BOMBA DURANTE 10 segundos////////
    if(banderatiempo==false){
      tiempobomba = tiempo;
      estadoriegoint = 1;
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      banderatiempo = true;
      
    }
    if(tiempo-tiempobomba>=10000 && banderatiempo==1){
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      banderariego = true;
      estadoriegoint = 0;
    }
  }

  if((horariego1_00[1] + 1)==minuto && (horariego2_00[1] + 1)==minuto && (horariego3_00[1] + 1)==minuto){
    banderariego = false;
    banderatiempo = false;
  }


    
  if (horariego2_00[0]==hora && horariego2_00[1]==minuto && banderariego == false) {
    
    /////ENCENDEMOS LA BOMBA DURANTE 10 segundos////////
    if(banderatiempo==false){
      tiempobomba = tiempo;
      estadoriegoint = 1;
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      banderatiempo = true;
    }
    if(tiempo-tiempobomba>=10000 && banderatiempo==1){
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      banderariego = true;
      estadoriegoint = 0;
    }
  }
  
  
  if (horariego3_00[0]==hora && horariego3_00[1]==minuto && banderariego == false) {
    
    /////ENCENDEMOS LA BOMBA DURANTE 10 segundos////////
    if(banderatiempo==false){
      tiempobomba = tiempo;
      estadoriegoint = 1;
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      banderatiempo = true;
    }
    if(tiempo-tiempobomba>=10000 && banderatiempo==1){
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      banderariego = true;
      estadoriegoint = 0;
    }
  }
}

void opcion_sensado() {
  
  conversion_datos();
  unsigned int tiempo_sensado= tiempo;
  
  strcpy(dht_temp, "Temperatura = ");//Añadimos la frase Temperatura = a nuestra cadena

  strcat(dht_temp, tmp);///Concatenamos "Temperatura =" con el valor de la temperatura
  
  strcpy(dht_hum, "Humedad = ");
  
  strcat(dht_hum, hmd);
  
  strcat(dht_hum, "%");
  //strcat(dht_hum, "% ");
  display.fill(0x00);
  while(millis() - tiempo_sensado <= 2000){
  escribir_texto(1, 0, dht_temp, 1);
  escribir_texto(1, 9, dht_hum, 1);
  }
  //delay(2000);
  menu = true;
}

void escribir_texto(byte x_pos, byte y_pos, char *text, byte text_size) {
  display.setFixedFont(ssd1306xled_font6x8);///Seleccionamos una fuente
  if (text_size == 1) {
    display.printFixed (x_pos,  y_pos, text, STYLE_NORMAL);
  }
  else if (text_size == 2) {
    display.printFixedN (x_pos, y_pos, text, STYLE_NORMAL, FONT_SIZE_2X);
  }
}

void conversion_datos(){
  
  dht_temp[0] = '\0';//Iniciamos las variables como una cadena vacía
  tmp[5] = '\0';
  dht_temp[0] = '\0';
  hmd[0] = '\0';
  //hgrmtro[0]= '\0':
  
  dtostrf((double(dht.celsius) / 10), 3, 2, tmp);///Función que sirve para convertir un float en un string. El 6 indica el número de enteros y el 2 el número de decimales

  dtostrf((double(dht.humidity) / 10), 5, 2, hmd);

  luz = map(analogRead(A2), 0, 1023, 0, 100);

  humedad_tierra = map(analogRead(higrometro), 0, 1023, 0, 100);

  

}

void mostrar_horas_riego(){

  
  hora_aux1[0] = 0;//Iniciamos en 0
  char aux1[3];//Esta cadena la usaremos para ir guardando los números enteros correspondientes a las horas, minutos y segundos de la primera hora de riego convertidos en caracteres
  aux1[0] = 0;///Iniciamos en 0
  hora_aux2[0] = 0;//Iniciamos en 0
  char aux2[3];//Esta cadena la usaremos para ir guardando los números enteros correspondientes a las horas, minutos y segundos convertidos en caracteres
  aux2[0] = 0;///Iniciamos en 0
  hora_aux3[0] = 0;//Iniciamos en 0
  char aux3[3];//Esta cadena la usaremos para ir guardando los números enteros correspondientes a las horas, minutos y segundos convertidos en caracteres
  aux3[0] = 0;///Iniciamos en 0
  
  for (int j = 0; j < 2; j++) {
    if (horariego1_00[j] < 10) {
      strcat(hora_aux1, "0");////En caso de que el número sea menor de 10, añadimos un 0 para que quede en formato: "09"
    }
    sprintf(aux1, "%i", horariego1_00[j]);////Función para convertir el entero horario[j] en una cadena de caracteres que se guarda en HORA_F. %i indica que el número a convertir es un entero
    strcat(hora_aux1, aux1);//Unimos las horas, minutos y segundos..
    if ( j < 1) {
      strcat(hora_aux1, ":");///..separando cada dos digitos por : para que el formato quede así 00:00:00 
    }
  }

  for (int j = 0; j < 2; j++) {
    if (horariego2_00[j] < 10) {
      strcat(hora_aux2, "0");////En caso de que el número sea menor de 10, añadimos un 0 para que quede en formato: "09"
    }
    sprintf(aux2, "%i", horariego2_00[j]);////Función para convertir el entero horario[j] en una cadena de caracteres que se guarda en HORA_F. %i indica que el número a convertir es un entero
    strcat(hora_aux2, aux2);//Unimos las horas, minutos y segundos..
    if ( j < 1) {
      strcat(hora_aux2, ":");///..separando cada dos digitos por : para que el formato quede así 00:00:00 
    }
  }

  for (int j = 0; j < 2; j++) {
    if (horariego3_00[j] < 10) {
      strcat(hora_aux3, "0");////En caso de que el número sea menor de 10, añadimos un 0 para que quede en formato: "09"
    }
    sprintf(aux3, "%i", horariego3_00[j]);////Función para convertir el entero horario[j] en una cadena de caracteres que se guarda en HORA_F. %i indica que el número a convertir es un entero
    strcat(hora_aux3, aux3);//Unimos las horas, minutos y segundos..
    if ( j < 1) {
      strcat(hora_aux3, ":");///..separando cada dos digitos por : para que el formato quede así 00:00:00 
    }
  }

   
}