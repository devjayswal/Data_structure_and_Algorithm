#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;


struct Node 
{
    int vt;
    int dis;
};


struct Compare 
{
    bool operator()(Node& a, Node& b) 
    {
        return a.dis > b.dis;
    }
};

void Dijkstra(vector<vector<pair<int, int>>>& graph,
                 int src, vector<int>& dist,
                  vector<int>& par) 
{
    int V = graph.size();
    dist.clear();
    par.clear();
    dist.assign(V, INT_MAX);
    par.assign(V, -1);

    priority_queue<Node, vector<Node>, Compare> pq;
    pq.push({src, 0});
    dist[src] = 0;

    while (!pq.empty()) 
    {
        int u = pq.top().vt;
        int uDist = pq.top().dis;
        pq.pop();

        if (uDist != dist[u]) 
        {
            continue;
        }

        for (const auto& neighbor : graph[u]) 
        {
            int v = neighbor.first;
            int wt = neighbor.second;

            if (uDist + wt < dist[v]) 
            {
                dist[v] = uDist + wt;
                par[v] = u;
                pq.push({v, dist[v]});
            }
        }
    }
}

int main() {
    cout<<"Dev Jayswal"<<endl<<"0901AM221031"<<endl;

    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<pair<int, int>>> graph(V);

    cout << "Enter the source, destination, and wt of each edge:\n";
    for (int i = 0; i < E; i++) 
    {
        int src, dest, wt;
        cin >> src >> dest >> wt;
        graph[src].push_back({dest, wt});
        graph[dest].push_back({src, wt}); 
    }

    int src;
    cout << "Enter the source vt: ";
    cin >> src;

    vector<int> dist, par;
    Dijkstra(graph, src, dist, par);

    cout << "\nShortest paths from vt " << src << " to all other vertices:\n";
    for (int i = 0; i < V; i++) {
        cout << "vt " << i << ": ";
        if (dist[i] == INT_MAX) {
            cout << "No path" << endl;
        } else {
            cout << dist[i] << " (Path: ";
            int curr = i;
            cout << curr;
            while (par[curr] != -1) {
                cout << " <- " << par[curr];
                curr = par[curr];
            }
            cout << ")" << endl;
        }
    }

    return 0;
}
