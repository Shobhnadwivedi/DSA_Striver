#include<iostream>
using namespace std;

class Node{
  public:

    int data;
    Node* next;

    Node(int d){
        data = d;
        next = nullptr;
    }

};

int main(){
    int arr[5] = {10,20,30,40,50};


    Node* head = new Node(arr[0]);
    Node* ptr = head;


    for(int i=1; i< sizeof(arr)/sizeof(arr[0]); i++){
        Node* temp = new Node(arr[i]);
        ptr-> next = temp;  // linking the new node to the previous node

        ptr = temp;   // or ptr = ptr->next;    moving the ptr to the new node   
    }

    cout << head->data << " " << head->next->data << " " << head->next->next->data << " " << head->next->next->next->data << " " << head->next->next->next->next->data << endl;



}