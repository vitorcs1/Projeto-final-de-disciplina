#include <stdio.h>
#include <stdlib.h>


#define MAX 5

typedef struct noh {
  int dado;
  struct noh *prox;
} noh;

typedef struct fila {
  int max_qtd, qtd_elementos;

  noh *inicio;
  noh *fim;
} fila;


void menu() {
  printf("\n=============================\n");
  printf("\n[1] Enfileirar\n");
  printf("[2] Desenfileirar\n");
  printf("[3] Exibir Fila\n");
  printf("[4] Buscar elemento\n");
  printf("\n[0] Sair\n");
  printf("\n=============================\n");
  printf("\nInsira opcao: ");
}


void queue(int dado, fila *f) {
  noh *ptr = (noh *)calloc(1, sizeof(struct noh));

  if (ptr == NULL) {
    printf("Erro na alocação\n");
  } else {
    ptr->dado = dado;

    if (f->inicio == NULL) {
      f->inicio = ptr;
    } else {
      f->fim->prox = ptr;
    }

    f->fim = ptr;

    f->qtd_elementos += 1;
  }
}

int dequeue(fila *f) {
  noh *ptr = f->inicio;
  int dado;

  if (ptr == NULL) {
    printf("\n|Fila vazia|\n");
  } else {
    f->inicio = ptr->prox;
    ptr->prox = NULL;
    dado = ptr->dado;
    free(ptr);
    f->qtd_elementos -= 1;
  }

  return dado;
}

void exibirfila(fila *fila) {
  noh *ptr = fila->inicio;

  if (ptr == NULL) {
    printf("\n|Fila vazia|\n");
  } else {
    while (ptr != NULL) {
      printf("%d  ", ptr->dado);
      ptr = ptr->prox;
    }
  }
}

int buscar_elemento(fila *fila, int dado_buscado) {
  noh *ptr = fila->inicio;

  while (ptr->dado != dado_buscado) {
    ptr = ptr->prox;
    if (ptr->prox == NULL && ptr->dado != dado_buscado) {
      printf("Elemento nao encontrado\n");
      
    }
  }
  printf("\nElemento encontrado: %d\n", ptr->dado);

  return dado_buscado;
}

int main(void) {


  fila *fila;
  fila = (struct fila *)calloc(1, sizeof(struct fila));

  int opc, dado, elemento_buscado;

  while (1) {
    menu();
    scanf("%d", &opc);

    if (opc == 1) {
      if (fila->qtd_elementos >= MAX) {
        printf("\n|Fila cheia, realize a operação 'Desenfileirar' para poder "
               "inserir um novo elemento|\n\n");
      } else {
        
        printf("Insira um inteiro: ");
        scanf("%d", &dado);
        queue(dado, fila);
        printf("\n|Elemento inserido|\n");
      }
    } else if (opc == 2) {
      
      dequeue(fila);
      if (fila->qtd_elementos >= 1) {
        printf("\n|Elemento removido|\n");
      }
    } else if (opc == 3) {
      
      printf("========== Fila Atual ===========\n");
      exibirfila(fila);
      printf("\n===============================\n");

    } else if (opc == 4) {
      
      if (fila->qtd_elementos < 1) {
        printf("\n==== Fila vazia ====\n");
      } else {
        printf("Insira o elemento a ser buscado: ");
        scanf("%d", &elemento_buscado);
        buscar_elemento(fila, elemento_buscado);
      }
    } else if (opc == 0) {
      
      break;
    } else {
      
      printf("=== Digite uma opcao valida ===");
    }
  }

  return 0;
}