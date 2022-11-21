#ifndef SELECAO_H
#define SELECAO_H

#include <iostream>
#include "registro.hpp"

using namespace std;

/**
 * @brief Classe que implementa o algoritmo de selecao
*/
class Selecao{
public:
    /**
     * @brief Ordena o vetor de forma crescente com quicksort selecao
     * 
     * @param registros Vetor de registros
     * @param posicaoInicial Posicao inicial do vetor
     * @param posicaoFinal Posicao final do vetor
    */
    static void ordenarCrescente(Registro registros[], int posicaoInicial , int posicaoFinal);
};

#endif
