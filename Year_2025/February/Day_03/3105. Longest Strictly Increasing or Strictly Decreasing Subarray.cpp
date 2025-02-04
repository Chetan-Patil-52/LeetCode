class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int inc = 1,dec = 1,maxi = 1;
        for(int i = 1;i<n;i++){
            if(nums[i]>nums[i-1]){
                inc++;
                dec = 1; // resets dec counter
            }
            else if(nums[i] < nums[i-1]){
                dec++;
                inc = 1;// resets inc counter
            }
            else{
                inc = 1; // resets both
                dec = 1;
            }
            maxi = max(maxi,max(inc,dec));
        }
        return maxi;
    }
};
