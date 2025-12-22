#include<iostream>
using namespace std;

class Node{
  public:
    int data;
    Node* next;

    Node(int d, Node* n = nullptr){
        data  = d;
        next = nullptr;
    }

};


void deleteTail(Node* head){
    Node* temp = head ;
    Node* prev = new Node(0);
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
void deleteTail2(Node* &head){
    if(head==nullptr){
        return;
    }
    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head ;
    Node* prev = nullptr;

    while(temp->next != nullptr ){
        prev = temp;
        temp = temp->next ;
    }

    // now temp is at tail and prev is the node just before tail.
    prev->next = nullptr;
    delete temp;


}

int main(){

    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);


    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = nullptr;

    
    deleteTail(head);

    Node* temp = head;
    while(temp != nullptr){
        cout<< temp->data << " ";
        temp = temp->next;
    }

    
    

}