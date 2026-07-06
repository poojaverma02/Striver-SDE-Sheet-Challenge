// T.C: O(N) 
// S.C: O(h) 
    // Best case (balanced tree): O(log N)
    // Worst case (skewed tree): O(N)
// Question Link: https://takeuforward.org/plus/dsa/problems/check-for-balanced-binary-tree?source=strivers-sde-sheet

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
 * };
 **/

class Solution {
private:
    // Helper function to calculate the height of the tree.
    // Returns -1 if the subtree is not height-balanced.
    int dfsHeight(TreeNode* root) {

        // Base case: an empty tree has height 0
        if (root == NULL)
            return 0;

        // Calculate the height of the left subtree
        int leftH = dfsHeight(root->left);

        // If the left subtree is unbalanced, propagate -1
        if (leftH == -1)
            return -1;

        // Calculate the height of the right subtree
        int rightH = dfsHeight(root->right);

        // If the right subtree is unbalanced, propagate -1
        if (rightH == -1)
            return -1;

        // If the height difference is greater than 1,
        // the current subtree is not balanced
        if (abs(leftH - rightH) > 1)
            return -1;

        // Return the height of the current subtree
        return 1 + max(leftH, rightH);
    }

public:
    bool isBalanced(TreeNode* root) {

        // If dfsHeight returns -1, the tree is not balanced.
        // Otherwise, it is balanced.
        return dfsHeight(root) != -1;
    }
};