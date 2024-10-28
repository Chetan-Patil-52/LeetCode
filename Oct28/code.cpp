class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // Approach 1
    //     unordered_map<int, int> mp;
    //     sort(begin(nums),end(nums));
    //     int max_streak = 0;

    //     for(auto &num : nums){
    //         // To check if it is an prefect square of num
    //         int root = (int)sqrt(num);

    //         if(root*root == num && mp.find(root) != mp.end()){
    //             mp[num] = mp[root] + 1;
    //         }else{
    //             mp[num] = 1;
    //         }

    //         max_streak = max(max_streak , mp[num]);
    //     }

    //     return max_streak < 2 ? -1 : max_streak;

       
    // }


    // Approach 2
    //     unordered_set<int> st(begin(nums),end(nums));

    //     int max_streak = 0;

    //     for(auto &num : nums){
    //         long long curr = num;
    //         int streak = 0;
    //         while(st.find(curr) != st.end()){
    //             streak++;
    //             if(curr*curr > 1e5){
    //                 break;
    //             }
    //             curr = curr*curr;
    //         }
    //         max_streak = max(max_streak,streak);
    //     }
    //     return max_streak<2 ? -1 : max_streak;

    // Approach 3 (Binary search)
    int n = nums.size();
    sort(nums.begin(), nums.end());  // Step 1: Sort the array for binary search
    int max_streak = 0;

    for (auto &num : nums) {
        long long curr = num;  // Step 2: Start with the current number
        int streak = 0;

        while (true) {
            // Step 3: Use binary search to check if `curr` exists in `nums`
            if (binary_search(nums.begin(), nums.end(), curr)) {
                streak++;
                if (curr * curr > 1e5) {  // Break if next square is too large
                    break;
                }
                curr = curr * curr;  // Update `curr` to its square
            } else {
                break;  // Exit if `curr` is not found in the array
            }
        }

        max_streak = max(max_streak, streak);
    }

    return max_streak < 2 ? -1 : max_streak;
}
    
};
