// T.C: O(N)
// S.C: O(N)
// Question Link: https://takeuforward.org/plus/dsa/problems/check-if-a-tree-is-a-bst-or-not?source=strivers-sde-sheet


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
    bool isBST(TreeNode* root) {
        // Use long long to handle INT_MIN and INT_MAX correctly
        return validate(root, LLONG_MIN, LLONG_MAX);
    }

private:
    bool validate(TreeNode* node, long long min, long long max) {
        if (node == nullptr) return true;
        
        // Check bounds. Because min/max are long long, INT_MIN/MAX won't trigger false positives.
        if (node->data <= min || node->data >= max) return false;
        
        // Recursively validate. 
        // Cast node->data to long long isn't strictly necessary but good for clarity
        return validate(node->left, min, node->data) && 
               validate(node->right, node->data, max);
    }
};     