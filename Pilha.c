#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Node
{
    int num;
    struct Node* prox;
};
typedef struct Node node;

////Protótipos
int obtemResposta(void);
void escolhe(int resposta, node* Pilha);
int vazia(node* Pilha);
void criaPilha(node* Pilha);
void limpaPilha(node* Pilha);
void exibePilha(node* Pilha);
void insereItem(node* Pilha);
void removeItem(node* Pilha);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    node* Pilha = (node*) malloc(sizeof(node));

    if(!Pilha)
    {
        puts("Não há memória suficiente!");
        exit(1);
    }
    else
    {
        criaPilha(Pilha);
        int resposta;
        do
        {
            resposta = obtemResposta();
            escolhe(resposta, Pilha);
        }while(resposta);
    }
    free(Pilha);
    return 0;
}

int obtemResposta()
{
    puts("\n\t\t\tEscolha uma das opções abaixo:\n");
    puts("0 - Sair.");
    puts("1 - Exibir elementos.");
    puts("2 - Inserir elementos.");
    puts("3 - Remover elementos.");
    puts("4 - Limpar Pilha");

    int resposta; printf("\nOpção: "); scanf("%d", &resposta);
    return resposta;
}

void escolhe(int resposta, node* Pilha)
{
    switch(resposta)
    {
        case 0:
            limpaPilha(Pilha);
            break;
        case 1:
            exibePilha(Pilha);
            break;
        case 2:
            insereItem(Pilha);
            break;
        case 3:
            removeItem(Pilha);
            break;
        case 4:
            criaPilha(Pilha);
            break;
        default:
            puts("\nOpção inválida! Verifique novamente as opções apresentadas.");
    }

}

int vazia(node* Pilha)
{
    if(Pilha->prox == NULL)
        return 1;
    else
        return 0;
}

void criaPilha(node* Pilha)
{
    Pilha->prox = NULL;
}

void limpaPilha(node* Pilha)
{
    if(!vazia(Pilha))
    {
        node* tmp = Pilha->prox;
        while(tmp->prox != NULL)
        {
            tmp = Pilha->prox;
            Pilha->prox = tmp->prox;
            free(tmp);
        }
    }
}

void exibePilha(node* Pilha)
{
    if(!vazia(Pilha))
    {
        node* tmp = Pilha->prox;  printf("\nItens da lista: ");
        while(tmp != NULL)
        {
            printf("%d ", tmp->num);
            tmp = tmp->prox;
        }
        puts("");
    }
    else
        puts("\nA Pilha está vazia!");
}

void insereItem(node* Pilha)
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
        node* velhoComeco = Pilha->prox;
        Pilha->prox = novoItem;
        novoItem->prox = velhoComeco;
    }
}

void removeItem(node* Pilha)
{
    if(!vazia(Pilha))
    {
        node* tmp = Pilha->prox;
        Pilha->prox = tmp->prox;
        free(tmp);
    }
    else
        puts("\nA Pilha está vazia!");
}
