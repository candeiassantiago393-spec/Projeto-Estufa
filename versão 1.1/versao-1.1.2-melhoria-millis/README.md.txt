# Projeto Estufa — Versão 1.1.2: Substituição de `delay()` por `millis()`

Esta versão do projeto da estufa apresenta uma melhoria na temporização do programa.  
O funcionamento geral mantém-se igual à versão anterior, mas o código foi alterado para deixar de depender de `delay()` no ciclo principal.

---

## Objetivo desta versão

O objetivo principal desta atualização foi substituir o uso de:

```cpp
delay(300);