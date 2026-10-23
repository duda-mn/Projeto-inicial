#include <Arduino.h>
#include <Bounce2.h>

// EXERCICIO 1

// Bounce Botao = Bounce();

// #define LED 16
// #define pinBot 22

// bool estadoLed=1;

// void setup() {

//   pinMode(LED, OUTPUT);
//   Botao.attach(pinBot, INPUT_PULLUP);
//   Serial.begin(115200);

// }

// void loop(){

// Botao.update();

// if(Botao.fell()){
// estadoLed =! estadoLed;
// }

// digitalWrite(LED, estadoLed);

// }


//EXERCICIO 2

Bounce Botao = Bounce();

#define LED 4
#define pinBot 22

bool estadoLed=0;

bool acionado = LOW;

void setup() {

  pinMode(LED, OUTPUT);
  Botao.attach(pinBot, INPUT_PULLUP);
  Serial.begin(115200);

}

void loop(){
  Botao.update();

  Serial.println(Botao.fell());
  Serial.println(Botao.currentDuration());

  if(Botao.read() ){ //  OU if(!Botao.read()); == 0 && Botao.currentDuration() >= 2000 && !acionado
    if(Botao.currentDuration()==2000&& acionado==false){
      estadoLed=!estadoLed;
      acionado = true;
    }    
    
  }

  if(Botao.read()){
    acionado = false;
  }

    digitalWrite(LED, estadoLed);

}


//EXERCICIO 3

// Bounce Botao = Bounce();

// #define LED 16
// #define pinBot 22

// bool estadoLed=0;

// void setup() {

//   pinMode(LED, OUTPUT);
//   Botao.attach(pinBot, INPUT_PULLUP);
//   Serial.begin(115200);

// }

// void loop(){
//   Botao.update();

//   Serial.println(Botao.fell());
//   Serial.println(Botao.currentDuration());

//   if(Botao.read() == 0 && Botao.currentDuration() >= 2000){
//   estadoLed=!estadoLed;
// }

// digitalWrite(LED, estadoLed);

// delay(500);
// }
