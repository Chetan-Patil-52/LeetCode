class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        // Approach 1
        // int n = arr.size();

        // vector<int> prefixMax(begin(arr),end(arr));
        // vector<int> suffixMin(begin(arr),end(arr));

        // for(int  i = 1;i<n;i++){
        //     prefixMax[i] = max(prefixMax[i],prefixMax[i-1]);
        // }

        // for(int i = n-2;i>=0;i--){
        //     suffixMin[i] = min(suffixMin[i],suffixMin[i+1]);
        // }

        // int count = 0;

        // for(int i = 0;i<n ;i++){
        //     int beforeMax = i>0 ? prefixMax[i-1] : -1;
        //     int afterMin = suffixMin[i];

        //     if(beforeMax < afterMin){
        //         count++;
        //     }
        // }

        // return count;

        // Approach - 2

    //     int n = arr.size();

    //     int original_sum = 0;
    //     int cumulative_sum = 0;

    //     int count = 0;
    //     for(int i=0;i<n;i++){

    //         cumulative_sum += arr[i];

    //         original_sum += i;

    //         if(original_sum==cumulative_sum){
    //             count++;
    //         }
    //     }

    //     return count;

        // Approach - 3

        int n = arr.size();

        int maxi = -1;
        int count = 0;

        for(int i = 0;i<n;i++){
            maxi = max(maxi,arr[i]);

            if(maxi == i){
                count++;
            }
        }
        
        return count;
        
    }

};
