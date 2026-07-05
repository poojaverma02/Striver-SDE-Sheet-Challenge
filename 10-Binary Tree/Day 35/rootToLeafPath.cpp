// T.C: O(N)
// S.C: O(N)
// Question Link: https://takeuforward.org/plus/dsa/problems/print-root-to-note-path-in-bt?source=strivers-sde-sheet

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
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Step 1: Create a map to store the parent of each node
        unordered_map<TreeNode*, TreeNode*> parentMap;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            // If the left child exists, map its parent and push it into the queue
            if (node->left) {
                parentMap[node->left] = node;
                q.push(node->left);
            }
            // If the right child exists, map its parent and push it into the queue
            if (node->right) {
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }

        // Step 2: Use BFS to find all nodes at distance k from the target
        vector<int> result;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int currentDistance = 0;

        // Continue BFS until the desired distance is reached
        while (!q.empty()) {
            if (currentDistance == k) {
                // Collect all nodes at distance k
                while (!q.empty()) {
                    result.push_back(q.front()->data);
                    q.pop();
                }
                return result;
            }
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                // Check left child
                if (node->left && visited.find(node->left) == visited.end()) {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                // Check right child
                if (node->right && visited.find(node->right) == visited.end()) {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                // Check parent
                if (parentMap.find(node) != parentMap.end() && visited.find(parentMap[node]) == visited.end()) {
                    q.push(parentMap[node]);
                    visited.insert(parentMap[node]);
                }
            }
            currentDistance++;
        }

        return result;
    }
};