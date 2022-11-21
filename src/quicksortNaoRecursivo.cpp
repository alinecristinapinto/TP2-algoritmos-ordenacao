#include "quicksortNaoRecusivo.hpp"

int QuickSortNaoRecursivo::particionar(Registro registros[], int indiceInicial, int indiceFinal){
    Registro pivo = registros[indiceFinal];
    int indicePivo = indiceInicial - 1;

    for(int i=indiceInicial; i<indiceFinal; i++){
        if(registros[i].chave <= pivo.chave){
            indicePivo++;

            Registro aux = registros[indicePivo];
            registros[indicePivo] = registros[i];
            registros[i] = aux;
        }
    }

    indicePivo +=1;

    Registro aux = registros[indicePivo];
    registros[indicePivo] = registros[indiceFinal];
    registros[indiceFinal] = aux;

    return indicePivo;
}

void QuickSortNaoRecursivo::ordenarCrescente(Registro registros[], int tamanho){
    Pilha pilha = Pilha();
    pilha.empilhar(0, (tamanho - 1));
    
    Intervalo indices; 
    int indicePivo;

    while(!pilha.vazia()){
        indices = pilha.desempilhar(); 

        indicePivo = particionar(registros, indices.inicio, indices.fim );
         
        if(indicePivo - 1 > indices.inicio ){
            pilha.empilhar(indices.inicio, indicePivo -1);
        }

        if(indicePivo + 1 < indices.fim){
            pilha.empilhar(indicePivo + 1, indices.fim);
        }
    }
}
