#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(0);
    ListNode* current = &dummy;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // Attach any remaining nodes from either list
    current->next = list1 ? list1 : list2;

    return dummy.next;
}
int main(){
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};
    // Helper lambdas to create, print and free linked lists
    auto createList = [](const vector<int>& vals) -> ListNode* {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        for (int v : vals) {
            ListNode* node = new ListNode(v);
            if (!head) head = tail = node;
            else { tail->next = node; tail = node; }
        }
        return head;
    };

    auto printList = [](ListNode* head) {
        ListNode* cur = head;
        while (cur) {
            cout << cur->val;
            if (cur->next) cout << " -> ";
            cur = cur->next;
        }
        cout << '\n';
    };

    auto freeList = [](ListNode* head) {
        while (head) {
            ListNode* nxt = head->next;
            delete head;
            head = nxt;
        }
    };

    vector<int> v1(begin(arr1), end(arr1));
    vector<int> v2(begin(arr2), end(arr2));

    ListNode* l1 = createList(v1);
    ListNode* l2 = createList(v2);

    cout << "List 1: "; printList(l1);
    cout << "List 2: "; printList(l2);

    ListNode* merged = mergeTwoLists(l1, l2);
    cout << "Merged: "; printList(merged);

    // merged now owns all nodes; just free merged
    freeList(merged);

    return 0;
}