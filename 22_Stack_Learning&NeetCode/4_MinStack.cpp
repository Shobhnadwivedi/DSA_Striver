#include <iostream>
#include <stack>

using namespace std;


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
*/


/* 
Constraints:

Methods pop, top and getMin operations will always be called on non-empty stacks.

*/


class MinStack { 
    stack<pair<int,int>> st;
    int minim ;

public:
    MinStack() {
        minim = INT_MAX; 
    }
    
    void push(int val) {
        if(st.empty()){
            minim = min(minim, val);
        }
        else{
            pair<int,int> top_pair = st.top();
            minim = min(top_pair.second, val);

        }
        
        st.push(pair<int,int>(val, minim));
        
    }
    
    void pop() {
        st.pop();
        if(st.empty()){
            minim = INT_MAX;
        }

    }
    
    int top() {
        pair<int,int> top_pair = st.top();
        int x = top_pair.first;
        return x;  
    }
    
    int getMin() {
        pair<int,int> top_pair = st.top();
        int x = top_pair.second;
        return x;
    }

};




// OPTIMAL SOL   =  S.C = O(N)  , T.C = O(1)

class MinStack2 {
    stack<long long> st ;
    long long minim ;

  public:
    MinStack2() {
        minim = LLONG_MAX;
    }

    void push(long long val){
        if(st.empty()) {
            minim = val;
            st.push(val);
        }
        else{
            if( val < minim) {    // if new val to be pushed is less than current minimum, it will be the new minimum and we will push an encoded value
                
                st.push(2LL *val - minim); // encoded value
                
                minim = val;// new minmum
            } 
            else{
                st.push(val);
            }   
        
        }
    }

    void pop(){
        long long top_char = st.top();
        st.pop();

        if(top_char < minim){
            // new minimum (of prev elemnts ) after removing top 
            minim = 2LL*minim - top_char;
        }

    }

    long long top(){
        if(minim > st.top()){
            return minim;
        }
        else{
            return st.top();    
        }
    }

    long long getMin(){
        return minim;
    }
};

int main(){

}

