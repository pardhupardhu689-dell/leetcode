class Solution {
public:

    void backtrack(vector<int>& candidates,
                   int target,
                   int start,
                   vector<int>& current,
                   vector<vector<int>>& result) {

        // Target reached
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicate numbers at the same level
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted, no need to continue
            if (candidates[i] > target)
                break;

            // Choose current number
            current.push_back(candidates[i]);

            // i + 1 because each number can be used only once
            backtrack(candidates,
                      target - candidates[i],
                      i + 1,
                      current,
                      result);

            // Undo choice
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                         int target) {

        vector<vector<int>> result;
        vector<int> current;

        // Sort to make duplicate handling possible
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0, current, result);

        return result;
    }
};