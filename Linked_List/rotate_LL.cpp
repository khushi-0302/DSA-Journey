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

int length(ListNode* head){
    ListNode* temp=head;
    int len=0;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}

/*ListNode* reverse(ListNode* head){
    if (head==NULL || head->next==NULL){
        return head;
    }
    ListNode* rev=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return rev;
}*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        int n=length(head);

        if (k>0){
            k=k%n;
        }

        ListNode* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }

        tail->next=head;

        ListNode* temp=head;
        for (int i=0 ; i<(n-k)-1 ; i++){
            temp=temp->next;
        }

        head=temp->next;
        temp->next=NULL;

        return head;
    }
};

void printList(ListNode* head){
    while(head!=NULL){
        cout << head->val << " ";
        head=head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int k = 3;
    Solution obj;
    head = obj.rotateRight(head, k);
    printList(head);
    return 0;
}