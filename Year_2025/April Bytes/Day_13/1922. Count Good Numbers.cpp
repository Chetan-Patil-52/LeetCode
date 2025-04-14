class Solution {
public:

    const int M = 1e9+7;
    // eg . 2^5 thus a=2,b=5
    // Binary exponential
    int findPower(long long a,long long b){
        if(b==0){
            return 1;
        }

        long long half = findPower(a,b/2);
        long long result = (half * half) % M;

        if(b % 2 == 1){
            result =(a * result) % M;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        // Here 5 coz there are 5 even numbers including 0 from 1-10 and 4 Prime numbers
        return (long long)findPower(5,(n+1)/2) * findPower(4,n/2) % M;
    }
};
