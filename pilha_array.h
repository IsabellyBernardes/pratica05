#ifndef PILHA_ARRAY_H
#define PILHA_ARRAY_H

#include "pilha.h"
#include <stdexcept>

template <typename T>
class PilhaArray : public Pilha<T> {
private:
    T* items;
    int topo;
public:
    PilhaArray(int capacidade) {
        this->capacidade = capacidade;
        this->items = new T[capacidade];
        this->topo = -1;
        this->tamanhoAtual = 0; // Inicia vazia
    }

    ~PilhaArray() override {
        delete[] items;
    }

    void empilha(T item) override {
        if (this->estaCheia()) {
            throw std::runtime_error("Estouro da pilha");
        }
        items[++topo] = item;
        this->tamanhoAtual++;
    }

    T desempilha() override {
        if (this->estaVazia()) {
            throw std::runtime_error("Pilha vazia");
        }
        this->tamanhoAtual--;
        return items[topo--];
    }

    int tamanho() const override {
        return this->tamanhoAtual;
    }
};

#endif // PILHA_ARRAY_H
