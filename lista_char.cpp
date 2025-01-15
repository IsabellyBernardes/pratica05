#include <iostream>
#include "lista_array.h"
#include "lista_ligada.h"

using namespace std;

template <typename ListaTipo>
void testarListaChar(const string& tipoLista) {
	cerr << "Testando Lista de caracteres com " << tipoLista << ":" << endl;
	ListaTipo lista(10);

	lista.adiciona('a'); cerr << "Adicionado: a" << endl;// a
	lista.adiciona('b'); cerr << "Adicionado: b" << endl;// a b
	lista.adiciona('c'); cerr << "Adicionado: c" << endl;// a b c
	lista.adiciona('d'); cerr << "Adicionado: d" << endl;// a b c d
	lista.adiciona('e'); cerr << "Adicionado: e" << endl;// a b c d e
	lista.exibe(); // a b c d e

	lista.remove(3); cerr << "Removido na posicao 03" << endl;// a b d e
	lista.exibe(); // a b d e

	cerr << "Pega: " << lista.pega(4) << endl;// e
	lista.insere(2, 'f'); cerr << "Inserido na posicao 02: f" << endl;// a f b d e
	lista.exibe(); // a f b d e

	lista.adiciona('g'); cerr << "Adicionado: g" << endl;// a f b d e g
	lista.insere(4, 'h'); cerr << "Inserido na posicao 04: h" << endl;// a f b h d e g
	cerr << "Pega: " << lista.pega(2) << endl;// f
	lista.exibe(); // a f b h d e g

	cerr << "Fim do teste com " << tipoLista << "." << endl;
}

int mainChar() {
	testarListaChar<Lista<char>>("array");

	cerr << endl; // Adiciona uma linha em branco para separar as saídas

	testarListaChar<ListaLigada<char>>("ponteiros");

	return 0;
}
