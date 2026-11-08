// SMART TENNIS ARENA
// Leitura de 16 LDRs pelo 74HC4067

const int SIG = A0;

const int S0 = 2;
const int S1 = 3;
const int S2 = 4;
const int S3 = 5;

void setup() {
  Serial.begin(9600);

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
}

void selecionarCanal(int canal) {
  digitalWrite(S0, bitRead(canal, 0));
  digitalWrite(S1, bitRead(canal, 1));
  digitalWrite(S2, bitRead(canal, 2));
  digitalWrite(S3, bitRead(canal, 3));
}

void loop() {

  for (int i = 0; i < 16; i++) {

    selecionarCanal(i);

    delayMicroseconds(50);

    int valor = analogRead(SIG);

    Serial.print("LDR ");
    Serial.print(i);
    Serial.print(": ");

    Serial.println(valor);
  }

  Serial.println("----------------");

  delay(500);
}

---------------------------------------------------------------
