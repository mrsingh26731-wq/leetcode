class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        function<void(int,int)> solve = [&](int open, int close) {
            if (curr.length() == 2 * n) {
                ans.push_back(curr);
                return;
            }
            if (open < n) {
                curr.push_back('(');
                solve(open + 1, close);
                curr.pop_back();
            }
            if (close < open) {
                curr.push_back(')');
                solve(open, close + 1);
                curr.pop_back();
            }
        };
        solve(0, 0);
        return ans;
    }
};