#include "quicksort.hpp"

void QuickSort::particionar(Registro registros[], int indiceInicial, int indiceFinal, int *indiceEsquerda, int *indiceDireita){
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

void QuickSort::ordenar(Registro registros[], int indiceInicial, int indiceFinal){
    int indiceEsquerda, indiceDireita;

    particionar(registros, indiceInicial, indiceFinal, &indiceEsquerda, &indiceDireita);

    if (indiceInicial < indiceDireita){
        ordenar(registros, indiceInicial, indiceDireita);
    }

    if (indiceEsquerda < indiceFinal){
        ordenar(registros, indiceEsquerda, indiceFinal);
    }
}

void QuickSort::ordenarCrescente(Registro registros[], int tamanho){
    ordenar(registros, 0, (tamanho - 1));
}
