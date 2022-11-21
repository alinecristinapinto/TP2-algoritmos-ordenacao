#include "geradorDados.hpp"

int GeradorDados::gerarInteiroAleatorioEmIntervalo(int minimo, int maximo){
    return minimo + (rand() % (maximo - minimo + 1));
}

Registro* GeradorDados::gerarVetorRegistrosAleatorios(int tamanho){
    Registro *registros = new Registro[tamanho];

    for(int i=0; i<tamanho; i++){
        registros[i].chave = rand();
    }

    return registros;
}
