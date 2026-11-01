class Solution {
public:
    int minMoves(std::vector<int>& nums) {
        int min_val = INT_MAX;
        long long sum = 0; // Using long long to prevent integer overflow during summation
        
        for (int num : nums) {
            sum += num;
            if (num < min_val) {
                min_val = num;
            }
        }
        
        return sum - (1LL * min_val * nums.size());
    }
};