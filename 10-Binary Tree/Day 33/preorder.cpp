// T.C: O(N) 
// S.C: O(h) + O(N), where h is the height of the tree for the recursion stack, plus O(n) for the output array, 
    // Best case (balanced tree): O(log N)
    // Worst case (skewed tree): O(N)

// Question Link: https://takeuforward.org/plus/dsa/problems/preorder-traversal?source=strivers-sde-sheet

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
    // Helper function to perform recursive preorder traversal
    void recursivePreorder(TreeNode* root, vector<int>& ans) {

        // Base case: if the current node is NULL, return
        if (root == NULL)
            return;

        // Step 1: Visit the current node
        ans.push_back(root->data);

        // Step 2: Traverse the left subtree
        recursivePreorder(root->left, ans);

        // Step 3: Traverse the right subtree
        recursivePreorder(root->right, ans);
    }

public:
    vector<int> preorder(TreeNode* root) {

        // Vector to store the preorder traversal
        vector<int> ans;

        // Start recursive traversal from the root
        recursivePreorder(root, ans);

        // Return the final preorder traversal
        return ans;
    }
};