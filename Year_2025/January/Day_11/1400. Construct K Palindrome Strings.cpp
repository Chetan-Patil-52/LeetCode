class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if(n==k) return true;
        if(n<k) return false;
        unordered_map<char,int> mp;
        int count = 0;
        for(char &ch : s){
            mp[ch-'a']++;
        }

        for(auto &it : mp){
            if(it.second%2!=0){
                count++;
            }
        }

        if(count<=k){
            return true;
        }
        return false;
    }
};
