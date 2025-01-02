class Solution {
public:
    int maxScore(string s) {
        // Approach 1 - Brute Force
        // int n = s.length();
        
        // int result = INT_MIN;

        // for(int i = 0;i<n-1;i++){
        //     int zero_count = 0;
        //     for(int j = 0;j<=i;j++){
        //         if(s[j]=='0'){
        //             zero_count++;
        //         }
        //     }

        //     int one_count = 0;
        //     for(int j = i+1;j<n;j++){
        //         if(s[j]=='1'){
        //             one_count++;
        //         }
        //     }

        //     result = max(result, one_count + zero_count);
        // }

        // return result;

        // Approach 2 - (Better) 2 pass

        // int n = s.length();

        // int result = INT_MIN;

        // int total_ones = count(begin(s),end(s),'1');

        // int ones = 0;
        // int zeros = 0;
        // for(int i = 0;i<n-1;i++){
        //     if(s[i]=='1'){
        //         ones++;
        //     }else{
        //         zeros++;
        //     }

        //     int right_ones = total_ones - ones;

        //     result = max(result, zeros + right_ones);
        // }
        // return result;

        // Approach 3 - (Otmimal) 1 pass

        int n = s.length();

        int result = INT_MIN;

        // int total_ones = count(begin(s),end(s),'1');

        int ones = 0;
        int zeros = 0;
        for(int i = 0;i<n-1;i++){
            if(s[i]=='1'){
                ones++;
            }else{
                zeros++;
            }
            
            result = max(result, (zeros - ones));

        }

        if(s[n-1]=='1'){
            ones++;
        }


        return result+ones;

    }
};
