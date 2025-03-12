class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int pos=0;int neg = 0;
        for(auto &num : nums){
            if(num >0){
                pos++;
            }else if(num < 0){
                neg++;
            }else{
                continue;
            }
        }
        return max(pos,neg);
    }
};
