class Solution {
public:
    string countAndSay(int n) {

        string s = "1";

        for (int i = 2; i <= n; i++) {

            string next = "";

            for (int j = 0; j < s.length(); ) {

                int count = 0;
                char ch = s[j];

                // Count consecutive same characters
                while (j < s.length() && s[j] == ch) {
                    count++;
                    j++;
                }

                // Add count + character
                next += to_string(count);
                next += ch;
            }

            s = next;
        }

        return s;
    }
};