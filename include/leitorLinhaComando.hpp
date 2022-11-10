#ifndef LEITORLINHACOMANDO_H
#define LEITORLINHACOMANDO_H

#include <iostream>
#include "msgassert.hpp" 

using namespace std;

const string QUICKSORT = "quicksort";
const string V_VARIACAO_QUICKSORT = "-v";
const string S_SEMENTE_GERADOR_NUMEROS = "-s";
const string I_NOME_ARQUIVO_ENTRADA = "-i";
const string O_NOME_ARQUIVO_SAIDA = "-o";

const string K_ELEMENTOS_QUICKSORT_MEDIANA = "-k";
const string M_TAMANHO_QUICKSORT_SELECAO = "-m";

class LeitorLinhaComando {
public:
    static int buscar_variacao_quicksort(int argc, char* argv[]);
    
    static int buscar_semente_gerador_numero(int argc, char* argv[]);

    static string buscar_nome_arquivo_entrada(int argc, char* argv[]);

    static string buscar_nome_arquivo_saida(int argc, char* argv[]);

    static int buscar_k_elementos_quicksort_mediana(int argc, char* argv[]);

    static int buscar_m_tamanho_quicksort_selecao(int argc, char* argv[]);

private:
    static string buscar_argumento(int argc, char* argv[], string param); 

    static bool verificar_parametro_presente(int argc, char* argv[], string parametro); 
};

#endif
