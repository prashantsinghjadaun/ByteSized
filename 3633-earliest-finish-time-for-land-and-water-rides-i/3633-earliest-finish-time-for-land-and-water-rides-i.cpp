class Solution {
public:
    int calculate(vector<int>& firstStart, vector<int>& firstDuration,
                  vector<int>& secondStart, vector<int>& secondDuration) {

        int earliestEnd = INT_MAX;

        for (int i = 0; i < firstStart.size(); i++) {
            earliestEnd = min(earliestEnd, firstStart[i] + firstDuration[i]);
        }

        int answer = INT_MAX;

        for (int i = 0; i < secondStart.size(); i++) {
            int startTime = max(earliestEnd, secondStart[i]);
            answer = min(answer, startTime + secondDuration[i]);
        }

        return answer;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int landFirst = calculate(landStartTime, landDuration,
                                  waterStartTime, waterDuration);

        int waterFirst = calculate(waterStartTime, waterDuration,
                                   landStartTime, landDuration);

        return min(landFirst, waterFirst);
    }
};