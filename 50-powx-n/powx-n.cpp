class Solution {
public:

    double solve(double x, long long n) {
        if (n == 0)
            return 1;
        if (n % 2 == 0) {
            double half = solve(x, n / 2);
            return half * half;
        }
        return x * solve(x, n - 1);
    }

    double myPow(double x, int n) {
        long long N = n;
        if (N < 0)
            return 1 / solve(x, -N);
        return solve(x, N);
    }
};