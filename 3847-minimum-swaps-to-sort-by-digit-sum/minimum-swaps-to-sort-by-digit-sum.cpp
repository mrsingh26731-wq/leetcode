
class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        auto lambda = [this](int num1, int num2) {
            int dsum1 = getDigitSum(num1);
            int dsum2 = getDigitSum(num2);

            if (dsum1 != dsum2)
                return dsum1 < dsum2;
            else
                return num1 < num2;
        };

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end(), lambda);

        unordered_map<int, int> valToIdx;

        for (int i = 0; i < n; i++) {
            valToIdx[nums[i]] = i;
        }

        int swapCount = 0;

        for (int i = 0; i < n; i++) {
            int expectedVal = sorted[i];
            int currVal = nums[i];

            if (expectedVal == currVal)
                continue;

            int idx = valToIdx[expectedVal];

            nums[i] = expectedVal;
            nums[idx] = currVal;

            valToIdx[expectedVal] = i;
            valToIdx[currVal] = idx;

            swapCount++;
        }

        return swapCount;
    }
};
