Q1. Hexadecimal and Hexatrigesimal Conversion©leetcode
CODE : 
class Solution {
public:
    // Helper function to convert number to any base <= 36
    string toBaseN(int num, int base) {
        if (num == 0) return "0";
        string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string result = "";

        while (num > 0) {
            result += digits[num % base];
            num /= base;
        }

        reverse(result.begin(), result.end());
        return result;
    }

    string concatHex36(int n) {
        int n2 = n * n;
        int n3 = n * n * n;

        string hex = toBaseN(n2, 16);     
        string base36 = toBaseN(n3, 36);  

        return hex + base36;
    }
};

2 Graphs 
Q2. Minimum Cost Path with Alternating Directions II
Q3. Minimum Time to Reach Destination in Directed Graph
Q4. Minimum Stability Factor of Array

