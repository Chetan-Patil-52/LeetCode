// Bruteforce gives TLE as it reequies to sort multiple timie - > O(n logn)

// Using MinHeap 
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long,vector<long>,greater<long>> pq(begin(nums),end(nums));

        int count = 0;

        while(!pq.empty() && pq.top() < k){
            int smallest = pq.top();
            pq.pop();
            int secondSmallest = pq.top();
            pq.pop();
            pq.push(smallest * 2 + secondSmallest);
            count++;
        }
        return count;
    }
};

