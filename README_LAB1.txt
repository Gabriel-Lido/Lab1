GABRIEL LIDO AMARAL

LAB 1

Modificação na frequencia de clock de 24MHz para 120MHz:
- É possível notar que o LED pisca 5x mais rápido, pois como o delay inserido
não ocorre por temporização de hardware, depende apenas da velocidade de execução,
alterar o clock influencia diretamente na temporização do delay.

Modificação na Otimização:
- Não houve mudança visível ao alterar o nível de otimização utilizando a função SysCtlDelay, pois a mesma 
executa um laço de apenas 3 instruções assembly, e devido a isso a otimização não tem relevância.
- Foi testado tambem utilizando um laço for, e neste caso sim, a otimização fez uma expressiva diferença, 
principalmente quando configurado para otimização máxima priorizando velocidade.
