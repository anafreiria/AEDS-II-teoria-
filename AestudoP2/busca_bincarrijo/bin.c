#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct noArvore_ noArvore;
struct noArvore_
{
    int valor;
    noArvore *esq;
    noArvore *dir;
};
noArvore *insere(noArvore *raiz, noArvore *n)
{
    if (raiz == NULL)
        return n;
    if (raiz->valor > n->valor)
        raiz->esq = insere(raiz->esq, n);
    else
        raiz->dir = insere(raiz->dir, n);
    return raiz;
}
noArvore *busca(noArvore *raiz, int k)
{
    if (raiz == NULL || raiz->valor == k)
        return raiz;
    if (raiz->valor > k)
        return busca(raiz->esq, k);
    else
        return busca(raiz->dir, k);
}
noArvore *removeNo(noArvore *raiz, int valor)
{
    noArvore *n = busca(raiz, valor); // checa se o noh existe
    if (n)
    {
        noArvore *pai = buscaPai(raiz, n); // descobre quem eh o noh pai
        if (pai)
        {                      // caso tenha noh pai
            if (pai->dir == n) // noh a ser removido eh filho a direita
                pai->dir = removeRaiz(n);
            else // noh a ser removido eh filho a esquerda
                pai->esq = removeRaiz(n);
        }
        else
        { // nao possui pai, logo, eh o proprio noh raiz
            raiz = removeRaiz(n);
        }
    }
    return raiz;
}