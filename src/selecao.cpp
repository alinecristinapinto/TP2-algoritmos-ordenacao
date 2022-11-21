#include "selecao.h"

void Selecao::ordenarCrescente(Registro registros[],  int posicaoInicial , int posicaoFinal) {
    for (int i = posicaoInicial; i <= posicaoFinal; i++) {
        int indexMenor = i;

        for (int j = i+1; j <= posicaoFinal; j++) {
            if (registros[j].chave < registros[indexMenor].chave) {
                indexMenor = j;
            }
        }

        Registro aux = registros[i];
        registros[i] = registros[indexMenor];
        registros[indexMenor] = aux;
    }
}
