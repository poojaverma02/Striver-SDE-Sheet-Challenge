// T.C: O(N) 
// S.C: O(h) 
    // Best case (balanced tree): O(log N)
    // Worst case (skewed tree): O(N)
// Question Link: https://takeuforward.org/plus/dsa/problems/check-if-two-trees-are-identical-or-not?source=strivers-sde-sheet


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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (p == NULL || q == NULL)
            return (p==q);

        // If the values of the current nodes are different,
        // the trees are not the same.
        if (p->data != q->data)
            return false;

        // Recursively compare the left and right subtrees.
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};