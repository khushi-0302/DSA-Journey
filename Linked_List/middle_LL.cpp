#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

/*int findlen(ListNode* head){
    int len=0;
    while(head!=NULL){
        head = head -> next;
        len++;
    }
    return len;
}*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL) {
            fast = fast->next;

            if (fast != NULL) {
                fast = fast->next;
            }

            slow = slow->next;
        }

        return slow;

        /*int len=findlen(head);
        int mid=len/2;
        int cnt=0;
        ListNode* temp=head;
        while(cnt<mid){
            temp=temp->next;
            cnt++;
        }
        return temp;*/
    }
};

int main() {

    // Example: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;
    ListNode* mid = obj.middleNode(head);

    cout << "Middle Node: " << mid->val << endl;

    return 0;
}