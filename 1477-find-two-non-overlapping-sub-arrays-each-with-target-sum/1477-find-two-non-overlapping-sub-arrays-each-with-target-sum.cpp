#include <vector>
#include <algorithm>

class Solution {
public:
    int minSumOfLengths(std::vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;
        
        std::vector<int> dp(n, INF);
        
        int left = 0;
        int current_sum = 0;
        int min_combined_len = INF;
        int best_single_len = INF; 
        
        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];
            
            while (current_sum > target) {
                current_sum -= arr[left];
                left++;
            }
            
            if (current_sum == target) {
                int current_len = right - left + 1;
                
                if (left > 0 && dp[left - 1] != INF) {
                    min_combined_len = std::min(min_combined_len, current_len + dp[left - 1]);
                }
                
                best_single_len = std::min(best_single_len, current_len);
            }
            
            dp[right] = best_single_len;
        }
        
        return (min_combined_len >= INF) ? -1 : min_combined_len;
    }
};
