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
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while(temp1 && temp2){
            if(temp1->val > temp2->val){
                curr->next =  temp2;
                curr = curr->next;
                temp2 = temp2-> next;
            }
            else {
                curr->next = temp1;
                curr = curr->next;
                temp1 = temp1->next;
            }
        }
        while(temp1){
            curr->next = temp1;
            curr = curr->next;
            temp1 = temp1->next;
        }
        while(temp2){
            curr->next =  temp2;
            curr = curr->next;
            temp2 = temp2-> next;
        }
        ListNode* toDlt = head;
        head = head->next;
        delete toDlt;
        return head;
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