# 1233. Remove Sub-Folders from the Filesystem

Intuition
The problem requires removing subfolders from a list of folder paths, keeping only the main folders without their nested subfolders. Intuitively, sorting the folder paths and filtering out any folder that appears as a subpath of another can solve this efficiently.

Approach
The solution can be achieved using two approaches:

Using a Set without Sorting:

Store each folder path in a set.
For each folder path, check if any parent folder exists by iteratively moving up the directory structure. If a parent is found in the set, it’s a subfolder and should be ignored; otherwise, add it to the result.
This approach has a time complexity of O(n * l^2), where 

L is the maximum length of a folder string.
Sorting and Filtering:

First, sort the list of folders alphabetically. Sorting ensures that subfolders follow their parent folders in order.
Start with the first folder in the result list (since it will be the parent due to sorting).
For each subsequent folder, check if it begins with the last added folder path followed by a '/' to confirm it’s a subfolder. If it isn’t, add it to the result.
This approach has a time complexity of 
O(nlogn) for sorting and 𝑂(𝑛)
O(n) for filtering.
Complexity
Time Complexity:

Sorting takes 
O(nlogn).
Iterating over the sorted list takes 

Overall, the time complexity is 
O(nlogn + n*l).
Space Complexity: O(n)

Using additional space for the result vector gives a space complexity of 

# Code
```cpp []
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


```
