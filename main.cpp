#include <iostream>
#include <limits>
#include "src/Produto.h"
#include "src/Funcoes.h"
using namespace std;

// Limpa buffer do cin após erros
void limparEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}

// Função genérica para ler um número double >= 0
double lerDoublePositivo(const string& mensagem) {
    double valor;
    while (true) {
        cout << mensagem;
        cin >> valor;

        if (cin.fail() || valor < 0) {
            limparEntrada();
            cout << "Valor inválido! Digite um valor não negativo.\n";
        } else {
            limparEntrada();
            return valor;
        }
    }
}

// Função genérica para ler um número int >= 0
int lerIntPositivo(const string& mensagem) {
    int n;
    while (true) {
        cout << mensagem;
        cin >> n;

        if (cin.fail() || n < 0) {
            limparEntrada();
            cout << "Valor inválido! Digite um número inteiro não negativo.\n";
        } else {
            limparEntrada();
            return n;
        }
    }
}

int main() {
    vector<Produto> produtos;
    set<string> categorias;
    map<string, int> contagemPorCategoria;
    map<string, double> valorPorCategoria;
    list<string> historico;

    int opcao;

    do {
        cout << "\n===== MENU LOJINHA LEGAL =====\n";
        cout << "1 - Listar produtos\n";
        cout << "2 - Adicionar produto\n";
        cout << "3 - Adicionar estoque a um produto\n";
        cout << "4 - Buscar produto\n";
        cout << "5 - Registrar venda\n";
        cout << "6 - Listar por categoria\n";
        cout << "7 - Mostrar valor total do inventário\n";
        cout << "8 - Mostrar histórico de vendas\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";

        cin >> opcao;

        if (cin.fail()) {
            limparEntrada();
            cout << "Entrada inválida! Tente novamente.\n";
            continue;
        }

        switch (opcao) {

        case 1: {
            cout << "\n=== Produtos no inventário ===\n";
            for (const auto& p : produtos)
                p.exibir();
            break;
        }

        case 2: {
            string nome, categoria;

            cout << "Nome do produto: ";
            limparEntrada();
            getline(cin, nome);

            // Verifica nome duplicado
            if (existeProduto(produtos, nome)) {
                cout << "Já existe um produto com esse nome! Escolha outro nome.\n";
                break;
            }
    
            cout << "Categoria: ";
            getline(cin, categoria);

            double preco = lerDoublePositivo("Preço do produto: R$ ");
            int estoque = lerIntPositivo("Quantidade em estoque: ");

            adicionarProduto(produtos, categorias, contagemPorCategoria,
                     valorPorCategoria, Produto(nome, categoria, preco, estoque));

            break;
        }

        case 3: {
            string nome;
            cout << "Nome do produto para adicionar estoque: ";
            limparEntrada();
            getline(cin, nome);

            Produto* p = buscarProduto(produtos, nome);
            if (!p) {
                cout << "Produto não encontrado!\n";
                break;
            }

            int qtd = lerIntPositivo("Quantidade para adicionar: ");

            if (qtd == 0) {
                cout << "Quantidade deve ser maior que zero.\n";
                break;
            }

            adicionarEstoque(produtos, nome, qtd);
            break;
        }

        case 4: {
            string nome;
            cout << "Digite o nome do produto: ";
            limparEntrada();
            getline(cin, nome);

            Produto* p = buscarProduto(produtos, nome);

            if (p) {
                cout << "\nProduto encontrado:\n";
                p->exibir();
            } else {
                cout << "Produto não encontrado.\n";
            }
            break;
        }

        case 5: {
            string nome;
            cout << "Produto vendido: ";
            limparEntrada();
            getline(cin, nome);

            int qtd = lerIntPositivo("Quantidade vendida: ");

            if (qtd == 0) {
                cout << "Quantidade deve ser maior que zero.\n";
                break;
            }

            registrarVenda(produtos, historico, nome, qtd);
            break;
        }

        case 6: {
            string categoria;
            cout << "Digite a categoria: ";
            limparEntrada();
            getline(cin, categoria);

            listarPorCategoria(produtos, categoria);
            break;
        }

        case 7: {
            cout << "\nValor total do inventário: R$ "
                 << calcularValorTotal(produtos) << endl;
            break;
        }

        case 8: {
            cout << "\n=== Histórico de vendas ===\n";
            for (const auto& h : historico)
                cout << h << endl;
            break;
        }

        case 0:
            cout << "Saindo do sistema...\n";
            break;

        default:
            cout << "Opção inválida!\n";
        }

    } while (opcao != 0);

    return 0;
}