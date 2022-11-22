#include "quicksortEmpilhaInteligente.hpp"

void QuickSortEmpilhaInteligente::particionar(Registro registros[], int indiceInicial, int indiceFinal, int *indiceEsquerda, int *indiceDireita){
    *indiceEsquerda = indiceInicial; 
    *indiceDireita = indiceFinal;

    Registro pivo = registros[(*indiceEsquerda + *indiceDireita) / 2]; 
    Registro aux;

    do {
        while (pivo.chave > registros[*indiceEsquerda].chave){
            (*indiceEsquerda)++;
        }
        while (pivo.chave < registros[*indiceDireita].chave){
            (*indiceDireita)--;
        }

        if (*indiceEsquerda <= *indiceDireita){
            aux = registros[*indiceEsquerda];
            registros[*indiceEsquerda] = registros[*indiceDireita];
            registros[*indiceDireita] = aux;
            (*indiceEsquerda)++;
            (*indiceDireita)--;
        }
    } while (*indiceEsquerda <= *indiceDireita);
}

void QuickSortEmpilhaInteligente::ordenarCrescente(Registro registros[], int tamanho){
    Intervalo indices; 
    Pilha pilha = Pilha();
    pilha.empilhar(0, (tamanho - 1));

    int indiceInicial = 0;
    int indiceFinal = tamanho - 1;
    int indiceEsquerda = 0;
    int indiceDireita = 0;

    do{
        if(indiceFinal > indiceInicial){
            particionar(registros, indiceInicial, indiceFinal, &indiceEsquerda, &indiceDireita);

            if((indiceDireita - indiceInicial) > (indiceFinal - indiceEsquerda)){
                pilha.empilhar(indiceInicial, indiceDireita);
                indiceInicial = indiceEsquerda;
            } else {
                pilha.empilhar(indiceEsquerda, indiceFinal);
                indiceFinal = indiceDireita;
            }
        } else {
            indices = pilha.desempilhar();
            indiceFinal = indices.fim;
            indiceInicial = indices.inicio;
        }
    } while (!pilha.vazia());
}
