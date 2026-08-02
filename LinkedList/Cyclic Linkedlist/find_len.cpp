#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};
Node* creation(int arr[], int n){
    int i = 0;
    Node* head = new Node(arr[i]);
    Node* curr = head;

    for(int i = 0; i < n; i++){
        Node* temp = new Node(arr[i]);
        curr->next = temp;
        curr = curr->next;
    }

    curr->next = head;
    
   return head;
}