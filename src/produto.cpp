#include "produto.h"
#include <iostream>
using namespace std;

Produto::Produto(string n, string c, double p, int e)
    : nome(n), categoria(c), preco(p), estoque(e) {}

string Produto::getNome() const { return nome; }
string Produto::getCategoria() const { return categoria; }
double Produto::getPreco() const { return preco; }
int Produto::getEstoque() const { return estoque; }

void Produto::reduzirEstoque(int qtd) {
    if (qtd <= estoque) {
        estoque -= qtd;
    }
}

void Produto::aumentarEstoque(int qtd) {
    if (qtd > 0) {
        estoque += qtd;
    }
}

void Produto::exibir() const {
    cout << "Produto: " << nome
         << " | Categoria: " << categoria
         << " | Preço: R$ " << preco
         << " | Estoque: " << estoque << endl;
}
