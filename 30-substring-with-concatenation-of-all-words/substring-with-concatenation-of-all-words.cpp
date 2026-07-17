class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;

        int wordLen = words[0].size();
        int wordCount = words.size();

        unordered_map<string, int> required;

        for (string& word : words)
            required[word]++;

        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int count = 0;

            unordered_map<string, int> current;

            for (int right = i; right + wordLen <= s.size();
                 right += wordLen) {

                string word = s.substr(right, wordLen);

                if (required.count(word)) {
                    current[word]++;
                    count++;

                    while (current[word] > required[word]) {
                        string leftWord = s.substr(left, wordLen);
                        current[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == wordCount) {
                        result.push_back(left);

                        string leftWord = s.substr(left, wordLen);
                        current[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                } else {
                    current.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return result;
    }
};