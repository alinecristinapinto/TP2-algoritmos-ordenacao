#include "heapsort.hpp"

void HeapSort::trocar(Registro* vetor1, Registro* vetor2, Desempenho *desempenho){
    Registro aux = *vetor1;
    *vetor1 = *vetor2;
    *vetor2 = aux;

    desempenho->numeroAtribuicoes += 3;
}

void HeapSort::empilharHeap(Registro registros[], int tamanho, int indiceAtual, Desempenho *desempenho){
    int indicePai = indiceAtual;
    int indiceEsquerda = 2 * indiceAtual + 1;
    int indiceDireta = 2 * indiceAtual + 2;
 
    desempenho->numeroComparacoes++;
    if (indiceEsquerda < tamanho && registros[indiceEsquerda].chave > registros[indicePai].chave){
        indicePai = indiceEsquerda;
    }

    desempenho->numeroComparacoes++;
    if (indiceDireta < tamanho && registros[indiceDireta].chave > registros[indicePai].chave){
        indicePai = indiceDireta;
    }

    if (indicePai != indiceAtual) {
        trocar(&registros[indiceAtual], &registros[indicePai], desempenho);
        empilharHeap(registros, tamanho, indicePai, desempenho);
    }
}

void HeapSort::ordenarCrescente(Registro registros[], int tamanho, Desempenho *desempenho){
    for (int i = (tamanho / 2 - 1); i >= 0; i--){
        empilharHeap(registros, tamanho, i, desempenho);
    }
 
    for (int i = (tamanho - 1); i > 0; i--) {
        trocar(&(registros[0]), &(registros[i]), desempenho);
        empilharHeap(registros, i, 0, desempenho);
    }
}

