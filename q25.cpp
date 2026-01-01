#include <bits/stdc++.h>

using namespace std;
void floydWarshall(vector<vector<int>> &adj) {
    int V = adj.size();
    vector<vector<int>> dist = adj;
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            cout << "Negative weight cycle detected.\n";
            break;
        }
    }
    cout << "\nShortest distance matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int V,e;
    cin >> V>>e;
    vector<vector<int>> adj(V,vector<int>(V,INT_MAX));
    for(int i=0;i<V;i++){
        adj[i][i]=0;
    }
    for(int i=0;i<e;i++){
        int u,v,w;
        cin >>u>>v>>w;
        adj[u][v]=w;
    }
    floydWarshall(adj);
    return 0;
}
