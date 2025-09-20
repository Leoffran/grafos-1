#include <bits/stdc++.h>
#include "grafo.h"

using namespace std;

int main(int argc, char* argv[]) {

    // Se houver ciclo euleriano imprime 1 e os vértices que o compõem, 
    // caso contrário imprime zero
    // Pra rodar:

    // levanta erro caso não sejam passados os argumentos corretos
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <arquivo_grafo>" << endl;
        return 1;
    } 

///// LER O ARQUIVO E CRIAR O GRAFO ///////////////////////////////////////

    // cria o grafo a partir do arquivo passado
    Grafo g(argv[1]);
    
    // pega a quantidade de vértices
    int n = g.qtdVertices();

    // vetor que marca true se um vertice já foi visitado
    vector<bool> visitado(n+1, false);
    
    // variável pra armazenar vertice de partida da BFS
    int start = -1;

    // encontra o primeiro vértice com grau > 0 para iniciar a BFS
    for (int i = 1; i <= n; i++) {
        if (g.grau(i) > 0) { 
            start = i; 
            break; 
        }
    }

    // se não houver nenhum vértice com arestas, grafo não tem ciclo Euleriano
    if (start == -1) { 
        cout << "0" << endl;
        return 0;
    }

///// INICIALIZAR O ALGORITMO /////////////////////////////////////////////

    // fila pra guardar os vertices a serem explorados
    queue<int> fila;

    // marca o vértice inicial (s) como visitado
    visitado[start] = true;

    // adiciona s na fila pra ser explorado
    fila.push(start);


///// LAÇO PRINCIPAL DA BUSCA EM LARGURA //////////////////////////////////

    // enquanto ainda houver vértices a serem explorados
    while(!fila.empty()) {

        // pega o vértice da fila
        int u = fila.front();
        fila.pop();

        // pra cada vértice vizinho
        for (int v : g.vizinhos(u)) {

            // se o vizinho ainda não foi visitado
            if (!visitado[v]) {

                // passa a ser visitado
                visitado[v] = true;

                // adiciona na fila pra ser explorado
                fila.push(v);

            }
        }
    }

    /////////// ainda tô fazendo

    return 0;
}