#include <iostream>
#include <stack>
using namespace std;

// Sort Stack using recursion 

void sortStack(stack<int>& s){
    if(s.empty()){
        return ;
    }

    int removed = s.top();
    s.pop();

    sortStack(s);

    if(removed >= s.top() || s.empty()){
        s.push(removed) ;
    }
    else{
        int badme = s.top() ;
        s.pop();
        s.push(removed) ;
        s.push(badme) ;
    }
}


int main() {
    stack<int> s;
    s.push(4);
    s.push(1);
    s.push(3);
    s.push(2);

    sortStack(s);

    // Print the sorted stack
    cout << "Sorted stack (descending order): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}