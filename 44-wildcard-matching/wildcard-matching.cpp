class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        // dp[j] = whether current s-prefix matches p[0...j-1]
        vector<bool> dp(m + 1, false);

        // Empty string matches only a pattern consisting entirely of '*'.
        dp[0] = true;

        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*')
                dp[j] = dp[j - 1];
            else
                break;
        }

        for (int i = 1; i <= n; i++) {
            bool prev = dp[0];

            // Non-empty string cannot match an empty pattern.
            dp[0] = false;

            for (int j = 1; j <= m; j++) {
                bool old = dp[j];

                if (p[j - 1] == '*') {
                    // '*' either:
                    // 1. matches empty -> dp[j]
                    // 2. matches current character -> dp[j] from previous row
                    dp[j] = dp[j] || dp[j - 1];
                } else {
                    // '?' or exact character match.
                    dp[j] = prev &&
                            (p[j - 1] == '?' || p[j - 1] == s[i - 1]);
                }

                prev = old;
            }
        }

        return dp[m];
    }
};
