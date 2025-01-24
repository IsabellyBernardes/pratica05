#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

#include <iostream>
#include <stdexcept>
#include "lista.h"

using namespace std;

template <class T>
class ListaLigada : public Lista<T> {
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

    No* inicio;
    int tamanhoAtual;
    int capacidadeMax;  // Agora a capacidade máxima será configurada pelo construtor

public:
    ListaLigada(int capacidadeMax) : Lista<T>(), inicio(nullptr), tamanhoAtual(0), capacidadeMax(capacidadeMax) {}

    ~ListaLigada() {
        while (inicio != nullptr) {
            remove(1);
        }
    }

    void adiciona(const T& item) {
        if (tamanhoAtual == capacidadeMax) {
            throw runtime_error("Lista cheia");
        }

        No* novo = new No(item);
        if (inicio == nullptr) {
            inicio = novo;
        } else {
            No* atual = inicio;
            while (atual->prox != nullptr) {
                atual = atual->prox;
            }
            atual->prox = novo;
        }
        tamanhoAtual++;
    }

    T pega(int idx) const override {
        if (idx < 1 || idx > tamanhoAtual) {
            throw runtime_error("Indice invalido");
        }
        No* atual = inicio;
        for (int i = 1; i < idx; i++) {
            atual = atual->prox;
        }
        return atual->dado;
    }

    void insere(int idx, const T& item) override {
        if (idx < 1 || idx > tamanhoAtual + 1) {
            throw runtime_error("Indice invalido");
        }
        No* novo = new No(item);
        if (idx == 1) {
            novo->prox = inicio;
            inicio = novo;
        } else {
            No* atual = inicio;
            for (int i = 1; i < idx - 1; i++) {
                atual = atual->prox;
            }
            novo->prox = atual->prox;
            atual->prox = novo;
        }
        tamanhoAtual++;
    }

    void remove(int idx) override {
        if (idx < 1 || idx > tamanhoAtual) {
            throw runtime_error("Indice invalido");
        }
        No* removido;
        if (idx == 1) {
            removido = inicio;
            inicio = inicio->prox;
        } else {
            No* atual = inicio;
            for (int i = 1; i < idx - 1; i++) {
                atual = atual->prox;
            }
            removido = atual->prox;
            atual->prox = removido->prox;
        }
        delete removido;
        tamanhoAtual--;
    }

    void exibe() const override {
        No* atual = inicio;
        while (atual != nullptr) {
            cerr << atual->dado << " ";
            atual = atual->prox;
        }
        cerr << endl;
    }

    int tamanho() const override {
        return tamanhoAtual;
    }
};

#endif // LISTA_LIGADA_H
