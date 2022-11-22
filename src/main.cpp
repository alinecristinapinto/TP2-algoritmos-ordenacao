//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : Algoritmos de Ordenacao
// Autor        : Aline Cristina Pinto (alinecristinapinto@ufmg.br)
//---------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <fstream>

#include "constantes.hpp"
#include "geradorDados.hpp"
#include "leitorLinhaComando.hpp"
#include "msgassert.hpp"
#include "selecao.h"
#include "desempenho.hpp"

#include "registro.hpp"
#include "quicksort.hpp"
#include "quicksortMediana.hpp"
#include "quicksortSelecao.hpp"
#include "quicksortNaoRecusivo.hpp"
#include "quicksortEmpilhaInteligente.hpp"
#include "mergesort.hpp"
#include "heapsort.hpp"

using namespace std;

// debug
void imprimir(Registro registros[], int tamanho){
    for(int i=0; i<tamanho; i++){
        cout << registros[i].chave << endl;
    }
}

void processar(int vQuicksort, int tamanho, int argc, char* argv[], Desempenho *desempenho){
    Registro *registros = GeradorDados::gerarVetorRegistrosAleatorios(tamanho);
    imprimir(registros,  tamanho);
    
    switch(vQuicksort) {
        case QUICKSORT_RECURSIVO: {
            cout << "Quicksort recursivo" << endl;        
            QuickSort::ordenarCrescente(registros, tamanho, desempenho);

            // cout << endl << "ORDENADO" << endl;
            // imprimir(registros,  tamanho);
        } break;
        case QUICKSORT_MEDIANA: {
            int k = LeitorLinhaComando::buscar_k_elementos_quicksort_mediana(argc, argv);
            cout << "Quicksort mediana, k " << k << endl;
            QuickSortMediana::ordenarCrescente(registros, tamanho, k, desempenho);

            // cout << endl << "ORDENADO" << endl;
            // imprimir(registros,  tamanho);
        } break;
        case QUICKSORT_SELECAO: {
            int m = LeitorLinhaComando::buscar_m_tamanho_quicksort_selecao(argc, argv);
            cout << "Quicksort selecao, m " << m << endl;
            QuickSortSelecao::ordenarCrescente(registros, tamanho, m, desempenho);

            // cout << endl << "ORDENADO" << endl;
            // imprimir(registros,  tamanho);
        } break;
        case QUICKSORT_NAO_RECURSIVO: {
            cout << "Quicksort nao recursivo" << endl;
            QuickSortNaoRecursivo::ordenarCrescente(registros, tamanho, desempenho);

            // cout << endl << "ORDENADO" << endl;
            // imprimir(registros,  tamanho);
        } break;
        case QUICKSORT_EMPILHA_INTELIGENTE: {
            cout << "Quicksort empilha inteligente" << endl;
            QuickSortEmpilhaInteligente::ordenarCrescente(registros, tamanho);

            // cout << endl << "ORDENADO" << endl;
            // imprimir(registros,  tamanho);
        } break;
        default: {
            erroAssert(false, "Variacao de algoritmo quicksort nao conhecido");
        }
    } 
}

int main(int argc, char* argv[]) {
    int vQuicksort = LeitorLinhaComando::buscar_variacao_quicksort(argc, argv);
    int semente = LeitorLinhaComando::buscar_semente_gerador_numero(argc, argv);
    string arquivoEntrada = LeitorLinhaComando::buscar_nome_arquivo_entrada(argc, argv);
    string arquivoSaida = LeitorLinhaComando::buscar_nome_arquivo_saida(argc, argv);

    ifstream arquivo(arquivoEntrada);
    erroAssert(arquivo.is_open(), "Nao foi possivel ler o arquivo de entrada");

    srand(semente);
    int nEntradas = 0, tamanho = 0;
    arquivo >> nEntradas;

    for(int i=0; i<nEntradas; i++){
        arquivo >> tamanho;
        Desempenho *desempenho = new Desempenho{0, 0};

        processar(vQuicksort, tamanho, argc, argv, desempenho);

        cout << "Metricas" << endl;
        cout << "Atribuicoes " << (*desempenho).numeroAtribuicoes << endl;
        cout << "Comparacoes " << (*desempenho).numeroComparacoes << endl;

        delete desempenho;
    }

    arquivo.close();

    // srand(10);
    // Registro *registros = GeradorDados::gerarVetorRegistrosAleatorios(10);
    // imprimir(registros, 10);

    // // QuickSort::ordenarCrescente(registros, 10);
    // HeapSort::ordenarCrescente(registros, 10);

    // cout << endl << "ORDENADO" << endl;
    // imprimir(registros,  10);

   return 0;
}