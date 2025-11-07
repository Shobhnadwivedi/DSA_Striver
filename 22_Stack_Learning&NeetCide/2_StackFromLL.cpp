#include<iostream>
using namespace std;


// Node structure for linked list
class Node{
  public:
    int data;
    Node* next;

  
    Node(int d){
        data = d;
        next = nullptr;
    }
};

// Stack implementation using linked list

class myStack{
    private:
        Node* top;
        int cnt;

    public:

        myStack(){
            top= nullptr;
            cnt=0;
        }
        
        void push(int x){
            Node* new_node = new Node(x);
            new_node->next  = top;
            top = new_node;
            cnt++;

        }

        int pop(){
            if (top == nullptr){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            Node* temp = top;
            top = top->next;
            int popped = temp->data;
            delete temp;
            cnt--;
            return popped;


        }

        int peek(){
            if(top == nullptr){
                cout << "Stack is empty ";
                return -1;
            }
            return top->data;
        }

        bool isEmpty(){
            return top == nullptr;
        }

        int size(){
            return cnt;
        }

};
