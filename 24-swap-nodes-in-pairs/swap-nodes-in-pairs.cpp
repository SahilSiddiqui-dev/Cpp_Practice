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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return NULL;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = head;
        int cnt = 0;
        while(second){
            second = second ->next;
            cnt++;
        }
        cnt /= 2;
        second = head;
        while(cnt--){
            second  = first->next;
            ListNode* prev = first;
            ListNode* curr = second;
            int x = 2;
            while(x-- && curr){
                ListNode* fut = curr->next;
                curr->next = prev;
                prev = curr;
                curr = fut;
            }
            first -> next = prev;
            second->next = curr;
            first = second;
        }
        return dummy->next;
    }
};