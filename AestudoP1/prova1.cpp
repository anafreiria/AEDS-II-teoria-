// Listas Lineares

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct no
{
    int chave;
    int valor;
} no;

// Operações para listas em forma de vetor ordenado


int n = 0; // Número atual de elementos no vetor
int m;     // Tamanho máximo do vetor
no L[MAX];
int topo = -1;


// Função busca normal *****
int busca1(no L[], int x)
{
    int i = 0;
    while (i < n)
    {
        if (L[i].chave == x)
        {
            return i;
            i = n + 1;
        }
        i++;
    }
    return -1; // Retorna a posição ou -1 se não encontrado
}


// Função segundo tipo de busca *****
int busca2(no L[], int n, int x){
    L[n + 1].chave = x;
    int i = 0;
    while (L[i].chave != x){
        i++;
    }
    if( i != n){
        return i;
    }else{
        return -1;
    }

} 


//Busca 3, lista ordenada *****
int busca3(no L[], int n, int x){
    L[n+1].chave = x;
    int i = 0;
    while (L[i].chave < x){
        i++;
    }
    if( i == n + 1 || L[i].chave != x){
        return -1;
    } else {
        return i;
    }
// Se x for encontrado, a função retorna a posição do valor;
// se não for encontrado, retorna -1.

}

// Função busca binária ******
int buscabin(no L[], int n, int x)
{
    int inf = 0, sup = n - 1, meio;
    while (inf <= sup)
    {
        meio = (inf + sup) / 2;
        if (L[meio].chave == x)
        {
            return meio;
        }
        else
        {
            if (L[meio].chave < x)
            {
                inf = meio + 1;
            }
            else
            {
                sup = meio - 1;
            }
        }
    }
    return -1;
}

// Função de inserção lista normal *****
int insere(no L[], int n, int m, struct no novo)
{
    if (n < m)
    {
        if (busca1( L, novo.chave) == -1)
        {
            L[n].chave = novo.chave;
            L[n].valor = novo.valor;
            return n + 1;
        }
        return 0;
    }

    return -1;
//lista cheia= -1, elemento já existe=0; 
//inserido= retorna tamanho da lista
}

// Função de remoção lista normal *****
no *retira(int x, no L[], int *n) //para chamar no main uso &n
{
    no *no_retorno = NULL;

    if (*n != 0)
    {
        int indice = busca1(L, x);
        if (indice >= 0)
        {
            no_retorno = (no *)malloc(sizeof(no));
            no_retorno->chave = L[indice].chave;
            no_retorno->valor = L[indice].valor;

            for (int i = indice; i < *n - 1; i++)
            {
                L[i].chave = L[i + 1].chave;
                L[i].valor = L[i + 1].valor;
            }
            (*n)--; // Decrementa n após o loop
        }
    }
    return no_retorno;
}

//
// Operações para listas em forma de pilha
//

// Inserção por pilha *******
int inserepilha(no L[], int *topo, struct no nova)
{
    int insere = -1;

    if (*topo != m -1)
    {
        (*topo)++;
        L[*topo] = nova;
        insere = *topo;
    }
    return insere;
}

// Função remoção por pilha
no *retirapilha(no L[], int *topo)
{
    no *no_retornopilha = NULL;


    if (*topo != -1){
        no_retornopilha = (no *)malloc(sizeof(no));
        if (no_retornopilha != NULL)
        {
            no_retornopilha->chave = L[*topo].chave;
            no_retornopilha->valor = L[*topo].valor;
            (*topo)--;// Decrementa o número de elementos após a remoção
        }
        return no_retornopilha;
    }
    return NULL;
}

//
// Operações para listas em forma de fila
//


int inserefila(no L [], int *r, int *f, struct no novas)
{
    int prov =( *r + 1) % (m + 1);

    if (prov != *f)
    { // Verifica se a fila não está cheia
        *r = prov;
        L[*r] = novas;
        if (*f == -1)
        { // Se a fila estava vazia, ajusta 'f'
            *f = *r;
        }
        return *r;
    }

    return -1; // Retorna a posição de inserção ou -1 se falhou
}

// Função para remover um elemento da fila
no *removeFila(no L[], int *f, int *r, int m)
{
    no *no_retornofila = NULL;

    if (*f != -1)
    { // Verifica se a fila não está vazia
        no_retornofila = (no *)malloc(sizeof(no));
        if (no_retornofila != NULL)
        {
            no_retornofila->chave = L[*f].chave;
            no_retornofila->valor = L[*f].valor;

            if (*f == *r)
            { // Se havia apenas um elemento, a fila fica vazia
                *f = *r = -1;
            }
            else
            {
                *f = (*f + 1) % m; // Atualiza o índice do início da fila (incremento circular)
            }
        }
    }

    return no_retornofila; // Retorna o valor removido ou -1 se a fila estava vazia
}


//Do menino
// int inserefila(no F[], int *f, int *r, int m, no novo)
// {
//     int aux = (*r + 1) % (m + 1);

//     if (aux != *f) {
//         *r = aux;
//         F[*r].chave = novo.chave;
//         F[*r].valor = novo.valor;
//         if (*f == -1) {
//             *f = *r;
//         }
//         return *r;
//     }
//     return -1;
// }

// no *removeFila(no F[], int *f)
// {
//     no *retorno = NULL;

//     if (*f != -1)
//     {
//         retorno = (no *)malloc(sizeof(no));
//         (*retorno).chave = F[*f].chave;
//         (*retorno).valor = F[*f].valor;

//         //*f = *f - 1;
//     }

//     return retorno;
// }



int main() {
    int choice, index,  r = -1, f = -1;
    struct no novo;
    no *result;
    
    printf("Tamanho máximo do vetor?\n");
    scanf("%d", &m);
    printf("Número inicial de elementos do vetor?\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        L[i].chave = i + 1;
        L[i].valor = (i + 1) * 10;
    }

    do {
        printf("\nMenu:\n");
        printf("1. Busca Normal\n");
        printf("2. Busca Tipo 2\n");
        printf("3. Busca Tipo 3\n");
        printf("4. Busca Binária\n");
        printf("5. Inserir na Lista\n");
        printf("6. Remover da Lista\n");
        printf("7. Inserir na Pilha\n");
        printf("8. Remover da Pilha\n");
        printf("9. Inserir na Fila\n");
        printf("10. Remover da Fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite a chave a ser buscada: ");
                scanf("%d", &index);
                index = busca1(L, index);
                if (index != -1) {
                    printf("Chave encontrada na posição: %d\n", index);
                } else {
                    printf("Chave não encontrada.\n");
                }
                break;

            case 2:
                printf("Digite a chave a ser buscada: ");
                scanf("%d", &index);
                index = busca2(L, n, index);
                if (index != -1) {
                    printf("Chave encontrada na posição: %d\n", index);
                } else {
                    printf("Chave não encontrada.\n");
                }
                break;

            case 3:
                printf("Digite a chave a ser buscada: ");
                scanf("%d", &index);
                index = busca3(L, n, index);
                if (index != -1) {
                    printf("Chave encontrada na posição: %d\n", index);
                } else {
                    printf("Chave não encontrada.\n");
                }
                break;

            case 4:
                printf("Digite a chave a ser buscada: ");
                scanf("%d", &index);
                index = buscabin(L, n, index);
                if (index != -1) {
                    printf("Chave encontrada na posição: %d\n", index);
                } else {
                    printf("Chave não encontrada.\n");
                }
                break;

            case 5:
                printf("Digite a chave e o valor a serem inseridos: ");
                scanf("%d %d", &novo.chave, &novo.valor);
                index = insere(L, n, m, novo);
                if (index == 0) {
                    printf("Elemento já existe.\n");
                } else if (index == -1) {
                    printf("Lista cheia.\n");
                } else {
                    n = index;
                    printf("Elemento inserido na posição: %d\n", index - 1);
                }
                break;

            case 6:
                printf("Digite a chave a ser removida: ");
                scanf("%d", &index);
                result = retira(index, L, &n);
                if (result != NULL) {
                    printf("Elemento removido: Chave: %d, Valor: %d\n", result->chave, result->valor);
                    free(result);
                } else {
                    printf("Elemento não encontrado ou lista vazia.\n");
                }
                break;

            case 7:
                printf("Digite a chave e o valor a serem inseridos na pilha: ");
                scanf("%d %d", &novo.chave, &novo.valor);
                index = inserepilha(L, &topo, novo);
                if (index == -1) {
                    printf("Pilha cheia.\n");
                } else {
                    printf("Elemento inserido na pilha na posição: %d\n", index);
                }
                break;

            case 8:
                result = retirapilha(L, &topo);
                if (result != NULL) {
                    printf("Elemento removido da pilha: Chave: %d, Valor: %d\n", result->chave, result->valor);
                    free(result);
                } else {
                    printf("Pilha vazia.\n");
                }
                break;

            case 9:
                printf("Digite a chave e o valor a serem inseridos na fila: ");
                scanf("%d %d", &novo.chave, &novo.valor);
                index = inserefila(L, &r, &f, novo);
                if (index == -1) {
                    printf("Fila cheia.\n");
                } else {
                    printf("Elemento inserido na fila na posição: %d\n", index);
                }
                break;

            case 10:
                result = removeFila(L, &f, &r, m);
                if (result != NULL) {
                    printf("Elemento removido da fila: Chave: %d, Valor: %d\n", result->chave, result->valor);
                    free(result);
                } else {
                    printf("Fila vazia.\n");
                }
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida.\n");
        }
    } while (choice != 0);

    return 0;
}