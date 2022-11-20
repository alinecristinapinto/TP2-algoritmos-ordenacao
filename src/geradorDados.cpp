#include "geradorDados.hpp"

Registro* GeradorDados::gerarVetorRegistrosAleatorios(int tamanho){
    Registro *registros = new Registro[tamanho];

    for(int i=0; i<tamanho; i++){
        registros[i].chave = rand();
    }

    return registros;
}
