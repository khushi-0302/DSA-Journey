#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

int length(ListNode* head) {
    int len = 0;
    ListNode* temp = head;

    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

ListNode* reverse(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* chhotahead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return chhotahead;
}

bool isPalindrome(ListNode* head) {
    int len = length(head);
    ListNode* mid = head;

    for (int i = 0; i < len / 2; i++) {
        mid = mid->next;
    }

    if (len % 2 != 0) {
        mid = mid->next;
    }

    ListNode* newhead = reverse(mid);
    ListNode* temp = head;

    while (newhead != NULL) {
        if (temp->val != newhead->val) {
            return false;
        }
        temp = temp->next;
        newhead = newhead->next;
    }

    return true;
}

int main() {
    // Example: 1 -> 2 -> 3 -> 2 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    if (isPalindrome(head)) {
        cout << "Yess Palindrome" << endl;
    } else {
        cout << "Not Palindrome " << endl;
    }

    return 0;
}