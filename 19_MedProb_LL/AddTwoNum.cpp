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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        int carry =0;
        while(l1 && l2){
            temp->next = new ListNode ( (l1->val + l2->val + carry)% 10);
            carry = (l1->val + l2->val + carry)/10;
            temp = temp->next;
            l1 = l1->next;  
            l2 = l2->next;
        }

        if(l1){
            while(l1){
                temp->next = new ListNode ( (l1->val + carry)% 10);
                carry = (l1->val + carry)/10;
                temp = temp->next;
                l1 = l1->next;
            }
        }

        if(l2){
            while(l2){
                temp->next = new ListNode ( (l2->val + carry)% 10);
                carry = (l2->val + carry)/10;
                temp = temp->next;
                l2 = l2->next;
            }
        }

        if(carry != 0){
            temp->next = new ListNode(carry);
        }

        return dummy->next;
    }
};

class Solution{
  public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        int carry =0;
        while(l1!=nullptr || l2!=nullptr){
            int sum= carry;

            if(l1){ 
                sum = sum + l1->val; 
                l1 = l1->next;
            }
            if(l2){
                sum= sum+ l2->val;
                l2 = l2->next;
            }

            temp->next = new ListNode(sum% 10);
            carry = sum/10;

            temp = temp->next;
        }

        if(carry != 0){
            temp->next = new ListNode(carry);
        }

        return dummy->next;
    }
};


int main(){
    ListNode* head1 = new ListNode(2);
    ListNode* second = new ListNode(4);
    ListNode* third = new ListNode(3);

    head1->next = second;
    second->next = third;
    third-> next = nullptr;

    ListNode* head2 = new ListNode(5);
    ListNode* second2 = new ListNode(6);
    ListNode* third2 = new ListNode(4);

    head2->next = second2;
    second2->next = third2;
    third2-> next = nullptr;
    

    Solution sol;
    ListNode* head = sol.addTwoNumbers(  head1 , head2); // Deleting 4th element from end

    ListNode* temp = head;
    while(temp != nullptr){ 
        cout<< temp->val << " ";
        temp = temp->next;
    }
    

}