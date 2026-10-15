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


void deleteTail(TreeNode* head){
    TreeNode* temp = head ;
    TreeNode* prev = new TreeNode(0);
    prev->next = head;

    while(temp->next != nullptr ){
        prev = temp;
        temp = temp->next ;
    }

    // now temp is at tail and prev is the node just before tail. 

    prev->next = nullptr;
    delete temp;
}


// Optimized Approach

//      1.  &head is passed as reference  , so that changes that are made in the function are also reflected outside the function
//      2.  We handle the case when there is only one node separately , it was not handled in the previous approach
//      3.  We do not create any extra node for prev, (prev is created using new but never deleted, This causes memory leak)
void deleteTail2(TreeNode* &head){
    if(head==nullptr){
        return;
    }
    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }

    TreeNode* temp = head ;
    TreeNode* prev = nullptr;

    while(temp->next != nullptr ){
        prev = temp;
        temp = temp->next ;
    }

    // now temp is at tail and prev is the node just before tail.
    prev->next = nullptr;
    delete temp;


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

    
    deleteTail(head);

    TreeNode* temp = head;
    while(temp != nullptr){
        cout<< temp->data << " ";
        temp = temp->next;
    }

    
    

}