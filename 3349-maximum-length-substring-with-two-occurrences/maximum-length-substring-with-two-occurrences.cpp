class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        unordered_map<int,int> mp;

        int n=s.length();
        int len=0;
        int i=0;
        for(int j=0;j<n;j++){
            mp[s[j]]++;

            while(mp[s[j]]>2){
                mp[s[i]]--;
                i++;
            }
            len=max(len,j-i+1);
        }
        return len;
    }
};