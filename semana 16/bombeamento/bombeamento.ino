#define led1 8    // LED 1 no pino digital 8
#define led2 9    // LED 2 no pino digital 9
#define led3 10   // LED 3 no pino digital 10 (não está sendo usado neste código)
#define led4 11   // LED 4 no pino digital 11 (não está sendo usado neste código)
#define pin_botaoA 2  // Botão A no pino digital 2
#define pin_botaoB 3  // Botão B no pino digital 3
#define pin_botaoC 4  // Botão C no pino digital 4 (não está sendo usado neste código)

void setup() {
  // Configura os LEDs como saída
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  // Configura os botões como entrada
  pinMode(pin_botaoA, INPUT);
  pinMode(pin_botaoB, INPUT);
  pinMode(pin_botaoC, INPUT);

  // Inicializa a comunicação serial, útil para monitoramento se desejar
  Serial.begin(9600);
}

void loop() {
  // Faz a leitura do estado dos botões
  bool sH = digitalRead(pin_botaoA); // Lê o estado do botão A (sH)
  bool sL = digitalRead(pin_botaoB); // Lê o estado do botão B (sL)

  // Se os dois botões estiverem SOLTOS (sL == 0 e sH == 0)
  if ((sL == 0) && (sH == 0)) {
    digitalWrite(led1, 1); // Liga LED1
    digitalWrite(led2, 1); // Liga LED2
  }

  // Se botão B estiver SOLTO (sL == 0) e botão A PRESSIONADO (sH == 1)
  if ((sL == 0) && (sH == 1)) {
    digitalWrite(led1, 0); // Desliga LED1
    digitalWrite(led2, 1); // Liga LED2
  }

  // Se botão B estiver PRESSIONADO (sL == 1) e botão A SOLTO (sH == 0)
  if ((sL == 1) && (sH == 0)) {
    digitalWrite(led1, 1); // Liga LED1
    digitalWrite(led2, 0); // Desliga LED2
  }

  // Se os dois botões estiverem PRESSIONADOS (sL == 1 e sH == 1)
  if ((sL == 1) && (sH == 1)) {
    digitalWrite(led1, 0); // Desliga LED1
    digitalWrite(led2, 0); // Desliga LED2
  }
}

