#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "system.h"

void init_system() {
  srand(time(NULL));

  while (1) {
    // init_physical_memory();
    print_interface();
    int option;
    printf("Opção: ");
    scanf("%d", &option);

    switch (option) {
    case 1:
      printf("Memória sendo vizualizada.");
      break;
    case 2:
      // create_process();
      printf("Processo criado!");
      break;
    case 3:
      printf("Tabela sendo vizualizada");
    case 0:
      return;
    default:
      break;
    }
  }
}

void print_interface() {
  printf("[1] Visualizar memória.\n");
  printf("[2] Criar processo.\n");
  printf("[3] Visualizar tabela de páginas.\n");
  printf("[0] Sair.\n");
}
