//Na presente verão da estufa foi usado um potenciometro
//com o objetivo de simular um sinal analogico do "sensor_solo"
// Bibliotecas display oled
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Atribuicoes display
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pinagem
const int led_vermelho = 2;
const int led_amarelo  = 4;
const int led_verde    = 7;
const int buzzer       = 6;
const int sensor_solo  = A0; // pino do sensor analogico

bool solo_humido = false; // AINDA SEM USO

// Limites
const int valor_limite_inferior = 35; // %
const int valor_limite_superior = 75; // %

void setup() {
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Falha no OLED");
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Estufa V1.1");
  display.println("OLED OK");
  display.display();

  // Atribuicao de entradas
  pinMode(sensor_solo, INPUT);

  // Atribuicao de saidas
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(buzzer, OUTPUT);

  delay(1200); // so para veres a tela inicial
}

void loop() {
  int valor_sensor_humidade_solo = analogRead(sensor_solo); // leitura do sensor
  int valor_sensor_percentagem = map(valor_sensor_humidade_solo, 0, 1023, 0, 100); // conversao para %
  valor_sensor_percentagem = constrain(valor_sensor_percentagem, 0, 100); // garante 0..100

  if (valor_sensor_percentagem < valor_limite_inferior) { // seco
    digitalWrite(led_vermelho, HIGH);
    digitalWrite(led_verde, LOW);
    digitalWrite(led_amarelo, LOW);
    tone(buzzer, 2000);

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(0, 0);
    display.print("Solo: ");
    display.print(valor_sensor_percentagem);
    display.println("%");

    display.setCursor(0, 16);
    display.println("Estado: SECO");

    display.setCursor(0, 32);
    display.println("LED: VERMELHO");

    display.setCursor(0, 48);
    display.println("Alerta: ON");
    display.display();

  } else if (valor_sensor_percentagem <= valor_limite_superior) { // ideal
    digitalWrite(led_vermelho, LOW);
    digitalWrite(led_verde, HIGH);
    digitalWrite(led_amarelo, LOW);
    noTone(buzzer);

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(0, 0);
    display.print("Solo: ");
    display.print(valor_sensor_percentagem);
    display.println("%");

    display.setCursor(0, 16);
    display.println("Estado: IDEAL");

    display.setCursor(0, 32);
    display.println("LED: VERDE");

    display.setCursor(0, 48);
    display.println("Alerta: OFF");
    display.display();

  } else { // molhado
    digitalWrite(led_vermelho, LOW);
    digitalWrite(led_verde, LOW);
    digitalWrite(led_amarelo, HIGH);
    tone(buzzer, 500);

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(0, 0);
    display.print("Solo: ");
    display.print(valor_sensor_percentagem);
    display.println("%");

    display.setCursor(0, 16);
    display.println("Estado: MOLHADO");

    display.setCursor(0, 32);
    display.println("LED: AMARELO");

    display.setCursor(0, 48);
    display.println("Alerta: ON");
    display.display();
  }

  delay(300); // reduz atualizacao excessiva do ecra
}