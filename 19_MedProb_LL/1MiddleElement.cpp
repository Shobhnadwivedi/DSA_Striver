#include <iostream>
#include<cmath>
using namespace std;

class ListNode {
  public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// T.C = O(N + N/2 ) 
// S.C = O(1) 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head== nullptr){
            return nullptr;
        }
        if(head->next == nullptr){
            return head;
        }
        ListNode* temp = head;
        int cnt =0;
        while(temp){
            cnt++;
            temp = temp->next;
        }

        int mid = cnt/2 +1 ;

        int cnt2 = 1;
        ListNode* temp2 = head;
        while(cnt2< mid){
            temp2 = temp2->next;
            cnt2++;
        }

        return temp2;
    }
};


// Tortoise/Hare    or   Slow /Fast  approach

// Optimal approach  =  T.C = O(N) , S.C = O(1)
class Solution2 {   
  public:
    ListNode* middleNode(ListNode* head) {
        if(head== nullptr){
            return nullptr;
        }
        if(head->next == nullptr){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!= nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

};


int main(){
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);
    ListNode* sixth = new ListNode(6);



    head->next = second;
    second->next = third;
    third-> next = fourth;
    fourth-> next = fifth;  
    fifth-> next = sixth;
    sixth-> next = nullptr;

    Solution2 sol;
    ListNode* ans = sol.middleNode(head);
    cout<< ans->val << endl;

}