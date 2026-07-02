class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> best(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;

        best[0][0] = startHealth;
        q.push({0, 0});

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == m - 1 && y == n - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                int remainingHealth = best[x][y] - grid[nx][ny];

                if (remainingHealth > 0 && remainingHealth > best[nx][ny]) {
                    best[nx][ny] = remainingHealth;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }
};