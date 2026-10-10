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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL && n == 1){
            delete head;
            return NULL;
        }
       ListNode* newHead = reverse(head);
       if(n == 1){
        ListNode* dlt = newHead;
        newHead = newHead->next;
        delete(dlt);
        head = reverse(newHead);
        return head;
       }

       ListNode* temp = newHead;

       n -= 1;
       while(--n){
            temp = temp->next;
       }
       ListNode* dltNode = temp->next;
       temp->next = dltNode->next;

       head = reverse(newHead);
       return head;
    }
};