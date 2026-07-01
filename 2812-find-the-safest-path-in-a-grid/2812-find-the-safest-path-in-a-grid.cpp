class Solution {
public:
    bool isValid(int x, int y, int n) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }

    bool canReach(vector<vector<int>>& dist, int limit) {
        int n = dist.size();

        if (dist[0][0] < limit || dist[n - 1][n - 1] < limit)
            return false;

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        q.push({0, 0});
        vis[0][0] = true;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == n - 1 && y == n - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (isValid(nx, ny, n) &&
                    !vis[nx][ny] &&
                    dist[nx][ny] >= limit) {

                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (isValid(nx, ny, n) &&
                    dist[nx][ny] == INT_MAX) {

                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        int left = 0;
        int right = 2 * n;
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canReach(dist, mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};