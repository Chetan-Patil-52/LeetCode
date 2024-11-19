// My Code
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long g_sum = 0, current_sum = 0;
        unordered_set<int> elements;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            // Add the current element to the window
            while (elements.count(nums[right]) || (right - left + 1 > k)) {
                // Remove elements from the left until valid
                elements.erase(nums[left]);
                current_sum -= nums[left];
                left++;
            }
            
            // Add current element
            elements.insert(nums[right]);
            current_sum += nums[right];

            // If the window size is k, update the global sum
            if (right - left + 1 == k) {
                g_sum = max(g_sum, current_sum);
            }
        }
        return g_sum;
    }
};


