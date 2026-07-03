// T.C: O(N) 
// S.C: O(h) + O(N), where h is the height of the tree for the recursion stack, plus O(n) for the output array, 
    // Best case (balanced tree): O(log N)
    // Worst case (skewed tree): O(N)

// Question Link: https://takeuforward.org/plus/dsa/problems/postorder-traversal?source=strivers-sde-sheet

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
private:
    // Helper function to perform recursive postorder traversal
    void recursivePostorder(TreeNode* root, vector<int>& ans) {

        // Base case: if the current node is NULL, return
        if (root == NULL)
            return;

        // Step 1: Traverse the left subtree
        recursivePostorder(root->left, ans);

        // Step 2: Traverse the right subtree
        recursivePostorder(root->right, ans);

        // Step 3: Visit the current node
        ans.push_back(root->data);
    }

public:
    vector<int> postorder(TreeNode* root) {

        // Vector to store the postorder traversal
        vector<int> ans;

        // Start recursive traversal from the root
        recursivePostorder(root, ans);

        // Return the final postorder traversal
        return ans;
    }
};