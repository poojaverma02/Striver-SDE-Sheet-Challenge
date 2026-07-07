// T.C: O(N) 
// S.C: O(h) 
    // Best case (balanced tree): O(log N)
    // Worst case (skewed tree): O(N)
// Question Link: https://takeuforward.org/plus/dsa/problems/lca-in-bt?source=strivers-sde-sheet

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // Base Case:
        // 1. If the current node is NULL, return NULL.
        // 2. If the current node is either p or q, return it.
        if (root == NULL || root == p || root == q)
            return root;

        // Search for p and q in the left subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // Search for p and q in the right subtree
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If left subtree doesn't contain either p or q,
        // the answer must be in the right subtree.
        if (left == NULL)
            return right;

        // If right subtree doesn't contain either p or q,
        // the answer must be in the left subtree.
        else if (right == NULL)
            return left;

        // If both left and right are non-NULL,
        // one node is found in each subtree.
        // Therefore, the current node is their Lowest Common Ancestor.
        else
            return root;
    }
};