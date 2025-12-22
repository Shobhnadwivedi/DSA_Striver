#include<iostream>
using namespace std;

class ListNode{
  public:
    int data;
    ListNode* next;

    ListNode(): data(0), next(nullptr){}
    ListNode(int d): data(d), next(nullptr){}
    ListNode(int d, ListNode* n): data(d), next(n){}

};



class Solution{
  public: 
    
    ListNode* reverselist(ListNode* head){

        if(head==nullptr ||  head->next == nullptr){
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr){

            //   1.   curr->next stored in forw , so after reversing of this portion , curr can be updated to curr->next. 
            ListNode* forw = curr->next;

            //   2. aage ka pointer(curr->next) ko peeche link krna ....to the prev node
            curr->next = prev;

            //   3. prev and curr ko aage badhana
            prev = curr;
            curr = forw;
        }
        return prev;
    }
};



int main(){
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);

    head->next = second;
    second->next = third;
    third-> next = nullptr;

    

    Solution sol;
    head = sol.reverselist( head ); 

    ListNode* temp = head;
    while(temp != nullptr){ 
        cout<< temp->data << " ";
        temp = temp->next;
    }
    

}