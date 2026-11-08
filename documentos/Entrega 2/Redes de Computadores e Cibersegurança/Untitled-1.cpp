
// SMART TENNIS ARENA
// Controle de 64 LEDs com 8 CIs 74HC595

// Pinos de comunicação com o Arduino Uno
const int DATA_PIN = 8;
const int CLOCK_PIN = 9;
const int LATCH_PIN = 10;

// Quantidade de registradores
const int TOTAL_CI = 8;

// Estado dos 64 LEDs
byte leds[8] = {0, 0, 0, 0, 0, 0, 0, 0};

void setup() {
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);

  apagarTodos();
}

void loop() {
}

// Apaga todos os LEDs
void apagarTodos() {
  for (int i = 0; i < TOTAL_CI; i++) {
    leds[i] = 0;
  }

  atualizarLEDs();
}

// Envia os dados para os 8 registradores
void atualizarLEDs() {
  digitalWrite(LATCH_PIN, LOW);

  for (int i = TOTAL_CI - 1; i >= 0; i--) {
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, leds[i]);
  }

  digitalWrite(LATCH_PIN, HIGH);
}



------------------------------------------------------------------------------------