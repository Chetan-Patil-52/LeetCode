class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        // create an unordered_map
        unordered_map<int,int> mp;
        
        // Populate it
        for(auto& pair : nums1){
            mp[pair[0]] += pair[1];
        }
        for(auto& pair : nums2){
            mp[pair[0]] += pair[1];
        }

        // Using vector to strore output
        vector<vector<int>> result;
        for(auto& pair : mp){
            result.push_back({pair.first,pair.second});
        }

        // sort the reuslt array
        sort(result.begin(),result.end());

        return result;
    }
};

// Optimal Approach - Two pointer 
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int m = nums1.size(),n = nums2.size();
        // step - 1 keep a loop until i < n and j < m
        int i = 0;
        int j = 0;
        vector<vector<int>> result;
        while(i<m && j<n){
            if(nums1[i][0] < nums2[j][0]){
                result.push_back(nums1[i]);
                i++;
            }else if(nums2[j][0] < nums1[i][0]){
                result.push_back(nums2[j]);
                j++;
            }else{
                result.push_back({nums1[i][0],nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
        }

        while(i<m){
            result.push_back(nums1[i]);
            i++;
        }

        while(j<n){
            result.push_back(nums2[j]);
            j++;
        }
        // if both are same increment both of them else eitherr one of them
        // put the result in result array

        return result;

    }
};
