class Solution {
public:
    vector<int> minOperations(string boxes) {

        // Approach - II (BruteForce)

        // int n = boxes.size();

        // unordered_set<int> st;
        
        // for(int i=0;i<n;i++){
        //     if(boxes[i]=='1'){
        //         st.insert(i);
        //     }
        // }

        // vector<int> answer(n,0);

        // for(int i = 0;i<n;i++){
        //     for(auto &idx : st){
        //         answer[i] += abs(idx-i);
        //     }
        // }
        // return answer;

        // Approach - II (BruteForce)

        // int n = boxes.size();

        // vector<int> answer(n,0);
        //     for(int i = 0;i<n;i++){

        //         if(boxes[i]=='1'){
        //             for(int j = 0;j<n;j++){
        //                 answer[j] += abs(j-i);
        //             }
        //         }
        //     }
        // return answer;


        // Approach - III (Optimal)

        int n = boxes.size();

        vector<int> answer(n,0);

        int cumValue = 0, cumValueSum = 0;

        for(int i = 0;i<n;i++){
            answer[i] = cumValueSum;
            cumValue += boxes[i] == '0' ? 0 : 1;
            cumValueSum += cumValue;
        }

        cumValue = 0;
        cumValueSum = 0;

        for(int i=n-1;i>=0;i--){
            answer[i] += cumValueSum;
            cumValue += boxes[i] == '0' ? 0 : 1;
            cumValueSum += cumValue;
        }

        // O(n+n) ~ O(n)
        return answer;
    }
};
