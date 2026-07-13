// T.C: O(N)
// S.C: O(H)
      // Balanced BST: O(log N)
      // Skewed BST: O(N)
// Question Link: https://takeuforward.org/plus/dsa/problems/largest-bst-in-binary-tree?source=strivers-sde-sheet

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
    // Helper class to store information about a subtree.
    struct NodeValue {
        int minNode, maxNode, maxSize;
        NodeValue(int minNode, int maxNode, int maxSize) : minNode(minNode), maxNode(maxNode), maxSize(maxSize) {}
    };

    // Helper function to recursively find the largest BST subtree.
    NodeValue largestBSTSubtreeHelper(TreeNode* node) {
        // Base case: if the node is null, return a default NodeValue.
        if (!node) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        // Recursively get values from the left and right subtrees.
        NodeValue left = largestBSTSubtreeHelper(node->left);
        NodeValue right = largestBSTSubtreeHelper(node->right);

        // Check if the current node is a valid BST node.
        if (left.maxNode < node->data && node->data < right.minNode) {
            // Current subtree is a valid BST.
            return NodeValue(
                min(node->data, left.minNode),
                max(node->data, right.maxNode),
                left.maxSize + right.maxSize + 1
            );
        }

        // Current subtree is not a valid BST.
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

    int largestBST(TreeNode* root) {
        // Initialize the recursive process and return the size of the largest BST subtree.
        return largestBSTSubtreeHelper(root).maxSize;
    }
};