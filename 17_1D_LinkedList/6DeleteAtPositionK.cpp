#include<iostream>
using namespace std;

class TreeNode{
  public:
    int data;
    TreeNode* next;

    TreeNode(int d, TreeNode* n = nullptr){
        data  = d;
        next = nullptr;
    }

};
// when k is given as position
class Solution {
public:
    TreeNode* deleteNode(TreeNode* head,int k) {
        if (head == nullptr){
            return nullptr;
        }
        if(k==1){
            TreeNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        int cnt=0;
        TreeNode* prev = nullptr;
        TreeNode* curr = head;
        while(curr!= nullptr){
            cnt++;
            
            if(cnt==k){
                prev->next = prev->next->next;
                delete curr;
                
                break;
            }
            prev = curr;
            curr= curr->next;
        }
        return head;

    }
};


// when node to be deleted is given directly
class Solution2 {
public:
    void deleteNode(TreeNode* node) {
        TreeNode* temp = node;
        node->data = node->next->data;
        
        node->next = node->next->next;
       
        delete temp->next;
    }
};

// when value to be deleted is given 
class Solution3{
  public:
    TreeNode* deleteNode(TreeNode* head , int val){
        
    }
};

int main(){
    TreeNode* head = new TreeNode(1);
    TreeNode* second = new TreeNode(2);
    TreeNode* third = new TreeNode(3);
    TreeNode* fourth = new TreeNode(4);
    TreeNode* fifth = new TreeNode(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = nullptr;

    

    Solution2 sol;
    sol.deleteNode(head->next->next); // Deleting node with value 3

    TreeNode* temp = head;
    while(temp != nullptr){ 
        cout<< temp->data << " ";
        temp = temp->next;
    }
    

}