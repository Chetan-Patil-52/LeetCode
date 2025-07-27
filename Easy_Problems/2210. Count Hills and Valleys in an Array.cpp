//First thought extream bruteforce
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int v = 0;
        int h = 0;
        for(int i=1;i<n-1;i++){
            if(nums[i]!=nums[i-1] && nums[i]!=nums[i+1]){
                if(nums[i] < nums[i+1] && nums[i] < nums[i-1]){
                    v++;
                }else if(nums[i] > nums[i+1] && nums[i] > nums[i-1]){
                    h++;
                }
            }
        }

        for(int i=1;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                int start = nums[i];
                int end = nums[i+1];
                int beforeStart = 0;
                for(int search=i;search>0;search--){
                    if(nums[search] != start){
                        beforeStart = nums[search];
                        break;
                    }
                }

                int afterStart = 0;
                for(int search=i+1;search<n-1;search++){
                    if(nums[search] != end){
                        afterStart = nums[search];
                        break;
                    }
                }

                if(start < beforeStart && end < afterStart){
                    v++;
                    // break;
                }else if(start > beforeStart && end > afterStart){
                    h++;
                    // break;
                }

                while (i + 1 < n && nums[i] == nums[i + 1]) {
                    i++;
                }
            }
        }
        return v+h;
    }
};


// Worked
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n= nums.size();
        vector<int> left(n,0);
        left[0] = nums[0];
        for(int i=1;i<n-1;i++){
            if(nums[i]==nums[i-1]){
                left[i]=left[i-1];
            }else{
                left[i]=nums[i-1];
            }
        }

        vector<int> right(n,0);
        right[n-1] = nums[n-1];
        for(int i=n-2;i>0;i--){
            if(nums[i]==nums[i+1]){
                right[i]=right[i+1];
            }else{
                right[i]=nums[i+1];
            }   
        }

        int v = 0;
        int h = 0;
        for(int i=1;i<n-1;i++){
            
            while(i<n-1 && nums[i]==nums[i+1]){
                i++;
            }

            if(i>= n-1) break;

            if(nums[i] < left[i] && nums[i] <right[i]) v++;
            if(nums[i] > left[i] && nums[i] >right[i]) h++;
        }

        return v+h;
    }
};
