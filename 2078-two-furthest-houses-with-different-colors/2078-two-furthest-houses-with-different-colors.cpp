class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int answer = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (colors[i] != colors[j]) {
                    answer = max(answer, j - i);
                }
            }
        }

        return answer;
    }
};