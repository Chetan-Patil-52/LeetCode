// Approach 2

        int n = nums.size();

        long long current_sum = 0;
        long long result = 0;

        unordered_set<int> st;

        int i=0;
        int j=0;

        while(j<n){
            // Adjust the window if nums[j] is already in the set
            while(st.count(nums[j])){
                current_sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            current_sum += nums[j];
            st.insert(nums[j]);

            if(j-i+1==k){
                result = max(result,current_sum);

                // Shrink the last element and move to next element
                current_sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return result;
    }
};
