// Na presente versão da estufa foi usado um potenciómetro
// com o objetivo de simular um sinal analógico do sensor de humidade do solo.

// Bibliotecas do display OLED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Bibliotecas do sensor de temperatura e humidade do ar
#include <DHT.h>

// Configuração do sensor DHT22
#define PIN_DHT 8
#define TIPO_DHT DHT22

DHT dht(PIN_DHT, TIPO_DHT);

// Configuração do display OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pinagem
const int led_vermelho = 2;
const int led_amarelo  = 4;
const int led_verde    = 7;
const int buzzer       = 6;
const int sensor_solo  = A0; // Pino do sensor analógico
const int bomba = 9;
// Limites de humidade do solo
const int valor_limite_inferior = 35; // %
const int valor_limite_superior = 75; // %

// Temporização com millis()
unsigned long tempoAnteriorAtualizacao = 0;
const unsigned long intervaloAtualizacao = 1000; // ms

// Função para atualizar o display OLED
void atualizarDisplay(int humidadeSolo, String estado, float temperaturaAr, float humidadeAr, String alerta) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 0);
  display.print("Solo: ");
  display.print(humidadeSolo);
  display.println("%");

  display.setCursor(0, 16);
  display.print("Estado: ");
  display.println(estado);

  display.setCursor(0, 32);
  display.print("Temp: ");
  display.print(temperaturaAr, 1);
  display.println(" C");

  display.setCursor(0, 48);
  display.print("Hum Ar: ");
  display.print(humidadeAr, 0);
  display.print("% ");
  display.print("Al:");
  display.println(alerta);

  display.display();
}
void logicaverdepisca() {
  digitalWrite(led_verde, HIGH);
  delay(300);
  digitalWrite(led_verde, LOW);
  delay(300);
}
void setup() {
  Serial.begin(9600);

  // Inicialização do sensor DHT22
  dht.begin();

  // Inicialização do display OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Falha no OLED");
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Estufa V1.3");
  display.println("OLED OK");
  display.println("DHT22 OK");
  display.display();

  // Configuração de entrada
  pinMode(sensor_solo, INPUT);

  // Configuração de saídas
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(bomba, OUTPUT);

  delay(1200); // Mantém apenas a tela inicial durante o arranque
}

void loop() {
  unsigned long tempoAtual = millis();

  if (tempoAtual - tempoAnteriorAtualizacao >= intervaloAtualizacao) {
    tempoAnteriorAtualizacao = tempoAtual;

    int valor_sensor_humidade_solo = analogRead(sensor_solo);

    int valor_sensor_percentagem = map(valor_sensor_humidade_solo, 0, 1023, 0, 100);
    valor_sensor_percentagem = constrain(valor_sensor_percentagem, 0, 100);

    float temperatura = dht.readTemperature();
    float humidadeAr = dht.readHumidity();

    if (isnan(temperatura) || isnan(humidadeAr)) {
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println("Erro DHT22");
      display.setCursor(0, 16);
      display.println("Verificar sensor");
      display.display();

      Serial.println("Erro ao ler o sensor DHT22");
      return;
    }

    Serial.print("Solo: ");
    Serial.print(valor_sensor_percentagem);
    Serial.print("% | Temp: ");
    Serial.print(temperatura);
    Serial.print(" C | Hum Ar: ");
    Serial.print(humidadeAr);
    Serial.println("%");

    if (valor_sensor_percentagem < valor_limite_inferior) {
      // Solo seco
      digitalWrite(led_vermelho, HIGH);
      digitalWrite(bomba, HIGH);
      digitalWrite(led_amarelo, LOW);
      logicaverdepisca();
      tone(buzzer, 2000);

      atualizarDisplay(
        valor_sensor_percentagem,
        "SECO",
        temperatura,
        humidadeAr,
        "ON"
      );

    } else if (valor_sensor_percentagem <= valor_limite_superior) {
      // Solo com humidade ideal
      digitalWrite(led_vermelho, LOW);
      digitalWrite(led_verde, HIGH);
      digitalWrite(led_amarelo, LOW);
      digitalWrite(bomba, LOW);


      noTone(buzzer);

      atualizarDisplay(
        valor_sensor_percentagem,
        "IDEAL",
        temperatura,
        humidadeAr,
        "OFF"
      );

    } else {
      // Solo demasiado molhado
      digitalWrite(led_vermelho, LOW);
      digitalWrite(led_verde, LOW);
      digitalWrite(led_amarelo, HIGH);
      digitalWrite(bomba, LOW);


      tone(buzzer, 500);

      atualizarDisplay(
        valor_sensor_percentagem,
        "MOLHADO",
        temperatura,
        humidadeAr,
        "ON"
      );
    }
  }
}
