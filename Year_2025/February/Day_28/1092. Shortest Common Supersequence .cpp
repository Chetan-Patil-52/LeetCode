/****************************************************************** C++ **********************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    public:
    int t[101][101];
    int solve(string& s1, string& s2, int m, int n) {
        if(m == 0 || n == 0) {
            return m+n;
        }
        
        if(t[m][n] != -1) {
            return t[m][n];
        }
        
        if(s1[m-1] == s2[n-1]) {
            return t[m][n] = 1 + solve(s1, s2, m-1, n-1);
        } else {
            return t[m][n] = 1 + min(solve(s1, s2, m-1, n), solve(s1, s2, m, n-1));
        }
        
        return 0;
    }
    
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string s1, string s2, int m, int n) {
        memset(t, -1, sizeof(t));
        return solve(s1, s2, m, n);
    }
};



//Approach-2 (Bottom Up)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string s1, string s2, int m, int n) {
        vector<vector<int>> t(m+1, vector<int>(n+1));
        
        for(int i = 0; i < m+1; i++) {
            for(int j = 0; j < n+1; j++) {
                if(i == 0 || j == 0) {
                    t[i][j] = i+j;
                } else if(s1[i-1] == s2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = 1 + min(t[i-1][j], t[i][j-1]);
                }
            }
        }
        
        return t[m][n];
    }
};


//Approach-3 (Using LCS Code)
//You need to write the common letters only once and then write remaining letters of s1 and s2
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string s1, string s2, int m, int n) {
        vector<vector<int>> t(m+1, vector<int>(n+1));
        
        for(int i = 0; i<m+1; i++) {
            for(int j = 0; j < n+1; j++) {
                if(i == 0 || j == 0)
                    t[i][j] = 0;
                else if(s1[i-1] == s2[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
        
        int LCS = t[m][n];
        
        int letters_from_s1 = m-LCS;
        int letters_from_s2 = n-LCS;
        
        return LCS + letters_from_s1 + letters_from_s2;
    }
};
