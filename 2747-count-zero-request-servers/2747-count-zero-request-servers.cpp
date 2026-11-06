#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const auto& a, const auto& b) { return a[1] < b[1]; });
        
        int m = queries.size();
        vector<pair<int, int>> sq(m);
        for (int i = 0; i < m; ++i) sq[i] = {queries[i], i};
        sort(sq.begin(), sq.end());

        unordered_map<int, int> counts;
        vector<int> ans(m);
        int left = 0, right = 0, logSize = logs.size();

        for (const auto& [time, idx] : sq) {
            while (right < logSize && logs[right][1] <= time) {
                counts[logs[right][0]]++;
                right++;
            }
            while (left < logSize && logs[left][1] < time - x) {
                if (--counts[logs[left][0]] == 0) counts.erase(logs[left][0]);
                left++;
            }
            ans[idx] = n - counts.size();
        }
        return ans;
    }
};
