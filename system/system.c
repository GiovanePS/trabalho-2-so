#include <stdio.h>

#include "system.h"

void init_system() {
  print_interface();
  int option;
  printf("Opção: ");
  scanf("%d", &option);

  switch(option) {
    case 1:
    default:
      return;
      break;
  }
}

void print_interface() {
  printf("[1] Visualizar memória.\n");
  printf("[2] Criar processo.\n");
  printf("[3] Visualizar tabela de páginas.\n");
  printf("[4] Sair.\n");
}
