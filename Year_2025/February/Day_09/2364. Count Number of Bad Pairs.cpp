class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // brute force gets TLE O(n^2) 57 / 65 testcases passed 
        // int n = nums.size();
        // long long count = 0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(j-i != nums[j]-nums[i]){
        //             count++;
        //         }
        //     }
        // }
        // return count;


        // Approach - 2
        // int n = nums.size();
        // long long result = 0;
        // for(int i=0;i<n;i++){
        //     nums[i] = nums[i] - i;
        // }
        // unordered_map<int, int> mp;
        // mp[nums[0]] = 1;

        // for(int j=1;j<n;j++){
        //     int countNumOfj = mp[nums[j]];
        //     int totalNumBeforej = j;
        //     int badPairs = j - countNumOfj;
        //     mp[nums[j]]++;
        //     result += badPairs;
        // }
        // return result;

        // Approach - 3
        int n = nums.size();
        long long result = 0;
        for(int i=0;i<n;i++){
            nums[i] = nums[i] - i;
        }

        unordered_map<int,int> mp;
        mp[nums[0]] = 1;

        for(int j=1;j<n;j++){
            int totalEle = j;
            int goodPairs = mp[nums[j]];
            int badPairs = totalEle - goodPairs;
            mp[nums[j]]++;
            result += badPairs;
        }
        return result;
    }
};
