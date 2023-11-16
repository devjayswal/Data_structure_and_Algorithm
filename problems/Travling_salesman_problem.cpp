#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();





class Node
{
public:
    int lev;
    vector<int> path;
    vector<bool> vis;
    int lowBound;
};

struct compare {
    bool operator()(const Node& a, const Node& b) const {
        return a.lowBound > b.lowBound;
    }
};

class Trav_selseman_pro
{
public:
    int n;
    int mincost;
    vector<int> bestPath;
    vector<vector<int>> gph;

    Trav_selseman_pro(int numCities)
    {
        n = numCities;
        mincost = INF;
        bestPath.assign(n + 1, 0);
        gph.assign(n, vector<int>(n, 0));
    }

    void addEdge(int u, int v, int wt)
    {
        gph[u][v] = wt;
        gph[v][u] = wt;
    }

    // Function to calculate the lower bound of a node
    int cal_low_bound(Node node)
    {
        int cost = 0;

        // Calculate the sum of the minimum and second minimum edge costs
        vector<int> min_edge(n, INF);
        vector<int> sec_min_edge(n, INF);
        for (int i = 0; i < node.lev; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!node.vis[j])
                {
                    if (gph[node.path[i]][j] <= min_edge[j])
                    {
                        sec_min_edge[j] = min_edge[j];
                        min_edge[j] = gph[node.path[i]][j];
                    }
                    else if (gph[node.path[i]][j] <= sec_min_edge[j])
                    {
                        sec_min_edge[j] = gph[node.path[i]][j];
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (min_edge[i] != INF && sec_min_edge[i] != INF)
            {
                cost += min_edge[i] + sec_min_edge[i];
            }
        }

        return cost / 2;
    }

    // Branch and Bound algorithm
   void branch_and_bound() {
    priority_queue<Node, vector<Node>, compare> pq;

    Node root;
    root.path.push_back(0);
    root.vis.assign(n, false);
    root.vis[0] = true;
    root.lev = 1;
    root.lowBound = cal_low_bound(root);
    pq.push(root);

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        // If the current node has a higher lower bound than the best cost, prune it
        if (current.lowBound > mincost) {
            continue;
        }

        if (current.lev == n) { // Reached the leaf node
            current.path.push_back(current.path[0]);
            
            // Calculate the actual cost of the path
            int actualCost = 0;
            for (int i = 0; i < n; i++) {
                actualCost += gph[current.path[i]][current.path[i+1]];
            }

            if (mincost > actualCost) {
                bestPath = current.path;
                mincost = actualCost;
            }
            continue;
        }

        for (int i = 0; i < n; i++) {
            if (!current.vis[i]) {
                Node newNode;
                newNode.path = current.path;
                newNode.path.push_back(i);
                newNode.vis = current.vis;
                newNode.vis[i] = true;
                newNode.lev = current.lev + 1;
                newNode.lowBound = cal_low_bound(newNode);

                pq.push(newNode);
            }
        }
    }
}

};

int main()
{
    int tottal_citi = 4;
    Trav_selseman_pro bbtsp(tottal_citi);

    // Add edges and their weights
    bbtsp.addEdge(0, 1, 10);
    bbtsp.addEdge(0, 2, 15);
    bbtsp.addEdge(0, 3, 20);
    bbtsp.addEdge(1, 2, 35);
    bbtsp.addEdge(1, 3, 25);
    bbtsp.addEdge(2, 3, 30);

    // Run the Branch and Bound algorithm
    bbtsp.branch_and_bound();

    // Print the optimal path and its cost
    cout << "Optimal Path: ";
    for (int i = 0; i < tottal_citi + 1; i++)
    {
        cout << bbtsp.bestPath[i] << " ";
    }
    cout << endl;

    cout << "Optimal Cost: " << bbtsp.mincost << endl;

    return 0;
}
