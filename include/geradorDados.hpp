#ifndef GERADORDADOS_H
#define GERADORDADOS_H

#include <iostream>
#include <cstdlib>
#include "registro.hpp"

using namespace std;

/**
 * @brief Classe responsavel por criar numeros e registros aleatorios
*/
class GeradorDados {
public:
    /**
     * @brief  Retorna um numero inteiro aleatorio dado um intervalo
     * 
     * @param minimo Valor minimo do intervalo
     * @param maximo Valor maximo do intervalo
     * @return Numero aleatorio
    */
    static int gerarInteiroAleatorioEmIntervalo(int minimo, int maximo);
    /**
     * @brief  Retorna um vetor de registros com inteiros aleatorios
     * 
     * @param tamanho Tamanho do vetor
     * @return Registro Vetor de registros
    */
    static Registro* gerarVetorRegistrosAleatorios(int tamanho);
};

#endif
