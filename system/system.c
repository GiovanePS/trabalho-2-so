#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "system.h"

void init_system() {
  srand(time(NULL));
  
  while (1) {
    print_interface();
    int option;
    printf("Opção: ");
    scanf("%d", &option);

    switch(option) {
      case 1:
        break;
      default:
        return;
    }
  }
}

void print_interface() {
  printf("[1] Visualizar memória.\n");
  printf("[2] Criar processo.\n");
  printf("[3] Visualizar tabela de páginas.\n");
  printf("[4] Sair.\n");
}
