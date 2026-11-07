#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        vector<int> ans(m);

        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first == b.first ? a.second > b.second : a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> idle(cmp);
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> busy;

        for (int i = 0; i < n; ++i) idle.push({servers[i], i});

        long long curTime = 0;
        for (int j = 0; j < m; ++j) {
            curTime = max(curTime, (long long)j);

            while (!busy.empty() && get<0>(busy.top()) <= curTime) {
                auto [t, w, idx] = busy.top(); busy.pop();
                idle.push({w, idx});
            }

            if (idle.empty()) {
                curTime = get<0>(busy.top());
                while (!busy.empty() && get<0>(busy.top()) <= curTime) {
                    auto [t, w, idx] = busy.top(); busy.pop();
                    idle.push({w, idx});
                }
            }

            auto [w, idx] = idle.top(); idle.pop();
            ans[j] = idx;
            busy.push({curTime + tasks[j], w, idx});
        }
        return ans;
    }
};
