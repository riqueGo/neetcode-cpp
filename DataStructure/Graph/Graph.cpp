#include <iostream>
#include <vector>

using std::vector;

//Space O(n²)
void matrixUndirectedGraph() {
    int n, m;
    std::cin >> n >> m;

    int adj[n+1][n+1];
    for (int i = 0; i < m; i++){
        int u, v;
        std::cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

//Space O(n²)
void matrixDirectedGraph() {
    int n, m;
    std::cin >> n >> m;

    int adj[n+1][n+1];
    for (int i = 0; i < m; i++){
        int u, v;
        std::cin >> u >> v;
        adj[u][v] = 1;
    }
}

//Space O(2*E)
void listUndirectedGraph() {
    int n, m;
    std::cin >> n >> m;

    vector<int> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

//Space O(E)
void listDirectedGraph() {
    int n, m;
    std::cin >> n >> m;

    vector<int> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
    }
}