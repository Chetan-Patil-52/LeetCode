class Solution {
public:

    int rec(int level,int maxor,vector<int>& nums,vector<int>& st){
        if(level==nums.size()){
            int temp = 0;
            for(auto &val : st){
                temp |= val;
            }
            if(temp==maxor){
                return 1;
            }else{
                return 0;
            }
        }

        int ans = 0;
        st.push_back(nums[level]);
        ans += rec(level+1,maxor,nums,st);
        st.pop_back();
        ans += rec(level+1,maxor,nums,st);
        return ans;       
    };

    int countMaxOrSubsets(vector<int>& nums) {
        int maxor = 0;
        for(int i=0;i<nums.size();i++){
            maxor |= nums[i];
        }
        
        vector<int> st;
        int ans = rec(0,maxor,nums,st);
        return ans;
    }
};
