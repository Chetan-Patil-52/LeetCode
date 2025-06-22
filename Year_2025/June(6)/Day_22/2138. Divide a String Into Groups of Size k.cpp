class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        int count = 0;
        vector<string> result;
        string part = "";

        for(int i=0;i<n;i++){
            part += s[i];
            count++;
            if(count==k){
                result.push_back(part);
                part = "";
                count = 0;
            }
        }
        if(!part.empty()){
            while(part.length() < k){
                part += fill;
            }
            result.push_back(part);
        }
        return result;
    }
};
