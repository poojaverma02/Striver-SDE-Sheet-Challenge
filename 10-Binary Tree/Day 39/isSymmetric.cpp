// T.C: O(N)
// S.C: O(h)
  // Balanced tree: O(log N)
  // Skewed tree: O(N)

// Question Link: https://takeuforward.org/plus/dsa/problems/check-for-symmetrical-bts?source=strivers-sde-sheet


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
    bool symmetry(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;  // Both nodes are null, so symmetric
        }

        if (left == nullptr || right == nullptr) {
            return false;  // One of the nodes is null, so not symmetric
        }

        if (left->data != right->data) {
            return false;  // The values of the nodes do not match, so not
                           // symmetric
        }

        // Recursively check the children of the nodes
        return symmetry(left->left, right->right) &&
               symmetry(left->right, right->left);
    }

   public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;  // An empty tree is symmetric
        }
        return symmetry(root->left, root->right);
    }
};