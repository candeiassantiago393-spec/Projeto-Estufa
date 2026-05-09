# Simulação Wokwi — Estufa Automática V1.3

## Descrição da simulação

Esta simulação foi criada no Wokwi para testar a lógica de funcionamento da versão 1.3 do projeto da estufa automática.

Nesta versão, o sistema lê a humidade do solo, a temperatura e a humidade do ar, apresentando os valores num display OLED. Além disso, foi adicionada uma saída para representar o controlo automático de uma bomba de água.

Como o Wokwi não simula diretamente uma bomba de água real com circulação de água, foi usado um LED para representar visualmente o estado da bomba.

---

## Adaptação da bomba de água no Wokwi

Na simulação, a bomba de água é representada por um LED ligado ao pino digital D9 do Arduino.

Quando o LED está aceso, significa que a bomba estaria ligada no circuito real.

Quando o LED está apagado, significa que a bomba estaria desligada.

Esta adaptação permite testar a lógica de controlo da bomba sem ser necessário usar uma bomba real na simulação.

---

## Funcionamento da bomba simulada

A bomba é ativada quando a humidade do solo está abaixo do limite mínimo definido no código.

```cpp
const int valor_limite_inferior = 35;