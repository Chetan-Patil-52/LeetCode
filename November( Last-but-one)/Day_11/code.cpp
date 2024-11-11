class Solution {
public:

    bool isPrime[1000];

    void seive(){
        fill(isPrime,isPrime+1000,true);// Initialize the array ith all ture
        isPrime[0] = false;
        isPrime[1] = false;

        for(int i=2;i*i<1000;i++){
            if(isPrime[i]==true){
                for(int j=i*i;j<1000;j+=i){
                    isPrime[j] = false;
                }
            }
        }
    }



    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();

        seive(); // it will populate my is prime array // O(1)
        // isPrime[i] == true means, i is a prime number els i is not a prime number;

        // O(n * maxNum)
        for(int i=n-2;i >= 0;i--){
            if(nums[i]<nums[i+1]){
                continue;
            }

            // nums[i] >= nums[i+1]
            // decrease nums[i] atleast less than nums[i+!]

            // check for the prime numbers less than n
            for(int p=2;p<nums[i];p++){
                if(!isPrime[p]){
                    continue;
                }

                if(nums[i] - p < nums[i+1]){
                    nums[i] -= p;
                    break;
                }
            }

            if(nums[i] >= nums[i+1]){
                return false;
            }
        }

        return true;
    }
};
