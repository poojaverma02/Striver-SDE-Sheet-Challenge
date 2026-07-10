// T.C: O(N)
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/populating-next-right-pointers-in-each-node?source=strivers-sde-sheet

class Solution {
public:
    // Function to connect next pointers in-place
    Node* connect(Node* root) {
        // Return if tree is empty
        if(!root) return nullptr;

        // Start from the root level
        Node* levelStart = root;

        // Traverse all levels until leaves
        while(levelStart->left) {
            Node* curr = levelStart;

            // Traverse nodes in current level using next pointers
            while(curr) {
                // Connect left child to right child
                curr->left->next = curr->right;

                // Connect right child to next node's left child if next exists
                if(curr->next) curr->right->next = curr->next->left;

                // Move to next node in level
                curr = curr->next;
            }

            // Move to next level
            levelStart = levelStart->left;
        }

        return root;
    }
};
