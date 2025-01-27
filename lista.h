#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Lista {
public:
    // Método virtual puro para inserir um item
    virtual void insere(const T& item) = 0;

    // Método virtual puro para obter um item pelo índice
    virtual T pega(int idx) const = 0;

    // Método virtual puro para remover um item pelo índice
    virtual void remove(int idx) = 0;

    // Método virtual puro para exibir os itens da lista
    virtual void exibe() const = 0;

    // Método virtual puro para obter o tamanho da lista
    virtual int tamanho() const = 0;

    // Destrutor virtual
    virtual ~Lista() {}
};

#endif // LISTA_H
