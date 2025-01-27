#ifndef LISTA_ARRAY_H
#define LISTA_ARRAY_H

#include "lista.h"
#include <stdexcept>
#include <iostream>

template <typename T>
class ListaArray : public Lista<T> {
private:
    T* dados;       
    int capacidade;     
    int tamanhoAtual;   

public:

    ListaArray(int capacidadeMax) : capacidade(capacidadeMax), tamanhoAtual(0) {
        dados = new T[capacidade];  
    }

    ~ListaArray() {
        delete[] dados; 
    }

    void adiciona(const T& valor) {
        if (cheia()) {
            throw std::runtime_error("Lista cheia");
        }
        dados[tamanhoAtual++] = valor;  
    }

    void insere(const T& valor) override {
        adiciona(valor);
    }

    T pega(int idx) const override {
        if (idx < 1 || idx > tamanhoAtual) {  
            throw std::out_of_range("Índice fora dos limites da lista");
        }
        return dados[idx - 1]; 
    }

    void remove(int idx) override {
        if (idx < 1 || idx > tamanhoAtual) {
            throw std::out_of_range("Índice fora dos limites da lista");
        }
        for (int i = idx - 1; i < tamanhoAtual - 1; ++i) {
            dados[i] = dados[i + 1];  
        }
        tamanhoAtual--;  
    }

    void exibe() const override {
        for (int i = 0; i < tamanhoAtual; ++i) {
            std::cout << dados[i] << " ";
        }
        std::cout << std::endl;
    }

    bool cheia() const {
        return tamanhoAtual == capacidade;
    }

    bool vazia() const {
        return tamanhoAtual == 0;
    }

    int tamanho() const override {
        return tamanhoAtual;
    }
};

#endif // LISTA_ARRAY_H
