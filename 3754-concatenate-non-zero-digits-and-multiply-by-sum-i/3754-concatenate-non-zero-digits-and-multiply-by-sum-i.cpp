class Solution {
public:
    long long sumAndMultiply(int n) {
        long long number = 0;
        int digitSum = 0;

        string s = to_string(n);

        for (char ch : s) {
            if (ch != '0') {
                int digit = ch - '0';
                number = number * 10 + digit;
                digitSum += digit;
            }
        }

        return number * digitSum;
    }
};