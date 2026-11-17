#include <iostream>

using namespace std;

class Graph {
    int V;
    int adj[20][20];

public:
    Graph(int v) {
        V = v;
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                adj[i][j] = 0;
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    void BFS(int startNode) {
        bool visited[20] = {false};
        int queue[20];
        int front = 0, rear = 0;

        visited[startNode] = true;
        queue[rear++] = startNode;

        while (front < rear) {
            int curr = queue[front++];
            cout << curr << " ";

            for (int i = 0; i < V; i++) {
                if (adj[curr][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    queue[rear++] = i;
                }
            }
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    g.BFS(0);
    return 0;
}