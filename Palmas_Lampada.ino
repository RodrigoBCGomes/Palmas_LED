int rele = 7;
#define micro 3

//Var do microfone
bool valor = false;

//Estágios da palma
bool estagio1 = false;
bool estagio2 = false;
bool estagio3 = false;

//Limite da onda por tempo
int a;
int b;

void setup() {
  pinMode(rele,OUTPUT);
  pinMode(micro,INPUT);
}

void loop() {
//Pega o valor do microfone
  valor = digitalRead(micro);

  if(valor == true && estagio1 == false){
    estagio1 = true;
    a = 0;
  }
  if(valor == false && estagio1 == true && estagio2 == false){
    estagio2 = true;
    a = 0;
  }
//Tempo da segunda palma em 200 milisegundos
  if(estagio1 == true && estagio2 == false){
    delay(1);
    a++;
    if(a>200){
      estagio1 = false;
    }
  }
//Tempo da onda passar de 700 milisegundos
  if(estagio2 == true){
    if(estagio3 == false){
      delay(1);
      a++;
      if(a>700){
        estagio1 = false;
        estagio2 = false;
      }
    }
    if(a>70){
      if(valor == true && estagio2 == true && estagio3 == false){
        estagio3 = true;
        b = 0;
      }
      if(valor == false && estagio3 == true){
        digitalWrite(rele,!digitalRead(rele));
        estagio1 = false;
        estagio2 = false;
        estagio3 = false;
        delay(1000);
      }
      if(estagio3 == true){
        delay(1);
        b++;
        if(b>200){
          estagio1 = false;
          estagio2 = false;
          estagio3 = false;
        }
      }
    }
  }
//Delay de 44KHz do áudio
  delayMicroseconds(1/44100*1000000);
}
