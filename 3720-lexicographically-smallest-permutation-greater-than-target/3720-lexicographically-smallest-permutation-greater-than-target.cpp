class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        // Try to make the answer greater at position i.
        for (int i = n - 1; i >= 0; i--) {

            // We need to use target[0 ... i-1] exactly.
            vector<int> cnt = freq;

            bool possible = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (cnt[x] == 0) {
                    possible = false;
                    break;
                }

                cnt[x]--;
            }

            if (!possible)
                continue;

            // At position i, choose the smallest character
            // strictly greater than target[i].
            int current = target[i] - 'a';

            for (int c = current + 1; c < 26; c++) {

                if (cnt[c] == 0)
                    continue;

                string ans = target.substr(0, i);

                ans += char('a' + c);
                cnt[c]--;

                // Put remaining characters in sorted order.
                for (int x = 0; x < 26; x++) {
                    ans += string(cnt[x], char('a' + x));
                }

                return ans;
            }
        }

        return "";
    }
};