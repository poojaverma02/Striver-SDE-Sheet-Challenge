// T.C: O(N) 
// S.C: O(N), Additionally, an auxiliary stack space of approximately O(H) is used, where H is the height of the Binary Tree.
// Question Link: https://takeuforward.org/plus/dsa/problems/construct-a-bt-from-preorder-and-inorder?source=strivers-sde-sheet

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
    private:
    // Recursive helper function to build the tree
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd,
                        vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inMap) {
        // Base case: If the start indices
        // exceed the end indices, return null
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        // Create a new TreeNode with value
        // at the current preorder index
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Find the index of the current root
        // value in the inorder traversal
        int inRoot = inMap[root->data];

        // Calculate the number of
        // elements in the left subtree
        int numsLeft = inRoot - inStart;

        // Recursively build the left subtree
        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft,
                               inorder, inStart, inRoot - 1, inMap);

        // Recursively build the right subtree
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd,
                                inorder, inRoot + 1, inEnd, inMap);

        // Return the current root node
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       unordered_map<int, int> inMap;

        // Populate the map with indices
        // of elements in the inorder traversal
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        // Call the private helper function
        // to recursively build the tree
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
    }
};