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

//Approach (Using Simple String traversal and Combinatorics multipliaction to find count)
//T.C : O((n - m) * log(limit)), n and m are lengths of start and finish
//S.C : O(1)
class Solution {
public:
    long long solve(string& str, string& inputSuffix, int limit) {
        if(str.length() < inputSuffix.length()) {
            return 0;
        }

        long long count = 0;
        string trailString = str.substr(str.length() - inputSuffix.length()); //"00"
        //"3000" - 4
        //"12" - 2
        int remainL = str.length() - inputSuffix.length();

        for(int i = 0; i < remainL; i++) {
            int digit = str[i] - '0';

            if(digit <= limit) {
                count += digit * pow(limit+1, remainL-i-1);
            } else {
                count += pow(limit+1, remainL-i); //5^pos
                return count;
            }
        }

        if(trailString >= inputSuffix) {
            count += 1;
        }


        return count;

    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string startStr = to_string(start-1);
        string finishStr = to_string(finish);

         return solve(finishStr, s, limit) - solve(startStr, s, limit);
    }
};
