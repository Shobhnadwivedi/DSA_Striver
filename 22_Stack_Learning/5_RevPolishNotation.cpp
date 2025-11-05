#include<iostream>
#include<stack>
#include<vector>
#include<string>  // to use stoi()  = stands for  " string to integer "  

using namespace std;


class Solution {
    stack<int> st;
public:
    int evalRPN(vector<string>& tokens) {
        for(auto it: tokens){
            if(it=="+" || it=="-" || it =="*" || it=="/"){
                int top2 = st.top();
                st.pop();
                int top1 = st.top();
                st.pop();

                if(it=="+"){
                    st.push(top1 + top2);
                }
                else if(it=="-"){
                    st.push(top1- top2) ;
                }
                else if(it== "/"){
                    if(top1< top2 ){
                        st.push(0); // integer division
                    }
                    else{
                        st.push(top1 / top2);
                    }
                }
                else {
                    st.push(top1 * top2);
                }
            }

            else{
                st.push(stoi(it));
            }
        }

        return st.top();
    }
};

int main (){
    Solution sol;
    vector<string> tokens = {"2","1","+","3","*"};
    cout<< sol.evalRPN(tokens) << endl;
}