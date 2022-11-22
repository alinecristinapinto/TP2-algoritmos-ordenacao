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

// debug
void imprimir(Registro registros[], int tamanho){
    for(int i=0; i<tamanho; i++){
        cout << registros[i].chave << endl;
    }
}

void direcionar(Registro *registros, int vQuicksort, int tamanho, int argc, char* argv[], Desempenho *desempenho){
    switch(vQuicksort) {
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

void processar(int vQuicksort, int nEntradas, int *tamanhos, int argc, char* argv[], ofstream& arquivo){
    struct rusage resources;
    int statusGetResources;

    double tempoTotalAnterior = 0.0;
    double tempoTotalAtual = 0.0;
    double tempoUsuario = 0.0;
    double tempoSistema = 0.0;
    double intervaloExecucao = 0.0;

    if((statusGetResources = getrusage(RUSAGE_SELF, &resources)) != 0) {
        cout << "Nao foi possivel iniciar getrusage()" << endl;
    }

    tempoUsuario = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
    tempoSistema = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
    tempoTotalAnterior = tempoUsuario + tempoSistema;

    for(int i=0; i<nEntradas; i++){
        Registro *registros = GeradorDados::gerarVetorRegistrosAleatorios(tamanhos[i]);
        imprimir(registros,  tamanhos[i]);
        Desempenho *desempenho = new Desempenho{0, 0};

        direcionar(registros, vQuicksort, tamanhos[i], argc, argv, desempenho);

        cout << "Metricas" << endl;
        cout << "Atribuicoes " << (*desempenho).numeroAtribuicoes << endl;
        cout << "Comparacoes " << (*desempenho).numeroComparacoes << endl;

        tempoUsuario = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
        tempoSistema = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;

        tempoTotalAtual = tempoUsuario + tempoSistema;
        intervaloExecucao = tempoTotalAtual - tempoTotalAnterior;
        tempoTotalAnterior = tempoTotalAtual;

        escreverMetricas(arquivo, tamanhos[i], desempenho->numeroAtribuicoes, desempenho->numeroComparacoes, intervaloExecucao);
        delete [] registros;
        delete desempenho;
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
    int *tamanhos = new int[nEntradas];

    arquivo >> nEntradas;
    for(int i=0; i<nEntradas; i++){
        arquivo >> tamanho;
        tamanhos[i] = tamanho;
    }

    arquivo.close();

    ofstream resultados(arquivoSaida);
    erroAssert(resultados.is_open(), "Nao foi possivel criar o arquivo de saida");
   
    escreverCabecalho(resultados);
    processar(vQuicksort, nEntradas, tamanhos, argc, argv, resultados);
  
    resultados.close();
    return 0;
}