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
        
        TreeNode(int d, TreeNode* n){
            data = d;
            next = n;
        }

};

// function that will convert an array to linked list and print it
void arrToLL(int arr[], int n){
    TreeNode* head = new TreeNode(arr[0]);
    TreeNode* temp = head;

    for(int i=1 ; i<n; i++){
        temp -> next = new TreeNode(arr[i]);
        temp = temp->next;
    }

    // print the linked list
    TreeNode* ptr = head;
    while(ptr){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}


int main(){

    int arr[5] = {10,20,30,40,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    arrToLL(arr, n);

}