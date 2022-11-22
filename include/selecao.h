#ifndef SELECAO_H
#define SELECAO_H

#include <iostream>
#include "registro.hpp"
#include "desempenho.hpp"

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
     * @param desempenho Struct que armazena dados de desempenho do codigo
    */
    static void ordenarCrescente(Registro registros[], int posicaoInicial , int posicaoFinal, Desempenho *desempenho);
};

#endif
