#define led_verde_A 10      // LED verde da Rua A no pino 10
#define led_vermelho_A 8    // LED vermelho da Rua A no pino 8

#define led_verde_B 13      // LED verde da Rua B no pino 13
#define led_vermelho_B 11   // LED vermelho da Rua B no pino 11

#define botao_ruaA 2        // Botão ou sensor da Rua A no pino 2
#define botao_ruaB 3        // Botão ou sensor da Rua B no pino 3

void setup() {
  // Configura os LEDs como uma saída
  pinMode(led_verde_A, OUTPUT);
  pinMode(led_vermelho_A, OUTPUT);
  pinMode(led_verde_B, OUTPUT);
  pinMode(led_vermelho_B, OUTPUT);

  // Configura os botões como entrada
  pinMode(botao_ruaA, INPUT);
  pinMode(botao_ruaB, INPUT);

}

void loop() {
  // verifica o estado do botão
  bool carroNaRuaA = digitalRead(botao_ruaA); // Leitura do sensor da Rua A
  bool carroNaRuaB = digitalRead(botao_ruaB); // Leitura do sensor da Rua B

  // Verifica se há carro na Rua A 
  if (carroNaRuaA == HIGH) {
    // Liga verde da Rua A e desliga vermelho
    digitalWrite(led_verde_A, HIGH);
    digitalWrite(led_vermelho_A, LOW);

    // Liga vermelho da Rua B e desliga verde
    digitalWrite(led_verde_B, LOW);
    digitalWrite(led_vermelho_B, HIGH);
  }
  // Verifica se há carro na Rua B e NÃO há carro na Rua A
  else if (carroNaRuaB == HIGH) {
    // Liga verde da Rua B e desliga vermelho
    digitalWrite(led_verde_B, HIGH);
    digitalWrite(led_vermelho_B, LOW);

    // Liga vermelho da Rua A e desliga verde
    digitalWrite(led_verde_A, LOW);
    digitalWrite(led_vermelho_A, HIGH);
  }
  // Caso não haja carro em nenhuma das ruas
  else {
    // Liga verde da Rua A e desliga vermelho
    digitalWrite(led_verde_A, HIGH);
    digitalWrite(led_vermelho_A, LOW);

    // Liga vermelho da Rua B e desliga verde
    digitalWrite(led_verde_B, LOW);
    digitalWrite(led_vermelho_B, HIGH);
  }

}
