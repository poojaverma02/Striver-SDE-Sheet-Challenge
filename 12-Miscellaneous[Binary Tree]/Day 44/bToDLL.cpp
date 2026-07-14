// T.C: O(N)
// S.C: O(H)
      // Balanced BST: O(log N)
      // Skewed BST: O(N)
// Question Link: https://takeuforward.org/plus/dsa/problems/binary-tree-to-doubly-linked-list?source=strivers-sde-sheet


class Solution {
private:
    // Pointer to track previous node during in-order traversal
    TreeNode* prev = nullptr;
    // Pointer to store head of DLL
    TreeNode* head = nullptr;

    // Helper function for in-order traversal
    void inorder(TreeNode* node) {
        // Return if node is nullptr
        if (!node) return;
        // Traverse left subtree
        inorder(node->left);
        // If prev is nullptr, current node is head
        if (!prev) {
            head = node;
        } else {
            // Link previous node with current node
            prev->right = node;
            node->left = prev;
        }
        // Update previous node
        prev = node;
        // Traverse right subtree
        inorder(node->right);
    }

public:
    // Function to convert Binary Tree to DLL
    TreeNode* bToDLL(TreeNode* root) {
        // Initialize pointers
        prev = nullptr;
        head = nullptr;
        // Start in-order traversal
        inorder(root);
        // Return head of DLL
        return head;
    }
};