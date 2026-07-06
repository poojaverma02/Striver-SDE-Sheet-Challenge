// T.C: O(N) 
// S.C: O(h) 
    // Best case (balanced tree): O(log N)
    // Worst case (skewed tree): O(N)
// Question Link: https://takeuforward.org/plus/dsa/problems/diameter-of-binary-tree?source=strivers-sde-sheet

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
    // Helper function to calculate the height of the tree
    // while simultaneously updating the maximum diameter
    int height(TreeNode* node, int &diameter) {

        // Base case: height of an empty tree is 0
        if (node == NULL)
            return 0;

        // Calculate the height of the left subtree
        int leftH = height(node->left, diameter);

        // Calculate the height of the right subtree
        int rightH = height(node->right, diameter);

        // Update the diameter if the path passing through
        // the current node is longer than the previous maximum
        diameter = max(diameter, leftH + rightH);

        // Return the height of the current node
        return 1 + max(leftH, rightH);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {

        // Stores the maximum diameter found so far
        int diameter = 0;

        // Compute heights and update diameter
        height(root, diameter);

        // Return the final diameter
        return diameter;
    }
};