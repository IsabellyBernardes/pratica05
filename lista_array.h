#ifndef LISTA_ARRAY_H
#define LISTA_ARRAY_H

#include <iostream>
#include <stdexcept>
#include "lista.h"

using namespace std;

template <class T>
class ListaArray : public Lista<T> {
private:
    T* array;
    int capacidade;
    int tamanhoAtual;

public:
    ListaArray(int capacidade) : capacidade(capacidade), tamanhoAtual(0) {
        array = new T[capacidade];
    }

    ~ListaArray() {
        delete[] array;
    }

    void adiciona(const T& item) override {
        if (tamanhoAtual == capacidade) {
            throw runtime_error("Lista cheia");
        }
        array[tamanhoAtual++] = item;
    }

    T pega(int idx) const override {
        if (idx < 1 || idx > tamanhoAtual) {
            throw runtime_error("Indice invalido");
        }
        return array[idx - 1];
    }

    void insere(int idx, const T& item) override {
        if (idx < 1 || idx > tamanhoAtual + 1) {
            throw runtime_error("Indice invalido");
        }
        if (tamanhoAtual == capacidade) {
            throw runtime_error("Lista cheia");
        }
        for (int i = tamanhoAtual; i >= idx; i--) {
            array[i] = array[i - 1];
        }
        array[idx - 1] = item;
        tamanhoAtual++;
    }

    void remove(int idx) override {
        if (idx < 1 || idx > tamanhoAtual) {
            throw runtime_error("Indice invalido");
        }
        for (int i = idx - 1; i < tamanhoAtual - 1; i++) {
            array[i] = array[i + 1];
        }
        tamanhoAtual--;
    }

    void exibe() const override {
        for (int i = 0; i < tamanhoAtual; i++) {
            cerr << array[i] << " ";
        }
        cerr << endl;
    }

    int tamanho() const override {
        return tamanhoAtual;
    }
};

#endif // LISTA_ARRAY_H
