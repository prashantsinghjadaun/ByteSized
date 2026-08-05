class Solution {
public:
    void markSuspicious(int node, vector<vector<int>>& graph, vector<bool>& suspicious) {
        suspicious[node] = true;

        for (int next : graph[node]) {
            if (!suspicious[next]) {
                markSuspicious(next, graph, suspicious);
            }
        }
    }

    void restoreMethods(int node, vector<vector<int>>& graph,
                        vector<bool>& suspicious, vector<bool>& visited) {
        visited[node] = true;
        suspicious[node] = false;

        for (int next : graph[node]) {
            if (!visited[next]) {
                restoreMethods(next, graph, suspicious, visited);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> directed(n);
        vector<vector<int>> undirected(n);

        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            directed[u].push_back(v);

            undirected[u].push_back(v);
            undirected[v].push_back(u);
        }

        vector<bool> suspicious(n, false);
        markSuspicious(k, directed, suspicious);

        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!suspicious[i] && !visited[i]) {
                restoreMethods(i, undirected, suspicious, visited);
            }
        }

        vector<int> answer;

        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) {
                answer.push_back(i);
            }
        }

        return answer;
    }
};