# Projeto Estufa — Versão 1.3 com Simulação de Bomba de Água

## Descrição

Esta versão do projeto representa uma evolução da estufa automática, passando a incluir uma simulação de bomba de água para rega automática.

Como o Wokwi não simula diretamente o funcionamento real de uma bomba de água com circulação de água, foi usado um LED como representação visual da bomba. Quando este LED está aceso, significa que a bomba estaria ligada no circuito real. Quando está apagado, significa que a bomba estaria desligada.

Nesta versão, a humidade do solo continua a ser simulada por um potenciómetro, permitindo variar o valor analógico lido pelo Arduino e testar os diferentes estados do sistema.

---

## Objetivo da versão 1.3

O principal objetivo desta versão é acrescentar uma ação automática ao sistema.

Nas versões anteriores, a estufa apenas indicava o estado da humidade do solo através de LEDs, buzzer e display OLED. Nesta versão, quando o solo se encontra seco, o sistema ativa uma saída digital que representa a bomba de água.

Assim, a estufa passa a simular um funcionamento mais próximo de um sistema real de rega automática.

---

## Componentes utilizados na simulação

- Arduino UNO
- Potenciómetro
- Sensor DHT22
- Display OLED SSD1306 I2C
- LED vermelho
- LED verde
- LED amarelo
- LED representativo da bomba de água
- Buzzer
- Resistências para os LEDs
- Cabos de ligação

---

## Simulação da humidade do solo

Na presente versão foi usado um potenciómetro para simular o sinal analógico de um sensor de humidade do solo.

O potenciómetro está ligado ao pino analógico A0 do Arduino. Ao rodar o potenciómetro, o valor analógico varia entre 0 e 1023. Esse valor é depois convertido para uma percentagem entre 0% e 100%.

```cpp
int valor_sensor_percentagem = map(valor_sensor_humidade_solo, 0, 1023, 0, 100);
valor_sensor_percentagem = constrain(valor_sensor_percentagem, 0, 100);
