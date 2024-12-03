// From the given problem and image:

// The graph follows a right-to-left exploration order, with Iterative Deepening Search (IDS).
// IDS explores all nodes level by level, and the goal state (J) is at depth 3.
// Nodes are revisited in successive iterations.
// Exploration process:
// Depth 0: Explore A → Count = 1.
// Depth 1: Explore A, C, B → Count = 3.
// Depth 2: Explore A, C, G, F, B, E, D → Count = 7.
// Depth 3: Explore A, C, G, M, L, K, F, J → Count = 8 (Stop after J is found).
// Total nodes generated: 19
// Answer path: A → C → G → M → L → K → F → J.


class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length();
        int m = spaces.size();

        int j = 0;
        string result = "";

        for(int i = 0;i<n;i++){
            if(j < m  && i==spaces[j]){
                result += " ";
                j++;
            }
            result += s[i];
        }

    return result;
    }
};
