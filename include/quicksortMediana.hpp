#ifndef QUICKSORTMEDIANA_H
#define QUICKSORTMEDIANA_H

#include <iostream>
#include "registro.hpp"

using namespace std;

/**
 * @brief Classe que implementa o algoritmo de quicksort mediana
*/
class QuickSortMediana {
public:
    /**
     * @brief Ordena o vetor de forma crescente com quicksort mediana
     * 
     * @param registros Vetor de registros
     * @param tamanho Tamanho do vetor
     * @param k Quantidade de pivos que serao selecionados para mediana
    */
    static void ordenarCrescente(Registro registros[], int tamanho, int k);

private:
    /**
     * @brief Obtem pivo a partir da mediana entre os numeros unicos do vetor
     * 
     * @param registros Vetor de registros
     * @param indiceInicial Indice inicial do vetor
     * @param indiceFinal Indice final do vetor
     * @param k Quantidade de pivos que serao selecionados para mediana
    */
    static Registro buscarPivo(Registro registros[], int indiceInicial, int indiceFinal, int k);
  
    /**
     * @brief Particiona o vetor de registros de forma crescente
     * 
     * @param registros Vetor de registros
     * @param indiceInicial Indice inicial do vetor
     * @param indiceFinal Indice final do vetor
     * @param k Quantidade de pivos que serao selecionados para mediana
     * @param incdiceEsqueda Ponteiro para indice que percorrera o vetor a esquerda
     * @param indiceDireita Ponteiro para indice que percorrera o vetor a direita
    */
    static void particionar(Registro registros[], int indiceInicial, int indiceFinal, int k, int *indiceEsquerda, int *indiceDireita);
    
    /**
     * @brief Ordena vetor de forma recursiva
     * 
     * @param registros Vetor de registros
     * @param indiceInicial Indice inicial do vetor
     * @param indiceFinal Indice final do vetor
     * @param k Quantidade de pivos que serao selecionados para mediana
    */
    static void ordenar(Registro registros[], int indiceInicial, int indiceFinal, int k);
};

#endif