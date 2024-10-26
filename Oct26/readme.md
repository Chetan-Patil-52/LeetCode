# 2458. Height of Binary Tree After Subtree Removal Queries

# Intuition
To solve this problem, the main idea is to preprocess each node in the tree to determine its height and level, which allows us to answer queries efficiently. By storing the maximum and second maximum heights for each level, we can handle scenarios where a node is removed and adjust the level heights accordingly. This enables us to determine the impact on the tree's height when a particular node is deleted.

# Approach
1. Calculate Heights and Levels: We use recursion to determine the height and level of each node. This involves traversing from the root and updating each node's height based on its children. The maximum and second maximum heights for each level are also stored.
2. Answer Queries: For each query, which requires "deleting" a node, we compute the resultant tree height by checking if the node has the maximum or second maximum height for its level. Adjustments are made based on this, and the modified height is appended to the result.

# Complexity
- Time complexity: 
  - Preprocessing (findHeight function) - $$O(n)$$, where \(n\) is the number of nodes in the tree, as we visit each node once.
  - Query Processing - $$O(m)$$, where \(m\) is the number of queries, as each query involves a constant-time operation.
  
- Space complexity:
  - Space Complexity - $$O(n)$$ due to the storage of height, level, and auxiliary arrays.



# Code
```cpp []
/* C++ */
//Approach - Simple Recursion and preprocessing
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int level[1000001]; //level of each node
    int height[100001]; //height of each node
    int levelMaxHt[100001];
    int levelSecondMaxHt[100001];

    int findHeight(TreeNode* root, int l) {
        if(!root) {
            return 0;
        }

        level[root->val] = l;
        height[root->val] = max(findHeight(root->left, l+1), findHeight(root->right, l+1)) + 1;

        if(levelMaxHt[l] < height[root->val]) {
            levelSecondMaxHt[l] = levelMaxHt[l];
            levelMaxHt[l] = height[root->val];
        } else if(levelSecondMaxHt[l] < height[root->val]) {
            levelSecondMaxHt[l] = height[root->val];
        }

        return height[root->val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        findHeight(root, 0);

        vector<int> result;

        for(int &node : queries) {
            //node = that we have to delete
            int L = level[node]; //O(1) //node ka level hai ye

            //L + H - 1

            int tempResult = L + (levelMaxHt[L] == height[node] ? levelSecondMaxHt[L] : levelMaxHt[L]) - 1;

            result.push_back(tempResult);
        } 

        return result;
    }
};

```
