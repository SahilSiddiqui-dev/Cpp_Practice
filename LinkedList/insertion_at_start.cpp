#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

int main() { 
    int arr[] = {1, 3, 4, 5, 8};
    Node *head = NULL;
    Node * last;
    for(int i = 0; i < 5; i++){
        if(head == NULL){
            head = new Node(arr[i]);
        }
        else {
            Node *temp;
            temp = new Node(arr[i]);
            temp -> next = head;
            head = temp;
        }
    }
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }

}