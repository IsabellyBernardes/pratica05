#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

#include "lista.h"
#include <stdexcept>

template <typename T>
class ListaLigada : public Lista<T> {
private:
    int capacidadeMaxima;  
    struct No {
        T dado;
        No* proximo;
        No(const T& dado) : dado(dado), proximo(nullptr) {}
    };

    No* inicio;
    No* fim;
    int tamanhoAtual;

public:
    
    ListaLigada(int capacidade = 100) : capacidadeMaxima(capacidade), tamanhoAtual(0), inicio(nullptr), fim(nullptr) {}

    
    void insere(const T& item) override { //complexidade O(1)
        if (tamanhoAtual >= capacidadeMaxima) {  
            throw std::runtime_error("Lista cheia");
        }
        No* novoNo = new No(item);  
        if (fim != nullptr) { 
            fim->proximo = novoNo;
        } else { 
            inicio = novoNo;
        }
        fim = novoNo;  
        tamanhoAtual++; 
    }

    T pega(int idx) const {
        if (idx < 1 || idx > tamanhoAtual) {
            throw std::out_of_range("Índice inválido");
        }

        No* atual = inicio;
        for (int i = 1; i < idx; ++i) {
            atual = atual->proximo; 
        }

        return atual->dado; 
    }

    void remove(int idx) {
        if (idx < 1 || idx > tamanhoAtual) {
            throw std::runtime_error("Índice inválido");
        }

        No* anterior = nullptr;
        No* atual = inicio;

        for (int i = 1; i < idx; ++i) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (anterior == nullptr) {
            inicio = atual->proximo;  
        } else {
            anterior->proximo = atual->proximo; 
        }

        if (atual == fim) {
            fim = anterior; 
        }

        delete atual;
        tamanhoAtual--;  
    }

    void exibe() const {
        No* atual = inicio;
        while (atual != nullptr) {
            std::cout << atual->dado << " ";
            atual = atual->proximo;
        }
        std::cout << std::endl;
    }

    int tamanho() const {
        return tamanhoAtual;
    }

    ~ListaLigada() {
        No* atual = inicio;
        while (atual != nullptr) {
            No* temp = atual;
            atual = atual->proximo;
            delete temp;
        }
    }
};

#endif // LISTA_LIGADA_H
