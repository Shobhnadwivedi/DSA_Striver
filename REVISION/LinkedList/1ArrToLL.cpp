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
        
        Node(int d, Node* n){
            data = d;
            next = n;
        }

};

// function that will convert an array to linked list and print it
void arrToLL(int arr[], int n){
    Node* head = new Node(arr[0]);
    Node* temp = head;

    for(int i=1 ; i<n; i++){
        temp -> next = new Node(arr[i]);
        temp = temp->next;
    }

    // print the linked list
    Node* ptr = head;
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