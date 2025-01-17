class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // Big Brain Approach 

        int xOR = 0;
        for(int num : derived){
            xOR ^= num;
        }

        if(xOR==0){
            return true;
        }else{
            return false;
        }


    //     int n= derived.size();
    //     vector<int> original(n);
    //     // let original[i]=0
    //     original[0] = 0;
    //     for(int i=0;i<n-1;i++){
    //         original[i+1] = original[i] ^ derived[i];
    //     }

    //     if(original[n-1] ^ original[0] == derived[n-1]){
    //         return true;
    //     }

    //     // let original[i]=1
    //     original[0] = 1;
    //     for(int i=0;i<n-1;i++){
    //         original[i+1] = original[i] ^ derived[i];
    //     }

    //     if(original[n-1] ^ original[0] == derived[n-1]){
    //         return true;
    //     }
    //     return false;
    }
};
