#include<iostream>
#include<vector>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;

    ListNode(int data): val(data), next(nullptr){};
    ListNode(int data, ListNode* nextnode): val(data), next(nextnode){};


};


class Solution{
public:

    ListNode* reverseLL(ListNode* head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forward;

        while(curr){

            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;

        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k){

        if(head == nullptr || head->next == nullptr){
            return head;
        }

        if(k==0){
            return head;
        }

        ListNode* temp = head;
        ListNode* newlist = head;
        vector<ListNode*> lists ;
        lists.push_back(head);

        while(temp){ 

            for(int cnt=1; cnt<k; cnt++){
                if(temp->next != nullptr){
                    temp = temp->next;
                }
                else{
                    break;
                }

            }
            lists.push_back(temp->next);
            
            temp = temp->next;

        }

        for(int i=0 ; i< lists.size() ; i++){
            reverseLL(lists[i]);
        }

    }
};
