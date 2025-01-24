#ifndef FILA_H
#define FILA_H

#include <stdexcept>

using namespace std;

template <class T>
class Fila {
public:
    virtual ~Fila() {}

    virtual void enfileira(const T& item) = 0;
    virtual T desenfileira() = 0;
    virtual bool cheia() const = 0;
    virtual bool vazia() const = 0;
    virtual int tamanho() const = 0;
};

#endif // FILA_H
