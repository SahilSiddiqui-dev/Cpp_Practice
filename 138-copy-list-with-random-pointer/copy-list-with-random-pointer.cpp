/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* Copyhead = new Node(0);
        Node* tail = Copyhead;
        Node* temp = head;
        Node* front1;
        Node* front2;
        Node* curr1;
        Node* curr2;
        while(temp){
            tail->next = new Node(temp->val);
            temp = temp->next;
            tail = tail->next;
        }
    
        Node* toDelete = Copyhead;
        Copyhead = Copyhead->next;
        delete toDelete;
        curr1 = head;
        curr2 = Copyhead;
        while(curr1){
            front1 = curr1->next;
            front2 = curr2->next;
            curr1->next = curr2;
            curr2->next = front1;
            curr1 = front1;
            curr2 = front2;
        }

        temp = head;

        while(temp){ 
            tail = temp->next;
            Node* find = temp->random;
            if(find){
                tail->random = find->next;
            }
            temp = tail->next;
        }

        curr1 = head;
        curr2 = Copyhead;
        while(curr1){
        curr1->next = curr1->next->next;
        curr2->next = curr2->next ? curr2->next->next : nullptr;

        curr1 = curr1->next;
        curr2 = curr2->next;
        
        }
        return Copyhead;
    }
};