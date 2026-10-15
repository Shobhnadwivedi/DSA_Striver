#include<iostream>
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

int main(){
    int arr[5] = {10,20,30,40,50};


    TreeNode* head = new TreeNode(arr[0]);
    TreeNode* ptr = head;


    for(int i=1; i< sizeof(arr)/sizeof(arr[0]); i++){
        TreeNode* temp = new TreeNode(arr[i]);
        ptr-> next = temp;  // linking the new node to the previous node

        ptr = temp;   // or ptr = ptr->next;    moving the ptr to the new node   
    }

    cout << head->data << " " << head->next->data << " " << head->next->next->data << " " << head->next->next->next->data << " " << head->next->next->next->next->data << endl;



}