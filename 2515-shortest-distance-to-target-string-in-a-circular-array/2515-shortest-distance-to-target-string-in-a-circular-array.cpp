class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int answer = n;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int distance = abs(i - startIndex);
                distance = min(distance, n - distance);

                answer = min(answer, distance);
            }
        }

        return answer == n ? -1 : answer;
    }
};