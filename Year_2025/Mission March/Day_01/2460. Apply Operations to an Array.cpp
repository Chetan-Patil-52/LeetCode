// Code
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        // Step - 1 (Transformation)
        for(int i=0;i<n;i++){
            if(i != n-1 && nums[i]==nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }

        // Step - 2 (Moving Zeros)
        int idx = 0;
        vector<int> result(n,0);
        for(int i=0;i<n;i++){
            if(nums[i] != 0){
                result[idx] = nums[i];
                idx++;
            }
        }

        return result;
    }
};
