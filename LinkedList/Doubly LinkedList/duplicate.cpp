#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};
Node* creation(int arr[], int index, int size, Node* prev){
    if(index == size){
        return NULL;
    }
    Node* temp = new Node(arr[index]);
    temp->prev = prev;
    temp->next = creation(arr, index + 1, size, temp);
    return temp;
}
Node* duplicate(Node* head){
    Node* slow = head;
    while(slow){
        Node* fast = slow->next;
        while(fast){
            if(slow->data == fast->data){
                if(fast->next == NULL){
                    Node* last = fast->prev;
                    delete fast;
                    last->next = NULL;
                    fast = NULL;
                }
                else {
                    Node* last = fast->prev;
                    Node* curr = fast;
                    fast = fast->next;
                    last->next = fast;
                    fast->prev = last;
                    delete curr;
                }
            }
            else {
                fast = fast->next;
            }
        }
            slow = slow->next;
    }
    return head;
}
int main(){
    int arr[] = {1, 2, 2, 2,2,3, 4, 7, 7, 8, 9, 9};
    Node* head = creation(arr, 0, 12, NULL);
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp -> next;
    }
    cout << endl;
    head = duplicate(head);
    temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp -> next;
    }
}