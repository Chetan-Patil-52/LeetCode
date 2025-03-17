class Solution {
public:
    typedef long long ll;
    bool divideArray(vector<int>& nums) {
        // Using a map 
        unordered_map<int,int> mp;

        for(int num : nums){
            mp[num]++;
        }

        for(auto& ele : mp){
            if((ele.second%2) != 0){
                return false;
            }
        }
        return true;
    }
};
