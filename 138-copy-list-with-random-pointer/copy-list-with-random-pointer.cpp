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
    unordered_map<Node*, Node*>find;
    Node* copyRandomList(Node* head) {
        Node* Copyhead = new Node(0);
        Node* tail = Copyhead;
        Node* temp = head;
        while(temp){
            tail->next = new Node(temp->val);
            find[temp] = tail->next;
            temp = temp->next;
            tail = tail->next;
        }
    
        Node* toDelete = Copyhead;
        Copyhead = Copyhead->next;
        delete toDelete;
        tail = Copyhead;
        temp = head;

        while(temp){
            Node* search = temp->random;
            if(search == NULL){
                tail->random = NULL;
            }
            tail->random = find[search];
            temp = temp->next;
            tail = tail->next;
        }
        return Copyhead;
    }
};