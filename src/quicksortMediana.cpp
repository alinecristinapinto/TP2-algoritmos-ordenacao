#include "quicksortMediana.hpp"

Registro QuickSortMediana::buscarPivo(Registro registros[], int indiceInicial, int indiceFinal, int k, Desempenho *desempenho){
    if(k >= (indiceFinal - indiceInicial + 1)) return registros[indiceInicial];

    Registro* medianas = new Registro[k];

    for(int i=0; i < k; i++){
        int indiceAleatorio = GeradorDados::gerarInteiroAleatorioEmIntervalo(indiceInicial, indiceFinal);
        medianas[i] = registros[indiceAleatorio];
    } 

    Selecao::ordenarCrescente(medianas, 0, k - 1, desempenho);
    
    int indiceMediana = std::floor(k / 2.0); 
    Registro pivo = medianas[indiceMediana];

    delete [] medianas;
    return pivo;
}

void QuickSortMediana::particionar(Registro registros[], int indiceInicial, int indiceFinal, int k, int *indiceEsquerda, int *indiceDireita, Desempenho *desempenho){
    *indiceEsquerda = indiceInicial; 
    *indiceDireita = indiceFinal;

    Registro aux, pivo = buscarPivo(registros, indiceInicial, indiceFinal, k, desempenho);
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
            (*desempenho).numeroAtribuicoes+= 3;

            (*indiceEsquerda)++;
            (*indiceDireita)--;
        }
    } while (*indiceEsquerda <= *indiceDireita);
}

void QuickSortMediana::ordenar(Registro registros[], int indiceInicial, int indiceFinal, int k, Desempenho *desempenho){
    int indiceEsquerda, indiceDireita;

    particionar(registros, indiceInicial, indiceFinal, k, &indiceEsquerda, &indiceDireita, desempenho);

    if (indiceInicial < indiceDireita){
        ordenar(registros, indiceInicial, indiceDireita, k, desempenho);
    }

    if (indiceEsquerda < indiceFinal){
        ordenar(registros, indiceEsquerda, indiceFinal, k, desempenho);
    }
}

void QuickSortMediana::ordenarCrescente(Registro registros[], int tamanho, int k, Desempenho *desempenho){
    ordenar(registros, 0, (tamanho - 1), k, desempenho);
}
