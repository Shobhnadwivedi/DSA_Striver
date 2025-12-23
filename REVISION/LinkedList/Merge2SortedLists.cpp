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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1==nullptr){ return list2; }
        if(list2==nullptr){ return list2; }

        ListNode* newnode = new ListNode(0);

        if(list1->val >= list2->val){
            newnode->val = list2->val;
            list2 = list2->next;
        }
        else{
            newnode->val = list1->val;
            list1 = list1->next;
        }

        ListNode* newtemp = newnode;
        while(list1 && list2){
            if(list1->val <= list2->val){
                newtemp->next = list1;
                list1 = list1->next;
            }
            else{
                newtemp->next = list2;
                list2 = list2->next;
            }
            newtemp= newtemp->next;
        }
        
        if(list1 == nullptr){
            newtemp->next = list2;
        }
        if(list2 == nullptr){
            newtemp->next = list1;
        }
        return newnode;
    }
};