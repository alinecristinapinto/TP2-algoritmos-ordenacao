#include "quicksort.hpp"

void QuickSort::particionar(Registro registros[], int indiceInicial, int indiceFinal, int *indiceEsquerda, int *indiceDireita, Desempenho *desempenho){
    *indiceEsquerda = indiceInicial; 
    *indiceDireita = indiceFinal;

    Registro aux, pivo = registros[(*indiceEsquerda + *indiceDireita) / 2]; 
    (*desempenho).numeroAtribuicoes++;

    do {
        (*desempenho).numeroComparacoes++; // primeira comparacao do while pra ver se percorre
        while (pivo.chave > registros[*indiceEsquerda].chave){
            (*indiceEsquerda)++;
            (*desempenho).numeroComparacoes++; // seguintes comparacoes a cada iteracao do laco
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
            (*desempenho).numeroAtribuicoes += 3;

            (*indiceEsquerda)++;
            (*indiceDireita)--;
        }
    } while (*indiceEsquerda <= *indiceDireita);
}

void QuickSort::ordenar(Registro registros[], int indiceInicial, int indiceFinal, Desempenho *desempenho){
    int indiceEsquerda, indiceDireita;

    particionar(registros, indiceInicial, indiceFinal, &indiceEsquerda, &indiceDireita, desempenho);

    if (indiceInicial < indiceDireita){
        ordenar(registros, indiceInicial, indiceDireita, desempenho);
    }

    if (indiceEsquerda < indiceFinal){
        ordenar(registros, indiceEsquerda, indiceFinal, desempenho);
    }
}

void QuickSort::ordenarCrescente(Registro registros[], int tamanho, Desempenho *desempenho){
    ordenar(registros, 0, (tamanho - 1), desempenho);
}
