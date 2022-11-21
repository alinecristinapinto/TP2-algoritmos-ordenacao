#include "quicksortSelecao.hpp"

void QuickSortSelecao::particionar(Registro registros[], int indiceInicial, int indiceFinal, int *indiceEsquerda, int *indiceDireita){
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

void QuickSortSelecao::ordenar(Registro registros[], int indiceInicial, int indiceFinal, int m){
    int indiceEsquerda, indiceDireita;

    if( (indiceFinal - indiceInicial + 1) <= m){
        Selecao::ordenarCrescente(registros, indiceInicial, indiceFinal);
        return;
    } 

    particionar(registros, indiceInicial, indiceFinal, &indiceEsquerda, &indiceDireita);

    if (indiceInicial < indiceDireita){
        ordenar(registros, indiceInicial, indiceDireita, m);
    }

    if (indiceEsquerda < indiceFinal){
        ordenar(registros, indiceEsquerda, indiceFinal, m);
    }
}

void QuickSortSelecao::ordenarCrescente(Registro registros[], int tamanho, int m){
    ordenar(registros, 0, (tamanho - 1), m);
}
