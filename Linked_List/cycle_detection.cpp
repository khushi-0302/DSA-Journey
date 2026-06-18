#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                ListNode* actual = slow;

                while (temp != actual) {
                    temp = temp->next;
                    actual = actual->next;
                }
                return temp;
            }
        }
        return NULL;
    }
};

int main() {
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;   

    Solution obj;
    ListNode* result = obj.detectCycle(head);

    if (result != NULL) {
        cout << "Cycle starts at node value: " << result->val << endl;
    } else {
        cout << "No cycle" << endl;
    }

    return 0;
}