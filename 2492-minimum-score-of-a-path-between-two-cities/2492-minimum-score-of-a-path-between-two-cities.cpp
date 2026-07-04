class Solution {
public:
    void dfs(int node, vector<vector<pair<int, int>>>& graph,
             vector<bool>& visited, int& answer) {

        visited[node] = true;

        for (auto& edge : graph[node]) {
            int next = edge.first;
            int distance = edge.second;

            answer = min(answer, distance);

            if (!visited[next]) {
                dfs(next, graph, visited, answer);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n + 1);

        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int d = road[2];

            graph[u].push_back({v, d});
            graph[v].push_back({u, d});
        }

        vector<bool> visited(n + 1, false);
        int answer = INT_MAX;

        dfs(1, graph, visited, answer);

        return answer;
    }
};