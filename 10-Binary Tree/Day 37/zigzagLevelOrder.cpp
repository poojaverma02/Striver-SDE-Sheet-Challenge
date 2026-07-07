// T.C: O(N) 
// S.C: O(N) 
// Question Link: https://takeuforward.org/plus/dsa/problems/zig-zag-or-spiral-traversal?source=strivers-sde-sheet

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        // Stores the final zigzag level order traversal.
        vector<vector<int>> result;

        // If the tree is empty, return an empty result.
        if (root == NULL) {
            return result;
        }

        // Queue for performing level order traversal (BFS).
        queue<TreeNode*> q;
        q.push(root);

        // Direction flag:
        // true  -> Left to Right
        // false -> Right to Left
        bool leftToRight = true;

        // Process nodes level by level.
        while (!q.empty()) {

            // Number of nodes in the current level.
            int size = q.size();

            // Create a vector of required size for this level.
            vector<int> row(size);

            // Traverse all nodes of the current level.
            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                // Determine the correct index based on traversal direction.
                int index = leftToRight ? i : (size - 1 - i);

                // Store the current node's value at the calculated index.
                row[index] = node->data;

                // Push the left child into the queue.
                if (node->left) {
                    q.push(node->left);
                }

                // Push the right child into the queue.
                if (node->right) {
                    q.push(node->right);
                }
            }

            // Reverse the traversal direction for the next level.
            leftToRight = !leftToRight;

            // Store the current level in the final answer.
            result.push_back(row);
        }

        return result;
    }
};