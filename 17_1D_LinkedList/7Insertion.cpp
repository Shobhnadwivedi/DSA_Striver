#include<iostream>
using namespace std;

class TreeNode{
  public:
    int data;
    TreeNode*next;

    TreeNode(int d, TreeNode* n = nullptr){
        data = d;
        next = nullptr;
    }
};

// Insert at head 
class Solution1{
  public:
    TreeNode* insertAtHead(TreeNode* head, int x){

        TreeNode* newnode = new TreeNode(x);
        newnode->next = head;
        return newnode;
    }
};

// Insert at tail
class Solution2{
  public:
    TreeNode* insertAtTail(TreeNode* head, int x){
        TreeNode* temp = head;
        TreeNode* newnode = new TreeNode(x);
        if(head == nullptr){
            return newnode;
        }
        while(temp->next != nullptr){
            temp = temp->next;
            
        }
        temp-> next = newnode;
        return head;
    }
};

// Insertion at position k

void insertAtK(TreeNode* &head, int k,int x){

    if(k<=0){
        return;
    }
   
    TreeNode* newnode = new TreeNode(x);
    
    if(k==1){
        newnode->next = head;
        head = newnode;
        return;
    }

    int cnt =1;
    TreeNode* curr = head;

    // pehle traverse till (k-1)th node 
    // by the condition ( cnt < k-1 ) , the last loop will run under condition cnt = k-2 , 
    // and since (k-2) < (k-1) , the loop will run one more time and curr will point to (k-1)th node

    while(curr && cnt<k-1){
        curr = curr->next;
        cnt++;
    }

    if(curr == nullptr){         //  mtlb k is more than length of ll 
        delete newnode;
        return; 
    }

    newnode->next = curr->next;
    curr->next = newnode;
    

} 



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

    Solution2  sol ;
    head = sol.insertAtTail(head, 10);

    TreeNode* temp = head;
    while(temp != nullptr){ 
        cout<< temp->data << " ";
        temp = temp->next;
    }
}