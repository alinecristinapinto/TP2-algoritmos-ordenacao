#include "mergesort.hpp"

void MergeSort::merge(Registro registros[], int const indiceEsquerda, int const indiceMeio, int const indiceDireita, Desempenho *desempenho){
    int const tamanhoVetorEsquerda = indiceMeio - indiceEsquerda + 1;
    int const tamanhoVetorDireita = indiceDireita - indiceMeio;

    Registro *vetorEsquerda = new Registro[tamanhoVetorEsquerda];
    Registro *vetorDireita = new Registro[tamanhoVetorDireita];
    
    for (int i = 0; i < tamanhoVetorEsquerda; i++){
        vetorEsquerda[i] = registros[indiceEsquerda + i];
        desempenho->numeroAtribuicoes ++;
    }
       
    for (int j = 0; j < tamanhoVetorDireita; j++){
        vetorDireita[j] = registros[indiceMeio + 1 + j];
        desempenho->numeroAtribuicoes ++;
    }

    int indiceVetorEsquerda = 0, indiceVetorDireita = 0;
    int indiceVetorMergeado = indiceEsquerda; 
 
    while (indiceVetorEsquerda < tamanhoVetorEsquerda && indiceVetorDireita < tamanhoVetorDireita) {
        desempenho->numeroComparacoes++;
        if (vetorEsquerda[indiceVetorEsquerda].chave <= vetorDireita[indiceVetorDireita].chave) {
            registros[indiceVetorMergeado] = vetorEsquerda[indiceVetorEsquerda];
            desempenho->numeroAtribuicoes ++;
            indiceVetorEsquerda++;
        } else {
            registros[indiceVetorMergeado] = vetorDireita[indiceVetorDireita];
            desempenho->numeroAtribuicoes ++;
            indiceVetorDireita++;
        }
        indiceVetorMergeado++;
    }
    
    while (indiceVetorEsquerda < tamanhoVetorEsquerda) {
        registros[indiceVetorMergeado] = vetorEsquerda[indiceVetorEsquerda];
        desempenho->numeroAtribuicoes ++;
        indiceVetorEsquerda++;
        indiceVetorMergeado++;
    }

    while (indiceVetorDireita < tamanhoVetorDireita) {
        registros[indiceVetorMergeado] = vetorDireita[indiceVetorDireita];
        desempenho->numeroAtribuicoes ++;
        indiceVetorDireita++;
        indiceVetorMergeado++;
    }

    delete[] vetorEsquerda;
    delete[] vetorDireita;
}

void MergeSort::mergeSort(Registro registros[], int indiceInicio, int indiceFim, Desempenho *desempenho){
    if (indiceInicio >= indiceFim) return; 
 
    auto indiceMeio = indiceInicio + (indiceFim - indiceInicio) / 2;
    mergeSort(registros, indiceInicio, indiceMeio, desempenho);
    mergeSort(registros, indiceMeio + 1, indiceFim, desempenho);
    merge(registros, indiceInicio, indiceMeio, indiceFim, desempenho);
}

void MergeSort::ordenarCrescente(Registro registros[], int tamanho, Desempenho *desempenho){
    mergeSort(registros, 0, (tamanho - 1), desempenho);
}
