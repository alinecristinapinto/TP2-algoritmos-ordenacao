//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : Algoritmos de Ordenacao
// Autor        : Aline Cristina Pinto (alinecristinapinto@ufmg.br)
//---------------------------------------------------------------------

#include <iostream>

#include "leitorLinhaComando.hpp"
#include "msgassert.hpp" 

using namespace std;

int main(int argc, char* argv[]) {
   int vQuicksort = LeitorLinhaComando::buscar_variacao_quicksort(argc, argv);

    cout << vQuicksort << endl;

   return 0;
}