// T.C: O(N1 + N2)  
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/merge-sorted-lists-?source=strivers-sde-sheet

// Definition of singly linked list:
// struct ListNode
// {
//     int val;
//     ListNode *next;
//
//     // Constructor for node with value only
//     ListNode(int data1)
//     {
//         val = data1;
//         next = NULL;
//     }
//
//     // Constructor for node with value and next pointer
//     ListNode(int data1, ListNode *next1)
//     {
//         val = data1;
//         next = next1;
//     }
// };

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to simplify handling of the head
        ListNode* dummyNode = new ListNode(-1);

        // Temporary pointer used to build the merged list
        ListNode* temp = dummyNode;

        // Traverse both lists until one becomes empty
        while (list1 != NULL && list2 != NULL) {
            // If current node of list1 is smaller (or equal),
            // attach it to the merged list
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;  // Move list1 forward
            } else {
                // Otherwise attach current node of list2
                temp->next = list2;
                list2 = list2->next;  // Move list2 forward
            }

            // Move temp to the last node of the merged list
            temp = temp->next;
        }

        // Attach the remaining nodes from the non-empty list
        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        // Return the head of the merged list
        // (skip the dummy node)
        return dummyNode->next;
    }
};