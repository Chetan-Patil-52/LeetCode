class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        // Optimal approach
        int n=nums.size();
        long long int maxi = nums[0];
        long long int curr_sum = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                curr_sum += nums[i];
            }else{
                curr_sum = nums[i];
            }
            maxi = max(curr_sum,maxi);
        }
        return maxi;
    }
};
