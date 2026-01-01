#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pp pair<int, pair<int, int>>
int Find(vector<int>& parent, int node) {
    if (parent[node] != node)
        parent[node] = Find(parent, parent[node]);
    return parent[node];
}
void Union(vector<int>& parent, vector<int>& rank, int u, int v) {
    int rootU = Find(parent, u);
    int rootV = Find(parent, v);
    if (rootU == rootV) return;
    if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
    } else if (rank[rootU] > rank[rootV]) {
        parent[rootV] = rootU;
    } else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}
int main() {
    int V;
    cin >> V;
    vector<pp> edges; // Store edges as (weight, (u, v))
    // Read adjacency matrix
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            int weight;
            cin >> weight;
            if (weight != 0 && i < j) { // to avoid duplicates
                edges.push_back({weight, {i, j}});
            }
        }
    }
    // Sort edges by weight (ascending)
    sort(edges.begin(), edges.end());
    // DSU structures
    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; ++i)
        parent[i] = i;

    int minCost = 0;
    for (auto edge : edges) {
        int w = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if (Find(parent, u) != Find(parent, v)) {
            minCost += w;
            Union(parent, rank, u, v);
        }
    }
    cout << "Minimum Spanning Weight: " << minCost << endl;
    return 0;
}

