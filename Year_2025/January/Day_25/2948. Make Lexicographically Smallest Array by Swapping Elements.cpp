// TC : O(n^2) TLE
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n= nums.size();
        for(int i=0;i<n;i++){
            while(true){
                int idx = -1;
                int smallVal = nums[i];
                for(int j=i+1;j<n;j++){
                    if(abs(nums[i]-nums[j])<=limit){
                        if(nums[j]<smallVal){
                            smallVal = nums[j];
                            idx = j;
                        }
                    }
                }
                if(idx != -1){
                    swap(nums[i],nums[idx]);
                }else{
                    break;
                }
            }
        }
        return nums;
    }
};

