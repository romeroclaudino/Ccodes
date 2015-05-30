void bubbleSortIt(node* ListaI)
{
    if(!vazia(ListaI))
    {
        node* tmp = ListaI->prox;
        int* listaInt = (int*) malloc(sizeof(int) * tamanho);
        int index = 0;
        while(index != tamanho)
        {
            listaInt[index] = tmp->num;
            tmp = tmp->prox;
            index++;
        }

        int aux;
        for(int i = tamanho-1; i >= 1; i--)
        {
            for(int j = 0; j < i; j++)
            {
                if(listaInt[j] > listaInt[j+1])
                {
                    aux = listaInt[j];
                    listaInt[j] = listaInt[j+1];
                    listaInt[j+1] = aux;
                }
            }
        }

        index = 0;
        tmp = ListaI->prox;
        while(index != tamanho)
        {
            tmp->num = listaInt[index];
            tmp = tmp->prox;
            index++;
        }
    }
}