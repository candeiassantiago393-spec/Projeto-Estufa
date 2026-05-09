# Projeto Estufa Automática com Arduino

Este projeto consiste no desenvolvimento de uma estufa automática controlada por Arduino, com leitura da humidade do solo, temperatura e humidade do ar.

O sistema permite monitorizar as condições da estufa e atuar automaticamente quando o solo se encontra seco, através da ativação de uma bomba de água simulada. A simulação foi realizada no Wokwi, utilizando um potenciómetro para representar o sensor de humidade do solo e um LED para representar a bomba de água.

---

## Objetivo do projeto

O objetivo principal deste projeto é simular o funcionamento de uma estufa automática capaz de:

- medir a humidade do solo;
- medir a temperatura do ar;
- medir a humidade relativa do ar;
- indicar o estado do solo através de LEDs;
- emitir alertas sonoros com buzzer;
- apresentar os dados num display OLED;
- ativar uma bomba de água quando o solo está seco.

Este projeto permite aplicar conceitos de eletrónica, programação em Arduino, sensores, atuadores e automação.

---

## Funcionamento geral

O sistema analisa a humidade do solo e classifica o estado da estufa em três situações:

| Humidade do solo | Estado | Ação do sistema |
|---|---|---|
| Inferior a 35% | Solo seco | Liga LED vermelho, buzzer e bomba simulada |
| Entre 35% e 75% | Solo ideal | Liga LED verde e mantém a bomba desligada |
| Superior a 75% | Solo molhado | Liga LED amarelo, buzzer e mantém a bomba desligada |

A humidade do solo é simulada através de um potenciómetro ligado ao pino analógico A0. O valor analógico lido pelo Arduino varia entre 0 e 1023 e é convertido para uma percentagem entre 0% e 100%.

---

## Versões do projeto

### Versão 1.0

Primeira versão do projeto, desenvolvida inicialmente no Tinkercad.

Nesta fase, o sistema fazia a leitura da humidade do solo e indicava o estado através de LEDs.

### Versão 1.1

Versão intermédia com melhorias na organização do código e na lógica de funcionamento.

### Versão 1.2

Adição do sensor DHT22 para leitura da temperatura e da humidade relativa do ar.

Também foi adicionado um display OLED SSD1306 para apresentar os valores medidos.

Nesta versão, a humidade do solo passou a ser simulada por um potenciómetro, uma vez que o Wokwi permite simular o display OLED, mas não disponibiliza diretamente o sensor de humidade do solo usado no circuito físico.

### Versão 1.3

Adição da simulação de uma bomba de água.

Como o Wokwi não simula diretamente uma bomba de água real, foi usado um LED para representar o funcionamento da bomba.

Quando o LED da bomba está aceso, significa que a bomba estaria ligada no circuito real.  
Quando o LED está apagado, significa que a bomba estaria desligada.

Futuramente, no circuito físico, o mesmo pino usado para controlar o LED poderá controlar um relé, transistor ou MOSFET responsável por acionar uma bomba de água real.

---

## Tecnologias utilizadas

### Software

- Arduino IDE
- Wokwi
- Tinkercad
- GitHub
- Linguagem C/C++

### Bibliotecas Arduino

- `Wire.h`
- `Adafruit_GFX.h`
- `Adafruit_SSD1306.h`
- `DHT.h`

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
| Potenciómetro / sensor de humidade do solo | A0 |
| OLED SDA | A4 |
| OLED SCL | A5 |

---

## Limites definidos no código

```cpp
const int valor_limite_inferior = 35;
const int valor_limite_superior = 75;
