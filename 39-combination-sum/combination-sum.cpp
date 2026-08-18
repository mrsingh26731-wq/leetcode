class Solution {
public:
    void solve(int index, vector<int>& candidates, int target,
               vector<int>& current, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target)
                continue;
            current.push_back(candidates[i]);
            solve(i, candidates, target - candidates[i], current, ans);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> current;
        solve(0, candidates, target, current, ans);
        return ans;
    }
};