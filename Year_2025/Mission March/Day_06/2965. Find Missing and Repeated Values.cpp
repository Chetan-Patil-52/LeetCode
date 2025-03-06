class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        int N = n*n;

        int a = -1;
        int b = -1;

        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[grid[i][j]]++;
            }
        }


        for(int i=1;i<=N;i++){
            if(!mp.count(i)){
                b = i;
            }
            else if(mp[i]==2){
                a = i;
            }

            if(a != -1 && b != -1){
                break;
            }
        }
        return {a,b};
    }
};
