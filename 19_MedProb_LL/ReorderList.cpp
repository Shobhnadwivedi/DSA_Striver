#include <iostream>
using namespace std;

class ListNode {
  public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution1 {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow-> next != nullptr && slow->next->next != nullptr){
            while( fast->next != nullptr){
                fast = fast->next;
            }
            ListNode* temp2 = fast;
            ListNode* temp = slow->next;
            slow->next = fast;
            fast -> next = temp;
            temp2 = nullptr;
            
            slow = slow->next->next;
            fast = slow;
        }


    }
};


ListNode* reverseList(ListNode* head){
    if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* newhead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;

        return newhead;
}


class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        //  Find the middle of the linked list
        while(fast!= nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is now at the middle point

        ListNode* head2= reverseList(slow->next);
        slow->next = nullptr;

        ListNode* temp = head ; 
        ListNode* temp2 = head2;

        while(temp != nullptr && temp2 != nullptr){
            ListNode* a = temp->next;
            ListNode* b = temp2->next;

            temp->next = temp2;
            temp2->next = a;

            temp = a;
            temp2 = b;
        }


    }
};




int main(){
    ListNode* head1 = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);


    head1->next = second;
    second->next = third;
    third-> next = fourth;
    fourth->next = fifth;
    fifth->next = nullptr;

    Solution obj;
    obj.reorderList(head1);

    ListNode* temp = head1;
    while(temp != nullptr){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    

    
    

}