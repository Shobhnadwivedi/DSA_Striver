#include <iostream>
#include <stack>

using namespace std;

/*
Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i< s.length(); i++){
            if(s[i]==')' || s[i]==']' || s[i]=='}'){
                if(st.empty()) return false;

                char top_char = st.top();
                if((s[i]==')'  && top_char=='(') ||  s[i]==']'  && top_char=='[' ||  s[i]=='}'  && top_char=='{'){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
                   
            }

            else{
                st.push(s[i]);
            }
        }

        return st.empty();
    }
};


// SAME COMPLEXITY BUT MORE EFFICIENT - 
// 2nd approach immediately returns false when there is a mismatch
//  but the previous one keeps pushing even the mismatched one , so it covers more iterations in general = more complexity

class Solution2 {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto it: s){
            if(it=='('  || it == '{'  || it == '['){
                st.push(it);
            }

            else{
                if(st.empty()){ return false;}
                char top_char = st.top();
                st.pop();

                if((  it ==')' && top_char =='('  )  ||  
                   (  it =='}' && top_char =='{'  )  ||  
                   (  it ==']' && top_char =='['  )         ){

                    continue;
                }
                else{
                    return false;
                }
            }
        }

        return st.empty();
                    
    }
};








class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto it: s){
            if(it=='('  || it == '{'  || it == '['){
                st.push(it);
            }

            else{
                char top_char = st.top();
                if(st.empty()){ return false;}
                // can't put the line - " char top_char = st.top(); " 
                // here bcuz , if/elsse if/ else ke beech mein koi normal statement nahi hona chahiye
                else if((  it ==')' && top_char =='('  )  ||  
                   (  it =='}' && top_char =='{'  )  ||  
                   (  it ==']' && top_char =='['  )         ){

                    st.pop();;
                }
                else{
                    st.push(it);
                }
            }
        }

        

        return st.empty();
    }
};