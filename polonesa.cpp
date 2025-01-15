#include <iostream>
#include "pilha_array.h"
#include "pilha_ligada.h"

using namespace std;

int ehOperador(char token) {
	switch (token) {
		case '+':
		case '-':
		case '*':
		case '/':
			return 1;
		default:
			return 0;
	}
}

int avalia(char token, int valorEsq, int valorDir) {
	switch (token) {
		case '+':
			return valorEsq + valorDir;
		case '-':
			return valorEsq - valorDir;
		case '*':
			return valorEsq * valorDir;
		case '/':
			return valorEsq / valorDir;
		default:
			return 0;
	}
}

template <typename PilhaTipo>
int polonesa(const char *exp) {
	PilhaTipo pilha(10);

	while (*exp) {
		char token = *exp;

		if (ehOperador(token)) {
			if (pilha.tamanho() < 2) {
				throw runtime_error("Pilha vazia");
			}
			int valorDir = pilha.desempilha();
			int valorEsq = pilha.desempilha();
			int resultado = avalia(token, valorEsq, valorDir);
			pilha.empilha(resultado);
		} else if (isdigit(token)) {
			int valor = token - '0';
			pilha.empilha(valor);
		} else {
			cerr << "Token invalido: " << token << endl;
		}
		exp++;
	}

	if (pilha.tamanho() == 1) {
		return pilha.desempilha();
	} else {
		throw runtime_error("Expression mal formada");
	}
}

int mainPol() {
	cerr << "Testando expressao polonesa com array:" << endl;
	cerr << "Resultado 1 (array): " << polonesa<Pilha<int>>("23+31-*") << endl;
	cerr << "Resultado 2 (array): " << polonesa<Pilha<int>>("93*42/-") << endl;

	cerr << "\nTestando expressao polonesa com ponteiros:" << endl;
	cerr << "Resultado 3 (ponteiros): " << polonesa<PilhaLigada<int>>("23+31-*") << endl;
	cerr << "Resultado 4 (ponteiros): " << polonesa<PilhaLigada<int>>("93*42/-") << endl;

	return 0;
}
