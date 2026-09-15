class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        if (n <= 1)
            return 0;

        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for (int i = 0; i < n - 1; i++) {
            // Farthest position reachable from the current range.
            farthest = max(farthest, i + nums[i]);

            // We have reached the end of the current jump.
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;

                // We can already reach the last index.
                if (currentEnd >= n - 1)
                    break;
            }
        }

        return jumps;
    }
};
