class Solution {
public:
    string result = "";
    char midChar = '$';
    int half = 0;

    bool solve(string& curr, vector<int>& count,
               string& target, int i, bool greater) {

        // Left half complete
        if (i == half) {

            string candidate = curr;

            // Add middle character for odd length
            if (midChar != '$')
                candidate += midChar;

            // Add reversed left half
            string rightHalf = curr;
            reverse(rightHalf.begin(), rightHalf.end());

            candidate += rightHalf;

            // Strictly greater than target
            if (candidate > target) {
                result = candidate;
                return true;
            }

            return false;
        }

        // Try characters from smallest to largest
        for (char ch = 'a'; ch <= 'z'; ch++) {

            int idx = ch - 'a';

            if (count[idx] == 0)
                continue;

            // If prefix is equal to target so far,
            // we cannot choose a smaller character.
            if (!greater && ch < target[i])
                continue;

            curr.push_back(ch);
            count[idx]--;

            bool isGreater = greater || (ch > target[i]);

            if (solve(curr, count, target, i + 1, isGreater))
                return true;

            // Backtrack
            curr.pop_back();
            count[idx]++;
        }

        return false;
    }

    string lexPalindromicPermutation(string s, string target) {

        // Reset class variables
        result = "";
        midChar = '$';

        int n = s.length();

        vector<int> count(26, 0);

        // Count characters
        for (char ch : s)
            count[ch - 'a']++;

        // Find odd frequency character
        int oddCount = 0;

        for (int c = 0; c < 26; c++) {

            if (count[c] % 2 == 1) {
                oddCount++;
                midChar = char(c + 'a');
            }
        }

        // More than one odd frequency means
        // palindrome is impossible.
        if (oddCount > 1)
            return "";

        // Number of characters in left half
        half = n / 2;

        // Each character contributes half of its count
        vector<int> halfCount(26, 0);

        for (int c = 0; c < 26; c++)
            halfCount[c] = count[c] / 2;

        string curr = "";

        solve(curr, halfCount, target, 0, false);

        return result;
    }
};