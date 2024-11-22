#include<stdio.h>
#include<stdlib.h>

typedef struct no_{
    int chave;
    int valor;
    struct no_ * prox;

} no;

no *topo=NULL;
no *iniciofila=NULL;
no *finalfila=NULL;


// 
// Operações encadeadas em lista enacadeada forma de vetor
// 


// Busca encadeada
void busca_enc(int x, no ** ant, no ** pont, no* ptlista){

    *ant = ptlista;
    *pont = NULL;
    no * ptr = (*ptlista).prox;

    while(ptr != NULL){
        if((*ptr).chave < x){
            *ant = ptr;
            ptr = (*ptr).prox;
        }else{ 
            if((*ptr).chave == x){
                *pont = ptr;
            }
            ptr = NULL;
        }
    }
}

// Inserção encadeada
int insere_enc(no * no_inserir, no* ptlista){
    no * ant;
    no * pont;
    busca_enc((*no_inserir).chave,
    &ant, &pont, ptlista);
    if(pont == NULL){
        (*no_inserir).prox = (*ant).prox;
        (*ant).prox = no_inserir;
        return 0;
    }

    return -1;
}


//Remoção encadeada
no * remove_enc(int x, no* ptlista){
    no * ant;
    no * pont;
    busca_enc(x, &ant, &pont, ptlista);
    if(pont != NULL){
        (*ant).prox = (*pont).prox;
        return pont;
    }
    return NULL;
}


// 
// Operações encadeadas em lista enacadeada forma de pilha
// 


//Impressão dos valores inclusos na pilha
void imprimir_pilha() {
    no *aux;
    aux = topo;
    while(aux != NULL) {
        printf("%d \n", aux->chave);
        aux = (*aux).prox;
    }
}

//Inserção por pilha encadeada
void inserir_pilha(no *no_pilha){

    (*no_pilha).prox = topo;
    topo = no_pilha;

}

// Remoção pilha encadeada
no *remove_pilha() {
    if (topo != NULL) {  // Correção: Operador de comparação correto
        no *retremove;
        retremove = topo;
        topo = (*topo).prox;
        return retremove;
    } else {
        return NULL;
    }
}


// 
// Operações encadeadas em lista enacadeada forma de pilha
// 

void imprimir_fila(){
    no *aux;
    aux=iniciofila;
    while(aux != NULL){
        printf("%d \n",aux->chave);
        aux=aux->prox;
    }
}

//Inserção por fila encadeada
void insere_fila(no *no_fila){
    if(finalfila != NULL){
        (*finalfila).prox = no_fila;
    }else{
        iniciofila= no_fila;
    }
    finalfila= no_fila;
}

// Remoção pilha encadeada
no *remove_fila(){
   
    if( iniciofila != NULL){
        no *retorno;
        retorno = iniciofila;
        iniciofila= (*iniciofila).prox;
        if (iniciofila == NULL){
        finalfila = NULL;
    }
    return retorno;
}
    return NULL;
}

int main(){

    // 
    // Alocação de memória e chamada de função para vetor encadeado
    // 
    no * ptlista;
    ptlista = malloc(sizeof(no));
    (*ptlista).prox = NULL;

    no * inserir = malloc(sizeof(no));
    (*inserir).chave = 1;
    (*inserir).valor = 1;
    (*inserir).prox = NULL;

    if(insere_enc(inserir, ptlista) == -1){
        printf("erro ao inserir\n");
    }else{
        printf("insercao realizada\n");
    }

    no* removido = remove_enc(2, ptlista);
    if(removido == NULL){
        printf("elemento nao encontrado\n");
    }else{
        printf("chave: %d | valor: %d\n",
        (*removido).chave, (*removido).valor );
    }


    removido = remove_enc(1, ptlista);
    if(removido == NULL){
        printf("elemento nao encontrado\n");
    }else{
        printf("chave: %d | valor: %d\n",
        (*removido).chave, (*removido).valor );
    }

    // 
    // Alocação de memória e chamada de função para pilha
    // 

    no * pilha = malloc(sizeof(no));
    (*pilha).chave = 3;
    (*pilha).valor = 2;
    (*pilha).prox = NULL;

    inserir_pilha(pilha);  // Chamar inserir_pilha para adicionar o elemento à pilha

    imprimir_pilha();  // Chamada correta da função imprimir_pilha


    no * pilhaS = malloc(sizeof(no));
    (*pilhaS).chave = 5;
    (*pilhaS).valor = 2;
    (*pilhaS).prox = NULL;
    
    inserir_pilha(pilhaS);  
    imprimir_pilha();

    no * retremovidopilha = remove_pilha();
    if( retremovidopilha != NULL){
        printf("Valor removido com sucesso\n");
        free(retremovidopilha);
    }else {
        printf("Valor não removido, pilha vazia\n");
    }
    
    // 
    // Alocação de memória e chamada de função para fila
    // 

     no * fila = malloc(sizeof(no));
    (*fila).chave = 4;
    (*fila).valor = 2;
    (*fila).prox = NULL;
    insere_fila(fila);
    imprimir_fila();

    no * retremovidofila = remove_fila();
    if( retremovidofila != NULL){
        printf("Valor removido com sucesso\n");
        free(retremovidofila);
    }else {
        printf("Valor não removido, fila vazia\n");
    }

    return 0;
}