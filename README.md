# Trabalho de RPG-Estrutura de dados
## <img width="100" height="165" alt="UFG_logo svg" src="https://github.com/user-attachments/assets/155134e7-2a91-4ca7-8841-cadd8b16f913" />
### Alunos: Luiz Augusto Correa Melo, Matrícula:202403033; Sofia Viana Mendes, Matrícula: 202403053.
### Professor: Bruno Brandão Soares Martins
##Descrição
Um trabalho feito para faculdade onde o objetivo é testar os conhecimentos sobre estrutura de dados e seus métodos de ordenação, neste caso foram utilizados listas e structs, além de também utilizar os métodos de ordenação quicksort e insertion sort.
## Funcionalidades:
# ⚔️ Gerenciador de Combate RPG em C

Este projeto é um sistema de gerenciamento de turnos para RPGs de mesa, desenvolvido em C. Ele permite controlar a ordem de iniciativa, adicionar e remover participantes dinamicamente e rolar dados.

## 📂 Estrutura do Projeto

O código foi organizado em módulos para facilitar a manutenção e escalabilidade:

### 1. Módulo Personagem (`personagem.h` / `.c`)
Responsável pela definição da entidade que participa do combate.
* **Struct Personagem:** Estrutura de dados que armazena:
    * Nome e Nível.
    * Tipo de dado de ataque (d4, d6, d20...).
    * Valor da Iniciativa atual.
    * Status `bool` (se está ativo em combate).
* **Funções:** Inclui `criar_personagem` para instanciar novos participantes e `mostrar_ordem` para exibir a lista formatada.

### 2. Módulo Utilidades (`utils.h` / `.c`)
Contém as ferramentas matemáticas e lógicas do sistema.
* **Rolar Dados:** Função para gerar números aleatórios baseados no tipo de dado do personagem.
* **Algoritmos de Ordenação:** Implementação de **QuickSort** (para ordenação inicial rápida) e **Insertion Sort** (para reordenações menores durante o combate).

### 3. Módulo Combate (`combate.h` / `.c`)
O "coração" do programa, onde as regras de negócio são aplicadas.
* **Iniciar Combate:** Recebe a lista inicial, calcula iniciativas e define a ordem.
* **Adicionar Personagem:** Insere novos participantes (reforços) no meio da batalha, recalculando a ordem automaticamente.
* **Remover Personagem:** Remove participantes abatidos e reorganiza a lista utilizando *Insertion Sort* para manter a integridade da fila.
* **Avançar Turno:** Rola novas iniciativas para todos os ativos e redefine a ordem do turno.

## 🛠️ Conceitos Técnicos Aplicados
* **Structs e Typedef:** Para modelagem de dados complexos.
* **Ponteiros:** Para manipulação eficiente de memória e passagem de parâmetros por referência.
* **Alocação de Vetores:** Gerenciamento de listas de participantes.
* **Algoritmos de Busca e Ordenação:** Uso prático de QuickSort e Insertion Sort.

## 🚀 Como Rodar
Compile o projeto utilizando o GCC:
```bash
gcc rpg.c personagem.c utilidades.c combate.c -o rpg_combate
./rpg_combate
