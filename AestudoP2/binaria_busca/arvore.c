
#include <stdio.h>
#include <stdlib.h>

typedef struct noArvore {
    int valor;
    struct noArvore *esq;
    struct noArvore *dir;
} noArvore;

noArvore* insere(noArvore* raiz, noArvore* n) {
    if (raiz == NULL)
        return n;
    if (raiz->valor > n->valor)
        raiz->esq = insere(raiz->esq, n);
    else
        raiz->dir = insere(raiz->dir, n);
    return raiz;
}

noArvore* busca(noArvore* raiz, int k) {
    if (raiz == NULL || raiz->valor == k)
        return raiz;
    if (raiz->valor > k)
        return busca(raiz->esq, k);
    else
        return busca(raiz->dir, k);
}



noArvore* buscaPai(noArvore* raiz, noArvore* n) {
    if (raiz == NULL || raiz->esq == n || raiz->dir == n)
        return raiz;
    if (raiz->valor > n->valor)
        return buscaPai(raiz->esq, n);
    else
        return buscaPai(raiz->dir, n);
}

noArvore* removeRaiz(noArvore* raiz) {
    noArvore *pai, *filho;
    if (raiz->esq == NULL && raiz->dir == NULL) {  // Caso 1: Nó folha
        free(raiz);
        return NULL;
    } else if (raiz->esq == NULL || raiz->dir == NULL) {  // Caso 2: Nó com 1 filho
        filho = (raiz->esq != NULL) ? raiz->esq : raiz->dir;
        free(raiz);
        return filho;
    } else {  // Caso 3: Nó com 2 filhos
        pai = raiz;
        filho = raiz->dir;
        while (filho->esq != NULL) {
            pai = filho;
            filho = filho->esq;
        }
        raiz->valor = filho->valor;
        if (pai->esq == filho)
            pai->esq = removeRaiz(filho);
        else
            pai->dir = removeRaiz(filho);
        return raiz;
    }
}

noArvore* removeNo(noArvore* raiz, int valor) {
    noArvore* n = busca(raiz, valor);  // Checa se o nó existe
    if (n) {
        noArvore* pai = buscaPai(raiz, n);  // Descobre quem é o nó pai
        if (pai) {
            if (pai->dir == n)  // Nó a ser removido é o filho à direita
                pai->dir = removeRaiz(n);
            else  // Nó a ser removido é o filho à esquerda
                pai->esq = removeRaiz(n);
        } else {  // Nó não possui pai, é a própria raiz
            raiz = removeRaiz(n);
        }
    }
    return raiz;
}

noArvore* novoNo(int valor) {
    noArvore* n = (noArvore*) malloc(sizeof(noArvore));
    n->valor = valor;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}



int main() {
    noArvore* raiz = NULL;
    
    // Inserindo valores
    raiz = insere(raiz, novoNo(50));
    raiz = insere(raiz, novoNo(30));
    raiz = insere(raiz, novoNo(70));
    raiz = insere(raiz, novoNo(20));
    raiz = insere(raiz, novoNo(40));
    raiz = insere(raiz, novoNo(60));
    raiz = insere(raiz, novoNo(80));

    // Buscando um valor
    noArvore* buscado = busca(raiz, 40);
    if (buscado)
        printf("Valor encontrado: %d\n", buscado->valor);
    else
        printf("Valor não encontrado\n");

    // Removendo um valor
    raiz = removeNo(raiz, 70);

    // Buscando valor removido
    buscado = busca(raiz, 70);
    if (buscado)
        printf("Valor encontrado: %d\n", buscado->valor);
    else
        printf("Valor não encontrado\n");

    return 0;
}

