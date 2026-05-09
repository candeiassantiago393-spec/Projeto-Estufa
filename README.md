# Estufa Automática com Arduino

Projeto desenvolvido com Arduino para simular o controlo automático de uma estufa, através da leitura da humidade do solo, temperatura e humidade do ar.

O sistema utiliza um potenciómetro para simular o sensor de humidade do solo, um sensor DHT22 para medir temperatura e humidade do ar, um display OLED para apresentar os dados, LEDs de estado, buzzer de alerta e uma saída digital para simular uma bomba de água.

Na versão mais recente, a bomba de água é representada por um LED no Wokwi. Quando este LED está aceso, significa que a bomba estaria ligada num circuito real.

---

## Funcionamento do sistema

O sistema analisa a humidade do solo e classifica o estado da estufa em três situações principais:

- **Solo seco:** a humidade está abaixo do limite mínimo definido. O LED vermelho liga, o buzzer emite alerta e a bomba simulada é ativada.
- **Solo ideal:** a humidade está dentro da zona adequada. O LED verde liga e a bomba permanece desligada.
- **Solo demasiado molhado:** a humidade ultrapassa o limite máximo definido. O LED amarelo liga, o buzzer emite alerta e a bomba permanece desligada.

A leitura da humidade do solo é feita através de um sinal analógico lido no pino A0. Na simulação, este sinal é gerado por um potenciómetro.

---

## Versões do projeto

### Versão 1.0

Primeira versão do projeto, com leitura da humidade do solo simulada em thinkercad com sensor de humidade de solo e indicação visual através de LEDs.

### Versão 1.1

Melhoria da lógica de funcionamento e organização do código.

### Versão 1.2

Adição do sensor DHT22 para leitura da temperatura e humidade relativa do ar.  
Adição do display OLED SSD1306 para apresentação dos valores medidos.
(Nesta versão foi onde se simulou com potenciometro devido ao simulador wowki que tem o display oled mas não o sensor de solo).

### Versão 1.3

Adição da simulação de uma bomba de água.

Como o Wokwi também não simula diretamente uma bomba de água real, foi usado um LED para representar a bomba. Quando o solo está seco, o Arduino ativa o pino da bomba, fazendo acender o LED. Futuramente, no circuito real, esse mesmo pino poderá controlar um relé, transistor ou MOSFET para acionar uma bomba de água verdadeira.

---

## Tecnologias utilizadas

### Software

- Arduino IDE
- Thinkercad
- Wokwi
- Linguagem C++

### Bibliotecas

- Wire.h
- Adafruit_GFX.h
- Adafruit_SSD1306.h
- DHT.h

---

## Componentes utilizados

- Arduino UNO
- Potenciómetro
- Sensor DHT22
- Display OLED SSD1306 I2C
- LED vermelho
- LED verde
- LED amarelo
- LED representativo da bomba de água
- Buzzer
- Resistências
- Cabos de ligação

---

## Pinagem principal

| Componente | Pino Arduino |
|---|---|
| LED vermelho | D2 |
| LED amarelo | D4 |
| LED verde | D7 |
| Buzzer | D6 |
| Sensor DHT22 | D8 |
| Bomba simulada por LED | D9 |
| Potenciómetro / sensor de solo | A0 |
| OLED SDA | A4 |
| OLED SCL | A5 |

---

## Limites de humidade definidos

```cpp
const int valor_limite_inferior = 35;
const int valor_limite_superior = 75;
