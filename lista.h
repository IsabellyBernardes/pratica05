#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class Lista {
private:
    T* items;         // Array de itens
    int capacidade;   // Capacidade máxima da lista
    int tamanhoAtual; // Número de itens atualmente na lista

public:
    Lista(int capacidade) {
        this->capacidade = capacidade;
        this->items = new T[capacidade];
        this->tamanhoAtual = 0; // Inicializa a lista vazia
    }

    ~Lista() {
        delete[] items; // Destruição do array
    }

    // Adiciona um item ao final da lista
    void adiciona(const T& item) {
        if (tamanhoAtual >= capacidade) {
            throw runtime_error("Lista cheia"); // Lança exceção se capacidade esgotada
        }
        items[tamanhoAtual++] = item; // Adiciona item ao final da lista
    }

    // Retorna um item pelo índice (começa em 1)
    T pega(int idx) const {
        if (idx < 1 || idx > tamanhoAtual) {
            throw runtime_error("Indice invalido"); // Lança exceção se posição inválida
        }
        return items[idx - 1]; // Retorna o item na posição especificada
    }

    // Insere um item na posição indicada (a partir de 1)
    void insere(int idx, const T& item) {
        if (idx < 1 || idx > tamanhoAtual + 1) {
            throw runtime_error("Indice invalido"); // Lança exceção se posição inválida
        }
        if (tamanhoAtual >= capacidade) {
            throw runtime_error("Lista cheia"); // Lança exceção se capacidade esgotada
        }
        for (int i = tamanhoAtual; i >= idx; i--) {
            items[i] = items[i - 1]; // Desloca itens existentes para a direita
        }
        items[idx - 1] = item; // Insere o item na posição especificada
        tamanhoAtual++;
    }

    // Remove o item de uma posição indicada (a partir de 1)
    void remove(int idx) {
        if (idx < 1 || idx > tamanhoAtual) {
            throw runtime_error("Indice invalido"); // Lança exceção se posição inválida
        }
        for (int i = idx - 1; i < tamanhoAtual - 1; i++) {
            items[i] = items[i + 1]; // Desloca itens uma posição à esquerda
        }
        tamanhoAtual--;
    }

    // Exibe os itens da saída padrão separados por espaços
    void exibe() const {
        for (int i = 0; i < tamanhoAtual; i++) {
            cout << items[i] << " "; // Exibe os itens da lista
        }
        cout << endl;
    }

    // Retorna a quantidade de itens atualmente na lista
    int tamanho() const {
        return tamanhoAtual;
    }
};

#endif // LISTA_H
