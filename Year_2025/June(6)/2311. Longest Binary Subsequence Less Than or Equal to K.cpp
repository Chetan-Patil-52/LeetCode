class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        long long powerValue = 1; // 2^1 is one 
        int length = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                length++;
            }else if(powerValue <= k){
                length++;
                k -= powerValue;
            }

            if(powerValue <= k){
                powerValue <<= 1; // or powerValue * 2
            }
        }
        return length;
    }
};
