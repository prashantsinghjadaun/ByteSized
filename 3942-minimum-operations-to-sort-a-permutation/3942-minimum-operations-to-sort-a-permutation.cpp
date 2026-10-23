#include <vector>
#include <algorithm>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        }
        
        auto it = std::find(nums.begin(), nums.end(), 0);
        int idx = std::distance(nums.begin(), it);
        
        bool is_increasing = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(idx + i) % n] != i) {
                is_increasing = false;
                break;
            }
        }
        
        if (is_increasing) {
            return std::min(idx, 2 + n - idx);
        }
        
        bool is_decreasing = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(idx - i + n) % n] != i) {
                is_decreasing = false;
                break;
            }
        }
        
        if (is_decreasing) {
            return std::min(idx + 2, n - idx);
        }
        
        return -1;
    }
};
