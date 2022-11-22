#include "heapsort.hpp"

void HeapSort::trocar(Registro* vetor1, Registro* vetor2){
    Registro aux = *vetor1;
    *vetor1 = *vetor2;
    *vetor2 = aux;
}

void HeapSort::empilharHeap(Registro registros[], int tamanho, int indiceAtual){
    int indicePai = indiceAtual;
    int indiceEsquerda = 2 * indiceAtual + 1;
    int indiceDireta = 2 * indiceAtual + 2;
 
    if (indiceEsquerda < tamanho && registros[indiceEsquerda].chave > registros[indicePai].chave){
        indicePai = indiceEsquerda;
    }

    if (indiceDireta < tamanho && registros[indiceDireta].chave > registros[indicePai].chave){
        indicePai = indiceDireta;
    }

    if (indicePai != indiceAtual) {
        trocar(&registros[indiceAtual], &registros[indicePai]);
        empilharHeap(registros, tamanho, indicePai);
    }
}

void HeapSort::ordenarCrescente(Registro registros[], int tamanho){
    for (int i = (tamanho / 2 - 1); i >= 0; i--){
        empilharHeap(registros, tamanho, i);
    }
 
    for (int i = (tamanho - 1); i > 0; i--) {
        trocar(&(registros[0]), &(registros[i]));
        empilharHeap(registros, i, 0);
    }
}

