#ifndef PILHA_LIGADA_H
#define PILHA_LIGADA_H

#include <stdexcept>

using namespace std;

template <class T>
class PilhaLigada {
private:
    
    class No {
    public:
        T dado;
        No* prox;

        No(T dado, No* prox = nullptr) {
            this->dado = dado;
            this->prox = prox;
        }
    };

    No* topo; 
    int tamanhoAtual;
    int capacidade;

public:
    PilhaLigada(int capacidade) {
        this->capacidade = capacidade;
        this->topo = nullptr;
        this->tamanhoAtual = 0;
    }

    ~PilhaLigada() {
        while (topo != nullptr) {
            desempilha();
        }
    }

    void empilha(T item) {
        if (tamanhoAtual >= capacidade) {
            throw runtime_error("Estouro da pilha");
        }
        topo = new No(item, topo);
        tamanhoAtual++;
    }

    T desempilha() {
        if (tamanhoAtual == 0) {
            throw runtime_error("Pilha vazia");
        }
        No* tmp = topo;
        T dado = topo->dado;
        topo = topo->prox;
        delete tmp;
        tamanhoAtual--;
        return dado;
    }

    int tamanho() const {
        return tamanhoAtual;
    }
};

#endif // PILHA_LIGADA_H
