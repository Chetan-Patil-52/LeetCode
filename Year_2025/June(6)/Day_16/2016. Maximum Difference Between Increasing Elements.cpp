// Approach - 1 O(n^2)
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n= nums.size();
        int maxi = -1;
        for(int i=0;i<n;i++){
            for(int j= i+1;j<n;j++){
                if(nums[j] > nums[i]){
                    maxi = max(maxi,nums[j]-nums[i]);
                }
            }
        }
        return maxi;
    }
};

// Approach - 2 O(n)
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n= nums.size();
        int maxi = -1;
        int mini = nums[0];
        for(int i=1;i<n;i++){
            mini = min(mini,nums[i]);
            if(nums[i] > mini){
                maxi = max(maxi,nums[i] - mini);
            }
        }
        return maxi;
    }
};
