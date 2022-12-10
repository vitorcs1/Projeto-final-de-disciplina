#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 70

typedef struct vinho {
  int safra;
  char nome[MAX];
  char origem[MAX];
  char tipo_uva[MAX];

  struct vinho *prox;
} vinho;

typedef struct pilha {
  vinho *topo;
  int qtd_elementos;
} pilha;


void menu() {
  printf("\n___________________________\n");
  printf("\n1 - Inserir vinho\n");
  printf("2 - Retirar vinho (Ocasi�o Especial - Mais recente)\n");
  printf("3 - Retirar vinho (Ocasi�o n�o Especial - Mais antigo)\n");
  printf("4 - Exibir as 5 aquisi��es mais recentes\n");
  printf("5 - Exibir as 5 aquisi��es mais antigas\n");
  printf("\n0 - Sair\n");
  printf("___________________________\n");
  printf("\nDigite sua opcao: ");
}

// Fun��es principais
void iniciarPilha(pilha *stack) { stack->topo = NULL; }

void push(pilha *stack) {
  vinho *ptr;

  int safra;
  char nome[MAX], origem[MAX], tipo_uva[MAX];

  ptr = (struct vinho *)calloc(1, sizeof(struct vinho));

  if (ptr == NULL) {
    printf("Erro na alocacao");
  } else {
    getchar();
    printf("|| Insira os vinhos por ordem de aquisi��o ||\n\n");
    printf("\nInsira o nome do vinho: ");
    fgets(nome, MAX, stdin);
    strcpy(ptr->nome, nome);

    printf("\nInsira a safra do vinho: ");
    scanf("%d", &safra);
    ptr->safra = safra;

    getchar();
    printf("\nInsira a origem do vinho: ");
    fgets(origem, MAX, stdin);
    strcpy(ptr->origem, origem);

    printf("\nInsira o tipo de uva: ");
    fgets(tipo_uva, MAX, stdin);
    strcpy(ptr->tipo_uva, tipo_uva);

    ptr->prox = stack->topo;
    stack->topo = ptr;
    stack->qtd_elementos += 1;
    system("clear || cls");
    printf("\nVinho inserido na adega\n");
  }
}

void ocasiao_especial(pilha *stack) {
  vinho *ptr = stack->topo;

  if (ptr == NULL) {
    system("clear || cls");
    printf("\nAdega Vazia!\n");
  } else {
    stack->topo = ptr->prox;
    ptr->prox = NULL;
    printf("\n|| Vinho adquirido mais recentemente selecionado! ||\n");
    printf("\nNome: %s", ptr->nome);
    printf("Safra: %d\n", ptr->safra);
    printf("Origem: %s", ptr->origem);
    printf("Tipo de uva: %s\n", ptr->tipo_uva);

    free(ptr);
    stack->qtd_elementos -= 1;
  }
}

void ocasiao_nao_especial(pilha *stack) {
  vinho *ptr = stack->topo;
  vinho *aux = ptr;
  vinho *aux2 = ptr;

  if (ptr == NULL) {
    system("clear || cls");
    printf("Adega Vazia!\n");
  } else {
    while (ptr->prox != NULL) {
      aux = ptr;
      ptr = ptr->prox;
      aux2 = ptr;
    }
    printf("\nNome: %s\n", ptr->nome);
    printf("Safra: %d\n", ptr->safra);
    printf("Origem: %s\n", ptr->origem);
    printf("Tipo de uva: %s\n", ptr->tipo_uva);

    ptr = aux;
    free(aux2);
  }
}

void display_recentes(pilha *stack) {
  vinho *ptr = stack->topo;

  int count = 0;

  if (ptr == NULL) {
    system("clear || cls");
    printf("\nAdega Vazia!\n");
  } else if (stack->qtd_elementos < 5) {
    system("clear || cls");
    printf("\nVoce possui menos que 5 vinhos...\n");
  } else {
    printf("--------- Cinco Aquisi��es mais Recentes ---------\n");
    while (count < 5) {
      printf("\nNome: %s\n", ptr->nome);
      printf("Safra: %d\n", ptr->safra);
      printf("Origem: %s\n", ptr->origem);
      printf("Tipo de uva: %s\n\n", ptr->tipo_uva);
      ptr = ptr->prox;
      count += 1;
    }
  }
}

void display_antigas(pilha *stack) {
  vinho *ptr = stack->topo;

  printf("--------- Cinco Aquisi��es mais Antigas ---------\n");
  int aux = stack->qtd_elementos - 5;
  int countOlder = 0;

  if (ptr == NULL) {
    system("clear || cls");
    printf("\nAdega Vazia!\n");
  } else {

    while (countOlder != aux) {
      ptr = ptr->prox;
      countOlder++;
    }
    int i;
    for (i = 0; i != 5; i++) {
      printf("\nNome: %s\n", ptr->nome);
      printf("Safra: %d\n", ptr->safra);
      printf("Origem: %s\n", ptr->origem);
      printf("Tipo de uva: %s\n\n", ptr->tipo_uva);
      ptr = ptr->prox;
    }
  }
}

int main(void) {


  pilha *STACK;
  STACK = (struct pilha *)calloc(1, sizeof(struct pilha));

  iniciarPilha(STACK);

  vinho vinho;

  int opc, safra;
  char nome[MAX];
  char origem[MAX];
  char tipo_uva[MAX];

  while (1) {
    menu();
    scanf("%d", &opc);
    if (opc == 1) {
      system("clear || cls");
      push(STACK);
    } else if (opc == 2) {
      ocasiao_especial(STACK);
    } else if (opc == 3) {
      ocasiao_nao_especial(STACK);
    } else if (opc == 4) {
      display_recentes(STACK);
    } else if (opc == 5) {
      display_antigas(STACK);
    } else if (opc == 0) {
      system("clear || cls");
      printf("\nEncerrando...");
      break;
    } else {
      printf("\nInsira uma op��o v�lida!\n");
      menu();
      scanf("%d", &opc);
    }
  }
  return 0;
}
