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
void criaLista(node* Lista);
int obtemResposta(void);
void escolhe(node* Lista, int resposta);
void exibeLista(node* Lista);
int vazia(node* Lista);
void esvaziaLista(node* Lista);
void novoComeco(node* Lista);
void novoFinal(node* Lista);
void removeUltimo(node* Lista);
void removePrimeiro(node* Lista);
void novaPosicao(node* Lista);
void removePosicao(node* Lista);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    node* Lista = (node*) malloc(sizeof(node));

    if(!Lista)
    {
        puts("Não há memória suficiente!");
        exit(1);
    }
    else
    {
        criaLista(Lista);
        int resposta;
        do
        {
            resposta = obtemResposta();
            escolhe(Lista, resposta);
        }while(resposta);
        free(Lista);
    }
    return 0;
}

void criaLista(node* Lista)
{
    Lista->prox = NULL;
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

    printf("\nOpção:  ");  scanf("%d", &resposta);
    return resposta;
}

void escolhe(node* Lista, int resposta)
{
    switch(resposta)
    {
        case 0:
            esvaziaLista(Lista);
            break;
        case 1:
            exibeLista(Lista);
            break;
        case 2:
            novoComeco(Lista);
            break;
        case 3:
            novoFinal(Lista);
            break;
        case 4:
            removePrimeiro(Lista);
            break;
        case 5:
            removeUltimo(Lista);
            break;
        case 6:
            novaPosicao(Lista);
            break;
        case 7:
            removePosicao(Lista);
            break;
        case 8:
            criaLista(Lista);
            break;
        default:
            puts("\nOpção inválida! Verifique novamente as opções apresentadas.");
    }
}

void exibeLista(node* Lista)
{
    if(vazia(Lista))
        puts("\nA lista está vazia!");
    else
    {
        node* tmp;
        tmp = Lista->prox;  printf("\nItens da lista: ");
        while(tmp != NULL)
        {
            printf("  %d", tmp->num);
            tmp = tmp->prox;
        }
        puts("");
    }
}

int vazia(node* Lista)
{
    if(Lista->prox == NULL)
        return 1;
    else
        return 0;
}

void esvaziaLista(node* Lista)
{
    if(!vazia(Lista))
    {
        node* tmp = Lista->prox;
        while(tmp->prox != NULL)
        {
            tmp = Lista->prox;
            Lista->prox = tmp->prox;
            free(tmp);
        }
    }
}

void novoComeco(node* Lista)
{
    node* novoItem = (node* ) malloc(sizeof(node));
    if(!novoItem)
    {
        puts("\nNão há memória suficiente!");
        exit(1);
    }
    else
    {
        printf("\nInsira o número: ");  scanf("%d", &novoItem->num);
        node* velhoComeco = Lista->prox;
        Lista->prox = novoItem;
        novoItem->prox = velhoComeco;
    }
}

void novoFinal(node* Lista)
{
    node* novoItem = (node* ) malloc(sizeof(node));
    if(!novoItem)
    {
        puts("\nNão há memória suficiente!");
        exit(1);
    }
    else
    {
        printf("\nInsira o número: ");  scanf("%d", &novoItem->num);
        novoItem->prox = NULL;
        if(vazia(Lista))
            Lista->prox = novoItem;
        else
        {
            node* tmp = Lista->prox;
            while(tmp->prox != NULL)
                tmp = tmp->prox;

            tmp->prox = novoItem;
        }
    }
}

void removeUltimo(node* Lista)
{
    if(vazia(Lista))
        puts("\nA lista está vazia!");
    else
    {
        node* tmp = Lista->prox;
        node* tmp2 = tmp->prox;
        while(tmp2->prox != NULL)
        {
            tmp = tmp->prox;
            tmp2 = tmp->prox;
        }
        tmp->prox = NULL;
        free(tmp2);
    }
}

void removePrimeiro(node* Lista)
{
    if(vazia(Lista))
        puts("\nA lista está vazia!");
    else
    {
        node* tmp = Lista->prox;
        Lista->prox = tmp->prox;
        free(tmp);
    }
}

void novaPosicao(node* Lista)
{
    if(vazia(Lista))
        puts("\nA lista está vazia! Adicione um item usando as outras opções antes.");
    else
    {
        node* tmp = (node*)malloc(sizeof(node));
        if(!tmp)
        {
            puts("\nNão há memória suficiente!");
            exit(1);
        }
        else
        {
            node* tmp = Lista->prox;
            int indice = 0, resposta;

            while(tmp->prox != NULL)
            {
                tmp = tmp->prox;
                indice++;
            }

            printf("\nInsira a posição: "); scanf("%d", &resposta);

            if(resposta > indice || resposta < 0)
                puts("\nA lista não tem esse comprimento!");
            else
            {
                if(resposta == 0)
                    novoComeco(Lista);
                else
                {
                    indice = 0;
                    node* novoItem = (node*) malloc(sizeof(node));  printf("\nInsira o número: "); scanf("%d", &novoItem->num);

                    node* atual = Lista->prox;
                    node* anterior = Lista;
                    while(indice < resposta)
                    {
                        anterior = atual;
                        atual = atual->prox;
                        indice++;
                    }
                    anterior->prox = novoItem;
                    novoItem->prox = atual;
                }
            }
        }
    }
}


void removePosicao(node* Lista)
{
    if(vazia(Lista))
        puts("\nA lista está vazia! Adicione um item usando as outras opções antes.");
    else
    {
        node* tmp = (node*)malloc(sizeof(node));
        if(!tmp)
        {
            puts("\nNão há memória suficiente!");
            exit(1);
        }
        else
        {
            node* tmp = Lista->prox;
            int indice = 0, resposta;

            while(tmp->prox != NULL)
            {
                tmp = tmp->prox;
                indice++;
            }

            printf("\nInsira a posição: "); scanf("%d", &resposta);

            if(resposta > indice || resposta < 0)
                puts("\nA lista não tem esse comprimento!");
            else
            {
                if(resposta == 0)
                    removePrimeiro(Lista);
                else
                {
                    indice = 0;

                    node* atual = Lista->prox;
                    node* anterior = Lista;
                    while(indice < resposta)
                    {
                        anterior = atual;
                        atual = atual->prox;
                        indice++;
                    }
                    anterior->prox = atual->prox;
                }
            }
        }
    }
}
