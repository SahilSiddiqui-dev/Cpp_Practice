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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode* fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        int carry = 0;
        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            carry = sum/10;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int sum = l1->val + carry;
            carry = sum/10;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            l1 = l1->next;
        }
        while(l2){
            int sum = l2->val + carry;
            carry = sum/10;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            l2 = l2->next;
        }

        if(carry){
            tail->next = new ListNode(carry%10);
            carry /= 10;
            tail = tail->next;
        }
        ListNode* result = dummy->next;
        delete dummy;
        result = reverse(result);
        return result;
    }
};