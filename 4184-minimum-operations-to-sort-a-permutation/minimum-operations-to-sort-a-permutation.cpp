class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        if (is_sorted(nums.begin(), nums.end())) {
            return 0;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zero = i;
                break;
            }
        }
        bool forward = true;
        bool backward = true;
        for (int i = 0; i < n; i++) {
            if (nums[(zero + i) % n] != i)
                forward = false;

            if (nums[(zero - i + n) % n] != i)
                backward = false;
        }

        int ans = INT_MAX;
        if (forward) {
            ans = min(ans, zero);
            ans = min(ans, n - zero + 2);
        }
        if (backward) {
            ans = min(ans, zero + 2);
            ans = min(ans, n - zero);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};