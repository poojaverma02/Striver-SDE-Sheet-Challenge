// T.C: O(N)
// S.C: O(h)
  // Balanced tree: O(log N)
  // Skewed tree: O(N)

// Question Link: https://takeuforward.org/plus/dsa/problems/children-sum-property-in-binary-tree?source=strivers-sde-sheet

/* class TreeNode {
       int val;
       TreeNode *left, *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };
*/

class Solution {
public:
    // Function to check children sum property
    bool checkChildrenSum(TreeNode* root) {
        // Return true if node is null
        if (!root) return true;
        // Return true if node is leaf
        if (!root->left && !root->right) return true;
        // Compute left and right child values
        int leftVal = root->left ? root->left->val : 0;
        int rightVal = root->right ? root->right->val : 0;
        // Check current node and recurse on children
        return (root->val == leftVal + rightVal) &&
               checkChildrenSum(root->left) &&
               checkChildrenSum(root->right);
    }
};
