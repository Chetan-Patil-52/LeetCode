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
