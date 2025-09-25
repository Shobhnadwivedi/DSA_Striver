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

class Solution {
public:
    Node* deleteNode(Node* head,int k) {
        if (head == nullptr){
            return nullptr;
        }
        if(k==1){
            Node* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        int cnt=0;
        Node* prev = nullptr;
        Node* curr = head;
        while(curr!= nullptr){
            cnt++;
            
            if(cnt==k){
                prev->next = prev->next->next;
                delete curr;
                
                break;
            }
            prev = curr;
            curr= curr->next;
        }
        return head;

    }
};

class Solution2 {
public:
    void deleteNode(Node* node) {
        Node* temp = node;
        node->data = node->next->data;
        
        node->next = node->next->next;
       
        delete temp->next;
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

    

    Solution2 sol;
    sol.deleteNode(head->next->next); // Deleting node with value 3

    Node* temp = head;
    while(temp != nullptr){ 
        cout<< temp->data << " ";
        temp = temp->next;
    }
    

}