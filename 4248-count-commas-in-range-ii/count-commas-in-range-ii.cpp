class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        if (n >= 1000000000000000LL) ans += n - 999999999999999LL;
        if (n >= 1000000000000LL)    ans += n - 999999999999LL;
        if (n >= 1000000000LL)       ans += n - 999999999L;
        if (n >= 1000000LL)          ans += n - 999999L;
        if (n >= 1000LL)             ans += n - 999L;
        return ans;
    }
};