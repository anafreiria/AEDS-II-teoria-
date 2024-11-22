#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//parent retorna pai do elemento

int heap_size = 0; //tamanho atual da arvore;
int capacity = 7; // Tamanho maximo do vetor;
int harr[7];

int parent(int i){
    return (i-1)/2; //Retorna a posição do pai
    //return harr[(i-1)/2]; //retorna o pai;
}

int left(int i){
    //return (2*i)+1; //retorna posição do filho a esquerda
    return harr[(2*i)+1]; //retorna o filho a esquerda;
}
int right(int i){
    //return (2*i)+2;
    return harr[(2*i)+2]; //retorna o filho a direita;
}

void minHeapInsertKey(int k){
    if(heap_size == capacity){
        printf("\nOverflow, could not insertKey\n");
        return;
    }

    heap_size++;
    int i = heap_size -1;
    harr[i] = k;

    while( i != 0 && harr[parent(i)] > harr[i]){
        int aux = harr[i];
        harr[i] =  harr[parent(i)];
        harr[(parent(i))] = aux;
        i = parent(i);
    } 
}

void minHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if(l < heap_size && harr[l] < harr[i]){
        smallest = l;
    }
    if(r < heap_size && harr[r] < harr[i]){
        smallest = r;
    }
    if(smallest != i){
        int aux = harr[i];
        harr[i] = harr[smallest];
        harr[smallest] = aux;
        minHeapify(smallest);
    }
}

int minHeapExtractMin(){
    if(heap_size <= 0){
        printf("\nsize == capacity\n");
        return INT_MAX;
    }
    if(heap_size == 1){
        heap_size--;
        return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[heap_size -1];
    heap_size--;
    minHeapify(0);

    return root;
}



int main(){
    minHeapInsertKey(5);
    minHeapInsertKey(2);
    minHeapInsertKey(4);
    minHeapInsertKey(15);
    minHeapInsertKey(7);
    minHeapInsertKey(3);
    minHeapInsertKey(1);

    for(int i = 0; i < 7; i++){
        printf("\nPosicao %d, elemento:%d \n",i , harr[i]);
    }

    minHeapExtractMin();
    minHeapExtractMin();

    printf("\n------------------\n");

    for(int i = 0; i < 7; i++){
        printf("\nPosicao %d, elemento:%d \n",i , harr[i]);
    }

    return 0;
}