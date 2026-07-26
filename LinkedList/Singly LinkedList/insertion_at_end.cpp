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
int main(){
    Node *head = NULL;
    Node *tail = NULL;
    int arr[] = {1, 3, 4, 5, 6};
    for(int i = 0; i < 5; i++){
        if(head == NULL){
            head = new Node(arr[i]);
            tail = head;
        }
        else {
            // its time complexity is not good
            // while(tail->next != NULL){
            //     tail = tail->next;
            // }
            tail->next = new Node(arr[i]);
            tail = tail->next;

        }
    }
    Node * temp = head;
    while(temp != NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}