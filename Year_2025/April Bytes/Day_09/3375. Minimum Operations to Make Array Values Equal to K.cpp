class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st;
        // int x;
        for(int num : nums){
            if(num < k){
                return -1;
            }
            
            else if(num > k){
                st.insert(num);
            }
        }
        return st.size();
    }
};
