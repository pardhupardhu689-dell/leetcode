class Solution {
public:
    vector<string> result;

    void backtrack(string& digits, int index,
                   string current, vector<string>& phone) {
        
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string letters = phone[digits[index] - '0'];

        for (char ch : letters) {
            backtrack(digits, index + 1,
                      current + ch, phone);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        vector<string> phone = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        backtrack(digits, 0, "", phone);

        return result;
    }
};