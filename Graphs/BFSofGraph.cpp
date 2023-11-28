#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function to perform BFS traversal of the graph
void BFS(vector<vector<int>>& graph, int start) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> graph(numVertices);

    cout << "Enter the edges:\n";
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    cout << "BFS traversal: ";
    BFS(graph, startVertex);

    return 0;
}
