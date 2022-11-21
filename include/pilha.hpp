#ifndef PILHA_H
#define PILHA_H

#include <iostream>
#include "msgassert.hpp"

using namespace std;

/**
 * @brief Representa um intervalo de ordenacao
*/
struct Intervalo {
    int inicio, fim;
};

/**
 * @brief No de uma pilha
*/
struct No {
  Intervalo indices;
  No* proximo;
};

/**
 * @brief Classe que implementa uma pilha
*/
class Pilha {
public:
    Pilha();

    bool vazia();

    void empilhar(int inicio, int fim);

    Intervalo desempilhar();

    ~Pilha();
private:
    No* topo;
};

#endif
