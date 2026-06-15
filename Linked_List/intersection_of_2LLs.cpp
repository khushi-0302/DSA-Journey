#include <iostream>
#include <cstdlib>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

int length(ListNode *head) {
    int len = 0;
    ListNode *temp = head;

    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len = length(headA);
        int len2 = length(headB);

        ListNode *temp = headA;
        ListNode *temp2 = headB;

        if (len > len2) {
            int diff = abs(len - len2);
            while (diff > 0) {
                temp = temp->next;
                diff--;
            }
        } else {
            int diff = abs(len2 - len);
            while (diff > 0) {
                temp2 = temp2->next;
                diff--;
            }
        }

        while (temp != temp2) {
            temp = temp->next;
            temp2 = temp2->next;
        }

        return temp;
    }
};

int main() {
    // Common part (intersection)
    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    // List A: 4 -> 1 -> 8 -> 4 -> 5
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    // List B: 5 -> 6 -> 1 -> 8 -> 4 -> 5
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    Solution obj;
    ListNode* ans = obj.getIntersectionNode(headA, headB);

    if (ans != NULL) {
        cout << "Intersection at node value: " << ans->val << endl;
    } else {
        cout << "No intersection" << endl;
    }

    return 0;
}