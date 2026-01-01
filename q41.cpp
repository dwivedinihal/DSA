#include <iostream>
#include <vector>
using namespace std;
void dfs(int u, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v, graph, visited);
        }
    }
}
int findMotherVertex(vector<vector<int>>& graph, int n) {
    vector<bool> visited(n, false);
    int candidate = 0;

    // Step 1: Find candidate mother vertex
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited);
            candidate = i;
        }
    }

    // Step 2: Check if candidate is mother vertex
    fill(visited.begin(), visited.end(), false);
    dfs(candidate, graph, visited);

    for (bool v : visited) {
        if (!v) return -1;  // no mother vertex
    }
    return candidate;
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph(n);

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;  // edge from u to v
        graph[u].push_back(v);
    }

    int mother = findMotherVertex(graph, n);
    if (mother == -1) cout << "No mother vertex found\n";
    else cout << mother << "\n";

    return 0;
}


