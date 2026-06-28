class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int maxKeep = 0;

        for (int i = 0; i < n; i++) {
            long long limit = 1LL * nums[i] * k;

            int j = upper_bound(nums.begin(), nums.end(), limit) - nums.begin();

            maxKeep = max(maxKeep, j - i);
        }

        return n - maxKeep;
    }
};