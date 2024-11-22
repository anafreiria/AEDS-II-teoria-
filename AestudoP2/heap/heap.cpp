#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 10

int V[M], tam = 0, temp;



int indiceEsquerda(int i) {
    return 2 * i + 1;
}

int indiceDireita(int i) {
    return 2 * i + 2;
}

//
//Funções para Min-Heap
//

// forma interativa
void arrumaValInterativa(int i) {
    while (true) {
        int e = indiceEsquerda(i);
        int d = indiceDireita(i);
        int menor = i;

        if (e < tam && V[e] < V[i]) {
            menor = e;
        }
        if (d < tam && V[d] < V[menor]) {
            menor = d;
        }
        if (menor != i) {
            // Troca V[i] com V[menor]
            int temp = V[i];
            V[i] = V[menor];
            V[menor] = temp;
            // Atualiza i para continuar ajustando o sub-heap
            i = menor;
        } else {
            break;
        }
    }
}

void corrigeHeap() {
    for (int i = (tam / 2) - 1; i >= 0; i--) {
        arrumaValInterativa(i);
    }
}

// forma recursiva
void arrumaVal(int i) {
    int e = indiceEsquerda(i);
    int d = indiceDireita(i);
    int menor = i;

    if (e < tam && V[e] < V[i]) {
        menor = e;
    }
    if (d < tam && V[d] < V[menor]) {
        menor = d;
    }
    if (menor != i) {
        // Troca V[i] com V[menor]
        int temp = V[i];
        V[i] = V[menor];
        V[menor] = temp;
        // Chama recursivamente para corrigir o sub-heap
        arrumaVal(menor);
    }
}

//Insertion para Min-Heap
void insertionMin(int k) {
    if (tam == M) {
        printf("overflow\n");
        return;
    }

    tam++;
    int i = tam - 1;
    V[i] = k;

    while (i != 0 && V[(i - 1) / 2] > V[i]) {
        temp = V[(i - 1) / 2];
        V[(i - 1) / 2] = V[i];
        V[i] = temp;
        i = (i - 1) / 2;
    }
}

//Remove para Min-Heap
int removeMin() {
    if (tam <= 0) {
        return M;
    }
    if (tam == 1) {
        tam--;
        return V[0];
    }

    int root = V[0];
    V[0] = V[tam - 1];
    tam--;
    arrumaVal(0);

    return root;
}

//
// Funções para Max-Heap
//

//Insertion para Max-Heap
void insertionMax(int k) {
    if (tam == M) {
        printf("overflow\n");
        return;
    }

    tam++;
    int i = tam - 1;
    V[i] = k;

    while (i != 0 && V[(i - 1) / 2] < V[i]) {
        temp = V[(i - 1) / 2];
        V[(i - 1) / 2] = V[i];
        V[i] = temp;
        i = (i - 1) / 2;
    }
}

// forma interativa
void arrumaValMaxInterativa(int i) {
    while (true) {
        int e = indiceEsquerda(i);
        int d = indiceDireita(i);
        int maior = i;

        if (e < tam && V[e] > V[i]) {
            maior = e;
        }
        if (d < tam && V[d] > V[maior]) {
            maior = d;
        }
        
        if (maior != i) {
            // Troca V[i] com V[maior]
            int temp = V[i];
            V[i] = V[maior];
            V[maior] = temp;
            // Atualiza i para continuar ajustando o sub-heap
            i = maior;
        } else {
            break;
        }
    }
}

// forma recursiva
void arrumaValMax(int i) {
    int e = indiceEsquerda(i);
    int d = indiceDireita(i);
    int maior = i;

    if (e < tam && V[e] > V[i]) {
        maior = e;
    }
    if (d < tam && V[d] > V[maior]) {
        maior = d;
    }
    if (maior != i) {
        // Troca V[i] com V[maior]
        int temp = V[i];
        V[i] = V[maior];
        V[maior] = temp;
        // Chama recursivamente para corrigir o sub-heap
        arrumaValMax(maior);
    }
}

//Remove para Max-Heap
int removeMax() {
    if (tam <= 0) {
        return -1;
    }
    if (tam == 1) {
        tam--;
        return V[0];
    }

    int root = V[0];
    V[0] = V[tam - 1];
    tam--;
    arrumaValMax(0);

    return root;
}


void exibirHeap() {
    printf("Valores na arvore: \n");
    for (int i = 0; i < tam; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
}

int main() {
    int opcao, k;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir valor na Min-Heap\n");
        printf("2. Remover menor valor da Min-Heap\n");
        printf("3. Exibir Min-Heap\n");
        printf("4. Inserir valor na Max-Heap\n");
        printf("5. Remover maior valor da Max-Heap\n");
        printf("6. Exibir Max-Heap\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &k);
                insertionMin(k);
                break;
            case 2:
                k = removeMin();
                if (k != M) {
                    printf("Menor valor removido: %d\n", k);
                } else {
                    printf("Heap está vazio, não há valor para remover.\n");
                }
                break;
            case 3:
                exibirHeap();
                break;
            case 4:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &k);
                insertionMax(k);
                break;
            case 5:
                k = removeMax();
                if (k != -1) {
                    printf("Maior valor removido: %d\n", k);
                } else {
                    printf("Heap está vazio, não há valor para remover.\n");
                }
                break;
            case 6:
                exibirHeap();
                break;
            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 7);

    return 0;
}