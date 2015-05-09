#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Node
{
    int num;
    struct Node* prox;
};
typedef struct Node node;

//Protótipos
int obtemResposta(void);
void escolhe(int resposta, node* Fila);
int vazia(node* Fila);
void criaFila(node* Fila);
void limpaFila(node* Fila);
void exibeFila(node* Fila);
void novoFinal(node* Fila);
void removePrimeiro(node* Fila);
int contador(node* Fila);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    node* Fila = (node*) malloc(sizeof(node));

    if(!Fila)
    {
        puts("\nNão há memória suficiente!");
        exit(1);
    }
    else
    {
        criaFila(Fila);
        int resposta;
        do
        {
            resposta = obtemResposta();
            escolhe(resposta, Fila);
        }while(resposta);
    }
    free(Fila);
    return 0;
}

int obtemResposta()
{
    puts("\n\t\t\tEscolha uma das opções abaixo:\n");
    puts("0 - Sair.");
    puts("1 - Exibir elementos.");
    puts("2 - Inserir elemento na fila.");
    puts("3 - Remover elemento na fila.");
    puts("4 - Limpar a fila.");

    int resposta;  printf("\nOpção: ");  scanf("%d", &resposta);
    return resposta;
}

void escolhe(int resposta, node* Fila)
{
    switch(resposta)
    {
        case 0:
            limpaFila(Fila);
            break;
        case 1:
            exibeFila(Fila);
            break;
        case 2:
            novoFinal(Fila);
            break;
        case 3:
            removePrimeiro(Fila);
            break;
        case 4:
            criaFila(Fila);
            break;
        default:
            puts("\nOpção inválida! Verifique novamente as opções apresentadas.");
    }
}

int vazia(node* Fila)
{
    if(Fila->prox == NULL)
        return 1;
    else
        return 0;
}

void criaFila(node* Fila)
{
    Fila->prox = NULL;
}

void limpaFila(node* Fila)
{
    if(!vazia(Fila))
    {
        node* tmp = Fila->prox;
        while(tmp->prox != NULL)
        {
            tmp = Fila->prox;
            Fila->prox = tmp->prox;
            free(tmp);
        }
    }
}

void exibeFila(node* Fila)
{
    if(!vazia(Fila))
    {
        node* tmp = Fila->prox;  printf("\nElementos da fila: ");
        while(tmp != NULL)
        {
            printf("%d ", tmp->num);
            tmp = tmp->prox;
        }
        puts("");
    }
    else
    {
        puts("\nA fila está vazia!");
    }
}

void novoFinal(node* Fila)
{
    node* novoItem = (node*) malloc(sizeof(node));
    if(!novoItem)
    {
        puts("\nNão há memória suficiente!");
        exit(1);
    }
    else
    {
        printf("\nInsira o número: ");  scanf("%d", &novoItem->num);
        if(vazia(Fila))
            Fila->prox = novoItem;
        else
        {
            node* tmp = Fila->prox;
            while(tmp->prox != NULL)
                tmp = tmp->prox;
            tmp->prox = novoItem;
        }
    }
}

void removePrimeiro(node* Fila)
{
    if(vazia(Fila))
        puts("\nA fila está vazia!");
    else
    {
        node* tmp = Fila->prox;
        Fila->prox = tmp->prox;
        free(tmp);
    }
}

int contador(node* Fila)
{
    int index = 0;
    node* tmp = Fila->prox;
    while(tmp->prox != NULL)
    {
        tmp = tmp->prox;
        index++;
    }
    return index;
}
