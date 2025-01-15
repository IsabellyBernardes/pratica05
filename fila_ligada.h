#ifndef FILA_LIGADA_H
#define FILA_LIGADA_H

#include <stdexcept>

using namespace std;

template <class T>
class FilaLigada {
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
    No* fim;   
    int tamanhoAtual;
    int capacidade;

public:
    FilaLigada(int capacidade) {
        this->capacidade = capacidade;
        this->inicio = nullptr;
        this->fim = nullptr;
        this->tamanhoAtual = 0;
    }

    ~FilaLigada() {
        while (!vazia()) {
            desenfileira();
        }
    }

    void enfileira(const T& item) {
        if (cheia()) {
            throw runtime_error("Fila cheia");
        }
        No* novo = new No(item);
        if (vazia()) {
            inicio = fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        tamanhoAtual++;
    }

    T desenfileira() {
        if (vazia()) {
            throw runtime_error("Fila vazia");
        }
        No* tmp = inicio;
        T dado = tmp->dado;
        inicio = inicio->prox;
        if (inicio == nullptr) {
            fim = nullptr;
        }
        delete tmp;
        tamanhoAtual--;
        return dado;
    }

    int cheia() const {
        return tamanhoAtual == capacidade;
    }

    int vazia() const {
        return tamanhoAtual == 0;
    }

    int tamanho() const {
        return tamanhoAtual;
    }
};

#endif // FILA_LIGADA_H