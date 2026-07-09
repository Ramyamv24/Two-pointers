#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* first = head;
        ListNode* second = head;

        while (second && second->next) {
            first = first->next;
            second = second->next->next;

            if (first == second) {
                first = head;

                while (first != second) {
                    first = first->next;
                    second = second->next;
                }

                return first;
            }
        }

        return nullptr;
    }
};

int main() {
    // Creating linked list: 3 -> 2 -> 0 -> -4
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    head->next = second;
    second->next = third;
    third->next = fourth;

    // Creating cycle: -4 -> 2
    fourth->next = second;

    Solution obj;
    ListNode* cycleStart = obj.detectCycle(head);

    if (cycleStart != nullptr)
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    else
        cout << "No cycle found." << endl;

    return 0;
}