class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> result;
        for(int i=0;i<n;i++){
            if(nums[i]==key){
                int start = max(0,i-k);
                int end = min(n-1,i+k);
                if(!result.empty() && result.back() >= start){
                    start = result.back()+1;
                }
                for(int j=start;j<=end;j++){
                    result.push_back(j);
                }
            }
        }
        return result;
    }
};
