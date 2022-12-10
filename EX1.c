#include <stdio.h>
#include <stdlib.h>


#define MAX 5

typedef struct noh {
  int dado;
  struct noh *prox;
} noh;

typedef struct pilha {
  noh *topo;
  int qtd_elementos;
} pilha;


void inicio() {
  printf("\n==========================\n");
  printf("\n|  [1] Inserir()\n");
  printf("|  [2] Remover()\n");
  printf("|  [3] Exibir pilha\n");
  printf("|  [4] Buscar elemento\n");
  printf("\n|  [0] Encerrar\n");
  printf("\n==========================\n");
  printf("\nInsira opcao: ");
}


void criarpilha(pilha *stack) { stack->topo = NULL; }

void push(int dado, pilha *stack) {
  noh *ptr;
  ptr = (struct noh *)calloc(1, sizeof(struct noh));

  if (ptr == NULL) {
    printf("Erro na alocacao");
  } else {
    ptr->dado = dado;
    ptr->prox = stack->topo;
    stack->topo = ptr;
    stack->qtd_elementos += 1;
  }
}

int pop(pilha *stack) {
  noh *ptr = stack->topo;
  int dado; 

  if (ptr == NULL) {
    printf("Esta pilha está vazia!\n");
  } else {
    stack->topo = ptr->prox;
    ptr->prox = NULL;
    dado = ptr->dado; 
    free(ptr);
    stack->qtd_elementos -= 1;
  }

  return dado;
}

void mostrapilha(pilha *stack) {
  noh *ptr = stack->topo;

  if (ptr == NULL) {
    printf("Esta pilha está vazia!\n");
  } else {
    printf("========= Pilha Atual =========\n");
    while (ptr != NULL) {
      printf("%d\n", ptr->dado);
      ptr = ptr->prox;
    }
    printf("\n=========");
    printf("\nQuantidade de elementos: %d\n", stack->qtd_elementos);
    printf("=========\n");
  }
}

int buscaelemento(pilha *stack, int dado_buscado) {
  noh *ptr = stack->topo;
  int ind = 0;

  if (ptr == NULL) {
    printf("Esta pilha está vazia!");
  } else {
    while (ptr->dado != dado_buscado) {
      ptr = ptr->prox;
      if (ptr->prox == NULL && ptr->dado != dado_buscado) {
        printf("Elemento não foi encontrado\n");
      }
    }
    printf("Elemento encontrado: %d\n", ptr->dado);
  }

  return dado_buscado;
}

////////////////////////////////////////////////////////////////////////////////////
int main(void) {

  
  pilha *STACK;
  STACK = (struct pilha *)calloc(1, sizeof(struct pilha));

  if (STACK == NULL) {
    printf("Erro na alocacao\n");
    exit(0);
  } else {
    criarpilha(STACK);
  }

  int opc = 0, dado = 0;

  while (1) {
    inicio();
    scanf("%d", &opc);

    if (opc == 1) {
      if (STACK->qtd_elementos >= MAX) {
        printf("\n!!! Pilha cheia, realize o comando pop() para poder inserir "
               "um novo "
               "elemento !!!\n");
      } else {
       
        printf("Insira um numero inteiro: ");
        scanf("%d", &dado);
        push(dado, STACK);
        
        printf("Item inserido a pilha!\n");
      }
    } else if (opc == 2) {
      
      pop(STACK);
    
      printf("Item removido da pilha !\n");
    } else if (opc == 3) {
     
      mostrapilha(STACK);
    } else if (opc == 4) {
     
      printf("Insira o elemento a ser buscado: ");
      scanf("%d", &dado);
      buscaelemento(STACK, dado);
    } else if (opc == 0) {
      printf("\n======= Finalizado =======");
      break;
    } else {
      printf("\n!!! Digite uma opção válida !!!\n");
    }
  }
  return 0;
}