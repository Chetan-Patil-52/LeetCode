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
