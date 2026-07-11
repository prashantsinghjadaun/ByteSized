class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited,
             int& nodes, int& edges) {

        visited[node] = true;
        nodes++;
        edges += graph[node].size();

        for (int next : graph[node]) {
            if (!visited[next]) {
                dfs(next, graph, visited, nodes, edges);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int completeComponents = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int nodes = 0;
                int totalEdges = 0;

                dfs(i, graph, visited, nodes, totalEdges);

                totalEdges /= 2;

                if (totalEdges == nodes * (nodes - 1) / 2) {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }
};