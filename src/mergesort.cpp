#include "mergesort.hpp"

void MergeSort::merge(Registro registros[], int const indiceEsquerda, int const indiceMeio, int const indiceDireita){
    int const tamanhoVetorEsquerda = indiceMeio - indiceEsquerda + 1;
    int const tamanhoVetorDireita = indiceDireita - indiceMeio;

    Registro *vetorEsquerda = new Registro[tamanhoVetorEsquerda];
    Registro *vetorDireita = new Registro[tamanhoVetorDireita];

    for (int i = 0; i < tamanhoVetorEsquerda; i++){
        vetorEsquerda[i] = registros[indiceEsquerda + i];
    }
       
    for (int j = 0; j < tamanhoVetorDireita; j++){
        vetorDireita[j] = registros[indiceMeio + 1 + j];
    }

    int indiceVetorEsquerda = 0, indiceVetorDireita = 0;
    int indiceVetorMergeado = indiceEsquerda; 
 
    while (indiceVetorEsquerda < tamanhoVetorEsquerda && indiceVetorDireita < tamanhoVetorDireita) {
        if (vetorEsquerda[indiceVetorEsquerda].chave <= vetorDireita[indiceVetorDireita].chave) {
            registros[indiceVetorMergeado] = vetorEsquerda[indiceVetorEsquerda];
            indiceVetorEsquerda++;
        }
        else {
            registros[indiceVetorMergeado] = vetorDireita[indiceVetorDireita];
            indiceVetorDireita++;
        }
        indiceVetorMergeado++;
    }
    
    while (indiceVetorEsquerda < tamanhoVetorEsquerda) {
        registros[indiceVetorMergeado] = vetorEsquerda[indiceVetorEsquerda];
        indiceVetorEsquerda++;
        indiceVetorMergeado++;
    }

    while (indiceVetorDireita < tamanhoVetorDireita) {
        registros[indiceVetorMergeado] = vetorDireita[indiceVetorDireita];
        indiceVetorDireita++;
        indiceVetorMergeado++;
    }

    delete[] vetorEsquerda;
    delete[] vetorDireita;
}

void MergeSort::mergeSort(Registro registros[], int indiceInicio, int indiceFim){
    if (indiceInicio >= indiceFim) return; 
 
    auto indiceMeio = indiceInicio + (indiceFim - indiceInicio) / 2;
    mergeSort(registros, indiceInicio, indiceMeio);
    mergeSort(registros, indiceMeio + 1, indiceFim);
    merge(registros, indiceInicio, indiceMeio, indiceFim);
}

void MergeSort::ordenarCrescente(Registro registros[], int tamanho){
    mergeSort(registros, 0, (tamanho - 1));
}
