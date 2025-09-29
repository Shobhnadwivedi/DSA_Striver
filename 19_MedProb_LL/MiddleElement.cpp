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

        int mid = ceil((cnt+1)/2);

        cnt = 0;
        ListNode* temp2 = head;
        while(cnt<= mid){
            temp2 = temp2->next;
            cnt++;
        }

        return temp2;
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
    fourth-> next = fifth;  
    fifth-> next = nullptr;

    Solution sol;
    ListNode* ans = sol.middleNode(head);
    cout<< ans->val << endl;

    

  
    

}