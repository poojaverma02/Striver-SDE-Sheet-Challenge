// T.C: O(N*logN)
// S.C: O(N) 
// Question Link: https://takeuforward.org/plus/dsa/problems/top-view-of-bt?source=strivers-sde-sheet

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
    vector<int> topView(TreeNode *root) {
        // Vector to store the final top view result
        vector<int> ans;

        // If tree is empty, return empty result
        if (root == nullptr) {
            return ans;
        }

        // Map to store first node encountered at each vertical distance
        // Key: vertical distance, Value: node value
        map<int, int> verticalMap;

        // Queue for level-order traversal
        // Stores pair of (TreeNode pointer, vertical distance)
        queue<pair<TreeNode*, int>> q;

        // Start BFS from root with vertical distance 0
        q.push({root, 0});

        // Perform BFS traversal
        while (!q.empty()) {
            // Get front element from queue
            auto current = q.front();
            q.pop();

            // Extract node and its vertical distance
            TreeNode* node = current.first;
            int vertical = current.second;

            // If this vertical distance is seen first time, store it
            if (verticalMap.find(vertical) == verticalMap.end()) {
                verticalMap[vertical] = node->data;
            }

            // If left child exists, push with vertical - 1
            if (node->left != nullptr) {
                q.push({node->left, vertical - 1});
            }

            // If right child exists, push with vertical + 1
            if (node->right != nullptr) {
                q.push({node->right, vertical + 1});
            }
        }

        // Extract values from map in sorted order of vertical distance
        for (auto &entry : verticalMap) {
            ans.push_back(entry.second);
        }

        // Return the top view
        return ans;
    }
};
