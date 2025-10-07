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




class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp2 = dummy;
        ListNode* temp = head;

        while(temp){
            temp2->next = temp->next;
            temp ->next = temp->next->next;

            temp = temp->next;
            temp2 = temp2->next;
        }

        temp = head;

        while(temp->next != nullptr){
            temp = temp->next;
        }

        temp->next = dummy->next;
        dummy ->next = nullptr;
        return head;
    }
};


class Solution2 {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp2 = dummy;
        ListNode* temp = head;

        while(temp->next != nullptr && temp != nullptr){    // ye kre se...pehle temp->next check krna hai fir temp!=nullptr, but if temp == nullptr then temp->next will give error, isliye pehle temp!=nullptr check krna hai
            temp2->next = temp->next;
            temp ->next = temp->next->next;

            temp = temp->next;
            temp2 = temp2->next;
        }

        temp2->next = nullptr; // to avoid cycle in linked list
        temp = head;

        while(temp->next != nullptr){
            temp = temp->next;
        }

        temp->next = dummy ->next ;
        dummy ->next = nullptr;
        return head;

        
    }
};

// TRUE CORRECT CODE
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next == nullptr || head->next->next == nullptr){
            return head;
        }

        
        ListNode* dummy = new ListNode(0);
        ListNode* temp2 = dummy;
        ListNode* temp = head;

        while(temp != nullptr && temp->next != nullptr){
            temp2->next = temp->next;
            temp ->next = temp->next->next;

            temp = temp->next;
            temp2 = temp2->next;
        }
        
        
        temp2->next = nullptr; // to avoid cycle in linked list
        temp = head;

        while(temp->next != nullptr){
            temp = temp->next;
        }

        temp->next = dummy ->next ;
        dummy ->next = nullptr;
        return head;


    }
};


int main(){
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);
    head->next = second;
    second->next = third;
    third-> next = fourth;
    fourth->next = fifth;
    fifth->next = nullptr;  
    

    Solution sol;
    ListNode* head = sol.oddEvenList(  head);// Deleting 4th element from end

    ListNode* temp = head;
    while(temp != nullptr){ 
        cout<< temp->val << " ";
        temp = temp->next;
    }
    

}