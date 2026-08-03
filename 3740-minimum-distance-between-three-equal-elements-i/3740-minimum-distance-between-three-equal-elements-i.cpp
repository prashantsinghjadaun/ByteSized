class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> positions;

        for (int i = 0; i < nums.size(); i++) {
            positions[nums[i]].push_back(i);
        }

        int answer = INT_MAX;

        for (auto &entry : positions) {
            vector<int>& index = entry.second;

            if (index.size() < 3)
                continue;

            for (int i = 0; i + 2 < index.size(); i++) {
                answer = min(answer, 2 * (index[i + 2] - index[i]));
            }
        }

        return answer == INT_MAX ? -1 : answer;
    }
};