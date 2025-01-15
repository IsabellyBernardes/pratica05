#ifndef LISTA_ARRAY_H
#define LISTA_ARRAY_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class Lista {
private:
    T* array;
    int capacidade;
    int tamanhoAtual;

public:
    Lista(int capacidade) {
        this->capacidade = capacidade;
        array = new T[capacidade];
        tamanhoAtual = 0;
    }

    ~Lista() {
        delete[] array;
    }

    void adiciona(const T& item) {
        if (tamanhoAtual == capacidade) {
            throw runtime_error("Lista cheia");
        }
        array[tamanhoAtual++] = item;
    }

    T pega(int idx) const {
        if (idx < 1 || idx > tamanhoAtual) {
            throw runtime_error("Indice invalido");
        }
        return array[idx - 1];
    }

    void insere(int idx, const T& item) {
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

    void remove(int idx) {
        if (idx < 1 || idx > tamanhoAtual) {
            throw runtime_error("Indice invalido");
        }
        for (int i = idx - 1; i < tamanhoAtual - 1; i++) {
            array[i] = array[i + 1];
        }
        tamanhoAtual--;
    }

    void exibe() const {
        for (int i = 0; i < tamanhoAtual; i++) {
            cerr << array[i] << " ";
        }
        cerr << endl;
    }

    int tamanho() const {
        return tamanhoAtual;
    }
};

#endif // LISTA_ARRAY_H
