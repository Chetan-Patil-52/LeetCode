class Solution {
public:

    // bool allSetBitCnt(int n){
    //     return (n & (n+1)) == 0;
    // }

    int smallestNumber(int n) {
        // int result = n;
        // while(!allSetBitCnt(result)){
        //     result++;
        // }

        // App - 2
        // int result = 1;
        // while(result < n){
        //     result = (result * 2) + 1;
        // }

        // App - 3
        int len = log2(n)+1;
        int result = (1 << len) - 1;
        
        return result;
    }
};
