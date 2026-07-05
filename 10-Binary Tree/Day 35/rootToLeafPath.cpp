// T.C: O(N)
// S.C: O(N)
// Question Link: https://takeuforward.org/plus/dsa/problems/print-root-to-note-path-in-bt?source=strivers-sde-sheet

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

 class Solution {
public:
    vector<vector<int>> allRootToLeaf(TreeNode* root) {
        vector<vector<int>> allPaths; // Vector to store all root-to-leaf paths
        vector<int> currentPath; // Vector to store the current path
        
        dfs(root, currentPath, allPaths);
        
        return allPaths;
    }

private:
    void dfs(TreeNode* node, vector<int>& path, vector<vector<int>>& allPaths) {
        if (!node) {
            return; // Base case: return if the current node is null
        }
        // Add the current node's data to the path
        path.push_back(node->data);

        if (!node->left && !node->right) {
            // Add the path to allPaths if it's a leaf node
            allPaths.push_back(path); 
        } else {
            // Recursively call the function on the left child
            dfs(node->left, path, allPaths); 
            // Recursively call the function on the right child
            dfs(node->right, path, allPaths); 
        }
         // Backtrack by removing the last node from the path 
        path.pop_back();
    }
};
               