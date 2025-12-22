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



// when k is given as position

void deleteatK(Node* &head, int k){

    // if linked list is empty
    if(head == nullptr){
        return;
    }

    // if k=1 ,i.e. head node to be deleted

    if(k==1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    int cnt=0;
    Node* prev = nullptr;
    Node* curr = head;

    while(curr){
        cnt++;
        
        if(cnt ==k){
            prev->next = prev->next->next;
            delete curr;
            break; 
        }

        prev = curr;
        curr= curr->next;
    }
    return;

}


int main(){

    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = nullptr;

    int k;
    cin >> k;

    deleteatK(head, k);

    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }

}