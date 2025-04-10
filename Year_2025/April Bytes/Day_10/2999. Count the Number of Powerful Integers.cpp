// Naive Approach - pretty close but missed one condition 

class Solution {
public:
    int countDigits(int num){
        int cnt = 0;
        while(num > 0){
            num/=10;
            cnt++;
        }
        return cnt;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        // step1 one convert string int int
        // step2 - cont the number of digits of int and create a map
        // step3 - Update the value of s each time with mp[count] and check if the (s<=finish & s/mp[count] < limit) result ++;

        int num = stoi(s);

        if(num > finish){
            return 0;
        }

        int digit = countDigits(num);

        long long value = 10;
        unordered_map<int,int> mp;
        for(int i=1;i<=digit;i++){
            mp[i] = value;
            value *= 10;
        }


        int result =  0;
        while(true){
            if(num < start){
                num += mp[digit];
                continue;
            }
            if((num > finish) || (num/mp[digit]) > limit){
                break;
            }
            result++;
            num += mp[digit];
        }
        return result;
    }
};
