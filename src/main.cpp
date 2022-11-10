//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : Algoritmos de Ordenacao
// Autor        : Aline Cristina Pinto (alinecristinapinto@ufmg.br)
//---------------------------------------------------------------------

#include <iostream>

#include "constantes.hpp"
#include "leitorLinhaComando.hpp"
#include "msgassert.hpp" 

using namespace std;

int main(int argc, char* argv[]) {
    int vQuicksort = LeitorLinhaComando::buscar_variacao_quicksort(argc, argv);
    int semente = LeitorLinhaComando::buscar_semente_gerador_numero(argc, argv);
    string arquivoEntrada = LeitorLinhaComando::buscar_nome_arquivo_entrada(argc, argv);
    string arquivoSaida = LeitorLinhaComando::buscar_nome_arquivo_saida(argc, argv);

    switch(vQuicksort) {
        case QUICKSORT_RECURSIVO: {
            cout << "Quicksort recursivo" << endl;
        } break;
        case QUICKSORT_MEDIANA: {
            int k = LeitorLinhaComando::buscar_k_elementos_quicksort_mediana(argc, argv);
            cout << "Quicksort mediana, k " << k << endl;
        } break;
        case QUICKSORT_SELECAO: {
            int m = LeitorLinhaComando::buscar_m_tamanho_quicksort_selecao(argc, argv);
            cout << "Quicksort selecao, m " << m << endl;
        } break;
        case QUICKSORT_NAO_RECURSIVO: {
            cout << "Quicksort nao recursivo" << endl;
        } break;
        case QUICKSORT_EMPILHA_INTELIGENTE: {
            cout << "Quicksort empilha inteligente" << endl;
        } break;
        default: {
            erroAssert(false, "Variacao de algoritmo quicksort nao conhecido");
        }
    } 

   return 0;
}