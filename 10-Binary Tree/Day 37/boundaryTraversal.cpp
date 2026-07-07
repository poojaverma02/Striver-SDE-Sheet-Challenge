// T.C: O(H) + O(N) + O(H) ~ O(N) 
// S.C: O(N) 
// Question Link: https://takeuforward.org/plus/dsa/problems/boundary-traversal?source=strivers-sde-sheet


class Solution {
private:

    // Checks whether the current node is a leaf node.
    bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
    }

    // Adds the left boundary nodes (excluding leaf nodes).
    void addLeftBoundary(TreeNode* root, vector<int>& res) {

        // Start from the left child of the root.
        TreeNode* cur = root->left;

        while (cur) {

            // Ignore leaf nodes to avoid duplicates.
            if (!isLeaf(cur)) {
                res.push_back(cur->data);
            }

            // Prefer moving to the left child.
            if (cur->left)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }

    // Adds all leaf nodes using DFS.
    void addLeaves(TreeNode* root, vector<int>& res) {

        // If the current node is a leaf, add it.
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }

        // Traverse the left subtree.
        if (root->left) {
            addLeaves(root->left, res);
        }

        // Traverse the right subtree.
        if (root->right) {
            addLeaves(root->right, res);
        }
    }

    // Adds the right boundary nodes (excluding leaf nodes)
    // in bottom-up order.
    void addRightBoundary(TreeNode* root, vector<int>& res) {

        // Start from the right child of the root.
        TreeNode* cur = root->right;

        // Temporary vector to store right boundary.
        vector<int> temp;

        while (cur) {

            // Ignore leaf nodes to avoid duplicates.
            if (!isLeaf(cur)) {
                temp.push_back(cur->data);
            }

            // Prefer moving to the right child.
            if (cur->right)
                cur = cur->right;
            else
                cur = cur->left;
        }

        // Add nodes in reverse order.
        for (int i = temp.size() - 1; i >= 0; i--) {
            res.push_back(temp[i]);
        }
    }

public:
    vector<int> boundary(TreeNode* root) {

        // Stores the final boundary traversal.
        vector<int> res;

        // If the tree is empty, return an empty result.
        if (!root)
            return res;

        // Add the root if it is not a leaf.
        if (!isLeaf(root)) {
            res.push_back(root->data);
        }

        // Step 1: Add the left boundary.
        addLeftBoundary(root, res);

        // Step 2: Add all leaf nodes.
        addLeaves(root, res);

        // Step 3: Add the right boundary in reverse order.
        addRightBoundary(root, res);

        return res;
    }
};