// App - 1
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> vec(n);
        for(int i=0;i<n;i++){
            vec[i] = make_pair(i,nums[i]);
        }

        auto chetan = [](auto &p1,auto &p2){
            return p2.second > p1.second;
        };

        // sort the nums in assending order
        sort(begin(vec),end(vec),chetan);
        // by default sort according to vec.first - ie. idx
        sort(begin(vec)+(n-k),end(vec));

        vector<int> result(k);
        for(int i=n-k;i<n;i++){
            result[i] = vec[i].second;
        }
        return result;
    }
};

App - 2 TC : O(n)

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        if(k==n){
            return nums;
        }

        vector<int> temp(nums);

        nth_element(begin(temp),begin(temp)+(k-1),end(temp),greater<int>());

        int kth_element = temp[k-1];
        int countKthElement = count(begin(temp),begin(temp)+(k),kth_element);

        vector<int> result;
        for(auto num : nums){
            if(num > kth_element){
                result.push_back(num);
            }else if(num == kth_element && countKthElement){
                result.push_back(num);
                countKthElement--;
            }

            if(result.size() == k) break;
        }
        return result;
    }
};
