// T.C: O(N)
// S.C: O(h)
  // Balanced tree: O(log N)
  // Skewed tree: O(N)

// Question Link: https://takeuforward.org/plus/dsa/problems/flatten-binary-tree-to-linked-list?source=strivers-sde-sheet

/* class TreeNode {
       int val;
       TreeNode *left, *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };
*/

class Solution {
   private:
    // Pointer to keep track of previous node in preorder
    TreeNode* prev = nullptr;

    // Helper recursive function to flatten the tree
    void flattenHelper(TreeNode* root) {
        if (!root) return;

        // Recursively flatten right subtree first
        flattenHelper(root->right);

        // Recursively flatten left subtree
        flattenHelper(root->left);

        // Rearrange pointers
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }

   public:
    void flatten(TreeNode* root) { flattenHelper(root); }
};

