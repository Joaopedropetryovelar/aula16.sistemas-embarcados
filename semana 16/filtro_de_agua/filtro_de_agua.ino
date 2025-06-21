#define led1 8    // LED 1 conectado no pino digital 8
#define led2 9    // LED 2 conectado no pino digital 9
#define led3 10   // LED 3 conectado no pino digital 10
#define led4 11   // LED 4 conectado no pino digital 11
#define pin_botaoA 2  // Botão A conectado no pino digital 2
#define pin_botaoB 3  // Botão B conectado no pino digital 3
#define pin_botaoC 4  // Botão C conectado no pino digital 4

void setup() {
  pinMode(led1, OUTPUT);//define os leds como uma saída(OUTPUT)
  pinMode(led2, OUTPUT);//define os leds como uma saída(OUTPUT)
  pinMode(led3, OUTPUT);//define os leds como uma saída(OUTPUT)
  pinMode(led4, OUTPUT);//define os leds como uma saída(OUTPUT)
  pinMode(pin_botaoA, INPUT);// Define os pinos dos botões como entrada (INPUT)
  pinMode(pin_botaoB, INPUT);// Define os pinos dos botões como entrada (INPUT)
  pinMode(pin_botaoC, INPUT);// Define os pinos dos botões como entrada (INPUT)

  Serial.begin(9600);//serve para se comunicar com o arduino

}

void loop() {
   // Lê o estado dos botões A e B
  bool A = digitalRead(pin_botaoA); // Lê se o botão A está pressionado (1) ou não (0)
  bool B = digitalRead(pin_botaoB); // Lê se o botão B está pressionado (1) ou não (0)
   
   // Se os dois botões estiverem soltos (A==0 e B==0)
  if ((A == 0) && (B == 0)) {
    digitalWrite(led1, 1); // Liga o LED 1
  } else {
    digitalWrite(led1, 0); // Caso contrário, desliga o LED 1
  }

  // Se A solto e B pressionado
  if ((A == 0) && (B == 1)) {
    digitalWrite(led1, 0); // Garante que o LED 1 está desligado
  }

  // Se A pressionado e B solto
  if ((A == 1) && (B == 0)) {
    digitalWrite(led1, 0); // Garante que o LED 1 está desligado
  }

  // Se A pressionado e B pressionado
  if ((A == 1) && (B == 1)) {
    digitalWrite(led1, 0); // Garante que o LED 1 está desligado
  }

}
