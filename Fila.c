#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Node
{
    int num;
    struct Node* prox;
};
typedef struct Node node;

//Prot�tipos
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
        puts("\nN�o h� mem�ria suficiente!");
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
    puts("\n\t\t\tEscolha uma das op��es abaixo:\n");
    puts("0 - Sair.");
    puts("1 - Exibir elementos.");
    puts("2 - Inserir elementos no in�cio da fila.");
    puts("3 - Inserir elementos no final da fila.");
    puts("4 - Remover primeiro elemento da fila.");
    puts("5 - Remover �ltimo elemento da fila.");
    puts("5 - Limpar a fila.");

    int resposta;  printf("\nOp��o: ");  scanf("%d", &resposta);
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
            novoComeco(Fila);
            break;
        case 3:
            novoFinal(Fila);
            break;
        case 4:
            removePrimeiro(Fila);
            break;
        case 5:
            removeUltimo(Fila);
            break;
        case 6:
            criaFila(Fila);
            break;
        default:
            puts("\nOp��o inv�lida! Verifique novamente as op��es apresentadas.");
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
        while(tmp != NULL)
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
        puts("\nA fila est� vazia!");
    }
}

void novoFinal(node* Fila)
{
    node* novoItem = (node*) malloc(sizeof(node));
    if(!novoItem)
    {
        puts("\nN�o h� mem�ria suficiente!");
        exit(1);
    }
    else
    {
        printf("\nInsira o n�mero: ");  scanf("%d", &novoItem->num);
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
        puts("\nA fila est� vazia!");
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
