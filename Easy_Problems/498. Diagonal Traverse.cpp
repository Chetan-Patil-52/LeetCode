class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        // int size = m*n;
        vector<int> result;
        map<int, vector<int>> mp;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }

        bool flag = true;;

        for(auto it : mp){
            
            vector<int> vec = it.second;

            if(flag){
                reverse(begin(vec),end(vec));
            }
            flag = !flag;

            for(int val : vec){
                result.push_back(val);
            }


        }

        // reverse(begin(result),end(result));
        return result;
    }
};
