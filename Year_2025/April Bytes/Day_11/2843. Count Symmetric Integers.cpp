// First Approach - But I missed to deal with odd numbers 
class Solution {
public:
    bool check(int num,int n){
        int sum1=0,sum2=0;
        // int temp = num;
        for(int i=0;i<n/2;i++){
            int rem = num%10;
            num /= 10;
            sum1 += rem;
        }
        for(int i=n/2;i<n;i++){
            int rem = num%10;
            num /= 10;
            sum2 += rem;
        }
        if(sum2==sum1){
            return true;
        }
        return false;
    }

    int countDigits(int num){
        int digits = 0;
        while(num > 0){
            num /= 10;
            digits++;
        }
        return digits;
    }

    int countSymmetricIntegers(int low, int high) {
        
        vector<int> result;
        for(int i=low;i<=high;i++){
            int n = countDigits(i);
            if(check(i,n)){
                result.push_back(i);
            }
        }
        return result.size();
    }
};

// After Debugging 

class Solution {
public:
    bool check(int num){
        string s = to_string(num);
        int n = s.size();
        if(n%2 != 0) return false;

        int half = n/2;
        int sum1=0,sum2=0;
        for(int i=0;i<half;i++) sum1 += s[i] - '0';
        for(int i=half;i<n;i++) sum2 += s[i] - '0';

        return sum1 == sum2;
    }

    int countSymmetricIntegers(int low, int high) {
        
        // vector<int> result;
        int count = 0;
        for(int i=low;i<=high;i++){
            // int n = countDigits(i);
            if(check(i)) count++;
        }
        return count;
    }
};


// Approach - 3 (Optimal) O(n)

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        // As it is mentioned in the constrain 10^4 the length can be btw 1-4;
        // But as it is symetric it may be either 2 or 4;
        for(int num=low;num<=high;num++){
            if(num>10 && num<=99 && num%11==0){
            count++;
            }
            else if(num>999 && num<=9999){
                int dig1 = num/1000;
                int dig2 = (num/100) % 10;
                int dig3 = (num/10) % 10;
                int dig4 = (num) % 10;

                if(dig1 + dig2 == dig3 + dig4){
                    count++;
                }
            }
        }
        return count;
    }
};

