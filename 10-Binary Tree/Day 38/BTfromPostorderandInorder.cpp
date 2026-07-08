// T.C: O(N)
// Building the unordered_map takes O(N).
// Each node is processed exactly once while constructing the tree.
// Overall: O(N).

// S.C: O(N)
// unordered_map stores N nodes.
// Recursive call stack takes O(H), where H is the height of the tree.
    // Balanced tree: O(log N)
    // Skewed tree: O(N)
    // Overall worst-case: O(N).


// Question Link: https://takeuforward.org/plus/dsa/problems/construct-a-bt-from-postorder-and-inorder?source=strivers-sde-sheet

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty() || inorder.size() != postorder.size()) {
            return nullptr;
        }

        // Create a map to store the indices of elements in the inorder traversal
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }

        // Call the recursive function to build the binary tree
        return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inorderMap);
    }

private:
    TreeNode* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd,
                              vector<int>& postorder, int postStart, int postEnd,
                              unordered_map<int, int>& inorderMap) {
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }

        // Create the root node from the last element in postorder
        int rootValue = postorder[postEnd];
        TreeNode* root = new TreeNode(rootValue);

        // Find the index of rootValue in inorder to determine the left and right subtrees
        int rootIndexInorder = inorderMap[rootValue];
        int leftSubtreeSize = rootIndexInorder - inStart;

        // Recursive calls to build left and right subtrees
        root->left = buildTreeHelper(inorder, inStart, rootIndexInorder - 1,
                                     postorder, postStart, postStart + leftSubtreeSize - 1, inorderMap);
        root->right = buildTreeHelper(inorder, rootIndexInorder + 1, inEnd,
                                      postorder, postStart + leftSubtreeSize, postEnd - 1, inorderMap);

        return root;
    }
};