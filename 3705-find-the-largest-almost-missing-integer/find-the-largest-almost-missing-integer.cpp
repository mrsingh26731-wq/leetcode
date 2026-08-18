class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> store;
        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> mp;
            for (int j = i; j < i + k; j++) {
                mp[nums[j]]++;
            }
            for (auto it : mp) {
                store[it.first]++;
            }
        }
        int Max = -1;
        for (auto it : store) {
            if (it.second == 1) {
                Max = max(Max, it.first);
            }
        }
        return Max;
    }
};