#include "quicksortSelecao.hpp"

void QuickSortSelecao::particionar(Registro registros[], int indiceInicial, int indiceFinal, int *indiceEsquerda, int *indiceDireita, Desempenho *desempenho){
    *indiceEsquerda = indiceInicial; 
    *indiceDireita = indiceFinal;

    Registro aux, pivo = registros[(*indiceEsquerda + *indiceDireita) / 2]; 
    (*desempenho).numeroAtribuicoes++;

    do {
        (*desempenho).numeroComparacoes++;
        while (pivo.chave > registros[*indiceEsquerda].chave){
            (*indiceEsquerda)++;
            (*desempenho).numeroComparacoes++;
        }

        (*desempenho).numeroComparacoes++;
        while (pivo.chave < registros[*indiceDireita].chave){
            (*indiceDireita)--;
            (*desempenho).numeroComparacoes++;
        }

        if (*indiceEsquerda <= *indiceDireita){
            aux = registros[*indiceEsquerda];
            registros[*indiceEsquerda] = registros[*indiceDireita];
            registros[*indiceDireita] = aux;
            (*desempenho).numeroAtribuicoes+= 3;
            
            (*indiceEsquerda)++;
            (*indiceDireita)--;
        }
    } while (*indiceEsquerda <= *indiceDireita);
}

void QuickSortSelecao::ordenar(Registro registros[], int indiceInicial, int indiceFinal, int m, Desempenho *desempenho){
    int indiceEsquerda, indiceDireita;

    if( (indiceFinal - indiceInicial + 1) <= m){
        Selecao::ordenarCrescente(registros, indiceInicial, indiceFinal, desempenho);
        return;
    } 

    particionar(registros, indiceInicial, indiceFinal, &indiceEsquerda, &indiceDireita, desempenho);

    if (indiceInicial < indiceDireita){
        ordenar(registros, indiceInicial, indiceDireita, m, desempenho);
    }

    if (indiceEsquerda < indiceFinal){
        ordenar(registros, indiceEsquerda, indiceFinal, m, desempenho);
    }
}

void QuickSortSelecao::ordenarCrescente(Registro registros[], int tamanho, int m, Desempenho *desempenho){
    ordenar(registros, 0, (tamanho - 1), m, desempenho);
}
