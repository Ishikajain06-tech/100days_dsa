class Solution {
  public:
    void dfs(int u, int parent, vector<int> adj[], vector<int> &disc, 
             vector<int> &low, vector<bool> &visited, vector<bool> &ap, int &timer) {
        
        visited[u] = true;
        disc[u] = low[u] = timer++;
        int children = 0;

        for (int v : adj[u]) {
            // Ignore parent
            if (v == parent) continue;

            if (!visited[v]) {
                children++;
                dfs(v, u, adj, disc, low, visited, ap, timer);

                // Update low value
                low[u] = min(low[u], low[v]);

                // Condition for articulation point (non-root)
                if (parent != -1 && low[v] >= disc[u]) {
                    ap[u] = true;
                }
            }
            else {
                // Back edge
                low[u] = min(low[u], disc[v]);
            }
        }

        // Root node condition
        if (parent == -1 && children > 1) {
            ap[u] = true;
        }
    }

    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> disc(V, -1), low(V, -1);
        vector<bool> visited(V, false), ap(V, false);
        int timer = 0;

        // Run DFS for all components (though graph is connected)
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, adj, disc, low, visited, ap, timer);
            }
        }

        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (ap[i]) result.push_back(i);
        }

        // If no articulation point
        if (result.empty()) return {-1};

        return result;
    }
};
