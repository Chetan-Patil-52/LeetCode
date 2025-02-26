class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int currSum = nums[0];
        int maxSum = nums[0];

        for(int i=1;i<n;i++){
            currSum = max(nums[i],currSum + nums[i]);
            maxSum = max(maxSum,currSum);
        }

        currSum = nums[0];
        int minSum = nums[0];
        for(int i=1;i<n;i++){
            currSum = min(nums[i],currSum+nums[i]);
            minSum = min(minSum,currSum);
        }

        return max(maxSum,abs(minSum));
    }
};
