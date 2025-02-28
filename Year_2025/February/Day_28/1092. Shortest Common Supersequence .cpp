// Working solution 
class Solution {
public:
    // Function to find the shortest common supersequence of two strings.
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> t(m+1, vector<int>(n+1, 0));

        // Filling the DP table
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                if(i == 0) {
                    t[i][j] = j;
                } else if(j == 0) {
                    t[i][j] = i;
                } else if(s1[i-1] == s2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = 1 + min(t[i-1][j], t[i][j-1]);
                }
            }
        }

        // Backtracking to construct the supersequence
        int i = m, j = n;
        string result = "";
        while(i > 0 && j > 0) {
            if(s1[i-1] == s2[j-1]) {
                result += s1[i-1];
                i--; j--;
            } else if(t[i-1][j] < t[i][j-1]) {
                result += s1[i-1];
                i--;
            } else {
                result += s2[j-1];
                j--;
            }
        }

        while(i > 0) {
            result += s1[i-1];
            i--;
        }
        while(j > 0) {
            result += s2[j-1];
            j--;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
