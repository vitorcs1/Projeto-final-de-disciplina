#include <stdio.h>
#include <string.h>



struct pilha{
  int item[20];
  int quantidade;
};


void criarpilha(struct pilha * pilha){
    memset(pilha, 0, sizeof(struct pilha));
}


int pushAB(struct pilha * pilha, int valor){
  
  if(pilha -> quantidade == 10){
    printf("\nNão foi possível adicionar o valor %d, pois a pilha está cheia", valor);
    return -1;
  }
    pilha -> item[pilha -> quantidade++] = valor;
  
    return 0;
}


void listagemA(struct pilha * pilha){
    
  int i = 0;

  if(!pilha -> quantidade){
    printf("\nA pilha A está vazia.\n");
    return;
}

    printf("\n\nPilha A:\n");
    
    for(i = pilha -> quantidade - 1; i >= 0; i--){
     printf("%dª Posição: %d\n", i + 1, pilha -> item[i]);
  }
}

void listagemB(struct pilha * pilha){
    
  int i = 0;

  if(!pilha -> quantidade){
    printf("\nA pilha B está vazia.\n");
    return;
}

    printf("\n\nPilha B:\n");
    
    for(i = pilha -> quantidade - 1; i >= 0; i--){
     printf("%dª Posição: %d\n", i + 1, pilha -> item[i]);
  }
}

int pushC(struct pilha * pilha, int valor){
    
    pilha -> item[pilha -> quantidade++] = valor;
  
    return 0;
}


int pushPilhaC(struct pilha * pilhaFinal, struct pilha * pilhaInicial){
    
  int i = 0;

   for(i = 0; i < pilhaInicial -> quantidade; i++){
     pushC(pilhaFinal, pilhaInicial -> item[i]);
  }   

    return 0;
}

void listagemC(struct pilha * pilha){
    
  int i = 0;

  if(!pilha -> quantidade){
    printf("\nA pilha C está vazia.\n");
    return;
}

    printf("\nPilha C:\n");
    
    for(i = pilha -> quantidade - 1; i >= 0; i--){
     printf("%dª Posição: %d\n", i + 1, pilha -> item[i]);
  }
}


void crescente(struct pilha * pilha){
  int i = 0;
  int j = 0;
  int aux = 0;

    for(i = 0; i < pilha -> quantidade; i++){
      for(j = i + 1; j < pilha -> quantidade; j++){
        if(pilha -> item[i] < pilha -> item[j]){
                aux = pilha -> item[i];
                pilha -> item[i] = pilha -> item[j];
                pilha -> item[j] = aux;
   }
  }
 }
}

void decrescente(struct pilha * pilha){
  int i = 0;
  int j = 0;
  int aux = 0;

    for(i = 0; i < pilha -> quantidade; i++){
      for(j = i + 1; j < pilha -> quantidade; j++){
        if(pilha -> item[i] > pilha -> item[j]){
                aux = pilha -> item[i];
                pilha -> item[i] = pilha -> item[j];
                pilha -> item[j] = aux;
   }
  }
 }
}

int pop(struct pilha * pilha){
    if(pilha -> quantidade == 0){
        return -2;
      }
    printf("\nO valor retirado foi o %d", pilha -> item[--pilha -> quantidade]);
    return pilha -> item[pilha -> quantidade];
}

int main(void){
    
   struct pilha pilhaA;
   struct pilha pilhaB;
   struct pilha pilhaC;

   criarpilha(&pilhaA);
   criarpilha(&pilhaB);
   criarpilha(&pilhaC);

   pushAB(&pilhaA, 12);
   pushAB(&pilhaA, 11);
   pushAB(&pilhaA, 10);
   pushAB(&pilhaA, 9);
   pushAB(&pilhaA, 8);
   pushAB(&pilhaA, 7);
   pushAB(&pilhaA, 6);
   pushAB(&pilhaA, 5);
   pushAB(&pilhaA, 4);
   pushAB(&pilhaA, 3);
   pushAB(&pilhaA, 2);
   pushAB(&pilhaA, 1);


   crescente(&pilhaA);
   listagemA(&pilhaA);
   
   pushAB(&pilhaB, 13);
   pushAB(&pilhaB, 14);
   pushAB(&pilhaB, 15);
   pushAB(&pilhaB, 16);
   pushAB(&pilhaB, 17);
   pushAB(&pilhaB, 18);
   pushAB(&pilhaB, 19);
   pushAB(&pilhaB, 20);
   pushAB(&pilhaB, 21222324);
   pushAB(&pilhaB, 11121314);

    pop(&pilhaB);
    pop(&pilhaB);
  
   crescente(&pilhaB);  
   listagemB(&pilhaB);

   pushPilhaC(&pilhaC, &pilhaA);
   pushPilhaC(&pilhaC, &pilhaB);

   decrescente(&pilhaC);
   listagemC(&pilhaC);

    return 0;
}
