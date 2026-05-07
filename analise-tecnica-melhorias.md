## Análise Técnica do Código

| Nº | Tipo | Problema encontrado | Explicação | Gravidade | Sugestão de resolução |
|---|---|---|---|---|---|
| 1 | Incongruência de versão | No ecrã aparece `Estufa V1.1`, mas o código está a ser tratado como versão 1.2 | A identificação apresentada no display OLED não corresponde à versão atual do projeto. | Baixa | Alterar a mensagem inicial para `Estufa V1.2`. |
| 2 | Omissão funcional | O código apenas monitoriza a humidade do solo | O sistema lê o sensor e mostra o estado, mas ainda não controla nenhum atuador real de rega. | Média/Alta | Adicionar uma saída para bomba de água, relé ou electroválvula. |
| 3 | Omissão funcional | Não existe controlo de temperatura | Uma estufa automatizada deve poder monitorizar temperatura ambiente. | Média | Adicionar um sensor de temperatura, como DHT11, DHT22 ou outro equivalente. |
| 4 | Omissão funcional | Não existe controlo de luminosidade | A luminosidade é uma variável importante numa estufa, especialmente para crescimento das plantas. | Média | Adicionar um sensor LDR ou BH1750 numa versão futura. |
| 5 | Incongruência funcional | O estado `SECO` ativa o buzzer continuamente | O buzzer fica sempre ligado enquanto o solo estiver seco, o que pode ser incomodativo. | Média | Tornar o aviso sonoro intermitente com `millis()`. |
| 6 | Incongruência funcional | O estado `MOLHADO` também ativa o buzzer continuamente | O solo demasiado molhado é uma situação de alerta, mas o buzzer contínuo pode não ser a melhor solução. | Média | Usar um som diferente, aviso intermitente ou apenas indicação visual no OLED e LED amarelo. |
| 7 | Conflito potencial | Uso de `delay(300)` no final do `loop()` | O `delay()` bloqueia o programa. Neste código simples ainda não é grave, mas pode causar problemas em versões com mais sensores, botões ou atuadores. | Média | Substituir por temporização com `millis()`. |
| 8 | Omissão técnica | Não existe calibração real do sensor de humidade | O código usa `map(valor, 0, 1023, 0, 100)`, mas sensores reais não costumam corresponder exatamente a esses limites. | Alta | Criar valores calibrados para solo seco e solo molhado. |
| 9 | Possível erro funcional | A percentagem pode estar invertida no sensor real | Em alguns sensores, solo seco gera valor analógico alto e solo molhado gera valor baixo. O código atual pode interpretar isso ao contrário. | Alta | Testar no sensor real e inverter o `map()` caso necessário. |
| 10 | Omissão de estabilidade | Não há média das leituras analógicas | A leitura do sensor pode oscilar, causando mudanças rápidas entre estados. | Média | Fazer média de várias leituras antes de calcular a percentagem. |
| 11 | Omissão de controlo | Não existe histerese | Perto dos limites de 35% e 75%, o sistema pode alternar repetidamente entre estados. | Média/Alta | Criar margens de segurança, por exemplo: entrar em seco abaixo de 35% e sair de seco apenas acima de 40%. |
| 12 | Organização do código | Os nomes das constantes de pinagem não seguem uma convenção técnica clara | Os nomes atuais funcionam, mas em projetos técnicos é mais comum usar maiúsculas para constantes. | Baixa | Usar nomes como `PIN_LED_VERMELHO`, `PIN_BUZZER` e `PIN_SENSOR_SOLO`. |
| 13 | Memória | Uso de `String` na função `atualizarDisplay()` | Em Arduino UNO, o uso repetido de `String` pode fragmentar a memória RAM em projetos maiores. | Média | Substituir `String` por `const char*`. |
| 14 | Omissão de depuração | O `Serial.begin(9600)` é iniciado, mas não há `Serial.print()` | O Serial Monitor poderia ajudar a verificar o valor bruto do sensor e a percentagem calculada. | Baixa/Média | Adicionar impressão do valor analógico e da percentagem no Serial Monitor. |
| 15 | Incongruência visual | O OLED é atualizado a cada 300 ms mesmo que o estado não mude | Isto pode causar atualizações desnecessárias e possível cintilação no display. | Baixa/Média | Atualizar o OLED apenas quando o estado mudar ou quando houver variação significativa da humidade. |
| 16 | Omissão de arranque | Os LEDs e o buzzer não são desligados explicitamente no `setup()` | Normalmente iniciam desligados, mas é mais seguro definir o estado inicial manualmente. | Baixa | Adicionar `digitalWrite(..., LOW)` e `noTone(buzzer)` no `setup()`. |
| 17 | Omissão de segurança | Não existe deteção de erro no sensor | Se o sensor estiver desligado ou avariado, o sistema pode interpretar leituras erradas como estado real do solo. | Média | Criar uma condição de erro para leituras anómalas ou valores extremos persistentes. |
| 18 | Organização funcional | A lógica dos LEDs continua repetida nos três estados | Apesar de o display já estar numa função, os LEDs ainda são controlados com vários `digitalWrite()` repetidos. | Baixa/Média | Criar uma função `controlarLeds()`. |
| 19 | Organização funcional | A lógica do buzzer está diretamente dentro dos blocos `if` | Se for necessário alterar o comportamento do buzzer, será preciso mexer em vários pontos do código. | Baixa/Média | Criar uma função `controlarBuzzer()` ou uma lógica de alarme separada. |
| 20 | Funcionalidade limitada | Existem apenas três estados: `SECO`, `IDEAL` e `MOLHADO` | Para uma versão inicial é suficiente, mas uma estufa mais completa pode precisar de outros estados. | Média | Adicionar estados como `ERRO_SENSOR`, `REGA_ATIVA` ou `ALERTA_EXCESSO_AGUA`. |
| 21 | Apresentação técnica | O comentário inicial podia ser mais claro sobre a simulação | O código usa um potenciómetro para simular o sensor, mas isso deve ficar bem explícito na documentação. | Baixa | Indicar claramente que o potenciómetro substitui o sensor real apenas em ambiente de simulação. |

## Prioridade das Melhorias

| Prioridade | Melhoria recomendada | Justificação |
|---|---|---|
| 1 | Substituir `String` por `const char*` | Torna o código mais leve e adequado para Arduino UNO. |
| 2 | Criar uma função para controlar os LEDs | Reduz repetição e melhora a organização do código. |
| 3 | Adicionar mensagens no Serial Monitor | Facilita testes e depuração dos valores do sensor. |
| 4 | Calibrar o sensor de humidade do solo | É essencial para obter leituras fiáveis no circuito real. |
| 5 | Fazer média das leituras analógicas | Reduz oscilações e melhora a estabilidade do sistema. |
| 6 | Implementar histerese | Evita alternância constante entre estados perto dos limites. |
| 7 | Substituir `delay()` por `millis()` | Prepara o código para funcionalidades mais avançadas sem bloqueios. |
| 8 | Adicionar controlo de bomba ou relé | Transforma o projeto de monitorização numa estufa automatizada. |
| 9 | Adicionar sensor de temperatura | Torna o projeto mais completo e realista. |
| 10 | Adicionar sensor de luminosidade | Permite controlar ou monitorizar a luz disponível para as plantas. |
