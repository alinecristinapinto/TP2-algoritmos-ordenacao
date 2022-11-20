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

/**
 * @brief Classe responsavel pela leitura dos dados por linha de comando
*/
class LeitorLinhaComando {
public:
    /**
     * @brief Retorna o tipo de algoritmo quicksort selecionado
     * 
     * @param argc Numero de parametros
     * @param argv String com comando digitado
     * @return int Numero da variacao de algoritmo
    */
    static int buscar_variacao_quicksort(int argc, char* argv[]);
    
    /**
     * @brief Retorna a semente para geracao de numeros aleatorios
     * 
     * @param argc Numero de parametros
     * @param argv String com comando digitado
     * @return int Numero da semente
    */
    static int buscar_semente_gerador_numero(int argc, char* argv[]);

    /**
     * @brief Retorna o nome do arquivo de entrada
     * 
     * @param argc Numero de parametros
     * @param argv String com comando digitado
     * @return string nome do arquivo
    */
    static string buscar_nome_arquivo_entrada(int argc, char* argv[]);

    /**
     * @brief Retorna o nome do arquivo de saida
     * 
     * @param argc Numero de parametros
     * @param argv String com comando digitado
     * @return string nome do arquivo
    */
    static string buscar_nome_arquivo_saida(int argc, char* argv[]);

    /**
     * @brief Retorna o numero k de elementos para quicksort mediana
     * 
     * @param argc Numero de parametros
     * @param argv String com comando digitado
     * @return int numero k
    */
    static int buscar_k_elementos_quicksort_mediana(int argc, char* argv[]);

    /**
     * @brief Retorna o numero de tamanho m para quicksort selecao
     * 
     * @param argc Numero de parametros
     * @param argv String com comando digitado
     * @return int numero m
    */
    static int buscar_m_tamanho_quicksort_selecao(int argc, char* argv[]);

private:
    /**
     * @brief  Retorna argumento do terminal baseado na opcao passada
     * 
     * @param argc Numero de parametros
     * @param argv String com comando digitado
     * @param param Parametro desejado
     * @return string Argumento do terminal referente ao parametro
    */
    static string buscar_argumento(int argc, char* argv[], string param); 

    /**
     * @brief  Retorna argumento do terminal baseado na opcao passada
     * 
     * @param argc Numero de parametros
     * @param argv String com comando digitado
     * @param parametro Parametro desejado
     * @return bool verdadeiro/falso para presenca de parametro no comando
    */
    static bool verificar_parametro_presente(int argc, char* argv[], string parametro); 
};

#endif
