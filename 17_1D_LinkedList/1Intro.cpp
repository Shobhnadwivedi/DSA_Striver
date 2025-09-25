#include<iostream>
using namespace std;

class Node{
 public: 
    int data;
    Node* next;

/*  constructor to initialize the node 
    // in C++ constructor has same name as class


    Node(int d, Node* n){          // here Node* n = nullptr means if we do not provide the value of n, it will be initialized to nullptr by default
        data =d;
        next = nullptr;                           
    }


*/
    // 2nd constructor to initialize the node with only data
    Node(int d){
        data= d;
        next = nullptr;
    }

};

/*
int x = 10 ;
int* y = &x ;       y is the pointer pointing to x

Same thing can also be written as :
int* y = new  int(10)

in case of Node data type :
Node* y = new Node(10) ;   // here 10 is the data part and next part is initialized to nullptr by default
*/

int main(){

    Node* head = new Node(1); 

    Node* second = new Node(2);

    head->next = second ; // linking first node to second node

    cout<< head->data << " "<<  second->data << endl;

    // important step to avoid memory leak
    

}