#include <iostream>

using namespace std;

class Graph {
    int V;
    int adj[20][20];
    bool visited[20];

public:
    Graph(int v) {
        V = v;
        for (int i = 0; i < V; i++) {
            visited[i] = false;
            for (int j = 0; j < V; j++)
                adj[i][j] = 0;
        }
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    void DFS(int v) {
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < V; i++) {
            if (adj[v][i] == 1 && !visited[i])
                DFS(i);
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    g.DFS(0);
    return 0;
}