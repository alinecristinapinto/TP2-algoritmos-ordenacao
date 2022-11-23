//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : Algoritmos de Ordenacao
// Autor        : Aline Cristina Pinto (alinecristinapinto@ufmg.br)
//---------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sys/resource.h>

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

void direcionar(Registro *registros, int tipoAlgoritmo, int tamanho, int argc, char* argv[], Desempenho *desempenho){
    switch(tipoAlgoritmo) {
        case QUICKSORT_RECURSIVO: {
            QuickSort::ordenarCrescente(registros, tamanho, desempenho);
        } break;
        case QUICKSORT_MEDIANA: {
            int k = LeitorLinhaComando::buscar_k_elementos_quicksort_mediana(argc, argv);
            QuickSortMediana::ordenarCrescente(registros, tamanho, k, desempenho);
        } break;
        case QUICKSORT_SELECAO: {
            int m = LeitorLinhaComando::buscar_m_tamanho_quicksort_selecao(argc, argv);
            QuickSortSelecao::ordenarCrescente(registros, tamanho, m, desempenho);
        } break;
        case QUICKSORT_NAO_RECURSIVO: {
            QuickSortNaoRecursivo::ordenarCrescente(registros, tamanho, desempenho);
        } break;
        case QUICKSORT_EMPILHA_INTELIGENTE: {
            QuickSortEmpilhaInteligente::ordenarCrescente(registros, tamanho, desempenho);
        } break;
        case ALGORITMO_MERGESORT: {
            MergeSort::ordenarCrescente(registros, tamanho, desempenho);    
        } break;
        case ALGORITMO_HEAPSORT: {
            HeapSort::ordenarCrescente(registros, tamanho, desempenho);
        } break;
        default: {
            erroAssert(false, "Variacao de algoritmo quicksort nao conhecido");
        }
    } 
}

void escreverCabecalho(ofstream& arquivo){
    arquivo << "Tamanho Atribuicoes Comparacoes Tempo" << endl;
}

void escreverMetricas(ofstream& arquivo, int tamanho, int atribuicoes, int comparacoes, double tempo){
    arquivo << tamanho << " " << atribuicoes << " " << comparacoes << " " << tempo << endl;
}

double obterTempoTotalExecucao(){
    struct rusage resources;
    int statusGetResources;

    double tempoUsuario = 0.0, tempoSistema = 0.0;

    if((statusGetResources = getrusage(RUSAGE_SELF, &resources)) != 0) {
        cout << "Nao foi possivel iniciar getrusage()" << endl;
    }

    tempoUsuario = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
    tempoSistema = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;

    return (tempoUsuario + tempoSistema);
}

int main(int argc, char* argv[]) {
    double tempoAnterior = 0.0, tempoAtual = 0.0, tempoReal = 0.0;

    int tipoAlgoritmo = LeitorLinhaComando::buscar_variacao_quicksort(argc, argv);
    int semente = LeitorLinhaComando::buscar_semente_gerador_numero(argc, argv);
    string arquivoEntrada = LeitorLinhaComando::buscar_nome_arquivo_entrada(argc, argv);
    string arquivoSaida = LeitorLinhaComando::buscar_nome_arquivo_saida(argc, argv);

    ifstream arquivo(arquivoEntrada);
    erroAssert(arquivo.is_open(), "Nao foi possivel ler o arquivo de entrada");

    srand(semente);
    int nEntradas = 0, tamanho = 0;
    arquivo >> nEntradas;

    ofstream resultados(arquivoSaida);
    erroAssert(resultados.is_open(), "Nao foi possivel criar o arquivo de saida");
    escreverCabecalho(resultados);

    for(int i=0; i<nEntradas; i++){
        arquivo >> tamanho;
        Registro *registros = GeradorDados::gerarVetorRegistrosAleatorios(tamanho);
        Desempenho *desempenho = new Desempenho{0, 0};

        tempoAnterior = obterTempoTotalExecucao();

        direcionar(registros, tipoAlgoritmo, tamanho, argc, argv, desempenho);

        tempoAtual = obterTempoTotalExecucao();
        tempoReal = tempoAtual - tempoAnterior;

        escreverMetricas(resultados, tamanho, desempenho->numeroAtribuicoes, desempenho->numeroComparacoes, tempoReal);

        delete [] registros;
        delete desempenho;
    }
  
    arquivo.close();
    resultados.close();
    return 0;
}