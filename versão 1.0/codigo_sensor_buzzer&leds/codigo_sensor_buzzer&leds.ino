//pinagem
const int led_vermelho = 2;
const int led_amarelo  = 4;
const int led_verde  = 7;
const int buzzer = 6;
const int sensor_solo = A0 ; //pino do sensor analogico
bool solo_humido = false;    // 0/1: false = seco, true = humido AINDA SEM USO

//limites e estado do csolo
const int valor_limite_inferior = 35; // %
const int valor_limite_superior = 75; // %
void setup() {
  Serial.begin(9600);
  //atribuição de entradas
  pinMode(sensor_solo, INPUT);
  //atribuição de saidas
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(buzzer, OUTPUT);


}

void loop() {
  int valor_sensor_humidade_solo = analogRead(sensor_solo);//leitura da humidade do sensor
  int valor_sensor_percentagem = map(valor_sensor_humidade_solo, 0, 1023, 0, 100); //conversão para percentagem
  valor_sensor_percentagem = constrain(valor_sensor_percentagem, 0, 100); // garante que a percentagem fica entre 0% e 100%(otimização)

  if (valor_sensor_percentagem < valor_limite_inferior) { // condição led vermelho , seco
    digitalWrite(led_vermelho, HIGH);
    digitalWrite(led_verde, LOW);
    digitalWrite(led_amarelo, LOW);
    tone(buzzer, 2000);
    Serial.print("Humidade do solo: ");
    Serial.print(valor_sensor_percentagem);
    Serial.println("% - Solo seco, LED vermelho ON");
  } else if (valor_sensor_percentagem <= valor_limite_superior) { // condição ideal (35..75) led verde
    digitalWrite(led_vermelho, LOW);
    digitalWrite(led_verde, HIGH);
    digitalWrite(led_amarelo, LOW);
    noTone(buzzer);
    Serial.print("Humidade do solo: ");
    Serial.print(valor_sensor_percentagem);
    Serial.println("% - Solo Ideal, LED Verde ON");
  } else { //>75, muito molhado condição led amarelo
    digitalWrite(led_vermelho, LOW);
    digitalWrite(led_verde, LOW);
    digitalWrite(led_amarelo, HIGH);
    tone(buzzer, 500);
    Serial.print("Humidade do solo: ");
    Serial.print(valor_sensor_percentagem);
    Serial.println("% - Solo molhado, LED amarelo ON");
  }
}

