class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        // Approach - 1 (Bruteforce)
        // // As the constrain is 10^5 O(n^2) solution doesent works and Gives TLE

        // int n = nums.size();

        // int count = 0;
        // for(int i = 0;i<n-1;i++){

        //     int sum1 = 0;
        //     for(int j = 0;j<=i;j++){
        //         sum1 += nums[j];
        //     }

        //     int sum2 = 0;
        //     for(int j = i+1;j<n;j++){
        //         sum2 += nums[j];
        //     }

        //     if(sum1 >= sum2){
        //         count++;
        //     }
        // }

        // Approach - 2 (Cumulative sum)

        // int n = nums.size();

        // vector<long long> cumsum(n);

        // long long sum = 0;
        // for(int i = 0;i<n;i++){
        //     sum += nums[i];
        //     cumsum[i] = sum;
        // }

        // int count = 0;
        // for(int i = 0;i<n-1;i++){

        //     long long part_1 = cumsum[i];

        //     long long part_2 = cumsum[n-1] - cumsum[i];

        //     if(part_1 >= part_2){
        //         count++;
        //     }
        // }


        // return count;

        // Approach - 3 (Without using Prefix Sum Array) 

        int n = nums.size();

        long long sum = 0;

        for(int &num : nums){
            sum += num;
        }

        long long part_1 = 0;
        long long part_2 = 0;
        int splits = 0;
        for(int i = 0;i< n-1;i++){
            part_1 += nums[i];

            part_2 = sum - part_1;

            if(part_1 >= part_2){
                splits++;
            }
        }

        return splits;

    }
};
