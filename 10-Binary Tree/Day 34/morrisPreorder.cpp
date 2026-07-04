// T.C: O(2N) 
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/morris-preorder-traversal-?source=strivers-sde-sheet

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
public:
    vector<int> preorder(TreeNode* root) {
        TreeNode* cur = root;
        vector<int> preorder;

        // Traverse the tree using Morris Preorder Traversal
        while (cur != NULL) {

            // Case 1: No left child
            // Visit the current node and move to the right child
            if (cur->left == NULL) {
                preorder.push_back(cur->data);
                cur = cur->right;
            }
            else {
                // Find the inorder predecessor
                // (rightmost node in the left subtree)
                TreeNode* prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }

                // Case 2: Thread doesn't exist
                if (prev->right == NULL) {

                    // Create a temporary thread back to the current node
                    prev->right = cur;

                    // Visit the current node before going left
                    // (Preorder: Root -> Left -> Right)
                    preorder.push_back(cur->data);

                    // Move to the left subtree
                    cur = cur->left;
                }
                else {
                    // Case 3: Thread already exists
                    // Remove the temporary thread
                    prev->right = NULL;

                    // Move to the right subtree
                    cur = cur->right;
                }
            }
        }

        return preorder;
    }
};