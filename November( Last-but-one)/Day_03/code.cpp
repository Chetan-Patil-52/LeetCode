class Solution {
public:
    bool rotateString(string s, string goal) {
        // Approach 1

        // int n = s.length();
        // int m = goal.length();

        // if( n != m){
        //     return false;
        // }

        // for(int i = 0;i<n;i++){
        //     rotate(begin(s),begin(s)+1,end(s));
        //     if(s==goal){
        //         return true;
        //     }
        // }
        // return false;

        // Approach 2

        int n = s.length();
        int m = goal.length();

        if( n != m){
            return false;
        }

        if((s+s).find(goal) != string::npos){
            return true;
        }
        return false;
    }
};
