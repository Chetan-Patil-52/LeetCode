// class Solution {
// public:
//     int shortestSubarray(vector<int>& nums, int k) {
//         int res = INT_MAX;
//         long long curSum = 0;
//         deque<pair<long long, int>> q;  // (prefix_sum, end_idx)
        
//         for (int r = 0; r < nums.size(); r++) {
//             curSum += nums[r];
            
//             if (curSum >= k) {
//                 res = min(res, r + 1);
//             }
            
//             // Find the minimum valid window ending at r
//             while (!q.empty() && curSum - q.front().first >= k) {
//                 auto [prefix, endIdx] = q.front();
//                 q.pop_front();
//                 res = min(res, r - endIdx);
//             }
            
//             // Validate the monotonic deque
//             while (!q.empty() && q.back().first > curSum) {
//                 q.pop_back();
//             }
//             q.push_back({curSum, r});
//         }
        
//         return res == INT_MAX ? -1 : res;
//     }
// };

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> sum(n + 1);
        
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        
        vector<int> q(n + 1);
        int l = 0, r = 0;
        int minLength = n + 1;
        
        for (int i = 0; i < sum.size(); i++) {
            while (r > l && sum[i] >= sum[q[l]] + k) {
                minLength = min(minLength, i - q[l++]);
            }
            
            while (r > l && sum[i] <= sum[q[r - 1]]) {
                r--;
            }
            
            q[r++] = i;
        }
        
        return minLength <= n ? minLength : -1;
    }
};

// class Solution {
// public:
//     int shortestSubarray(vector<int>& nums, int k) {
//         int shortest = INT_MAX;  // Track shortest valid subarray length
//         deque<pair<long long, int>> queue;  // Store (sum, length) pairs
//         long long total = 0;     // Track current sum
//         int currLen = 0;         // Track current length
        
//         for (int i = 0; i < nums.size(); i++) {
//             int n = nums[i];
//             if (n < 0) {
//                 if (total + n <= 0) {  // Handle neg. numbers
//                     queue.clear();
//                     total = 0;
//                     currLen = 0;
//                     continue;
//                 } else {
//                     auto [removed, removeLen] = queue.back(); // Merge neg. number
//                     queue.pop_back();
//                     long long curr = n + removed;
//                     int stackLength = 1 + removeLen;
                    
//                     while (!queue.empty() && curr < 0) { // Keep merging non-neg. sum
//                         auto [removed2, removeLen2] = queue.back();
//                         queue.pop_back();
//                         curr += removed2;
//                         stackLength += removeLen2;
//                     }
                    
//                     total += n;
//                     queue.push_back({curr, stackLength});
//                     currLen += 1;
//                 }
//             } else {
//                 queue.push_back({n, 1}); // Handle pos. number
//                 total += n;
//                 currLen += 1;
//             }
            
//             while (!queue.empty() && total >= k) { // Check if cur. window sum exceeds k
//                 shortest = min(shortest, currLen);
//                 auto [removed, removeLen] = queue.front();
//                 queue.pop_front();
//                 total -= removed;
//                 currLen -= removeLen;
//             }
//         }
        
//         return shortest <= nums.size() ? shortest : -1;
//     }
// };
