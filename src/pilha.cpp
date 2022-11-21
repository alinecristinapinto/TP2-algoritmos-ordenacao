#include "pilha.hpp"

Pilha::Pilha() {
    this->topo = nullptr;
}

bool Pilha::vazia(){
    return this->topo == nullptr;
}

void Pilha::empilhar(int inicio, int fim){
    No* novoNo = new No{ Intervalo {inicio, fim}, this->topo};
    this->topo = novoNo;
}

Intervalo Pilha::desempilhar(){
    if(this->vazia())
        return;
    
    No* no = this->topo;
    Intervalo indices = topo->indices;

    this->topo = this->topo->proximo;
    
    delete no;
    return indices;
}

Pilha::~Pilha(){
    while (this->topo) {
        desempilhar();
    }
}
