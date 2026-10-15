#include <iostream>
using namespace std;

class TreeNode{
  public:

    int data;
    TreeNode* next;

    TreeNode(int d){
        data = d;
        next = nullptr;
    }

};

// Count nodes in Linked List
class Solution {
  public:
    int getCount(TreeNode* head) {
        // Code here
        TreeNode* ptr = head;
        int cnt;

        while(ptr){
            ptr = ptr-> next;
            cnt++;
        }
        return cnt;

    }
};

// Search in Linked List
class Solution2 {
  public:
    bool searchKey(TreeNode* head, int key) {
        // Code here
        bool isthere= false;
        TreeNode* ptr = head;
        
        while(ptr != nullptr){
            if(ptr->data == key){
                isthere = true;
            }
            else{
                ptr = ptr->next;
            }
        }
        return isthere;
    }
};