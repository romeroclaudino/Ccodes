#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Node
{
	int num;
	struct Node* ant;
	struct Node* prox;
};
typedef struct Node node;


//Protótipos
int obtemResposta(void);
void escolhe(node* ListaI, int resposta);
void criaLista(node* ListaI);
int vazia(node* ListaI);
void exibeLista(node* ListaI);
void esvaziaLista(node* ListaI);
void novoComeco(node* ListaI);
void novoFinal(node* ListaI);
void removePrimeiro(node* ListaI);
void removeUltimo(node* ListaI);
void insere(node* ListaI);
void removee(node* ListaI);
void incrementaTamanho(void);
void decrementaTamanho(void);
void zeraTamanho(void);

int tamanho; //Variável criada para armazenar o comprimento da lista.
int main(void)
{
    setlocale(LC_ALL, "Portuguese");    
	node* ListaI = (node*) malloc(sizeof(node));

	if(!(ListaI))
    {
        puts("\nNão há memória suficiente!");
        exit(1);
    }
    else
    {
        criaLista(ListaI);
        int resposta;
        do
        {   resposta = obtemResposta();
            escolhe(ListaI, resposta);
        }while(resposta);
    }
	return 0;
}


int obtemResposta(void)
{
    int resposta;
    printf("%d<--Tamanho\n", tamanho);
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

    printf("\nOpção:  ");  scanf("%d", &resposta);
    return resposta;
}

void escolhe(node* ListaI, int resposta)
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
            novoComeco(ListaI);
            break;
        case 3:
            novoFinal(ListaI);
            break;
        case 4:
            removePrimeiro(ListaI);
            break;
        case 5:
            removeUltimo(ListaI);
            break;
        case 6:
            insere(ListaI);
            break;
        case 7:
            removee(ListaI);
            break;
        case 8:
            criaLista(ListaI);
            break;
        default:
            puts("\nOpção inválida! Verifique novamente as opções apresentadas.");
    }
}

void criaLista(node* ListaI)
{
    ListaI->prox = NULL;
    ListaI->ant = NULL;
    zeraTamanho();
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
        puts("\nA lista está vazia!");
    else
    {
        node* tmp = ListaI->prox;    printf("\nElementos da lista: ");
        int tamanhoAux = tamanho;
        while(tamanhoAux)
        {
            printf("   %d", tmp->num);
            tmp = tmp->prox;
            tamanhoAux--;
        }
        puts("");
    }
}

void esvaziaLista(node* ListaI)
{
    if(!vazia(ListaI))
    {
        node* tmp;
        do
        {
            tmp = ListaI->prox;
            ListaI->prox = tmp->prox;
            free(tmp);
        }while(tmp->prox != ListaI->prox);
        zeraTamanho();
    }
}

void novoComeco(node* ListaI)
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
        if(vazia(ListaI))
        {
            ListaI->prox = novoItem;
            novoItem->ant = novoItem;
            novoItem->prox = novoItem;
            incrementaTamanho();
        }
        else
        {
            node* velhoComeco = ListaI->prox;
            novoItem->ant = velhoComeco->ant;
            novoItem->prox = velhoComeco;
            velhoComeco->ant->prox = novoItem;
            velhoComeco->ant = novoItem;
            ListaI->prox = novoItem;
            incrementaTamanho();
        }
    }
}

void novoFinal(node* ListaI)
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
        if(vazia(ListaI))
        {
            ListaI->prox = novoItem;
            novoItem->ant = novoItem;
            novoItem->prox = novoItem;
            incrementaTamanho();
        }
        else
        {
            node* velhoFinal = ListaI->prox->ant;
            novoItem->ant = velhoFinal;
            novoItem->prox = ListaI->prox;
            ListaI->prox->ant = novoItem;
            velhoFinal->prox = novoItem;
            incrementaTamanho();
        }
    }
}

void removePrimeiro(node* ListaI)
{
    if(!vazia(ListaI))
    {
        if(tamanho == 1)
        {
            node* tmp = ListaI->prox;
            criaLista(ListaI);
            free(tmp);
            decrementaTamanho();
        }
        else
        {
            node* tmp = ListaI->prox;
            ListaI->prox = tmp->prox;
            tmp->prox->ant = tmp->ant;
            tmp->ant->prox = tmp->prox;
            free(tmp);
            decrementaTamanho();            
        }
    }
    else
        puts("\nA lista está vazia!");
}

void removeUltimo(node* ListaI)
{
    if(!vazia(ListaI))
    {
        if (tamanho == 1)
        {
            node* tmp = ListaI->prox;
            criaLista(ListaI);
            free(tmp);
            decrementaTamanho();
        }
        else
        {
            node* tmp = ListaI->prox->ant;
            ListaI->prox->ant = tmp->ant;
            tmp->ant->prox = ListaI->prox;
            free(tmp);
            decrementaTamanho();
        }
    }
    else
        puts("\nA lista estão vazia!");
}

void insere(node* ListaI)
{
    node* novoItem = (node*) malloc(sizeof(node));
    if(!novoItem)
    {
        puts("\n Não há memória suficiente!");
        exit(1);
    }
    else
    {
        if(vazia(ListaI))
            novoComeco(ListaI);
        else
        {
            int resposta;
            printf("\nInsira a posição: ");  scanf("%d", &resposta);
            if(resposta > tamanho || resposta < 0)
                puts("\nA lista não tem esse comprimento!");
            else
            {
                int index = 0;
                node* tmp = ListaI->prox;
                while(resposta != index)
                {
                    tmp = tmp->prox;
                    index++;
                }
                node* velhoItem = tmp;
                novoItem->ant = tmp->ant;
                novoItem->prox = tmp;
                tmp->ant->prox = novoItem;
                tmp->ant = novoItem;
                incrementaTamanho();
            }
        }
    }
}

void removee(node* ListaI)
{
    if(vazia(ListaI))
        puts("\nA lista está vazia!");
    else
    {
        int resposta;
        printf("\nInsira a posição: ");  scanf("%d", &resposta);
        if(resposta > tamanho || resposta < 0)
            puts("A lista não tem esse comprimento!");
        else
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