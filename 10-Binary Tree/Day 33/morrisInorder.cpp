// T.C: O(2N) 
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/morris-inorder-traversal-?source=strivers-sde-sheet

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
 * };
 */

class Solution {
public:
    vector<int> getInorder(TreeNode* root) {

        // Vector to store the inorder traversal
        vector<int> inorder;

        // Start traversal from the root
        TreeNode* cur = root;

        while (cur != NULL) {

            // Case 1: Current node has no left child
            if (cur->left == NULL) {

                // Visit the current node
                inorder.push_back(cur->data);

                // Move to the right subtree
                cur = cur->right;
            }
            else {

                // Find the inorder predecessor of the current node
                TreeNode* prev = cur->left;

                // Move to the rightmost node of the left subtree
                // or stop if a thread already exists
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }

                // If no thread exists, create one
                if (prev->right == NULL) {

                    // Create a temporary link back to the current node
                    prev->right = cur;

                    // Move to the left child
                    cur = cur->left;
                }
                else {

                    // Thread already exists, remove it
                    prev->right = NULL;

                    // Visit the current node
                    inorder.push_back(cur->data);

                    // Move to the right subtree
                    cur = cur->right;
                }
            }
        }

        // Return the inorder traversal
        return inorder;
    }
};
