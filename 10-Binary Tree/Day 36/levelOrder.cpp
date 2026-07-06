// T.C: O(N)
// S.C: O(N)
// Question Link: https://takeuforward.org/plus/dsa/problems/level-order-traversal?source=strivers-sde-sheet

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
    vector<vector<int>> levelOrder(TreeNode* root) {

        // Stores the final level order traversal
        vector<vector<int>> ans;

        // If the tree is empty, return an empty result
        if (root == NULL) return ans;

        // Queue is used for Breadth First Search (BFS)
        queue<TreeNode*> q;
        q.push(root);

        // Traverse until all nodes are processed
        while (!q.empty()) {

            // Number of nodes present at the current level
            int size = q.size();

            // Stores all node values of the current level
            vector<int> level;

            // Process every node of the current level
            for (int i = 0; i < size; i++) {

                // Get the front node from the queue
                TreeNode* node = q.front();
                q.pop();

                // Store the current node's value
                level.push_back(node->data);

                // Push the left child into the queue if it exists
                if (node->left != NULL)
                    q.push(node->left);

                // Push the right child into the queue if it exists
                if (node->right != NULL)
                    q.push(node->right);
            }

            // Store the completed level in the answer
            ans.push_back(level);
        }

        // Return the level order traversal
        return ans;
    }
};