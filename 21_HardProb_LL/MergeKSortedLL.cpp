// YT Explainnation =   https://youtu.be/1zktEppsdig?si=jHUw02nYNX0By2UY

#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



// 
class Solution {
  public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        // if the list is empty
        if(lists.size() ==0){
            return nullptr;
        }
        // if the list contains only one ll
        if(lists.size()==1){
            return lists[0];
        }

        // 1. combine all LL into 1 array
        vector<int> arr;

        for(int i=0 ; i<lists.size();i++){
            while(lists[i] != nullptr){
                arr.push_back(lists[i]->val);
                lists[i]= lists[i]-> next;
            }
        }

        // 2. sort the array
        sort(arr.begin(),arr.end());

        // 3. create a new sortedd ll from array

        ListNode* sorted = new ListNode(arr[0]);
        ListNode* temp = sorted;
        for(int i=1; i< arr.size(); i++){
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }

        return sorted;

    }
};





// Solution 2 , T.C = O( ) , S.C = 
class Solution {
public:

    ListNode* merge2SortedLL(ListNode* l1, ListNode* l2){
        ListNode* merged = new ListNode(-1);
        ListNode* temp = merged;

        while(l1 != nullptr && l2 != nullptr){
            if(l1->val <= l2->val){
                temp->next = l1;
                l1 = l1->next;
                temp = temp->next;
            }
            else{
                temp->next = l2;
                l2 = l2->next;
                temp = temp->next;
            }
        }

        if(l1 != nullptr){
            temp->next = l1;
        }
        if(l2 != nullptr){
            temp->next = l2;
        }

        return merged->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* finalmerged = lists[0];
        
        for(int i = 0 ; i< lists.size(); i++){
            finalmerged = merge2SortedLL(finalmerged, lists[i]);

        }
        return finalmerged;
    }
};


