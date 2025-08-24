class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int longest = 0;
        int zeros = 0;

        int n = nums.size();
        int i = 0;
        for(int j=0;j<n;j++){
            if(nums[j]==0) zeros++;

            while(zeros > 1){
                if(nums[i]==0) zeros--;
                i++;
            }

            longest = max(longest,j-i);
        }
        return longest;
    }
};
