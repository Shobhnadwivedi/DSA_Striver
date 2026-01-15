#include<iostream>
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

    ListNode* merge(ListNode* head , ListNode* mid){
        ListNode* left = head;
        ListNode* right = mid;
        
        ListNode* merged = new ListNode (-1);  // very important to delete late vrna memory leak hoga , kyunki har recursion mein dummy node bnega
        ListNode* temp = merged;

        while(left && right){
            if(left->val <= right->val){
                temp->next = left;
                left = left->next;
                temp = temp->next;
            }
            else{
                temp->next = right;
                right= right->next;
                temp = temp->next;
            }
        }

        if(left){
            temp->next = left;
        }
        if(right){
            temp->next = right;
        }
        return merged->next;

    }

    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next == nullptr){
            return head;
        }

        // find mid     and  mid->next se new list
        ListNode* slow = head ;
        ListNode* fast = head->next ;  
        
        // important to put fast at head->next , vrna slow will be at mid for even length ll, but we want it at mid-1 , taki we can break the ll into 2 halves properly
    
        while(fast && fast->next){
            slow = slow->next ;
            fast = fast->next->next;
            
        }
        // slow is at mid
        ListNode* mid = slow->next ;
        slow = nullptr ;   // break the list into 2 halves

        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        return merge(left , right);
            
    }
};