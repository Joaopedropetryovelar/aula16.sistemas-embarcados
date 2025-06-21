// Definição dos pinos dos LEDs
#define led1 8
#define led2 9
#define led3 10
#define led4 11
// Definição dos pinos dos botões
#define pin_botaoA 2
#define pin_botaoB 3
#define pin_botaoC 4

void setup() {
  // Configura os pinos dos LEDs como saída
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  // Configura os pinos dos botões como entrada
  pinMode(pin_botaoA, INPUT);
  pinMode(pin_botaoB, INPUT);
  pinMode(pin_botaoC, INPUT);

  Serial.begin(9600);//inicia comunicação com o arduino

}

void loop() {
  // Faz a leitura do estado dos botões
  bool A = digitalRead(pin_botaoA);
  bool B = digitalRead(pin_botaoB);
  bool C = digitalRead(pin_botaoC);

  // Verifica se apenas o botão C está pressionado
  if ((A == 0) && (B == 0) && (C == 1)) {
    digitalWrite(led1, 1); // Acende o LED 1
  } else {
    digitalWrite(led1, 0); // Apaga o LED 1
  }

  // Verifica se apenas o botão B está pressionado
  if ((A == 0) && (B == 1) && (C == 0)) {
    digitalWrite(led1, 1); // Acende o LED 1
  } else {
    digitalWrite(led1, 0); // Apaga o LED 1
  }

  // Verifica se apenas o botão A está pressionado
  if ((A == 1) && (B == 0) && (C == 0)) {
    digitalWrite(led1, 1); // Acende o LED 1
  } else {
    digitalWrite(led1, 0); // Apaga o LED 1
  }

  // Verifica se todos os botões estão pressionados
  if ((A == 1) && (B == 1) && (C == 1)) {
    digitalWrite(led1, 1); // Acende o LED 1
  } else {
    digitalWrite(led1, 0); // Apaga o LED 1
  }

}
