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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* third = head;
        while(--left){
            first = first->next;
        }
        while(right--){
            third = third->next;
        }
        ListNode* curr = first->next;
        ListNode* prev = first;
        ListNode* second = first->next;
        while(curr != third){
            ListNode* fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }
        first->next = prev;
        second->next = third;
        return dummy->next;
    }
};