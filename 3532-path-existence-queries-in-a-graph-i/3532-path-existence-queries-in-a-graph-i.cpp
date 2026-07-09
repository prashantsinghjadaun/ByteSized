class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int node) {
        if (parent[node] != node)
            parent[node] = find(parent[node]);

        return parent[node];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV)
            return;

        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {

        parent.resize(n);
        rank.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                unite(i, i - 1);
            }
        }

        vector<bool> answer;

        for (auto& query : queries) {
            answer.push_back(find(query[0]) == find(query[1]));
        }

        return answer;
    }
};