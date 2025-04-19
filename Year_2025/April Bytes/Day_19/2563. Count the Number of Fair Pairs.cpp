class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        int result = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int val = nums[i]+nums[j];
                if(val >=lower && val <= upper){
                    result++;
                }
            }
        }
        return result;
    }
};
