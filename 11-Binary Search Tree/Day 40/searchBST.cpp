// T.C: O(H), where H is the height of the BST.
    // Best Case: O(1) (target is the root)
    // Balanced BST: O(log N)
    // Skewed BST: O(N)
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/search-in-bst?source=strivers-sde-sheet


/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {	
public:	
    TreeNode* searchBST(TreeNode* root, int val) {
        // Traverse the tree until we find the node 
        // with the given value or reach the end
        while (root != nullptr && root->data != val) {
            // Move to the left or right child 
           // depending on the value comparison
            root = (root->data > val) ? root->left : root->right;
        }
        // Return the found node or nullptr if not found
        return root; 
    }
};