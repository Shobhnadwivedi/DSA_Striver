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

    
    

    Node* secondlast = head;
    while( secondlast->next->next != nullptr){
        secondlast = secondlast->next;
    }

    Node* tail_variable = secondlast->next;
    secondlast->next = nullptr;
    delete tail_variable;

    Node* temp = head;
    while(temp != nullptr){
        cout<< temp->data << " ";
        temp = temp->next;
    }

    
    

}