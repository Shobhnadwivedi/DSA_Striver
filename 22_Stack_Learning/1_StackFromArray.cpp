#include <iostream>
#include <vector>
using namespace std;


//  using a static array to implement stack 
//  for every size stack we need to change the array size in the class definition
class mystack{
  private:
    int arr[10];
    int top;

  public:

    mystack(){
        top = -1;
    }

    void push(int x){
        if(top ==9){
            cout<< "Stack Overflow";
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop(int x){
        if(top== -1){
            cout << "Stack Underflow";
            return;
        }
        top--;
    }

    int peek(){
        if(top == -1){
            cout << "Stack is empty";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty(){
        return top == -1;
    }

    int size(){
        return top + 1;
    }

};


// Dynamically allocating array for stack - manually allocating and deallocating memory in heap 
// different from dynamic array - vector -  automatically manages memory
class mystack2{
  private:
    int* arr;            // pointer to integer array
    int capacity;
    int top;

  public:
    // Constructor
    mystack2(int cap){
      capacity = cap;
      arr = new int[capacity];    // dynamically allocating array in heap
      top = -1;
    }


    // Destructor
    ~mystack2(){
        delete[] arr;       // deallocating memory to prevent memory leak
    }                       // this step is very important when we use new to allocate memory in heap manually

    void push(int x){
        if(top ==9){
            cout<< "Stack Overflow";
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop(int x){
        if(top== -1){
            cout << "Stack Underflow";
            return;
        }
        top--;
    }

    int peek(){
        if(top == -1){
            cout << "Stack is empty";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty(){
        return top == -1;
    }

    int size(){
        return top + 1;
    }

};


//  Stack implementation using  std::vector
//  vector is a dynamic array that automatically manages memory 
class mystack_vector{
  public:
    vector<int> v1;

  public:
    
    void push(int x){
      v1.push_back(x);
    }

    void pop(){
      if(v1.empty()){
        cout<< "Stack Underflow";
        return;
      }
      v1.pop_back();
    }

    int peek(){
      if(v1.empty()){
        cout << "Stack is empty";
        return -1;
      }
      return v1.back();
    }

    bool isEmpty(){
      return v1.empty();
    }

    int size(){
      return v1.size();
    }

};




int main(){}