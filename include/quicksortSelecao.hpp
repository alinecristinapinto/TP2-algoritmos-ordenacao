#ifndef QUICKSORTSELECAO_H
#define QUICKSORTSELECAO_H

#include <iostream>
#include "registro.hpp"
#include "desempenho.hpp"
#include "selecao.h"

using namespace std;

/**
 * @brief Classe que implementa o algoritmo de quicksort selecao
*/
class QuickSortSelecao{
public:
    /**
     * @brief Ordena o vetor de forma crescente com quicksort selecao
     * 
     * @param registros Vetor de registros
     * @param tamanho Tamanho do vetor
     * @param m Tamanho minimo para iniciar algoritmo de selecao
     * @param desempenho Struct que armazena dados de desempenho do codigo
    */
    static void ordenarCrescente(Registro registros[], int tamanho, int m, Desempenho *desempenho);

private:
    /**
     * @brief Particiona o vetor de registros de forma crescente
     * 
     * @param registros Vetor de registros
     * @param indiceInicial Indice inicial do vetor
     * @param indiceFinal Indice final do vetor
     * @param incdiceEsqueda Ponteiro para indice que percorrera o vetor a esquerda
     * @param indiceDireita Ponteiro para indice que percorrera o vetor a direita
     * @param desempenho Struct que armazena dados de desempenho do codigo
    */
    static void particionar(Registro registros[], int indiceInicial, int indiceFinal, int *indiceEsquerda, int *indiceDireita, Desempenho *desempenho);
    
    /**
     * @brief Ordena vetor de forma recursiva
     * 
     * @param registros Vetor de registros
     * @param indiceInicial Indice inicial do vetor
     * @param indiceFinal Indice final do vetor
     * @param m Tamanho minimo para iniciar algoritmo de selecao
     * @param desempenho Struct que armazena dados de desempenho do codigo
    */
    static void ordenar(Registro registros[], int indiceInicial, int indiceFinal, int m, Desempenho *desempenho);
};

#endif
