#include "selecao.h"

void Selecao::ordenarCrescente(Registro registros[],  int posicaoInicial , int posicaoFinal, Desempenho *desempenho) {
    for (int i = posicaoInicial; i <= posicaoFinal; i++) {
        int indexMenor = i;

        for (int j = i+1; j <= posicaoFinal; j++) {
            desempenho->numeroComparacoes++;
            if (registros[j].chave < registros[indexMenor].chave) {
                indexMenor = j;
            }
        }

        Registro aux = registros[i];
        registros[i] = registros[indexMenor];
        registros[indexMenor] = aux;
        desempenho->numeroAtribuicoes += 3;
    }
}
