class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int m = pref.length();
        int count = 0;
        for(int i = 0;i<n;i++){
            string word = words[i];
            if(word.length() >= m && word.substr(0,m)==pref ){
                count++;
            }
        }
        return count;
    }
};
