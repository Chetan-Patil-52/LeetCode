class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        int arr[n];
        for(char &ch : s){
            if(ch=='0'){
                arr.push_back(ch);
            }
        }
        int arrLen= arr.size();
        for(int i = (n-arrLen)+1;i<n;i++){
            arr[i] = '1';
        }
        return arr;
    }
};
