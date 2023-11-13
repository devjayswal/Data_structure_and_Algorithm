#include<iostream>
#include<list>
#include<vector>
#include<queue>

using namespace std;

class Graph {
    int V; 
    list<int> *adj;

public:
    Graph(int v) {
        V = v;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void BFS(int startVertex) {
        vector<bool> visited(V, false); 

        queue<int> q;
        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int currentVertex = q.front();
            cout << currentVertex << " ";
            q.pop();

            for (auto it = adj[currentVertex].begin(); it != adj[currentVertex].end(); ++it) {
                if (!visited[*it]) {
                    visited[*it] = true;
                    q.push(*it);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (auto it = adj[vertex].begin(); it != adj[vertex].end(); ++it) {
            if (!visited[*it]) {
                DFSUtil(*it, visited);
            }
        }
    }

    void DFS(int startVertex) {
        vector<bool> visited(V, false); 
        DFSUtil(startVertex, visited);
        cout << endl;
    }
};

int main() {
    cout<<"Dev Jayswal"<<endl<<"0901AM221031"<<endl;

    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter the source and destination vertex of each edge:\n";
    for (int i = 0; i < E; i++) {
        int src, dest;
        cin >> src >> dest;
        g.addEdge(src, dest);
    }

    int startVertex;
    cout << "Enter the starting vertex for BFS and DFS: ";
    cin >> startVertex;

    cout << "\nBFS traversal starting from vertex " << startVertex << ": ";
    g.BFS(startVertex);

    cout << "DFS traversal starting from vertex " << startVertex << ": ";
    g.DFS(startVertex);

    return 0;
}
