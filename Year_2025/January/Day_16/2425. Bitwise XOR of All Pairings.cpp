
// Approch - 1 (Memory exceded)
# define ll long long int

class Solution {
public:
    // bruete force gives Memory level exceded 
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        ll n = nums1.size();
        ll m = nums2.size();
        vector<ll> nums3(m*n,0);
        ll idx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(idx<n*m){
                    nums3[idx] = nums1[i] ^ nums2[j];
                    idx++;
                }
            }
        }

        ll sum = 0;
        for(int i=0;i<nums3.size();i++){
            sum ^= nums3[i];
        }

        return sum;
    }
};



// Approch - 2 (Optimal )

class Solution {
public:
    // Optimal Approach 
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int  m = nums2.size();
        
        int xOR1 = 0;
        int xOR2 = 0;
        for(int num : nums1) xOR1 ^= num;
        for(int num : nums2) xOR2 ^= num;
     

        return (n%2==1 ? xOR2 : 0) ^ (m%2==1 ? xOR1 : 0);
    }
};

// OR 
class Solution {
public:
    // Optimal Approach 
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int xOR = 0;
        if(m%2!=0){
            for(int num : nums2){
                xOR ^= num;
            }
        }

        if(n%2!=0){
            for(int num : nums1){
                xOR ^= num;
            }
        }

        return xOR;
    }
};
