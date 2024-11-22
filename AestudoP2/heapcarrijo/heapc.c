#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


// Insere uma nova chave 'k'
void insertKey(int *harr, int *heap_size, int capacity, int k)
{
    if (*heap_size == capacity)
    {
        printf("\nOverflow: Não foi possível inserir a chave\n");
        return;
    }
    // Primeiro insere a nova chave no final
    (*heap_size)++;
    int i = *heap_size - 1;
    harr[i] = k;
    // Corrige a propriedade do heap mínimo se ela for violada
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}
// Método para remover o elemento mínimo (ou raiz) do heap mínimo
int extractMin(int *harr, int *heap_size)
{
    if (*heap_size <= 0)
        return INT_MAX;
    if (*heap_size == 1)
    {
        (*heap_size)--;
        return harr[0];
    }
    // Armazena o valor mínimo e o remove do heap
    int root = harr[0];
    harr[0] = harr[*heap_size - 1];
    (*heap_size)--;
    MinHeapify(harr, *heap_size, 0);
    return root;
}

//Arruma valor para Min-Heap
// Um método recursivo para heapificar uma subárvore com a raiz no índice dado
// Este método assume que as subárvores já estão heapificadas
void MinHeapify(int *harr, int heap_size, int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(harr, heap_size, smallest);
    }
}