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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummynode = new ListNode(-1);
        ListNode* res = dummynode;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                res->next = list1;
                res = list1;
                list1 = list1->next;
            }
            else {
                res->next = list2;
                res = list2;
                list2 = list2->next;
            }
        }

        if (list1) res->next = list1;
        else res->next = list2;

        return dummynode->next;
    }
};

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);
    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);
    Solution obj;
    ListNode* merged = obj.mergeTwoLists(list1, list2);
    printList(merged);

    return 0;
}