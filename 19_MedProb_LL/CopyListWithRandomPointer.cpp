#include <iostream>
#include<unordered_map>
using namespace std;

class TreeNode {
  public:
    int val;
    TreeNode *next;
    TreeNode* random;

    // different constructors
    TreeNode() : val(0), next(nullptr), random(nullptr) {}
    TreeNode(int x) : val(x), next(nullptr) , random(nullptr) {}
    TreeNode(int x, TreeNode *next) : val(x), next(next) , random(nullptr) {}
    TreeNode(int x, TreeNode *next, TreeNode* random) : val(x), next(next) , random(random) {}

};


class Solution {
public:
    TreeNode* copyRandomList(TreeNode* head) {
        if(head == nullptr){
            return nullptr;
        }

        TreeNode* temp = head;
        unordered_map<TreeNode*, TreeNode*> mp;

        while(temp){
            TreeNode* newnode = new TreeNode(temp->val);
            mp[temp]= newnode;
            temp = temp->next;
        }

        temp = head;
        while(temp){
            mp[temp]->next = mp[temp->next];
            mp[temp]-> random = mp[temp->random];
            temp = temp->next;
        }
        
        return mp[head];
        
    }
};



class Solution2 {
public:
    TreeNode* copyRandomList(TreeNode* head) {
        if(head == nullptr){
            return nullptr;
        }

        TreeNode* temp = head;

        while(temp){
            TreeNode* a = temp->next;
            temp->next = new TreeNode(temp->val);
            temp->next->next = a;
            temp = a;        //  or temp = temp->next->next;
        }


        temp = head;
        while(temp != nullptr && temp->next != nullptr){
            if(temp->random != nullptr){
                temp->next ->random = temp->random ->next;
            }
            temp = temp->next ->next;
        }

        TreeNode* dummy = new TreeNode(0);
        TreeNode* temp2 = dummy;
        temp = head;
        while(temp){
            TreeNode* a = temp->next->next;
            temp2 ->next = temp->next;
            temp2 = temp2->next;
            temp ->next = a;
            temp = a;
        }

        return dummy->next;
    }
};