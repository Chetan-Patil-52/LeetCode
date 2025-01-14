// class Solution {
// public:
//     int minimumLength(string s) {
//         int n=s.length();
//         vector<int> v(26,0);
//         for(int i=0;i<n;i++){
//             v[s[i]-'a']++;
//             if(v[s[i]-'a'] == 3){
//                 v[s[i]-'a'] -=2;
//             }
//         }
//         int result = 0;
//         for(int i=0;i<26;i++){
//             if(v[i] == 0) continue;
//             else{
//                 result += v[i];
//             }
//         }
//         return result;
//     }
// };


// Optimal Solution 
class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        vector<int> v(26,0);
        int deleted = 0;
        for(int i=0;i<n;i++){
            v[s[i]-'a']++;
            if(v[s[i]-'a'] == 3){
                v[s[i]-'a'] -=2;
                deleted += 2;
            }
        }
       
        return n-deleted;
    }
};
