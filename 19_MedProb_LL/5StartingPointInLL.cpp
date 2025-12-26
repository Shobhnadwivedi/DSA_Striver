#include <iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class ListNode {
  public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). 

It is -1 if there is no cycle. Note that pos is not passed as a parameter.

*/


// Brute force Approach : Using Hashing (unordered_set ya map can also be used - unordered_map<ListNode*, count> )

class Solution1 {
  public:
    ListNode *detectCycle(ListNode *head) {

      if(head==nullptr || head->next==nullptr){
        return nullptr;
      }

      unordered_set<ListNode*> s1 ;
      ListNode* temp = head;

      while(temp){
        if(s1.count(temp)){
          return temp;
        }
        s1.insert(temp);
        temp = temp->next;
      }

      return nullptr;
    }
};


// Optimal Approach : Tortoise and Hare Algorithm 

// first check if cycle is present or not
// if cycle is present , then find the starting point of the cycle  

// Logic : jab slow and fast mil jatey h , we place any one pointer at head again and keep other at meeting point only , 
// and then move both of them one step at a time , where they meet again is the starting point of the cycle


class Solution2{
  public:
    ListNode* detectCycle(ListNode* head){
      if(head==nullptr || head->next==nullptr){
        return nullptr;
      }

      ListNode* slow = head;
      ListNode* fast = head;

      // step 1 : check if cycle is present or not 

      bool isCycle = false;

      while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
          isCycle = true;
          break;
        }
      }

      // step 2 : if cycle is present , find the starting point of the cycle 

      if(isCycle){
        slow = head;

        while(slow != fast){
          slow = slow->next;
          fast = fast->next;
        }

        return slow; // starting point of the cycle 
      }

      return nullptr; // no cycle present
    }

};