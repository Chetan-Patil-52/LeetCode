//  Approach 1 using Substring without provious sorting T.C : O(n * L^2)
// class Solution {
// public:
//     vector<string> removeSubfolders(vector<string>& folder) {
//         unordered_set<string> st(begin(folder),end(folder)); // Space : O(n)
//         vector<string> result;

//         for(string& currFolder : folder){ T.C : O(n)
//             bool isSubFolder = false;
//             string tempFolder = currFolder;
//             while(!currFolder.empty()){   T.C : O(L)
//                 size_t position = currFolder.find_last_of('/'); T.C : O(L)

//                 currFolder = currFolder.substr(0,position);

//                 if(st.find(currFolder) != st.end()){
//                     // It means currFolder is not an subfolder
//                     isSubFolder = true;
//                     break;
//                 }
//             }

//             if(!isSubFolder){
//                 result.push_back(tempFolder);
//             }
//         }
//     return result;
//     }

// };

// Approach 2 using sort function of T.C : O(nlogn) to sort string of vectors
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(begin(folder),end(folder));
        vector<string> result;

        result.push_back(folder[0]); // As the array is sorted 1st elem will always be parent so we just pushed it

        for(int i = 1; i< folder.size(); i++){
            string currFolder = folder[i];
            string lastFolder = result.back();
            lastFolder += '/';

            if(currFolder.find(lastFolder) != 0){
                result.push_back(currFolder);
            }
        }
        return result;
    }
};

