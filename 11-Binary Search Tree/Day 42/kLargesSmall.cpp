// T.C: O(N)
// S.C: O(H)
// Question Link: https://takeuforward.org/plus/dsa/problems/kth-smallest-and-largest-element-in-bst?source=strivers-sde-sheet


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
    // Function to find the kth smallest element
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        this->result = -1;
        inorder(root);
        return result;
    }

    // Function to find the kth largest element
    int kthLargest(TreeNode* root, int k) {
        this->k = k;
        this->result = -1;
        reverse_inorder(root);
        return result;
    }

    // Function to return kth smallest and kth largest elements
    vector<int> kLargesSmall(TreeNode* root, int k) {
        return {kthSmallest(root, k), kthLargest(root, k)};
    }

private:
    int k;
    int result;

    // Helper function for inorder traversal
    void inorder(TreeNode* node) {
        if (node != nullptr) {
            inorder(node->left);
            if (--k == 0) {
                result = node->data;
                return;
            }
            inorder(node->right);
        }
    }

    // Helper function for reverse inorder traversal
    void reverse_inorder(TreeNode* node) {
        if (node != nullptr) {
            reverse_inorder(node->right);
            if (--k == 0) {
                result = node->data;
                return;
            }
            reverse_inorder(node->left);
        }
    }
};
