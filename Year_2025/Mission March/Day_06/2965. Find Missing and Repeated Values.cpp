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


//Approach-2 (using maths)
// SAME 
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        long long N = n*n;

        long long gridSum   = 0;
        long long gridSqSum = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                gridSum += grid[i][j];
                gridSqSum += grid[i][j]*grid[i][j];
            }
        }

        long long sum   = (N * (N+1))/2; //Expected sum of N natural numbers
        long long sqSum = (N * (N+1) * (2*N+1))/6; //Expected sq sum of natural numbers

        int sqDiff  = gridSqSum - sqSum;
        int sumDiff = gridSum - sum;

        int a = (sqDiff/sumDiff + sumDiff)/2; 
        int b = (sqDiff/sumDiff - sumDiff)/2;

        return {a, b};
    }
};
