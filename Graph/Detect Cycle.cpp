// Detect Cycle in Module Dependency Graph
// Given n modules labeled 0 to n-1 and a list of directed edges dependencies where [u, v] means module u depends on module v,
// return 1 if there is a cycle in the dependency graph, otherwise return 0.

// Input:n = 4,dependencies = [[1, 0], [2, 1], [3, 2]] 
// Output:0
bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& inStack) {
    visited[node] = 1;
    inStack[node] = 1;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, visited, inStack))
                return true;
        } else if (inStack[neighbor]) {
            return true;
        }
    }

    inStack[node] = 0; 
    return false;
}

bool hasCircularDependency(int n, vector<vector<int>> dependencies) {
    vector<vector<int>> adj(n);
    for (auto& dep : dependencies) {
        int u = dep[0], v = dep[1];
        adj[u].push_back(v);
    }

    vector<int> visited(n, 0); 
    vector<int> inStack(n, 0); 

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, inStack))
                return true;
        }
    }

    return false;
}
