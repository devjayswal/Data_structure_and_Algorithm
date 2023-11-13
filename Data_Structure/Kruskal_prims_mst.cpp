#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <numeric>

using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}


int findpar(vector<int>& par, int v) {
    return (v == par[v]) ? v : (par[v] = findpar(par, par[v]));
}

void unionSets(vector<int>& par, vector<int>& rank, int u, int v) {
    int upar = findpar(par, u);
    int vpar = findpar(par, v);

    if (rank[upar] < rank[vpar])
        par[upar] = vpar;
    else if (rank[upar] > rank[vpar])
        par[vpar] = upar;
    else {
        par[vpar] = upar;
        rank[upar]++;
    }
}
vector<Edge> kruskal_mst(int V, vector<Edge>& edges) {
    vector<Edge> result;
    vector<int> par(V);
    vector<int> rank(V, 0);

    sort(edges.begin(), edges.end(), compareEdges);

    for (int v = 0; v < V; ++v) {
        par[v] = v;
    }

    int count = 0;
    int i = 0;

    while (count < V - 1 && i < edges.size()) {
        Edge curr = edges[i++];
        int srcpar = findpar(par, curr.src);
        int destpar = findpar(par, curr.dest);

        if (srcpar != destpar) {
            result.push_back(curr);
            unionSets(par, rank, srcpar, destpar);
            count++;
        }
    }

    return result;
}


vector<Edge> prims_mst(int V, vector<Edge>& edges) {
    vector<Edge> result;
    vector<int> par(V, -1);
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int src = 0;
    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (const auto& edge : edges) {
            int v = (edge.src == u) ? edge.dest : edge.src;
            int weight = edge.weight;

            if (inMST[v] == false && weight < key[v]) {
                key[v] = weight;
                par[v] = u;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    for (int i = 1; i < V; i++) {
        result.push_back({par[i], i, key[i]});
    }

    return result;
}

int main() {
    cout<<"Dev Jayswal"<<endl<<"0901AM221031"<<endl;
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge> edges;
    cout << "Enter the source, destination, and weight of each edge:\n";
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        edges.push_back({src, dest, weight});
    }

    // Kruskal MST
    vector<Edge> kruskalMST = kruskal_mst(V, edges);
    cout << "Kruskal's Minimum Spanning Tree:\n";
    for (const auto& edge : kruskalMST) {
        cout << edge.src << " -- " << edge.dest << " : " << edge.weight << endl;
    }

    // Prims MST
    vector<Edge> primsMST = prims_mst(V, edges);
    cout << "\nPrim's Minimum Spanning Tree:\n";
    for (const auto& edge : primsMST) {
        cout << edge.src << " -- " << edge.dest << " : " << edge.weight << endl;
    }

    return 0;
}
