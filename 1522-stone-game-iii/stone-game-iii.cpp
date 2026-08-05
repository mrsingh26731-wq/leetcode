class Solution {
public:
    int n;
    vector<int> t;

    int solve(vector<int>& stones, int i) {
        if (i >= n) return 0;

        if (t[i] != -1) return t[i];

        int result = stones[i] - solve(stones, i + 1);

        if (i + 1 < n)
            result = max(result, stones[i] + stones[i + 1] - solve(stones, i + 2));

        if (i + 2 < n)
            result = max(result, stones[i] + stones[i + 1] + stones[i + 2] - solve(stones, i + 3));

        return t[i] = result;
    }

    string stoneGameIII(vector<int>& stones) {
        n = stones.size();
        t.assign(n, -1);

        int diff = solve(stones, 0);

        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};