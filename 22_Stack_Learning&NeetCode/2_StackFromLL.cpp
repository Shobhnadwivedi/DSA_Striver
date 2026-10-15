#include<iostream>
using namespace std;


// Node structure for linked list
class TreeNode{
  public:
    int data;
    TreeNode* next;

  
    TreeNode(int d){
        data = d;
        next = nullptr;
    }
};

// Stack implementation using linked list

class myStack{
    private:
        TreeNode* top;
        int cnt;

    public:

        myStack(){
            top= nullptr;
            cnt=0;
        }
        
        void push(int x){
            TreeNode* new_node = new TreeNode(x);
            new_node->next  = top;
            top = new_node;
            cnt++;

        }

        int pop(){
            if (top == nullptr){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            TreeNode* temp = top;
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
