#ifndef PRODUTO
#define PRODUTO

#include <string>
using namespace std;

class Produto {
private:
    string nome;
    string categoria;
    double preco;
    int estoque;

public:
    Produto(string n, string c, double p, int e);

    string getNome() const;
    string getCategoria() const;
    double getPreco() const;
    int getEstoque() const;

    void reduzirEstoque(int qtd);
    void aumentarEstoque(int qtd);
    void exibir() const;
};

#endif
