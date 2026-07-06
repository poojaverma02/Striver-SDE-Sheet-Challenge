// T.C: O(N) 
// S.C: O(h) 
    // Best case (balanced tree): O(log N)
    // Worst case (skewed tree): O(N)
// Question Link: https://takeuforward.org/plus/dsa/problems/maximum-depth-in-bt?source=strivers-sde-sheet

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
    int maxDepth(TreeNode* root) {

        // Base case: if the tree is empty, its height is 0
        if (root == NULL)
            return 0;

        // Recursively find the height of the left subtree
        int leftH = maxDepth(root->left);

        // Recursively find the height of the right subtree
        int rightH = maxDepth(root->right);

        // Height of the current node is 1 (current node)
        // plus the maximum height of its left and right subtrees
        return 1 + max(leftH, rightH);
    }
};