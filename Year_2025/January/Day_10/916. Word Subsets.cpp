class Solution {
public:
    
    bool isSubset(vector<int>& freq,vector<int>& temp){
        for(int i =0;i<26;i++){ // O(26) ~ O(1);
            if(temp[i]<freq[i]){
                return false;
            }
        }
        return true;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        vector<int> freq(26);
        for(string &word : words2){ // O(n)
            int temp[26] = {0};
            for(char &ch : word){ // O(l)
                temp[ch-'a']++;
                freq[ch-'a'] = max(freq[ch-'a'],temp[ch-'a']);
            }
        }

        for(string &word : words1){ // O(n)
            vector<int> temp(26,0);
            for(char &ch : word){ // O(l)
                temp[ch-'a']++;
            }
            if(isSubset(freq,temp)==true){
                result.push_back(word);
            }
        }
        return result;
        TC: O(m*l1 + n*l2);
        SC: O(1);
    }
};
