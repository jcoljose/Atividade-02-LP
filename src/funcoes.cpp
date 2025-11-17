#include "funcoes.h"
#include <iostream>

bool existeProduto(const vector<Produto>& produtos, const string& nome) {
    for (const auto& p : produtos)
        if (p.getNome() == nome)
            return true;
    return false;
}

void adicionarProduto(vector<Produto>& produtos,
                      set<string>& categorias,
                      map<string, int>& contagemPorCategoria,
                      map<string, double>& valorPorCategoria,
                      const Produto& p)
{
    if (existeProduto(produtos, p.getNome())) {
        cout << "Erro: já existe um produto com esse nome!\n";
        return;
    }

    produtos.push_back(p);
    categorias.insert(p.getCategoria());
    contagemPorCategoria[p.getCategoria()]++;
    valorPorCategoria[p.getCategoria()] += p.getPreco() * p.getEstoque();

    cout << "Produto adicionado com sucesso!\n";
}

Produto* buscarProduto(vector<Produto>& produtos, const string& nome) {
    for (auto& p : produtos) {
        if (p.getNome() == nome) {
            return &p;
        }
    }
    return nullptr;
}

void listarPorCategoria(const vector<Produto>& produtos, const string& categoria) {
    cout << "\nProdutos da categoria '" << categoria << "':\n";
    for (const auto& p : produtos) {
        if (p.getCategoria() == categoria) {
            p.exibir();
        }
    }
}

double calcularValorTotal(const vector<Produto>& produtos) {
    double total = 0;
    for (const auto& p : produtos) {
        total += p.getPreco() * p.getEstoque();
    }
    return total;
}

void registrarVenda(vector<Produto>& produtos,
                    list<string>& historico,
                    const string& nome,
                    int qtd)
{
    Produto* p = buscarProduto(produtos, nome);

    if (!p) {
        cout << "Produto não encontrado!\n";
        return;
    }

    if (qtd > p->getEstoque()) {
        cout << "Estoque insuficiente!\n";
        return;
    }

    p->reduzirEstoque(qtd);

    historico.push_back("Venda: " + nome + " (quantidade: " + to_string(qtd) + ")");
    cout << "Venda registrada!\n";
}

void adicionarEstoque(vector<Produto>& produtos, const string& nome, int qtd) {
    Produto* p = buscarProduto(produtos, nome);

    if (!p) {
        cout << "Produto não encontrado!\n";
        return;
    }

    if (qtd <= 0) {
        cout << "Quantidade deve ser maior que zero!\n";
        return;
    }

    p->aumentarEstoque(qtd);
    cout << "Estoque atualizado com sucesso! Novo estoque: " << p->getEstoque() << endl;
}
