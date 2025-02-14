// Approach -1 (Brute force)
class ProductOfNumbers {
public:

    vector<int> nums;
    int n;

    ProductOfNumbers() {
        nums.clear();
        n = 0;
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        n = nums.size();
        int prod = 1;
        for(int i=n-k;i<n;i++){
            prod *= nums[i];
        }
        return prod;
    }
};

// Approach - 2 (Optimized)

class ProductOfNumbers {
public:

    vector<int> nums;
    int n;

    ProductOfNumbers() { // this is an constructor 
        nums.clear();
        n = 0;
    }
    
    void add(int num) {
        // check if the num is zero if it is reinitilize stack start from zero 
        if(num == 0){
            nums = {};
            n = 0;
        }else{
            if(nums.empty()){
                nums.push_back(num);
            }else{
                nums.push_back(nums[n-1] * num);
            }
            n++;
        }
    }
    
    int getProduct(int k) {
        if(k > n){
            return 0;
        }else if(k==n){
            return nums[n-1];
        }else{
            return nums[n-1] / nums[n-k-1];
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
