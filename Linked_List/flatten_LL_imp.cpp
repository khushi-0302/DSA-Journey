#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int val) {
        data = val;
        next = nullptr;
        child = nullptr;
    }
};

Node* merge(Node* list1, Node* list2) {
    Node* dummynode = new Node(-1);
    Node* res = dummynode;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else {
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = nullptr;
    }

    if (list1) res->child = list1;
    else res->child = list2;

    return dummynode->child;
}

Node* flattenLinkedList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* mergehead = flattenLinkedList(head->next);
    head = merge(head, mergehead);

    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(4);
    head->next->next = new Node(7);
    head->child = new Node(2);
    head->child->child = new Node(3);
    head->next->child = new Node(5);
    head->next->child->child = new Node(6);
    head->next->next->child = new Node(8);
    head->next->next->child->child = new Node(9);
    Node* flat = flattenLinkedList(head);
    printList(flat);

    return 0;
}