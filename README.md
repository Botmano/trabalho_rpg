# Trabalho de RPG-Estrutura de dados
## <img width="100" height="165" alt="UFG_logo svg" src="https://github.com/user-attachments/assets/155134e7-2a91-4ca7-8841-cadd8b16f913" />
### Alunos: Luiz Augusto Correa Melo, Matrícula:202403033; Sofia Viana Mendes, Matrícula: 202403053.
## Descrição:
O Programa feito para o trabalho, um sistema de iniciativa para combate em um rpg, usando de quicksort e insertion sort para organizar a ordem de turnos para cada personagem.
## Funcionalidades:
Personagem, são os itens que vão ser responsáveis pelo combate no código, sendo eles um struct que carrega o nível, o tipo de dado, a iniciativa, nome e um bool que representa se estão em combate. Há também a função criar personagem que recebe os dados e cria um struct do tipo. Além disso, no arquivo onde está o código da relação do personagem, há também a função monstrar_ordem que emprime a ordem definida na lista de personagens
Utilidades, onde está as ferramentas usadas pelo programa para definir como o dado rola, e as ordenações utilizadas no programa.
Combate, parte principal do programa, como iniciar combate que recebe uma lista inicial, calcula a iniciativa dos participantes e imprime a ordem, adicionar personagem, adiciona um personagem ao combate já ativo, e organiza a ordem de combate, remover remove um personagem ativo em combate e organiza novamente utilizando insertion sort, e avançar turno que rola as iniciativas novamente define os turnos e imprime agora qual é a nova ordem de personagens.
