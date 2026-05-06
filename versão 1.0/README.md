# Estufa - Versao 1 (Sensor de Solo + LEDs + Buzzer)

Esta versao implementa apenas o modulo de monitorizacao da humidade do solo.
O objetivo e validar a logica de leitura do sensor e os alertas visuais/sonoros.

## Objetivo desta fase

- Ler a humidade do solo no pino analogico.
- Converter a leitura para percentagem (0 a 100).
- Classificar o estado do solo em tres faixas: seco, ideal, molhado.
- Acionar LEDs conforme o estado.
- Acionar buzzer em estados de alerta.
- Mostrar os dados e estado no Serial Monitor.

## Ficheiro principal

- `codigo_sensor_buzzer&leds.ino`

## Pinagem usada

- `sensor_solo` -> `A0`
- `led_vermelho` -> `D2`
- `led_amarelo` -> `D4`
- `led_verde` -> `D7`
- `buzzer` -> `D6`

## Limites desta versao

- Limite inferior: `35%`
- Limite superior: `75%`

Interpretacao:

- `< 35%` -> solo seco
- `35% a 75%` -> solo ideal
- `> 75%` -> solo muito molhado

## Principais funcoes/rotina

### `setup()`

- Inicia comunicacao serial (`9600`).
- Define pinos de entrada/saida.

### `loop()`

1. Le o sensor (`analogRead`).
2. Converte para percentagem (`map`).
3. Garante intervalo valido (`constrain`).
4. Aplica regras por estado:
   - Seco: LED vermelho ON + buzzer 2000 Hz.
   - Ideal: LED verde ON + buzzer OFF.
   - Molhado: LED amarelo ON + buzzer 500 Hz.
5. Escreve no Serial:
   - percentagem atual
   - estado atual
   - LED ativo

## Comportamento esperado no teste

- Quando a percentagem baixar de 35, o LED vermelho acende e buzzer toca agudo.
- Entre 35 e 75, apenas o LED verde fica aceso.
- Acima de 75, o LED amarelo acende e buzzer toca grave.

## Nota tecnica

- O programa imprime mensagens em todos os ciclos do `loop()`.
- Sem controlo por tempo, o Serial pode receber muitas linhas rapidamente.
- Isso e normal nesta versao inicial.

## Proximos passos sugeridos

- Limitar o ritmo de prints no Serial com `millis()`.
- Calibrar o sensor com valores reais de seco/molhado.
- Integrar DHT22 em modulo separado.
- Trocar interface Serial por OLED no hardware real.
