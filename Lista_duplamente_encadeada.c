#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Node
{
    int num;
    struct Node* prox;
    struct Node* ant;
};
typedef struct Node node;


//Protótipos
int obtemResposta(void);
void escolhe(node* ListaI, node* ListaF, int resposta);
void criaLista(node* ListaI, node* ListaF);
int vazia(node* ListaI);
void exibeLista(node* ListaI);
void esvaziaLista(node* ListaI);
void novoComeco(node* ListaI, node* ListaF);
void novoFinal(node* ListaI, node* ListaF);
void removePrimeiro(node* ListaI, node* ListaF);
void removeUltimo(node* ListaI, node* ListaF);
void novaPosicao(node* ListaI, node* ListaF);
void removePosicao(node* ListaI, node* ListaF);
void incrementaTamanho(void);
void decrementaTamanho(void);
void zeraTamanho(void);

int tamanho; //Variável criada para armazenar o comprimento da lista.
int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    node* ListaI = (node*) malloc(sizeof(node));
    node* ListaF = (node*) malloc(sizeof(node));

    if(!(ListaI && ListaF))
    {
        puts("\nNão há memória suficiente!");
        exit(1);
    }
    else
    {
        criaLista(ListaI, ListaF);
        int resposta;
        do
        {
            resposta = obtemResposta();
            escolhe(ListaI, ListaF, resposta);
        }while(resposta);
    }

    return 0;
}

int obtemResposta(void)
{
    int resposta;
    puts("\n\t\t\tEscolha uma das opções abaixo:\n");
    puts("0 - Sair.");
    puts("1 - Exibir a lista.");
    puts("2 - Adicionar item no início da lista.");
    puts("3 - Adicionar item no final da lista.");
    puts("4 - Remover o primeiro item da lista.");
    puts("5 - Remover o último item da lista.");
    puts("6 - Inserir em uma posição específica.");
    puts("7 - Remover em uma posição específica.");
    puts("8- Limpar a lista.");
    puts("9- Exibir a lista.");

    printf("\nOpção:  ");  scanf("%d", &resposta);
    return resposta;
}

void escolhe(node* ListaI, node* ListaF, int resposta)
{
    switch(resposta)
    {
        case 0:
            esvaziaLista(ListaI);
            break;
        case 1:
            exibeLista(ListaI);
            break;
        case 2:
            novoComeco(ListaI, ListaF);
            break;
        case 3:
            novoFinal(ListaI, ListaF);
            break;
        case 4:
            removePrimeiro(ListaI, ListaF);
            break;
        case 5:
            removeUltimo(ListaI, ListaF);
            break;
        case 6:
            novaPosicao(ListaI, ListaF);
            break;
        case 7:
            removePosicao(ListaI, ListaF);
            break;
        case 8:
            criaLista(ListaI, ListaF);
            break;
        default:
            puts("\nOpção inválida! Verifique novamente as opções apresentadas.");
    }
}

void criaLista(node* ListaI, node* ListaF)
{
    ListaI->prox = NULL;
    ListaI->ant = NULL;
    ListaF->prox = NULL;
    ListaF->ant = NULL;
}

int vazia(node* ListaI)
{
    if(ListaI->prox == NULL)
        return 1;
    else
        return 0;
}

void exibeLista(node* ListaI)
{
    if(vazia(ListaI))
        puts("\nA lista estão vazia!");
    else
    {
        node* tmp = ListaI->prox;    printf("\nElementos da lista: ");
        while(tmp != NULL)
        {
            printf("   %d", tmp->num);
            tmp = tmp->prox;
        }
        puts("");
    }
}

void esvaziaLista(node* ListaI)
{
    if(!vazia(ListaI))
    {
        node* tmp = ListaI->prox;
        while(tmp->prox!= NULL)
        {
            tmp = ListaI->prox;
            ListaI->prox = tmp->prox;
            free(tmp);
        }
        zeraTamanho();
    }
}

void novoComeco(node* ListaI, node* ListaF)
{
    node* novoItem = (node*) malloc(sizeof(node));
    if(!novoItem)
    {
        puts("\nNÃ£o há memória suficiente!");
        exit(1);
    }
    else
    {
        if(vazia(ListaI))
        {
            printf("\nInsira o número: ");    scanf("%d", &novoItem->num);
            ListaI->prox = novoItem;
            ListaF->prox = novoItem;
            incrementaTamanho();
        }
        else
        {
            printf("\nInsira o número: ");    scanf("%d", &novoItem->num);
            node* velhoComeco = ListaI->prox;
            ListaI->prox = novoItem;
            novoItem->prox = velhoComeco;
            velhoComeco->ant = novoItem;
            incrementaTamanho();
        }
    }
}

void novoFinal(node* ListaI, node* ListaF)
{
    node* novoItem = (node*) malloc(sizeof(node));
    if(!novoItem)
    {
        puts("\nNão há memória suficiente!");
        exit(1);
    }
    else
    {
        if(vazia(ListaI))
        {
            printf("\nInsira o número: ");    scanf("%d", &novoItem->num);
            ListaI->prox = novoItem;
            ListaF->prox = novoItem;
            incrementaTamanho();
        }
        else
        {
            printf("\nInsira o número: ");    scanf("%d", &novoItem->num);
            node* velhoFinal = ListaF->prox;
            ListaF->prox = novoItem;
            novoItem->ant = velhoFinal;
            velhoFinal->prox = novoItem;
            incrementaTamanho();
        }
    }
}

void removePrimeiro(node* ListaI, node* ListaF)
{
    if(!vazia(ListaI))
    {
        if(tamanho == 1)
        {
            node* tmp = ListaI->prox;
            criaLista(ListaI, ListaF);
            free(tmp);
            decrementaTamanho();
        }
        else
        {
            node* tmp = ListaI->prox;
            ListaI->prox = tmp->prox;
            ListaI->prox->ant = NULL;
            free(tmp);
            decrementaTamanho();
        }
    }
    else
        puts("\nA lista está vazia!");
}

void removeUltimo(node* ListaI, node* ListaF)
{
    if(!vazia(ListaI))
    {
        if(tamanho == 1)
        {
            node* tmp = ListaI->prox;
            criaLista(ListaI, ListaF);
            free(tmp);
            decrementaTamanho();
        }
        else
        {
            node* tmp = ListaF->prox;
            ListaF->prox = tmp->ant;
            ListaF->prox->prox = NULL;
            free(tmp);
            decrementaTamanho();

        }
    }
    else
        puts("\nA lista estão vazia!");
}

void novaPosicao(node* ListaI, node* ListaF)
{
    node* novoItem = (node*) malloc(sizeof(node));
    if(!novoItem)
    {
        puts("\nNão há memória suficiente!");
        exit(1);
    }
    else
    {
        int pivot = (int) tamanho / 2;
        int resposta;
        printf("\nInsira a posição: ");   scanf("%d", &resposta);

        if (resposta > tamanho || resposta < 0)
            puts("\nA lista não tem esse comprimento!");
        else
        {
            if (resposta == 0)
                novoComeco(ListaI, ListaF);
            else if(resposta == (tamanho-1) || resposta == tamanho)
                novoFinal(ListaI, ListaF);
            else if(resposta <= pivot)
            {
                printf("\nInsira o número: "); scanf("%d", &novoItem->num);

                int index = 0;
                node* tmp = ListaI->prox;
                while(resposta != index)
                {
                    tmp = tmp->prox;
                    index++;
                }
                novoItem->ant = tmp->ant;
                novoItem->prox = tmp; 
                tmp->ant->prox = novoItem;
                tmp->ant = novoItem;
                incrementaTamanho();
            }
            else
            {
                printf("\nInsira o número: "); scanf("%d", &novoItem->num);

                int index = (tamanho-1);
                node* tmp = ListaF->prox;
                while(resposta != index)
                {
                    tmp = tmp->ant;
                    index--;
                }
                novoItem->ant = tmp->ant;
                novoItem->prox = tmp;
                tmp->ant->prox = novoItem;
                tmp->ant = novoItem;
                incrementaTamanho();
            }
        }
    }
}

void removePosicao(node* ListaI, node* ListaF)
{
    if(!vazia(ListaI))
    {
        int pivot = (int) tamanho / 2;
        int resposta;
        printf("\nInsira a posição: ");   scanf("%d", &resposta);

        if (tamanho == 0 || resposta >= tamanho || resposta < 0)
            puts("\nA lista não tem esse comprimento!");
        else if(resposta == 0)
            removePrimeiro(ListaI, ListaF);
        else if(resposta == (tamanho-1))
                removeUltimo(ListaI, ListaF);
        else if (resposta <= pivot)
        {
            int index = 0;
            node* tmp = ListaI->prox;
            while(resposta != index)
            {
                tmp = tmp->prox;
                index++;
            }
            node* velhoItem = tmp;
            tmp = tmp->ant;
            tmp->prox = velhoItem->prox;
            velhoItem->prox->ant = tmp;
            free(velhoItem);
            decrementaTamanho();
        }
        else
        {
            int index = tamanho-1;
            node* tmp = ListaF->prox;
            while(resposta != index)
            {
                tmp = tmp->ant;
                index--;
            }
            node* velhoItem = tmp;
            tmp = tmp->ant;
            tmp->prox = velhoItem->prox;
            velhoItem->prox->ant = tmp;
            free(velhoItem);
            decrementaTamanho();

        }
    }
}

void incrementaTamanho(void)
{
    tamanho++;
}

void decrementaTamanho(void)
{
    tamanho--;
}

void zeraTamanho(void)
{
    tamanho = 0;
}
