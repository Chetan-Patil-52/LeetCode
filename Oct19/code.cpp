class Solution {
public:
    char findKthBit(int n, int k) {
        // S1 = "0"
        // S2 = "011"
        // S3 = "0111001"
        // S4 = "011100110110001"

        if(n==1){
            return '0';
        }

        int length = (1 << n)-1;

        if(k < ceil(length/2.0)){
            return findKthBit(n-1,k);
        }
        else if(k == ceil(length/2.0)){
            return '1';
        }
        else{
            char ch = findKthBit(n,length-(k-1)); // Handling the Reversed idx
            return (ch=='0') ? '1' : '0';
        }

    }
};
