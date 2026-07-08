// T.C: O(N) 
// S.C: O(h) 
    // Best case (balanced tree): O(log N)
    // Worst case (skewed tree): O(N)
// Question Link: https://takeuforward.org/plus/dsa/problems/maximum-path-sum-?source=strivers-sde-sheet

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
private:
    // Recursive function to calculate the maximum path sum.
    // 'maxi' stores the overall maximum path sum found so far.
    int findMaxPathSum(TreeNode* root, int& maxi) {

        // Base case: if the node is NULL, contribute 0.
        if (root == NULL)
            return 0;

        // Recursively calculate the maximum path sum from the left subtree.
        // Ignore negative sums by taking max with 0, since they would reduce the total.
        int leftMaxPath = max(0, findMaxPathSum(root->left, maxi));

        // Recursively calculate the maximum path sum from the right subtree.
        // Ignore negative sums as well.
        int rightMaxPath = max(0, findMaxPathSum(root->right, maxi));

        // Calculate the maximum path passing through the current node.
        // This path can include both left and right children.
        maxi = max(maxi, leftMaxPath + rightMaxPath + root->data);

        // Return the maximum sum of a path that can be extended to the parent.
        // We can only choose one side (left or right), not both.
        return max(leftMaxPath, rightMaxPath) + root->data;
    }

public:
    int maxPathSum(TreeNode* root) {

        // Initialize the answer with the smallest possible integer.
        int maxi = INT_MIN;

        // Start DFS traversal to compute the maximum path sum.
        findMaxPathSum(root, maxi);

        // Return the overall maximum path sum.
        return maxi;
    }
};