#include<iostream>
using namespace std;

class TreeNode{
 public: 
    int data;
    TreeNode* next;

    TreeNode(int d){
        data= d;
        next = nullptr;
    }

};


int main(){

    TreeNode* head = new TreeNode(1); 

    TreeNode* second = new TreeNode(2);

    head->next = second ; // linking first node to second node

    cout<< head->data << " "<<  second->data << endl;

    // delete head of linked list

    TreeNode* var = head->next;

    head->next = nullptr;

    head = var;

    cout<< head->data << endl;
}


/*    IN above method we are not deleting the head node from memory, we are just moving the head pointer to next node
      so to avoid memory leak we can do it like this :

    Node* temp = head;   // storing the address of head node in a variable

    head = head->next;   // moving the head pointer to next node

    delete temp;         // deleting the previous head node using temp pointer

    cout<< head->data << endl;



*/