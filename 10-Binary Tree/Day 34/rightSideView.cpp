// T.C: O(N) 
// S.C: O(H) where H is the height of the tree
// Question Link: https://takeuforward.org/plus/dsa/problems/right-left-view-of-bt?source=strivers-sde-sheet

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

    // DFS helper function
    // Traverses the tree in Root -> Right -> Left order
    void func(TreeNode* root, int level, vector<int>& ans) {

        // Base case: if the node is NULL, return
        if (root == NULL)
            return;

        // If this is the first node visited at this level,
        // it is the rightmost node because we visit the right subtree first.
        if (ans.size() == level)
            ans.push_back(root->data);

        // Visit the right subtree first
        func(root->right, level + 1, ans);

        // Then visit the left subtree
        func(root->left, level + 1, ans);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        // Start DFS from the root at level 0
        func(root, 0, ans);

        return ans;
    }
};