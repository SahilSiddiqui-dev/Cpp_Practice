#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};

class Solution {
public:
    vector<Node*> arr;

    Node* merge(Node* head1, Node* head2) {
        Node* dummy = new Node(0);
        Node* tail = dummy;

        while (head1 && head2) {
            if (head1->data <= head2->data) {
                tail->bottom = head1;
                head1 = head1->bottom;
            } else {
                tail->bottom = head2;
                head2 = head2->bottom;
            }
            tail = tail->bottom;
            tail->bottom = nullptr;
        }

        if (head1) {
            tail->bottom = head1;
        } else {
            tail->bottom = head2;
        }

        Node* mergedHead = dummy->bottom;
        delete dummy;
        return mergedHead;
    }

    void mergeSort(vector<Node*>& arr, int start, int end) {
        if (start >= end) {
            return;
        }

        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        arr[start] = merge(arr[start], arr[mid + 1]);
    }

    Node* flatten(Node* head) {
        arr.clear();
        Node* temp = head;

        while (temp) {
            arr.push_back(temp);
            temp = temp->next;
        }

        if (arr.empty()) {
            return nullptr;
        }

        mergeSort(arr, 0, arr.size() - 1);
        return arr[0];
    }
};