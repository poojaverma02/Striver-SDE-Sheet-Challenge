// T.C: Constructor: O(H)
      // next(): O(1) amortized
      // hasNext(): O(1)
// S.C: O(H)
// Question Link: https://takeuforward.org/plus/dsa/problems/bst-iterator?source=strivers-sde-sheet


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class BSTIterator {
    stack<TreeNode*> myStack;

public:
    // Constructor initializes the iterator on the root of the BST
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    // Returns true if there is a next element in the iterator
    bool hasNext() {
        return !myStack.empty();
    }
    
    // Returns the next smallest element in the BST
    int next() {
        TreeNode* temp = myStack.top();
        myStack.pop();
        pushAll(temp->right);
        return temp->data;
    }

private:
    // Helper function to push all the left nodes onto the stack
    void pushAll(TreeNode* node) {
        for (; node != NULL; myStack.push(node), node = node->left);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */