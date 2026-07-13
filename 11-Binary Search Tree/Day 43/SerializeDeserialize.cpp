// T.C: O(N)
// S.C: O(N)
// Question Link: https://takeuforward.org/plus/dsa/problems/serialize-and-de-serialize-bt?source=strivers-sde-sheet
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
    // Encodes the tree into a single string
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }

        // Initialize an empty string
        // to store the serialized data
        stringstream ss;
        // Use a queue for level-order traversal
        queue<TreeNode*> q;
        // Start with the root node
        q.push(root);

        // Perform level-order traversal
        while (!q.empty()) {
            // Get the front node in the queue
            TreeNode* curNode = q.front();
            q.pop();

            // Check if the current node is null and append "#" to the string
            if (curNode == nullptr) {
                ss << "#,";
            } else {
                // Append the value of the current node to the string
                ss << curNode->data << ",";
                // Push the left and right children to the queue for further traversal
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }

        // Return the serialized string
        return ss.str();
    }

    // Decode the encoded data to a tree
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }

        // Use a stringstream to tokenize the serialized data
        stringstream s(data);
        string str;
        getline(s, str, ',');
        // Read the root value from the serialized data
        TreeNode* root = new TreeNode(stoi(str));

        // Use a queue for level-order traversal
        queue<TreeNode*> q;
        // Start with the root node
        q.push(root);

        // Perform level-order traversal to reconstruct the tree
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Read the value of the left child from the serialized data
            getline(s, str, ',');
            if (str != "#") {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            // Read the value of the right child from the serialized data
            getline(s, str, ',');
            if (str != "#") {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        // Return the reconstructed root of the tree
        return root;
    }

  
};


