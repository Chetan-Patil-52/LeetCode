
// Brute Force O(n^2) TLE

class Solution {
public:
    bool isVowel(char &ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ){
            return true;
        }else{
            return false;
        }
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int q = queries.size();

        vector<int> ans(q,0);

        for(int i = 0;i<q;i++){
            int count = 0;
            for(int j = queries[i][0];j<= queries[i][1];j++){
                if(isVowel(words[j][0]) && isVowel(words[j].back())){
                    count++;
                }
            }
            ans[i] = count;
        }
        return ans;
    }
};

// Approach - 2 (Optimized) using CumulativeSum

class Solution {
public:
    bool isVowel(char &ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ){
            return true;
        }else{
            return false;
        }
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int q = queries.size();

        vector<int> result(q,0);

        vector<int> cumsum(n,0);
        int sum = 0;
        for(int i = 0;i<n;i++){
            if(isVowel(words[i][0]) && isVowel(words[i].back())){
                sum++;
            }
            cumsum[i] = sum;
        }

        for(int i = 0;i<q;i++){
            int l = queries[i][0];
            int r = queries[i][1];

            result[i] = cumsum[r] - ((l>0) ? cumsum[l-1] : 0);

        }
        return result;
    }
};
