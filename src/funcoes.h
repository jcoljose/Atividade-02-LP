#ifndef FUNCOES
#define FUNCOES

#include <vector>
#include <set>
#include <map>
#include <list>
#include "Produto.h"
using namespace std;

bool existeProduto(const vector<Produto>& produtos, const string& nome);

void adicionarProduto(vector<Produto>& produtos,
                      set<string>& categorias,
                      map<string, int>& contagemPorCategoria,
                      map<string, double>& valorPorCategoria,
                      const Produto& p);

Produto* buscarProduto(vector<Produto>& produtos, const string& nome);

void listarPorCategoria(const vector<Produto>& produtos, const string& categoria);

double calcularValorTotal(const vector<Produto>& produtos);

void registrarVenda(vector<Produto>& produtos,
                    list<string>& historico,
                    const string& nome,
                    int qtd);

void adicionarEstoque(vector<Produto>& produtos, const string& nome, int qtd);

#endif
