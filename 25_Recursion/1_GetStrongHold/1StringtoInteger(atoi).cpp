#include<iostream>
using namespace std;


class Solution {
public:
    int myAtoi(string s) {
        int num = 0;

        bool negative = false;
        if(s[0] < '0' || s[0] > '9'){
            return 0;
        }

        for(char ch: s){
            if(ch < '0' || ch > '9'){
                break;
            }
            if(ch == '-'){
                negative = true;
                continue;
            }
            if(ch ==' '){
                continue;
            }
            if(ch == '+'){
                continue;
            }
            int digit = ch - '0';
            num = num * 10 + digit ;
        }

        if(negative){
            num = -num;
        }

        if(num < INT_MIN){
            return INT_MIN;
        }
        if(num > INT_MAX){
            return INT_MAX;
        }

        return num;
    }
};


int main(){
    string str= "-42";
    
    Solution sol ;
    
    cout << sol.myAtoi(str) ;
}