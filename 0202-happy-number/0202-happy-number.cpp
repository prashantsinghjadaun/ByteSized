class Solution {
public:
    int sumOfSquares(int num) {
        int result = 0;

        while (num > 0) {
            int digit = num % 10;
            result += digit * digit;
            num /= 10;
        }

        return result;
    }

    bool isHappy(int n) {
        unordered_set<int> visited;

        while (n != 1) {
            if (visited.count(n)) {
                return false;
            }

            visited.insert(n);
            n = sumOfSquares(n);
        }

        return true;
    }
};