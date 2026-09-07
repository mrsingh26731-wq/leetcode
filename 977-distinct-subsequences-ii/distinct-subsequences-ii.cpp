class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

       
        vector<long long> last(26, 0);

        long long total = 1; 

        for (char c : s) {
            int idx = c - 'a';

            long long newSubseq = total;

            total = (total + newSubseq - last[idx] + MOD) % MOD;

            last[idx] = newSubseq;
        }
        return (total - 1 + MOD) % MOD;
    }
};