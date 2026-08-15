class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n =nums.size();

        int result = 0;
        bool allZero = true;

        for( int&x: nums){
            result= (result ^ x);

            if(x!=0){
                allZero =false;
            }

        }

        if(allZero){
            return 0;
        }
        return (result == 0)? n-1 : n;
    }
};