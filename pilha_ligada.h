#ifndef PILHA_LIGADA_H
#define PILHA_LIGADA_H

#include "pilha.h"
#include <stdexcept>

template <class T>
class PilhaLigada : public Pilha<T> {
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
public:
    PilhaLigada(int capacidade) {
        this->capacidade = capacidade;
        this->topo = nullptr;
        this->tamanhoAtual = 0;
    }

    ~PilhaLigada() override {
        while (topo != nullptr) {
            desempilha();
        }
    }

    void empilha(T item) override {
        if (this->estaCheia()) {
            throw std::runtime_error("Estouro da pilha");
        }
        topo = new No(item, topo);
        this->tamanhoAtual++;
    }

    T desempilha() override {
        if (this->estaVazia()) {
            throw std::runtime_error("Pilha vazia");
        }
        No* tmp = topo;
        T dado = topo->dado;
        topo = topo->prox;
        delete tmp;
        this->tamanhoAtual--;
        return dado;
    }

    int tamanho() const override {
        return this->tamanhoAtual;
    }
};

#endif // PILHA_LIGADA_H
