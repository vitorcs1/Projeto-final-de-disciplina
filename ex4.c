#include <stdio.h>
#define MAX 2147483647 
#include <stdlib.h>

typedef struct Node Node;

struct Node{
  int number;
  struct Node *next;
};

Node filas[3];
int qtd=0;
  
void InsercaoFilas(){
  
  int num, num_ant;
  int i = 0, n = 0, x = 0, y = 0;
  
  printf("Digite a 1º fila em ordem crescente:\n");
  printf("\nQuebre a ordem para sair\n");
  
  for(;n==0; i++){
    
    Node *aux, *novo = malloc(sizeof(Node));
    
    printf("\n%dº número:\n", i+1);
    scanf("%d", &num);
    
    novo->number=num;
    novo->next=NULL;
    
    if(x==0){
      filas[0]=*novo;
      x=1;
      num_ant=num;
      qtd++;
    } 
    else if(num>=num_ant){
      aux=&filas[0];
      while(aux->next!=NULL){
        aux=aux->next;
      }
      aux->next=novo;
      num_ant=num;
      qtd++;
    }
    else {
      n=1;
    }
  }

  printf("\nDigite a 2º fila em ordem crescente:\n");
  printf("\nQuebre a ordem para sair\n");
  
  for(i = 0, n = 0, x = 0;n==0;i++){
    
    Node *aux, *novo = malloc(sizeof(Node));
    
    printf("\n%dº número:\n", i+1);
    scanf("%d", &num);
    
    novo->number=num;
    novo->next=NULL;
    
    if(x==0){
      filas[1] = *novo;
      x = 1;
      num_ant=num;
      qtd++;
    }
    else if(num>=num_ant){
      aux = &filas[1];
      while(aux->next){
        aux=aux->next;
      }
      aux->next=novo;
      num_ant=num;
      qtd++;
    }
    else {
      n=1;
    }
  }

  for(i=0, n=0, x=0;i<qtd;i++){
    Node* aux, *novo = malloc(sizeof(Node));
    int NextNum;
    
    if(filas[0].number<=filas[1].number && x<2){
      NextNum=filas[0].number;
      if(x == 1)
        x=2;
        filas[0].number=MAX;
      if(filas[0].next&&x==0){
        filas[0]=*filas[0].next;
        if(!filas[0].next)
          x=1;
      }
    }
    else if(y<2){
      NextNum = filas[1].number;
      if(y == 1)
        y=2;
        filas[1].number=MAX;
      if(filas[1].next&&y == 0){
        filas[1] = *filas[1].next;
        if(!filas[1].next)
          y = 1;
      }
    }
    novo->number = NextNum;
    novo->next = NULL;
    
    if(n==0){
      filas[2] = *novo;
      n=1;
    }
    else {
      aux = &filas[2];
      while(aux->next){
        aux=aux->next;
      }
      aux->next = novo;
    }
  }
  
}


int main(void) {
  
  InsercaoFilas();

  printf("\nFila mista em ordem crescente: ");
  
  int n = 0;
  for(;filas[2].next;n++){
    printf("%d ", filas[2].number);
    filas[2] = *filas[2].next;
  }
  printf("%d", filas[2].number);
  
    return 0;

  }

