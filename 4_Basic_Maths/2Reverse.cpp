/*      Q.1
Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
*/

# include<iostream>
# include<math.h>
using namespace std ;

int reverse1(int x){
    int num=0, a ;
    while(x!=0){
        a= x%10;
        x=x/10;
        // setting the limit
        if(num> std::numeric_limits<int>::max()/10 || (num== std::numeric_limits<int>::max() && a>7 )) {return 0;}
        if(num< std::numeric_limits<int>::min()/10 || (num== std::numeric_limits<int>::min() && a < (-8) )) {return 0;}

        num= (num*10) + a ;
    }
    return num;
}

/*
signed 32-bit integer range [-2^31, 2^31 - 1], which is [   .
*/


int mod(int x ){
    int y;
    y= x%10;
    return y;
}

int main(){
    int x;
    cin>> x;
    int num = reverse1(x);
    cout<< num; 

} 