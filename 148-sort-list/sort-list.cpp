/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        
        // 2. Attach the rest instantly in O(1) time
        curr->next = list1 ? list1 : list2;

        return dummy.next;
    }
    ListNode* getMiddle(ListNode* head){
       ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeSort(ListNode* head){
        if(!head || !head->next) return head;

        ListNode* mid = getMiddle(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;
        left = mergeSort(left);
        right  = mergeSort(right);
        return merge(left, right);
    }
    ListNode* sortList(ListNode* head) {
        if(!head) {
            return NULL;
        }
        return mergeSort(head);
        
    }
};