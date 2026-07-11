// T.C: O(H)
// S.C: O(H)
// Question Link: https://takeuforward.org/plus/dsa/problems/lca-in-bst?source=strivers-sde-sheet

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{	
public:
    
    // Function to get the LCA in Binary Search Tree
	TreeNode* lca(TreeNode* root, int p, int q){
	    // base case
        if(root == nullptr) return nullptr;

        // Store the current node data
        int curr = root->data; 
        
        // If both nodes are smaller than root
        if(curr < p && curr < q)
            // LCA lies in the right subtree
            return lca(root-> right, p, q);
        
        // If both nodes are larger than root 
        if(curr > p && curr > q)
            // LCA lies in the left subtree
            return lca(root-> left, p, q);

        // Else root is the LCA 
        return root;
	}
};
