#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> mp; // Store top 2 max values for each sum

        for (int num : nums) {
            int sum = 0, temp = num;
            while (temp > 0) { // Calculate sum of digits
                sum += temp % 10;
                temp /= 10;
            }

            // Maintain the two largest values for each sum
            if (mp.find(sum) == mp.end()) {
                mp[sum] = {num, -1}; // Initialize with first number, second empty
            } else {
                auto &[max1, max2] = mp[sum];
                if (num > max1) {
                    max2 = max1;
                    max1 = num;
                } else if (num > max2) {
                    max2 = num;
                }
            }
        }

        int result = -1;
        for (auto &[sum, p] : mp) {
            if (p.second != -1) { // Ensure at least two valid numbers exist
                result = max(result, p.first + p.second);
            }
        }

        return result;
    }
};


// ------------------------

#include <bits/stdc++.h>
using namespace std;

int getDigitSum(int num){
    int sum = 0;
    while(num > 0){
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int result = -1;

        unordered_map<int, int> mp;

        for(int i=0;i<n;i++){
            int digitSum = getDigitSum(nums[i]);

            if(mp.count(digitSum)){
                result = max(result,mp[digitSum] + nums[i]);
            }

            mp[digitSum] = max(mp[digitSum], nums[i]);
        }
        return result;
    }
};


//---------------
#include <bits/stdc++.h>
using namespace std;

int getDigitSum(int num){
    int sum = 0;
    while(num > 0){
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int result = -1;

        // unordered_map<int, int> mp;
        int mp[82] = {0};

        for(int i=0;i<n;i++){
            int digitSum = getDigitSum(nums[i]);

            if(mp[digitSum] > 1){
                result = max(result,mp[digitSum] + nums[i]);
            }

            mp[digitSum] = max(mp[digitSum], nums[i]);
        }
        return result;
    }
};


