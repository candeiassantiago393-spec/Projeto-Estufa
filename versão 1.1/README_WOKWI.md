# Simulacao no Wokwi (OLED + potenciometro)

Este ficheiro documenta a simulacao da estufa no **Wokwi**, focada em mostrar no **OLED SSD1306** a informacao que antes era apresentada no **Serial Monitor**.

## Porque foi necessario simular o sensor de solo

Durante o desenvolvimento foram usados dois simuladores:

- **Tinkercad**: tinha **sensor de humidade do solo**, mas **nao tinha OLED SSD1306**.
- **Wokwi**: tinha **OLED SSD1306**, mas **nao tinha um sensor de solo equivalente** (para esta montagem).

Para conseguir testar a interface no OLED no Wokwi, foi usado um **potenciometro** para simular o sinal analogico do `sensor_solo`.

## Como o potenciometro simula o sensor

O sensor de solo (real) fornece um valor analogico lido com `analogRead(A0)` (intervalo `0..1023`).
No Wokwi, o **potenciometro** faz o mesmo papel:

- Ao rodar o potenciometro, muda a tensao no pino central.
- O Arduino le essa tensao em `A0` como um valor analogico `0..1023`.
- O codigo converte esse valor para percentagem (`0..100%`) com `map()` e limita o intervalo com `constrain()`.

## Ligacoes recomendadas (Wokwi)

### OLED SSD1306 (I2C)

- `GND` -> `GND`
- `VCC` -> `5V`
- `SDA` -> `A4`
- `SCL` -> `A5`
- Endereco I2C tipico: `0x3C`

### Potenciometro (simular `sensor_solo`)

- uma ponta -> `5V`
- outra ponta -> `GND`
- pino do meio (wiper) -> `A0`

## O que aparece no OLED nesta versao

O OLED apresenta as mesmas informacoes que eram impressas na consola:

- **Humidade do solo (%)** (derivada do potenciometro)
- **Estado**: `SECO`, `IDEAL` ou `MOLHADO`
- **LED ativo** (vermelho/verde/amarelo)
- **Alerta**: `ON`/`OFF`

## Logica de estados (limites)

- `< 35%` -> **SECO** (LED vermelho + buzzer 2000 Hz)
- `35%..75%` -> **IDEAL** (LED verde + buzzer OFF)
- `> 75%` -> **MOLHADO** (LED amarelo + buzzer 500 Hz)

## Nota

Se a percentagem ficar invertida (por exemplo, rodar para a direita diminuir a percentagem), basta inverter o `map()` (trocar `0` e `1023`).

