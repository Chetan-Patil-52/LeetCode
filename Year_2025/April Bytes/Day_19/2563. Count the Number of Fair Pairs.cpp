// Brute force
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

// Optimized 

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        sort(begin(nums), end(nums)); //nlogn

        long long result = 0;

        for(int i = 0; i < n; i++) { //O(n * logn)
             //o(n)
            int idx = lower_bound(begin(nums) + i + 1, end(nums), lower-nums[i]) - begin(nums); //Gives the firstc element NOT LESS than (lower - nums[i]) //log(n)
            int x   = idx - 1 - i;

            idx = upper_bound(begin(nums) + i + 1, end(nums), upper-nums[i]) - begin(nums); //Gives the firstc element GREATER than (upper - nums[i]) //log(n)

            int y = idx - 1 - i;

            result += (y-x);
        }

        return result;
    }
};
