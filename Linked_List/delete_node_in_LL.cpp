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

class Solution {
public:
    void deleteNode(ListNode* node) {
        //if(node->next!=NULL){
            //if (node->next->next!=NULL){
                node->val=node->next->val;
                node->next=node->next->next;
            //}    
        //}
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
    // Linked List: 4 -> 5 -> 1 -> 9
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Before deletion: ";
    printList(head);

    Solution obj;
    obj.deleteNode(head->next); // delete node with value 5

    cout << "After deletion: ";
    printList(head);

    return 0;
}