# Primeira Simulação Real — Projeto Estufa Automatizada

## Descrição

Esta pasta contém a primeira versão de simulação real do projeto **Estufa Automatizada com Arduino**.

Nesta fase inicial, o principal objetivo foi testar a lógica base do sistema, nomeadamente a leitura de um sinal analógico e a resposta do Arduino perante diferentes valores simulados de humidade do solo.

Ainda não foi utilizado o sensor de humidade do solo real. Em vez disso, foi usado um **potenciómetro** para simular o comportamento do sensor.

---

## Objetivo da Simulação

O objetivo desta primeira simulação foi verificar se o Arduino consegue:

- Ler corretamente um valor analógico;
- Interpretar esse valor como se fosse a humidade do solo;
- Ativar ou desativar uma saída consoante o nível de humidade simulado;
- Apresentar informação no display;
- Testar a lógica principal do sistema antes da utilização do sensor real.

---

## Utilização do Potenciómetro

Nesta versão, o potenciómetro foi usado para substituir temporariamente o sensor de humidade do solo.

Ao rodar o potenciómetro, o valor analógico lido pelo Arduino varia entre **0 e 1023**, simulando diferentes níveis de humidade:

- Valores mais baixos podem representar solo mais húmido;
- Valores mais altos podem representar solo mais seco.

Esta adaptação permite testar a programação sem depender imediatamente do sensor físico.

---

## Diferença Entre a Simulação Wokwi e a Primeira Simulação Real

Na simulação feita no **Wokwi**, foi utilizado um display para apresentar o estado do sistema, permitindo visualizar de forma mais direta os valores e as condições da estufa.

Na primeira simulação real, o funcionamento foi adaptado aos componentes disponíveis fisicamente. Por esse motivo, podem existir pequenas diferenças entre o circuito montado no Wokwi e o circuito real.

A principal alteração nesta fase foi a substituição temporária do sensor de humidade do solo por um potenciómetro. O potenciómetro permite simular manualmente a variação do sinal analógico que, futuramente, será fornecido pelo sensor de humidade do solo.

Assim, a lógica principal do projeto mantém-se semelhante, mas alguns elementos podem mudar consoante o ambiente de teste:

| Ambiente | Componente usado | Função |
|---|---|---|
| Wokwi | Sensor/potenciómetro simulado | Simular a humidade do solo |
| Primeira simulação real | Potenciómetro físico | Testar a leitura analógica no circuito real |
| Versão futura | Sensor de humidade do solo | Medir a humidade real da terra |

---

## Referência Apresentada no Display

No display pode aparecer uma referência associada à entrada analógica utilizada pelo Arduino, como por exemplo **A1**.

A referência **A1** indica que o sinal analógico está a ser lido através da entrada analógica **A1** do Arduino.

Ou seja, quando o display apresenta algo como **A1 ON** ou **A1 OFF**, está a indicar o estado associado à leitura dessa entrada analógica, conforme os limites definidos no código.

Na prática:

- **A1** corresponde ao pino analógico usado para receber o sinal do potenciómetro;
- O potenciómetro simula o sensor de humidade do solo;
- O estado apresentado no display muda consoante o valor lido pelo Arduino;
- Futuramente, quando for usado o sensor real, a lógica será semelhante, mudando apenas o componente ligado à entrada analógica.

---

## Adaptação Para o Sensor de Humidade do Solo

Nesta versão, o potenciómetro está ligado à entrada analógica do Arduino e simula diferentes valores de humidade.

Na versão futura, o sensor de humidade do solo será ligado no lugar do potenciómetro, enviando também um sinal analógico para o Arduino.

Assim, a lógica principal do código não precisa de mudar completamente. A principal alteração será física, ou seja, substituir o potenciómetro pelo sensor real.

Desta forma, o projeto pode ser testado primeiro de forma simples e controlada, antes de passar para uma aplicação mais próxima do funcionamento real de uma estufa automatizada.

---

## Funcionamento Geral

O Arduino lê o valor analógico proveniente do potenciómetro e compara esse valor com limites definidos no código.

Consoante o valor lido, o sistema pode indicar diferentes estados da estufa, como por exemplo:

- Solo seco;
- Solo com humidade adequada;
- Solo demasiado húmido.

Nesta fase, a saída pode ser representada por um LED, simulando futuramente o acionamento de uma bomba de água através de um módulo relé.

---

## Simulação da Bomba de Água

Nesta primeira simulação real, a bomba de água ainda não foi acionada diretamente.

Foi utilizado um **LED** para simular o funcionamento da bomba. Quando o sistema deteta que o solo está seco, o LED pode ligar, representando a ativação da bomba.

Futuramente, este LED será substituído por um **módulo relé**, que permitirá controlar uma bomba de água real.

Esta alteração não obriga a uma mudança significativa na lógica do código, pois o Arduino continuará apenas a ativar ou desativar uma saída digital.

A diferença principal será no componente ligado a essa saída:

| Versão | Saída usada | Função |
|---|---|---|
| Simulação inicial | LED | Simular a bomba de água |
| Versão final | Relé + bomba | Acionar a rega real |

---

## Componentes Utilizados

- Arduino;
- Potenciómetro;
- Display;
- LED de simulação;
- Resistência para o LED;
- Jumpers;
- Protoboard;
- Cabo USB para alimentação e programação.

---

## Nota Importante

Nesta primeira simulação real, o sensor de humidade do solo ainda não foi utilizado.

Foi usado um potenciómetro para simular o sinal analógico do sensor, permitindo testar a lógica do programa e o comportamento do sistema antes da montagem final.

A referência apresentada no display, como por exemplo **A1**, indica a entrada analógica utilizada no Arduino para receber esse sinal.

Quando o projeto passar da simulação Wokwi para a montagem real com sensor de humidade, a lógica do código mantém-se praticamente igual. A principal diferença será a substituição do potenciómetro pelo sensor real.

---

## Evolução Futura

Numa próxima fase do projeto, o potenciómetro será substituído pelo **sensor de humidade do solo**.

Além disso, o LED usado para simular a bomba poderá ser substituído por um **módulo relé**, permitindo o controlo real de uma bomba de água.

Desta forma, o sistema passará de uma simulação inicial para uma aplicação mais próxima do funcionamento real de uma estufa automatizada.

Possíveis melhorias futuras:

- Utilização do sensor de humidade do solo real;
- Controlo de uma bomba de água através de relé;
- Melhor apresentação dos dados no display;
- Definição de limites de humidade mais ajustados;
- Organização do código por funções;
- Inclusão de mais sensores, como temperatura e luminosidade.

---

## Conclusão

Esta primeira simulação real foi importante para validar a lógica inicial do projeto.

Apesar de ainda não utilizar o sensor de humidade do solo, permitiu testar a leitura analógica, a tomada de decisão do Arduino, a apresentação de informação no display e a ativação de saídas conforme os valores simulados pelo potenciómetro.

Esta etapa serve como base para a evolução do projeto até uma versão mais completa, onde será utilizado o sensor de humidade real e, posteriormente, uma bomba de água controlada por relé.
