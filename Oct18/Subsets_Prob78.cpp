class Solution {

vector<vector<int>> result;

void solve(int i,vector<int>& nums,vector<int>& temp){
    if(i>=nums.size()){ // returns whenever the value of i matches with lev 3 ie. maxDepth
        result.push_back(temp);
        return;
    } 

    temp.push_back(nums[i]);
    solve(i+1,nums,temp);
    temp.pop_back();
    solve(i+1,nums,temp);
}

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;// Creating extra temp to add subsets;

        solve(0,nums,temp);
        return result;
    }
};
