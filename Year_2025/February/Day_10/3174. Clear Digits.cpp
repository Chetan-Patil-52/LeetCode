// App - 1
 class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();
        int i = 0;
        while(i<n){
            if(isdigit(s[i])){
                s.erase(i,1);
                if(i-1 >= 0){
                    s.erase(i-1,1);
                    i--;
                    n--;
                }
            }else{
                i++;
            }
        }
        return s;
    }
};
