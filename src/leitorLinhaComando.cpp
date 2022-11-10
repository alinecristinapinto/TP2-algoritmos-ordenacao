#include "leitorLinhaComando.hpp"

string LeitorLinhaComando::buscar_argumento(int argc, char* argv[], string param) {
    string argumento = "";

    for(int i=0; i<argc; i++){
        if(argv[i] == param && (i+1)< argc) {
            argumento = argv[i + 1];
            return argumento;
        }; 
    }

    return argumento;
}

bool LeitorLinhaComando::verificar_parametro_presente(int argc, char* argv[], string param){
    for(int i=0; i<argc; i++){
        if(argv[i] == param) return true;
    }

    return false;
}

int LeitorLinhaComando::buscar_variacao_quicksort(int argc, char* argv[]){
    bool quicksort = verificar_parametro_presente(argc, argv, QUICKSORT);
    erroAssert(quicksort, "Palavra reservada quicksort obrigatoria!");
    string variacao = buscar_argumento(argc, argv, V_VARIACAO_QUICKSORT);
    erroAssert(variacao != "", "Indicacao da variacao de quicksort obrigatorio!");

    return stoi(variacao);
}

int LeitorLinhaComando::buscar_semente_gerador_numero(int argc, char* argv[]){
    string semente = buscar_argumento(argc, argv, S_SEMENTE_GERADOR_NUMEROS);
    erroAssert(semente != "", "Semente para gerar numeros aleatorios obrigatoria!");

    return stoi(semente);
}


string LeitorLinhaComando::buscar_nome_arquivo_entrada(int argc, char* argv[]) {
    string entrada = buscar_argumento(argc, argv, I_NOME_ARQUIVO_ENTRADA);
    erroAssert(entrada != "", "Nome do arquivo de entrada obrigatorio!");

    return entrada;
}

string LeitorLinhaComando::buscar_nome_arquivo_saida(int argc, char* argv[]) {
    string saida = buscar_argumento(argc, argv, O_NOME_ARQUIVO_SAIDA);
    erroAssert(saida != "", "Nome do arquivo de saida obrigatorio!");

    return saida;
}

int LeitorLinhaComando::buscar_k_elementos_quicksort_mediana(int argc, char* argv[]){
    string k = buscar_argumento(argc, argv, K_ELEMENTOS_QUICKSORT_MEDIANA);
    erroAssert(k != "", "k para quicksort mediana obrigatorio!");

    return stoi(k);
}

int LeitorLinhaComando::buscar_m_tamanho_quicksort_selecao(int argc, char* argv[]){
    string m = buscar_argumento(argc, argv, M_TAMANHO_QUICKSORT_SELECAO);
    erroAssert(m != "", "m para quicksort selecao obrigatorio!");

    return stoi(m);
}
