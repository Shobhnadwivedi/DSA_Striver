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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr){ return list2; }
        if(list2 == nullptr){ return list1; }

        ListNode* newhead = new ListNode(0);

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        

        if(temp1->val <= temp2->val){
            newhead->val = temp1->val;
            temp1 = temp1->next;
        }
        else{
            newhead->val = temp2->val;
            temp2 = temp2->next;
        }

        ListNode* newtemp = newhead;

        while (temp1 != nullptr  && temp2 != nullptr){
            if(temp1->val <= temp2->val){
                newtemp -> next = temp1;
                temp1 = temp1->next;
            }
            else{
                newtemp -> next = temp2;
                temp2 = temp2 ->next;
            }
            newtemp = newtemp -> next;
        }

        if(temp1 == nullptr){
            newtemp->next = temp2;
        }
        if(temp2 == nullptr){
            newtemp->next = temp1;
        }

        return newhead;
    }
};


int main(){
    ListNode* head1 = new ListNode(1);
    ListNode* second = new ListNode(3);
    ListNode* third = new ListNode(4);

    head1->next = second;
    second->next = third;
    third-> next = nullptr;

    ListNode* head2 = new ListNode(1);
    ListNode* second2 = new ListNode(2);
    ListNode* third2 = new ListNode(4);

    head2->next = second2;
    second2->next = third2;
    third2-> next = nullptr;
    

    Solution sol;
    ListNode* head = sol.mergeTwoLists(  head1 , head2); // Deleting 4th element from end

    ListNode* temp = head;
    while(temp != nullptr){ 
        cout<< temp->val << " ";
        temp = temp->next;
    }
    

}