class Solution {
public:
    unordered_map<string, bool> memo;

    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.size() != s2.size()) return false;

        string key = s1 + "#" + s2;
        if (memo.count(key)) return memo[key];

        // check if the frequency of characters matches
        if (!hasSameChars(s1, s2)) {
            memo[key] = false;
            return false;
        }

        int n = s1.size();
        for (int i = 1; i < n; i++) {
            // Case 1: No swap
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }

            // Case 2: Swap
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                isScramble(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }

    bool hasSameChars(const string &a, const string &b) {
        int count[26] = {0};
        for (char c : a) count[c - 'a']++;
        for (char c : b) count[c - 'a']--;
        for (int i = 0; i < 26; i++)
            if (count[i] != 0) return false;
        return true;
    }
};
