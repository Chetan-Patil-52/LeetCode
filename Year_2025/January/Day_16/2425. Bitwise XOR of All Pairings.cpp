
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
