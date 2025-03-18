class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for(int i=0;i<n;i++){
            int mask = 0;
            for(int j=i;j<n;j++){
                if((mask & nums[j]) != 0){
                    break;
                }
                result = max(result,j-i+1);
                mask = (mask | nums[j]);
            }
        }
        return result;
    }
};

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n= nums.size();
        int i=0;
        int j=0;

        int result = 1;
        int mask = 0;
        while(j < n){

            while(mask & nums[j] != 0){
                mask = (mask ^ nums[i]);
                i++;
            }
            result = max(result,j-i+1);
            mask = (mask | nums[j]);
            j++;
        }
        return result;
    }
};
