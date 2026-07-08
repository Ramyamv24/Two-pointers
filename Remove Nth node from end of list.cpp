#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* d = new ListNode(0);
        d->next = head;

        ListNode* f = d;
        ListNode* s = d;

        // Move fast pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            f = f->next;
        }

        while (f) {
            f = f->next;
            s = s->next;
        }

        ListNode* t = s->next;
        s->next = s->next->next;
        delete t;

        head = d->next;
        delete d;

        return head;
    }
};

int main() {
    int n, x, k;

    cout << "Enter number of nodes: ";
    cin >> n;

    ListNode *head = nullptr, *tail = nullptr;

    cout << "Enter the node values: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        ListNode *newNode = new ListNode(x);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Enter n: ";
    cin >> k;

    Solution obj;
    head = obj.removeNthFromEnd(head, k);

    cout << "Linked List after deletion: ";
    ListNode *temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;

    return 0;
}