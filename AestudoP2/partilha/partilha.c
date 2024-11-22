#include <stdlib.h>

//nó do vetor, possui campos para valor e frequência
typedef struct nov_{
    int valor;
    int freq;
}nov;

//nó da árvore, possui campos para valor, partilha e os dois ponteiros
typedef struct noa_{
    int valor;
    int partilha;
    struct noa_ *esq, *dir;
}noa;

//constroi a árvore a partir de um vetor ordenado com campos de valor e frequência
noa* construcao(nov v[], int inf, int sup){
    
    noa* raiz = malloc(sizeof(noa)); //espaço é reservado para a raiz da árvore/subárvore 

    if (inf != sup){ //se houver um intervalo com mais de um nó a ser considerado

        int max = inf; //max guardará o índice do valor de freqência máxima 
        
        for (int i = inf; i <= sup; i++) //para cada posição do intervalo do vetor
            if (v[i].freq > v[max].freq) //se o valor de índice i for maior que o valor máximo até agora
                max = i; //i é o novo índice de valor máximo

        raiz->valor = v[max].valor; //o valor da raiz criada é o valor de frequência mais alta

        for (int i = max; i < sup; i++) //"apaga" o nó usado (cujo valor foi guardado na raiz)
            v[i]=v[i+1]; 

        sup--; //já que um item foi removido, sup é decrescido
        
        int mid = (inf + sup) / 2; //guarda o índice da metade do vetor (piso)
        raiz->partilha = v[mid].valor; //o valor da metade é usado como partilha

        raiz->esq = construcao(v, inf, mid); //constroi recursivamente a subárvore esquerda
        raiz->dir = construcao(v, mid+1, sup); //constroi recursivamente a subárvore direita

    } else { //se inf for igual a sup, só foi passado um nó e ele será o nó folha

        raiz->valor = v[inf].valor; //o valor é o único passado
        raiz->partilha = -1; //a partilha é um valor inválido 
        raiz->esq = NULL; //ambos os ponteiros são nulos
        raiz->dir = NULL;
    }

    return raiz;
}