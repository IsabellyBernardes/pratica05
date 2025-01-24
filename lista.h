#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
class Lista {
public:
    virtual ~Lista() {}

    virtual void adiciona(const T& item) = 0;
    virtual T pega(int idx) const = 0;
    virtual void insere(int idx, const T& item) = 0;
    virtual void remove(int idx) = 0;
    virtual void exibe() const = 0;
    virtual int tamanho() const = 0;
};

#endif // LISTA_H
