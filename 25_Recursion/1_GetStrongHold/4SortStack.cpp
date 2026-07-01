//  https://www.geeksforgeeks.org/problems/sort-a-stack/1

#include <iostream>
#include <stack>
using namespace std;

// Sort Stack using recursion 


// Wrong solution - 
void sortStack1(stack<int>& s){
    if(s.empty()){
        return ;
    }

    int removed = s.top();       // is solution me sortStack1 is suposed to take only unsorted stack as a n argument ; its task is just to -   1. remove top      2. sort the remaining stack recursively     
    s.pop();

    sortStack1(s);

    if( s.empty()|| removed >= s.top() ){
        s.push(removed) ;
        return;
    }
    else{
        int badme = s.top() ;
        s.pop();
        if(s.empty() || removed >= s.top()){
            s.push(removed);
            s.push(badme) ;
            return;
        }
        else{
            s.push(removed) ; 
            sortStack1(s);           // here we are calling sortStack1 again with a partially sorted stack which is not correct
            s.push(badme);
            return;
        }
    }
}

class Solution {
  public:  
    void insertInSortedOrder(stack<int> &s, int element){
        // Base case : agr stack empty h ya fir element to be inserted is greater than equal to the top one
        if(s.empty() || element >= s.top()){
            s.push(element);
            return ;
        }

        // if not , then top wale ko temporarily remove and recursively insert the element in the remaining stack 
        int val = s.top();
        s.pop();
        insertInSortedOrder(s, element);

        // finally after inserting element at correct position , we need to put back the temporarily removed element
        s.push(val);

    }
    void sortStack(stack<int> &s){
        if(s.empty()){
            return ;
        }

        int removed = s.top();
        s.pop();
        sortStack(s);   // sort the remaining stack recursively
        insertInSortedOrder(s , removed);   // insert the removed element in sorted order in the sorted remaining stack

    


    }
};


int main() {
    stack<int> s;
    s.push(4);
    s.push(1);
    s.push(3);
    s.push(2);

    sortStack1(s);

    // Print the sorted stack
    cout << "Sorted stack (descending order): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}