#include<iostream>
using namespace std;

class Node{
  public:
    int data;
    Node*next;

    Node(int d, Node* n = nullptr){
        data = d;
        next = nullptr;
    }
};

// Insert at head 
class Solution1{
  public:
    Node* insertAtHead(Node* head, int x){

        Node* newnode = new Node(x);
        newnode->next = head;
        return newnode;
    }
};

// Insert at tail
class Solution2{
  public:
    Node* insertAtTail(Node* head, int x){
        Node* temp = head;
        Node* newnode = new Node(x);
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

    Solution2  sol ;
    head = sol.insertAtTail(head, 10);

    Node* temp = head;
    while(temp != nullptr){ 
        cout<< temp->data << " ";
        temp = temp->next;
    }
}