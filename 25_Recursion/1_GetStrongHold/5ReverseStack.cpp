//         https://www.geeksforgeeks.org/problems/reverse-a-stack/1

// same logic as sort stack = use 2 recursive functions 
#include<iostream>
#include<stack>
using namespace std;

class Solution {
  public:  
    void insertAtEnd(stack<int> &st, int elem){

        if(st.empty()){
            st.push(elem);
            return;
        }

        int temp = st.top();
        st.pop();
        insertAtEnd(st, elem);
        st.push(temp);

    }

    void reverseStack(stack<int> &st) {
        if(st.empty()){
            return;
        }

        int removed = st.top();
        st.pop();
        reverseStack(st);
        insertAtEnd(st, removed);
        
    }
};