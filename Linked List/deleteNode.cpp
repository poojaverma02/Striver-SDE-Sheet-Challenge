// T.C: O(1) 
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/delete-node-in-a-linked-list-o1?source=strivers-sde-sheet

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy value from next node
        node->val = node->next->val;
        // Skip the next node
        node->next = node->next->next;
    }
};
