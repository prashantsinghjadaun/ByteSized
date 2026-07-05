class Solution {
public:
    void generate(string current, int n, vector<string>& happyStrings) {
        if (current.size() == n) {
            happyStrings.push_back(current);
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (current.empty() || current.back() != ch) {
                generate(current + ch, n, happyStrings);
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> happyStrings;

        generate("", n, happyStrings);

        if (k > happyStrings.size())
            return "";

        return happyStrings[k - 1];
    }
};