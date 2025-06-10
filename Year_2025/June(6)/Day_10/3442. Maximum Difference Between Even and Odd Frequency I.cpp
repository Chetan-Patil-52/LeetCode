class Solution {
public:
    int maxDifference(string s) {
        int n = s.length();

        vector<int> freq(26,0);
        for(auto ch : s){
            freq[ch - 'a']++;
        }

        int mini = s.length();
        int maxi = 0;

        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;

            if(freq[i]%2==0){
                mini = min(freq[i],mini);
            }else{
                maxi = max(freq[i],maxi);
            }
        }

        return maxi-mini;
    }
};
