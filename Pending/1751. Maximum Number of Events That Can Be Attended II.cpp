// TC : O(n+1) * O(k+1) * O(n)-Liner Search
// Gives TLE (69/70)
class Solution {
public:
    int n;
    int solve(vector<vector<int>>& events, int idx, int k){
        if(idx >= n || k == 0){
            return 0;
        }

        int start = events[idx][0];
        int end   = events[idx][1];
        int value = events[idx][2];

        int skip = solve(events,idx+1,k);

        int j = idx+1;
        for( ; j<n;j++){
            if(events[j][0] > events[idx][1]){
                break;
            }
        }
        int take = value + solve(events,j,k-1);
        return max(take,skip);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        sort(begin(events),end(events));

        return solve(events,0,k);
    }
};

// TC : O(n+1) * O(k+1) * O(nlogn)-Liner Search
// Gives TLE (68/70)

class Solution {
public:
    int n;
    vector<vector<int>> t;
    int solve(vector<vector<int>>& events, int idx, int k){
        if(idx >= n || k == 0){
            return 0;
        }

        if(t[idx][k] != -1){
            return t[idx][k];
        }

        int start = events[idx][0];
        int end   = events[idx][1];
        int value = events[idx][2];

        int skip = solve(events,idx+1,k);

        vector<int> temp = {end,INT_MAX,INT_MAX};
        int j = upper_bound(events.begin()+idx+1,events.end(),temp) - events.begin();

        int take = value + solve(events,j,k-1);
        return t[idx][k] = max(take,skip);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        sort(begin(events),end(events));
        t.resize(n+1, vector<int>(k+1,-1));
        return solve(events,0,k);
    }
};
// with predefined/Custom comparator
class Solution {
public:
    int n;
    vector<vector<int>> t;

    int solve(vector<vector<int>>& events, int idx, int k){
        if(idx >= n || k == 0){
            return 0;
        }

        if(t[idx][k] != -1){
            return t[idx][k];
        }

        int value = events[idx][2];

        // Skip current event
        int skip = solve(events, idx + 1, k);

        // Binary search: find first event with start time > current event's end
        int endTime = events[idx][1];
        int j = upper_bound(events.begin(), events.end(), endTime,
            [](int val, const vector<int>& event) {
                return val < event[0];
            }) - events.begin();

        int take = value + solve(events, j, k - 1);
        return t[idx][k] = max(take, skip);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        sort(events.begin(), events.end());
        t.assign(n, vector<int>(k + 1, -1));
        return solve(events, 0, k);
    }
};


//Approach-3 (Without doing any linear or binary search) - Simply keep track of last taken event
class Solution {
public:
    int n;
    vector<vector<int>> t;
    int solve(vector<vector<int>>& events, int i, int prev, int k) {
        
        if(k == 0 || i == n)
            return 0;
        
        if(t[prev+1][k] != -1) //prev+1 because intially prev is = -1
            return t[prev+1][k];
        
        int start = events[i][0];
        int endt   = events[i][1];
        int value = events[i][2];
        
        
        int take = 0, skip = 0;
        if(prev == -1 || events[prev][1] < events[i][0]) {
            take = value + solve(events, i+1, i, k-1);
        }   
        
        skip = solve(events, i+1, prev, k);
        
        return t[prev+1][k] = max(take, skip);
        
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        
        auto lambda = [&](auto &a, auto &b) {
            if(a[1]==b[1])  
                return a[0]-b[0];
            
            return a[1]-b[1];
        };
        
        sort(begin(events), end(events));
        
        n = events.size();
        
        t.resize(n+1, vector<int>(k+1, -1));
        
        return solve(events, 0, -1, k);
    }
};
