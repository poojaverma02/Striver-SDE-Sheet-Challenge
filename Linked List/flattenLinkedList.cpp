// T.C: O(M × N²)
// S.C: O(N)
// Question Link: https://takeuforward.org/plus/dsa/problems/flattening-of-ll?source=strivers-sde-sheet

/*
Definition of special linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next1;
    }
};
*/

class Solution {
   private:
    /* Merge the two linked lists in a particular
     order based on the data value */
    ListNode* merge(ListNode* list1, ListNode* list2) {
        /* Create a dummy node as a
        placeholder for the result */
        ListNode* dummyNode = new ListNode(-1);
        ListNode* res = dummyNode;

        // Merge the lists based on data values
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                res->child = list1;
                res = list1;
                list1 = list1->child;
            } else {
                res->child = list2;
                res = list2;
                list2 = list2->child;
            }
            res->next = NULL;
        }

        // Connect the remaining elements if any
        if (list1) {
            res->child = list1;
        } else {
            res->child = list2;
        }

        // Break the last node's link to prevent cycles
        if (dummyNode->child) {
            dummyNode->child->next = NULL;
        }

        return dummyNode->child;
    }

   public:
    // Function to flatten a linked list with child pointers
    ListNode* flattenLinkedList(ListNode* head) {
        // If head is null or there is no next node
        if (head == NULL || head->next == NULL) {
            return head;  // Return head
        }

        // Recursively flatten the rest of the linked list
        ListNode* mergedHead = flattenLinkedList(head->next);

        // Merge the lists
        head = merge(head, mergedHead);
        return head;
    }
};


