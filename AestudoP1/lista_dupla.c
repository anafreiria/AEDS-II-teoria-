#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no_
{
    int chave;
    int valor;
    struct no_ *ant;
    struct no_ *prox;
} no;

// Função de busca
no *buscar(no *ptlista, int x)
{
    no *ultimo = ptlista->ant; // Último nó da lista (pois é circular)

    // Se a lista não estiver vazia e a chave procurada estiver na lista
    if (ultimo != ptlista && x <= ultimo->chave)
    {
        no *pont = ptlista->prox; // Começa do primeiro nó após o nó cabeça
        while (pont->chave < x)
        {
            pont = pont->prox; // Avança até encontrar ou passar a chave
        }
        return pont; // Retorna o nó encontrado
    }
    return ptlista; // Se a lista estiver vazia ou x maior que o último, retorna nó cabeça
}

// Função de inserção
no *inserir(no *ptlista, no *novo_no)
{
    no *pont = buscar(ptlista, novo_no->chave); // Busca posição de inserção

    if (pont == ptlista || pont->chave != novo_no->chave)
    {
        // Ajusta os ponteiros para inserir o novo nó
        novo_no->prox = pont;
        novo_no->ant = pont->ant;
        pont->ant->prox = novo_no;
        pont->ant = novo_no;
        return NULL; // Sucesso
    }

    return pont; // Retorna o nó se a chave já existir (não insere duplicado)
}

// Função de remoção
no *remover(no *ptlista, int x)
{
    no *pont = buscar(ptlista, x); // Busca o nó a ser removido

    if (pont->chave == x && pont != ptlista)
    {
        // Ajusta os ponteiros para remover o nó
        pont->ant->prox = pont->prox;
        pont->prox->ant = pont->ant;
        return pont; // Retorna o nó removido
    }

    return NULL; // Se não encontrar, retorna NULL
}

// Função para criar um nó novo
no *criar_no(int chave, int valor)
{
    no *novo = (no *)malloc(sizeof(no));
    if (novo != NULL)
    {
        novo->chave = chave;
        novo->valor = valor;
        novo->prox = novo->ant = NULL;
    }
    return novo;
}

// Função para inicializar a lista (cabeça)
no *inicializar_lista()
{
    no *cabeca = (no *)malloc(sizeof(no));
    if (cabeca != NULL)
    {
        cabeca->prox = cabeca;
        cabeca->ant = cabeca;
        cabeca->chave = -1; // Chave da cabeça é fictícia
    }
    return cabeca;
}

// Função para imprimir a lista
void imprimir_lista(no *ptlista)
{
    no *pont = ptlista->prox;
    printf("Lista: ");
    while (pont != ptlista)
    {
        printf("(Chave: %d, Valor: %d) ", pont->chave, pont->valor);
        pont = pont->prox;
    }
    printf("\n");
}

// Função para buscar e exibir o resultado
void buscar_elemento(no *ptlista, int chave)
{
    no *pont = buscar(ptlista, chave);

    if (pont != ptlista && pont->chave == chave)
    {
        printf("Elemento encontrado: Chave: %d, Valor: %d\n", pont->chave, pont->valor);
    }
    else
    {
        printf("Elemento com chave %d não encontrado.\n", chave);
    }
}

// Função principal (main) para testar as operações
int main()
{
    no *lista = inicializar_lista();
    int opcao, chave, valor;
    no *resultado;

    do
    {
        printf("\nMenu:\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Exibir lista\n");
        printf("4. Buscar elemento\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                printf("Digite a chave e o valor do novo elemento: ");
                scanf("%d %d", &chave, &valor);
                no *novo_no = criar_no(chave, valor);
                if (inserir(lista, novo_no) == NULL)
                {
                    printf("Elemento inserido com sucesso!\n");
                }
                else
                {
                    printf("Elemento com chave %d já existe!\n", chave);
                    free(novo_no); // Libera a memória se a inserção falhar
                }
                break;

            case 2:
                printf("Digite a chave do elemento a ser removido: ");
                scanf("%d", &chave);
                resultado = remover(lista, chave);
                if (resultado != NULL)
                {
                    printf("Elemento removido: Chave: %d, Valor: %d\n", resultado->chave, resultado->valor);
                    free(resultado); // Libera a memória do nó removido
                }
                else
                {
                    printf("Elemento não encontrado!\n");
                }
                break;

            case 3:
                imprimir_lista(lista);
                break;

            case 4:
                printf("Digite a chave do elemento a ser buscado: ");
                scanf("%d", &chave);
                buscar_elemento(lista, chave);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
