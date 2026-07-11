// T.C: O(N)
// S.C: O(h)
// Question Link: https://takeuforward.org/plus/dsa/problems/construct-a-bst-from-a-preorder-traversal?source=strivers-sde-sheet

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // Start the recursive function with the first element as the root
        // and the entire range of valid numbers
        int index = 0; // Initialize index
        return bstFromPreorderHelper(preorder, INT_MAX, index);
    }

private:
    TreeNode* bstFromPreorderHelper(vector<int>& preorder, int bound, int& index) {
        // If all elements are used or the next element
        // is greater than the bound, return null
        if (index == preorder.size() || preorder[index] > bound) return nullptr;

        // Create a new TreeNode with the current value
        TreeNode* root = new TreeNode(preorder[index++]);

        // Recursively construct the left subtree
        // with the current value as the new bound
        root->left = bstFromPreorderHelper(preorder, root->data, index);

        // Recursively construct the right subtree
        // with the same bound as the parent's bound
        root->right = bstFromPreorderHelper(preorder, bound, index);

        // Return the constructed subtree's root
        return root;
    }
};
