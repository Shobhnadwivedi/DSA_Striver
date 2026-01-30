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

//  RECURSIVE SOLUTION
class Solution2{
  public:

    int helper(string &s, int i , long long num, int sign){

        if(i>= s.size() || !isdigit(s[i])){
            return num * sign ;
        }

        int digit = s[i] - '0' ;
        num = num *10 + digit ;

        if(sign*num < INT_MIN){ return INT_MIN ;}
        if(sign*num > INT_MAX){ return INT_MAX ;}

        return helper(s, i+1, num , sign);
    }
    int myAtoi(string s) {
        int i = 0;

        while(s[i]==' ' && i < s.size()){
            i++;
        }

        int sign= 1;
        if(s[i] == '-'){
            sign = -1 ;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }

        long long num = 0 ;
        
        return helper(s, i , num , sign);
    }
    
};


int main(){
    string str= "-42";
    
    Solution sol ;
    
    cout << sol.myAtoi(str) ;
}