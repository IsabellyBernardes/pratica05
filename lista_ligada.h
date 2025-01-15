#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
class ListaLigada {
private:
    // Classe para representar os nós da lista
    class No {
    public:
        T dado;
        No* prox;

        No(T dado, No* prox = nullptr) {
            this->dado = dado;
            this->prox = prox;
        }
    };

    No* inicio; // Ponteiro para o primeiro nó da lista
    int tamanhoAtual;

public:
    // Construtor padrão
    ListaLigada() {
        inicio = nullptr;
        tamanhoAtual = 0;
    }

    // Construtor com parâmetro de capacidade (compatibilidade com Lista baseada em arrays)
    ListaLigada(int capacidade) : ListaLigada() {
        (void)capacidade; // Ignora o parâmetro de capacidade
    }

    // Destrutor
    ~ListaLigada() {
        while (inicio != nullptr) {
            remove(1);
        }
    }

    static const int CAPACIDADE_MAX = 100;

    void adiciona(const T& item) {
        if (tamanhoAtual >= CAPACIDADE_MAX) {
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

    T pega(int idx) const {
        if (idx < 1 || idx > tamanhoAtual) {
            throw runtime_error("Indice invalido");
        }
        No* atual = inicio;
        for (int i = 1; i < idx; i++) {
            atual = atual->prox;
        }
        return atual->dado;
    }

    void insere(int idx, const T& item) {
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

    void remove(int idx) {
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

    void exibe() const {
        No* atual = inicio;
        while (atual != nullptr) {
            cerr << atual->dado << " ";
            atual = atual->prox;
        }
        cerr << endl;
    }


    int tamanho() const {
        return tamanhoAtual;
    }
};

#endif // LISTA_LIGADA_H
