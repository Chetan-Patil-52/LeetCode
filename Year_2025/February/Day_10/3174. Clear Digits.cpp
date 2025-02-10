class Solution {
public:
    string clearDigits(string s) {
        // Approach - 1 (BT)
        // int n = s.length();
        // int i = 0;
        // while(i<n){
        //     if(isdigit(s[i])){
        //         s.erase(i,1);
        //         if(i-1 >= 0){
        //             s.erase(i-1,1);
        //             i--;
        //             n--;
        //         }
        //     }else{
        //         i++;
        //     }
        // }
        // return s;
        

        // Approach - 2 (Using Stack)
        // stack<int> st;
        // int n = s.length();

        // for(int i=0;i<s.length();i++){
        //     if(isdigit(s[i])){
        //         if(!st.empty()){
        //             st.pop();
        //             // n--;
        //         }
        //     }else{
        //         st.push(s[i]);
        //     }
        // }

        // string result = "";
        // while(!st.empty()){
        //     result.push_back(st.top());
        //     st.pop();
        // }

        // reverse(result.begin(),result.end());

        // return result;

        // Approach - 3 (without stack)

        // string result = "";
        // for(char &ch : s){
        //     if(isdigit(ch)){
        //         result.pop_back();
        //     }else{
        //         result.push_back(ch);
        //     }
        // }
        // return result;

        // Approach - 4 (Inplace modification)

        int n = s.size();
        int i=0,j=0;
        while(i<n){
            if(isdigit(s[i])){
                j = max(j-1,0);
            }else{
                s[j] = s[i];
                j++;
            }
            i++;
        }
        return s.substr(0,j);
    }
};
