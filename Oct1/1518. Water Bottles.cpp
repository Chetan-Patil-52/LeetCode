class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        while(numBottles >=  numExchange){
            res += numBottles/numExchange;
            int fullBottles = numBottles/numExchange;
            int reminder = numBottles%numExchange;
            numBottles = fullBottles + reminder;
        }
        // if(numB > 0){
        //     res += numBottles;
        // }
        return res;
    }
};
