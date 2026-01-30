#include <iostream>
using namespace std;




class Solution {                         // This solution gave error in cases like x = 2.00000 , n = -2147483648 ; in the line n = - n ;
public:
    double myPow(double x, int n) {     // As n can be -ve and its range is -2^31 to 2^31 -1 , so if n = -2^31 then -n will exceed the range of int data type
                                        // hence we will use long long data type for n


        long long N = n ;               // Instead of this line , we can directly use long long in function parameter like double myPow(double x, long long n)
        // base case 

        if(N==0){ return 1.0 ; }
        if(N==1){ return x ; }

        if (N<0){
            x = 1/x ;
            N = -N ;
        }
        if(N%2 == 0){
            double half = myPow(x, N/2) ;
            return half * half ;
        }
        else{ 
            return x * myPow(x, N-1) ;
        }
        
    }
};


// OPTIMISED RECURSIVE SOLUTION

class Solution2 {
public:
    double myPow(double x, long long n) {
        // base case 

        if(n==0){ return 1.0 ; }
        if(n==1){ return x ; }

        if (n<0){
            x = 1/x ;
            n = -n ;
        }
        if(n%2 == 0){
            double half = myPow(x, n/2) ;
            return half * half ;
        }
        else{ 
            return x * myPow(x, n-1) ;
        }
        
    }
};