class Solution {
public:
    int maxDistance(string s, int k) {
        int maxMD = 0;
        int E = 0;
        int W = 0;
        int N = 0;
        int S = 0;

        for(int i=0;i<s.length();i++){
            if(s[i] == 'E') E++;
            else if(s[i]=='W') W++;
            else if(s[i]=='N') N++;
            else if(s[i]=='S') S++;

            int currMD = abs(E-W) + abs(N-S);
            int steps = (i+1);
            int wasted = steps - currMD;

            int extra = 0;
            if(wasted!=0){
                extra = min(2*k, wasted);
            }

            int finalMaxDistance = currMD + extra;

            maxMD = max(maxMD, finalMaxDistance);

        }
        return maxMD;
    }
};
