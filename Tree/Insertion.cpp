#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};
 
Node* createTree(){
    int x;
    cin >> x;
    if(x == -1) {
        return NULL;
    }
    Node* temp = new Node(x);
    cout << "Enter the left child of " << x << " : ";
    temp->left = createTree();
    cout << "Enter the right child of " << x << " : ";
    temp->right = createTree();

    return temp;
}

int main() {
    cout << "Enter the root Node : ";
    Node* root = createTree();
    // int first, second;
    // Node* root = new Node(x);
    // queue<Node*>q;
    // q.push(root);

    // while(!q.empty()) {
    //     Node* temp = q.front();
    //     q.pop();
    //     cout << "Enter the left child of " << temp->data << " : ";
    //     cin >>first;
        
    //     if(first != -1){
    //         temp->left = new Node(first);
    //         q.push(temp->left);
    //     }
    //     cout << "Enter the right child of " << temp->data << " : ";
    //     cin >> second;
    //     if(second != -1) {
    //         temp -> right = new Node(second);
    //         q.push(temp->right);
    //     }
    // }

    return 0;
}