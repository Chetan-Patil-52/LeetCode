class Solution {
public:

    bool isPalindrome(string baseK){
        int i=0,j=baseK.length()-1;
        while(i<=j){
            if(baseK[i]!=baseK[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    string convertToBaseK(long long pal_num, int k){
        if(pal_num == 0) return "0";
        string result = "";
        while(pal_num>0){
            result += to_string(pal_num%k);
            pal_num /= k;
        }
        return result;
    }

    long long kMirror(int k, int n) {
        int L = 1; // First well remove all the palindroms of Length 1 
        long long sum = 0;
        while(n>0){
            int half_length = (L+1)/2;
            long long min_num = pow(10,half_length-1);
            long long max_num = pow(10,half_length)-1;

            for(int num = min_num;num<=max_num;num++){
                string first_half = to_string(num);
                string second_half = first_half;
                reverse(begin(second_half),end(second_half));
                string pal = "";
                if(L%2==0){
                    pal = first_half + second_half;
                }else{
                    pal = first_half + second_half.substr(1);
                }

                long long pal_num = stoll(pal);
                string baseK = convertToBaseK(pal_num,k);
                if(isPalindrome(baseK)){
                    sum += pal_num;
                    n--;
                }
                if(n==0) break;
            }
            L++;
        }
        return sum;
    }
};
