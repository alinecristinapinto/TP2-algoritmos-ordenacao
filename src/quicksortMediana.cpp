#include "quicksortMediana.hpp"

Registro QuickSortMediana::buscarPivo(Registro registros[], int indiceInicial, int indiceFinal, int k){
    if(k >= (indiceFinal - indiceInicial + 1)) return registros[indiceInicial];

    Registro* medianas = new Registro[k];

    for(int i=0; i < k; i++){
        int indiceAleatorio = GeradorDados::gerarInteiroAleatorioEmIntervalo(indiceInicial, indiceFinal);
        medianas[i] = registros[indiceAleatorio];
    } 

    Selecao::ordenarCrescente(medianas, 0, k - 1);
    
    int indiceMediana = std::floor(k / 2.0); 
    Registro pivo = medianas[indiceMediana];

    delete [] medianas;
    return pivo;
}

void QuickSortMediana::particionar(Registro registros[], int indiceInicial, int indiceFinal, int k, int *indiceEsquerda, int *indiceDireita){
    *indiceEsquerda = indiceInicial; 
    *indiceDireita = indiceFinal;

    Registro pivo = buscarPivo(registros, indiceInicial, indiceFinal, k);
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

void QuickSortMediana::ordenar(Registro registros[], int indiceInicial, int indiceFinal, int k){
    int indiceEsquerda, indiceDireita;

    particionar(registros, indiceInicial, indiceFinal, k, &indiceEsquerda, &indiceDireita);

    if (indiceInicial < indiceDireita){
        ordenar(registros, indiceInicial, indiceDireita, k);
    }

    if (indiceEsquerda < indiceFinal){
        ordenar(registros, indiceEsquerda, indiceFinal, k);
    }
}

void QuickSortMediana::ordenarCrescente(Registro registros[], int tamanho, int k){
    ordenar(registros, 0, (tamanho - 1), k);
}
