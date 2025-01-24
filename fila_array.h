#ifndef FILA_ARRAY_H
#define FILA_ARRAY_H

#include "fila.h"
//deixa mais livre o atendimento para novas funções como se fosse um atendimento de restaurante
template <class T>
class FilaArray : public Fila<T> {
private:
    T* items;
    int capacidade;
    int tamanhoAtual;
    int inicio;
    int fim;

public:
    FilaArray(int cap) {
        capacidade = cap;
        items = new T[capacidade];
        tamanhoAtual = 0;
        inicio = 0;
        fim = -1;
    }

    ~FilaArray() {
        delete[] items;
    }

    void enfileira(const T& item) override {
        if (cheia()) {
            throw runtime_error("Fila cheia");
        }
        fim = (fim + 1) % capacidade;
        items[fim] = item;
        tamanhoAtual++;
    }

    T desenfileira() override {
        if (vazia()) {
            throw runtime_error("Fila vazia");
        }
        T item = items[inicio];
        inicio = (inicio + 1) % capacidade;
        tamanhoAtual--;
        return item;
    }

    bool cheia() const override {
        return tamanhoAtual == capacidade;
    }

    bool vazia() const override {
        return tamanhoAtual == 0;
    }

    int tamanho() const override {
        return tamanhoAtual;
    }
};

#endif // FILA_ARRAY_H
