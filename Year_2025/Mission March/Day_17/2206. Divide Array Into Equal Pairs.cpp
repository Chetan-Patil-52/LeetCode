class Solution {
public:
    typedef long long ll;
    bool divideArray(vector<int>& nums) {
        // Using a map 
        unordered_map<int,int> mp;

        for(int num : nums){
            mp[num]++;
        }

        for(auto& ele : mp){
            if((ele.second%2) != 0){
                return false;
            }
        }
        return true;
    }
};

// Using Set 
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> st;
        for(auto& ele : nums){
            if(st.count(ele)){
                st.erase(ele);
            }else{
                st.insert(ele);
            }
        }
        return st.empty();
    }
};

// Using Vector 
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<bool> paired(501,true);

        for(int &x : nums){
            paired[x] = !paired[x];
        }

        for(int i=0;i<501;i++){
            if(paired[i] != true){
                return false;
            }
        }
        return true;

    }
};

// Sort and Check 
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=1;i<n;i+2){
            if(nums[i] != nums[i-1]){
                return false;
            }
        }

        return true;
    }
};

// Sort and XOR
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums),end(nums));

        for(int i=1;i<n;i+=2){
            if(nums[i] ^ nums[i-1]){
                return false;
            }
        }
        return true;
    }
};
