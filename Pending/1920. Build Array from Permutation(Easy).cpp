// https://www.youtube.com/watch?v=0Q7m9VFCrUI

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> newNums(n);
        for(int i=0;i<n;i++){
            // int newIndex = nums[i];
            newNums[i] = nums[nums[i]];
        }
        return newNums;
    }
};
