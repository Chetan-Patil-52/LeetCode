class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        bool swapped = true;

        for(int i=0;i<n;i++){
            swapped = false;

            for(int j=0;j<n-i-1;j++){

                if(nums[j] <= nums[j+1]){
                    continue;
                } else{
                    if(__builtin_popcount(nums[j]) == __builtin_popcount(nums[j+1])) {
                        swap(nums[j],nums[j+1]);
                        swapped = true;
                    } else{
                        // Cant be swaped hence can't be sorted
                        return false;
                    }
                }
            }

        if(swapped == false){
            break;
        }

        }
        return true;
    }
};
