class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n = nums.size();

        vector<int> t(n,1);

        vector<int> prev_idx(n,-1);

        int last_choosen_idx = 0;
        int maxL = 1;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(t[i]<t[j]+1){
                        t[i] = t[j]+1;
                        prev_idx[i] = j;
                    }

                    if(t[i] > maxL){
                        maxL = t[i];
                        last_choosen_idx = i;
                    }
                } 
            }
        }

        vector<int> result;
        while(last_choosen_idx >= 0){
            result.push_back(nums[last_choosen_idx]);
            last_choosen_idx = prev_idx[last_choosen_idx];
        }
        return result;
    }
};
