// T.C: O(N)
// S.C: O(H)
// Question Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    // Main function to convert a sorted array into a balanced BST
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        // If the array is empty, no tree can be formed
        if (nums.empty())
            return nullptr;

        // Build BST using the entire array
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }

    // Recursive helper function to build BST from nums[beg...end]
    TreeNode* sortedArrayToBST(vector<int>& nums, int beg, int end) {

        // Base case: invalid range
        if (beg > end)
            return nullptr;

        // Find the middle element
        int mid = (beg + end) / 2;

        // Create the root node with the middle element
        TreeNode* root = new TreeNode(nums[mid]);

        // Recursively construct the left subtree
        root->left = sortedArrayToBST(nums, beg, mid - 1);

        // Recursively construct the right subtree
        root->right = sortedArrayToBST(nums, mid + 1, end);

        // Return the root of the constructed subtree
        return root;
    }
};