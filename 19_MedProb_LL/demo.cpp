#include <iostream>
using namespace std;

class ListNode{
  public:
    int val;
    ListNode* next;

    ListNode(int v , ListNode* n = nullptr){
        val = v;
        next = n;
    }

    ListNode(){
        val = 0;
        next = nullptr;
    }

    ListNode(int v){
        val = v;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head){
        if(head== nullptr || head->next == nullptr){
            return head;
        }
        ListNode* newhead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;

        return newhead;
    }

    void reorderList(ListNode* head) {

        if(head == nullptr || head->next == nullptr){
            return ;
        } 

        // divide the linked list into two halves
        // slow->next pointer se 2nd half ka head milega
         
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head2 = slow->next;
        slow->next = nullptr;

        // reverse the 2nd half
        head2 = reverseList(head2);

        // merge the two halves
        ListNode* curr1 = head;
        ListNode* curr2 = head2;

        while(curr2){
            ListNode* x = curr1->next;
            ListNode* y = curr2->next;

            curr1->next = curr2;
            curr1->next->next = x;

            curr1 = x;
            curr2 = y;
        
        }
    }

};