#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>

using namespace std;

/**
 * @brief Classe responsavel pelo armazenamento dos registros utiilizados nos algoritmos 
 * de orderanacao
 */
class Registro {
public:
    int chave;
    char caracteres[15][200];
    float numeros[10];

    /**
     * @brief Construtor generico da classe.
    */
    Registro();

    /**
     * @brief Construtor que inicializa algumas variaveis da classe.
     * 
     * @param chave chave do registro para ordenacao
    */
    Registro(int chave);

    /**
     * @brief Destrutor da classe
    */
    ~Registro() = default;
};

#endif