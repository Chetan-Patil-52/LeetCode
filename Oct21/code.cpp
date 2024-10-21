class Solution {
public:

    void solve(string s,int i, unordered_set<string>& st,int curr_count,int& max_count){

        if(curr_count + (s.length() - i) <= max_count){
            return;
        }

        if(i>= s.length()){
            max_count = max(curr_count,max_count);
            return;
        }

        for(int j = i;j<s.length();j++){
            string sub = s.substr(i,j-i+1);//O(n)
            if(st.find(sub) == st.end()){
                st.insert(sub);// Do
                solve(s,j+1,st,curr_count + 1,max_count); // Explore
                st.erase(sub); // Undo
            }
        }

    }

    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int max_count = 0;
        int curr_count = 0;
        int i = 0;
        solve(s,i,st,curr_count,max_count);

        return max_count;
    }
};
