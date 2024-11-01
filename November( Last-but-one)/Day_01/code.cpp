class Solution {
public:
    string makeFancyString(string s) {
        int count = 1;
        // int n = s.length();
        char prev = s[0];

        string result;
        result += s[0];

        for(int i=1;i< s.length();i++){
            if(s[i] == prev){
                count++;
                // If the count is <3 we are adding the char
                if(count < 3){
                    result += s[i];
                }
            }else{
                count = 1;
                prev = s[i];
                result += s[i];
            }
        }
        return result;
    }
};
