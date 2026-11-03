class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());
        int operations = 0;

        for (int i = 0; i < nums.size(); i++) {
            operations += maxElement-nums[i] ;
        }
        return operations;
    }
};