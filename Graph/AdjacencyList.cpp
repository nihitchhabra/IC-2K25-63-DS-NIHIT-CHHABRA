#include <iostream>

using namespace std;

struct Node {
    int dest;
    Node* next;
};

struct AdjList {
    Node* head;
};

class Graph {
    int V;
    AdjList* array;

public:
    Graph(int v) {
        V = v;
        array = new AdjList[V];
        for (int i = 0; i < V; ++i)
            array[i].head = nullptr;
    }

    void addEdge(int src, int dest) {
        Node* newNode = new Node();
        newNode->dest = dest;
        newNode->next = array[src].head;
        array[src].head = newNode;

        Node* newNode2 = new Node();
        newNode2->dest = src;
        newNode2->next = array[dest].head;
        array[dest].head = newNode2;
    }

    void printGraph() {
        for (int v = 0; v < V; ++v) {
            Node* pCrawl = array[v].head;
            cout << v;
            while (pCrawl) {
                cout << " -> " << pCrawl->dest;
                pCrawl = pCrawl->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.printGraph();
    return 0;
}