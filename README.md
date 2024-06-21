# Projeto de criação de um sistema de gerenciamento de memória com paginação paginação para a disciplina de Sistemas Operacionais (INE 5611-2024.01) do curso de Sistemas de Informação.

## Descrição:
### O objetivo aqui é implementar um programa que simula o gerenciamento de memória usando paginação. As instruções foram dadas abaixo:

O programa deve implementar o mecanismo de paginação para alocação não contígua de memória para processos. Isto inclui a implementação dos algoritmos e das estruturas de dados necessárias. A memória física pode ser representada por um vetor de bytes, cujo tamanho deve ser configurável. A memória lógica também pode ser representada por um vetor de bytes, porém o tamanho deverá ser definido no momento da criação do processo. O tamanho máximo de um processo, isto é, da sua memória lógica, deve ser configurável no programa. O tamanho de uma página e, consequentemente, de um quadro também devem ser configuráveis no programa. Assuma, para os tamanhos das memórias física e lógica e da página (quadro), valores que são múltiplos de dois.

Na criação de um processo, sua memória lógica deve ser inicializada (preferencialmente, com valores aleatórios), as páginas da memória lógica devem ser carregadas para quadros da memória física e uma tabela de páginas deve ser criada e inicializada com o mapeamento entre páginas e quadros. Nesta atividade, é suficiente que cada entrada na tabela de páginas possua apenas o número do quadro. Isto é, não é necessário incluir bits auxiliares. Também não é necessário, neste trabalho, implementar algoritmos de substituição de páginas. Para alocar memória para um processo, o gerenciador de memória deverá manter uma estrutura de dados contendo os quadros livres. Pode ser utilizada uma lista encadeada ou um mapa de bits.

### Interface do Simulador com o Usuário
A interface do simulador pode ser por linha de comando (terminal) e deve oferecer as seguintes opções para o usuário:
* Visualizar memória: esta opção deve exibir o porcentual de memória livre e cada quadro da memória física, com seu respectivo valor. Inicialmente, todos os quadros devem estar livres e vazios.
* Criar processo: para criação do processo, o usuário deve informar um número inteiro que identifica o processo e o tamanho do processo em bytes. Se o tamanho informado for maior que o tamanho máximo configurado, uma mensagem deve ser exibida e um novo valor deve ser solicitado. Se não houver memória suficiente para alocar o processo, uma mensagem deve ser exibida e o usuário deve poder solicitar outra opção.
* Visualizar tabela de páginas: esta opção deve exibir o tamanho do processo e a tabela de páginas para o processo identificado pelo número inteiro informado pelo usuário.

## Como executar:
### 1. Clone o repositório:
```
$ git clone https://github.com/GiovanePS/paging
```

### 2. Compile com CMake:
```
$ cd paging
$ mkdir build
$ cd build
$ cmake ..
$ make
```

### 3. Execute:
`./main.c`
