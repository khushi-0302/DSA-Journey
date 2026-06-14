#include <iostream>
using namespace std;

// Definition of ListNode
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

int findlen(ListNode* head) {
    int len = 0;
    while (head != NULL) {
        head = head->next;
        len++;
    }
    return len;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = findlen(head);

        if (len == 1 || len == 0) {
            return NULL;
        }

        if (len == 2) {
            if (n == 2) {
                head = head->next;
                head->next = NULL;
            } else {
                head->next = NULL;
            }
            return head;
        }

        int N = len - n + 1;
        int i = 1;
        ListNode* temp = head;

        if (N == 1) {
            head = head->next;
            return head;
        }

        while (i < N - 1) {
            temp = temp->next;
            i++;
        }

        temp->next = temp->next->next;
        return head;
    }
};

// Print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int n;
    cout << "Enter n: ";
    cin >> n;
    Solution obj;
    head = obj.removeNthFromEnd(head, n);
    printList(head);
    return 0;
}