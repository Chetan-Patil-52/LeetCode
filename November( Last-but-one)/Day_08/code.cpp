class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();

        vector<int> result(n);

        // Getting the overall XOR
        int XOR = 0;
        for(int i=0;i<n;i++){
            XOR ^= nums[i];
        }

        // Getting the mask 
        int mask = (1<<maximumBit) -1;

        // Getting the fiped bit
        for(int i=0;i<n;i++){
            int k = XOR ^ mask;
            result[i] = k;

            XOR ^= nums[n-i-1];
        }
        return result;
    }
};
