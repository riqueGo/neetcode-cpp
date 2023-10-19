#include <iostream>
#include <queue>
#include <vector>
#include <array>

using std::queue;
using std::vector;
using std::array;

class Graph {
public:
    Graph() {}

    void addEdgeUndirected(vector <int> adj[], int from, int to) {
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    vector<int> bfsWalk(int node, int n, vector <int> adj[]) {
        int visitedArray[n] = {0};
        visitedArray[0] = 1;
        visitedArray[node] = 1;

        queue<int> visitedQueue;
        visitedQueue.push(node);

        vector<int> bfs;

        while (!visitedQueue.empty()) {
            int currNode = visitedQueue.front();
            visitedQueue.pop();

            bfs.push_back(currNode);

            for(auto& edge : adj[currNode]) {
                if(visitedArray[edge]) continue;

                visitedArray[edge] = 1;
                visitedQueue.push(edge);
            }
        }

        return bfs;
    }
};

int main() {
    Graph graph;
    vector <int> adj[6];

    graph.addEdgeUndirected(adj, 1, 5);
    graph.addEdgeUndirected(adj, 1, 2);
    graph.addEdgeUndirected(adj, 2, 3);
    graph.addEdgeUndirected(adj, 2, 5);
    graph.addEdgeUndirected(adj, 3, 5);
    graph.addEdgeUndirected(adj, 3, 4);
    graph.addEdgeUndirected(adj, 4, 5);

    vector<int> result = graph.bfsWalk(1, 6, adj);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
}