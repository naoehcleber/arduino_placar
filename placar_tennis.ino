#include "LedControl.h"

const int DIN = 4;
const int CS = 5;
const int CLK = 6;

const int BotaoEsquerda = 10;
const int BotaoDireita = 11;
const int BotaoReset = 12;
int buttonstateRESET;
int buttonstateESQUERDA;
int buttonstateDIREITA

LedControl lc=LedControl(DIN, CLK, CS,4);

int placarDireito = 0;
int placarEsquerdo = 0;

void setup(){
  Serial.begin(9600);

  pinMode(BotaoEsquerda, INPUT_PULLUP);
  //inicializa o display
  lc.shutdown(0, false);
  lc.shutdown(1, false);
  lc.shutdown(2, false);
  lc.shutdown(3, false);
  //Ajusta o brilho de cada display
  lc.setIntensity(0, 8);
  lc.setIntensity(1, 8);
  lc.setIntensity(2, 8);
  lc.setIntensity(3, 8);
  //Apaga os displays
  lc.clearDisplay(0);
  lc.clearDisplay(1);
  lc.clearDisplay(2);
  lc.clearDisplay(3);
}

void zerarPlacar(int lado){
  byte sprite_zero[8] = {B00000000,B01100110,B10011001,B10011001,B10011001,B10011001,B01100110,B00000000};
  
  for(int i = 0; i<8; i++){
    //lc.setRow(lado, row, posicao no vetor)
    lc.setRow(lado, i, sprite_zero[i]);
  }
}

void imprimirQuinze(int lado){
  byte sprite_quinze[8] = {B00000000,B01000111,B11000100,B01000100,B01000111,B01000001,B11100111,B00000000};
  
  for(int i = 0; i<8; i++){
    //lc.setRow(lado, row, posicao no vetor)
    lc.setRow(lado, i, sprite_quinze[i]);
  }
}

void imprimitTrinta(int lado){
  byte sprite_trinta[8] = {B00000000,B11100110,B00101001,B00101001,B11101001,B00101001,B11100110,B00000000};

  for(int i = 0; i<8; i++){
    //lc.setRow(lado, row, posicao no vetor)
    lc.setRow(lado, i, sprite_trinta[i]);
  }
}

void imprimirQuarenta(int lado){
  byte sprite_quarenta[8] = {B00000000,B10100110,B10101001,B10101001,B11101001,B00101001,B00100110,B00000000};
  lc.clearDisplay(lado);

  for(int i = 0; i<8; i++){
    //lc.setRow(lado, row, posicao no vetor)
    lc.setRow(lado, i, sprite_quarenta[i]);
  }
}

void imprimirGame(){
  lc.clearDisplay(0);
  lc.clearDisplay(1);
  lc.clearDisplay(2);
  lc.clearDisplay(3);

  byte sprite_G[8] = {B00000000,B00111110,B01000000,B01000000,B01001110,B01000010,B00111110,B00000000};
  byte sprite_A[8] = {B00000000,B00011000,B00100100,B01000010,B01000010,B01111110,B01000010,B00000000};
  byte sprite_M[8] = {B00000000,B01100110,B01011010,B01011010,B01000010,B01000010,B01000010,B00000000};
  byte sprite_E[8] = {B00000000,B01111110,B01000000,B01111000,B01000000,B01000000,B01111110,B00000000};

  for(int i = 0; i<8; i++){
    //lc.setRow(lado, row, posicao no vetor)
    lc.setRow(3, i, sprite_G[i]);
  }
  for(int i = 0; i<8; i++){
    //lc.setRow(lado, row, posicao no vetor)
    lc.setRow(2, i, sprite_A[i]);
  }
  for(int i = 0; i<8; i++){
    //lc.setRow(lado, row, posicao no vetor)
    lc.setRow(1, i, sprite_M[i]);
  }
  for(int i = 0; i<8; i++){
    //lc.setRow(lado, row, posicao no vetor)
    lc.setRow(0, i, sprite_E[i]);
  }
}

void loop(){
  buttonstateESQUERDA = digitalRead(BotaoEsquerda);
  buttonstateDIREITA = digitalRead(BotaoDireita);
  buttonstateRESET = digitalRead(BotaoReset);

  if (buttonstateESQUERDA == HIGH){
    placarEsquerdo += 1;
    Serial.println(placarEsquerdo);
    while(digitalRead(BotaoEsquerda) == HIGH){}
  }

  if (buttonstateDIREITA == HIGH){
    placarEsquerdo += 1;
    Serial.println(placarDireito);
    while(digitalRead(BotaoDireita) == HIGH){}
  }
  
  if (buttonstateRESET == HIGH){
    placarEsquerdo = 0;
    placarDireito = 0;
    Serial.println("Resetado");
    while(digitalRead(BotaoDireita) == HIGH){}
  }


  switch (placarEsquerdo){
    case 0:
      lc.clearDisplay(3);
      zerarPlacar(3);
      break;
    case 1:
      lc.clearDisplay(3);
      imprimirQuinze(3);
      break;
    case 2:
      lc.clearDisplay(3);
      imprimitTrinta(3);
      break;
    case 3:
      lc.clearDisplay(3);
      imprimirQuarenta(3);
      break;
    case 4 :
      placarDireito = 4;
      lc.clearDisplay(3);
      imprimirGame();
      break;
    case 5:
      if(placarEsquerdo == 5){
        placarDireito = 5;
      }
      zerarPlacar(3);
      lc.clearDisplay(2);
      lc.clearDisplay(1);
      //zerarPlacar(0);
      placarEsquerdo = 0;
      placarDireito = 0;
      break;
    }
  
  switch (placarDireito){
    case 0:
      lc.clearDisplay(0);
      zerarPlacar(0);
      break;
    case 1:
      lc.clearDisplay(0);
      imprimirQuinze(0);
      break;
    case 2:
      lc.clearDisplay(0);
      imprimitTrinta(0);
      break;
    case 3:
      lc.clearDisplay(0);
      imprimirQuarenta(0);
      break;
    case 4 :
      lc.clearDisplay(0);
      imprimirGame();
      break;
    case 5:
      if(placarDireito == 5){
        placarEsquerdo = 4;
      }
      zerarPlacar(0);
      lc.clearDisplay(2);
      lc.clearDisplay(1);
      //zerarPlacar(0);
      //placarEsquerdo = 0;
      placarEsquerdo = 0;
      placarDireito = 0;
      break;
    }
} 
