#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Lista {
public:
    
    virtual void insere(const T& item) = 0;
    virtual T pega(int idx) const = 0;
    virtual void remove(int idx) = 0;
    virtual void exibe() const = 0;
    virtual int tamanho() const = 0;
    virtual ~Lista() {}
};

#endif // LISTA_H
