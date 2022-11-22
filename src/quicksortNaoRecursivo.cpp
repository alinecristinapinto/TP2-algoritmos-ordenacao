#include "quicksortNaoRecusivo.hpp"

int QuickSortNaoRecursivo::particionar(Registro registros[], int indiceInicial, int indiceFinal, Desempenho *desempenho){
    int indicePivo = indiceInicial - 1;
    Registro pivo = registros[indiceFinal];
    desempenho->numeroAtribuicoes++;

    for(int i=indiceInicial; i<indiceFinal; i++){
        desempenho->numeroComparacoes++;
        if(registros[i].chave <= pivo.chave){
            indicePivo++;

            Registro aux = registros[indicePivo];
            registros[indicePivo] = registros[i];
            registros[i] = aux;
            desempenho->numeroAtribuicoes += 3;
        }
    }

    indicePivo +=1;

    Registro aux = registros[indicePivo];
    registros[indicePivo] = registros[indiceFinal];
    registros[indiceFinal] = aux;
    desempenho->numeroAtribuicoes += 3;

    return indicePivo;
}

void QuickSortNaoRecursivo::ordenarCrescente(Registro registros[], int tamanho, Desempenho *desempenho){
    Pilha pilha = Pilha();
    pilha.empilhar(0, (tamanho - 1));
    
    Intervalo indices; 
    int indicePivo;

    while(!pilha.vazia()){
        indices = pilha.desempilhar(); 

        indicePivo = particionar(registros, indices.inicio, indices.fim, desempenho);
         
        if(indicePivo - 1 > indices.inicio ){
            pilha.empilhar(indices.inicio, indicePivo -1);
        }

        if(indicePivo + 1 < indices.fim){
            pilha.empilhar(indicePivo + 1, indices.fim);
        }
    }
}
