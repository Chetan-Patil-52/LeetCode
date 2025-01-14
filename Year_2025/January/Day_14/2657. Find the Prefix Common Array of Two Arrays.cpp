// Brute Force (Approach - 1)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n, 0);
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<=i;j++){
                for(int k=0;k<=yi;k++){
                    if(A[j]==B[k]){
                        count++;
                        break;
                    }
                }
            }
            C[i] = count;
        }
        return C;
    }
};

// Better (Approach - 2)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<bool> isPresentA(n+1,false);
        vector<bool> isPresentB(n+1,false);
        vector<int> C(n,0);

        for(int i=0;i<n;i++){
            isPresentA[A[i]] = true;
            isPresentB[B[i]] = true;
            int count = 0;
            for(int j=1;j<=n;j++){
                if(isPresentA[j] == true && isPresentB[j] == true){
                    count++;
                }
            }
            C[i] = count;
        }
        return C;
    }
};



// Optimail (Approach - 3)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> C(n,0);

        map<int,int> mp;
        int count = 0;
        for(int i=0;i<n;i++){
            mp[A[i]]++;
            if(mp[A[i]] == 2){
                count++;
            }
            mp[B[i]]++;
            if(mp[B[i]] == 2){
                count++;
            }
            C[i] = count;
        }
        return C;
    }
};
// Using Set DS
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> C(n,0);

        set<int> setA,setB;
        int count = 0;
        for(int i=0;i<n;i++){
            setA.insert(A[i]);
            if(setB.find(A[i]) != setB.end()){
                count++;
            }

            setB.insert(B[i]);
            if(setA.find(B[i]) != setA.end()){
                count++;
            }

            C[i] = count;
        }
        return C;
    }
};



