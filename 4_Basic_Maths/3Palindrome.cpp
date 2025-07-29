/*      Q.1)    
Given an integer x, return true if x is a palindrome, and false otherwise.
*/

#include<iostream>
using namespace std ;

bool palindrome(int x){ 
    int original =x, a, rev=0;
    while(x!=0){
        a = x%10;
        x/=10 ;
        rev = (rev*10) +a ;
    }
    if(rev != original || rev < 0 ){
        return false ;
    }
    return true;
}


int main(){
    int x;
    cin>> x;
    if(palindrome(x)){
        cout <<" it is palindrome."; 
    }
    else cout<< "not a palindrome.";

 
}